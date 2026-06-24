// ~/robocross_all/robokross_ws/src/robokross_control/src/stm32_bridge_node.cpp
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/u_int8.hpp>
#include <std_msgs/msg/u_int16.hpp>
#include <std_msgs/msg/bool.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <boost/asio.hpp>
#include <cmath>

class STM32BridgeNode : public rclcpp::Node {
public:
    STM32BridgeNode() : Node("stm32_bridge"), io_context_(), serial_port_(io_context_) {
        // Параметры
        this->declare_parameter<std::string>("uart_port", "/dev/ttyTHS1");
        this->declare_parameter<int>("baudrate", 115200);
        this->declare_parameter<double>("max_speed_ms", 2.5);  // 9 км/ч без помощника
        this->declare_parameter<double>("wheel_base", 0.7);
        
        std::string port = this->get_parameter("uart_port").as_string();
        int baud = this->get_parameter("baudrate").as_int();
        max_speed_ = this->get_parameter("max_speed_ms").as_double();
        wheel_base_ = this->get_parameter("wheel_base").as_double();
        
        // Инициализация UART
        try {
            serial_port_.open(port);
            serial_port_.set_option(boost::asio::serial_port_base::baud_rate(baud));
            serial_port_.set_option(boost::asio::serial_port_base::character_size(8));
            serial_port_.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
            serial_port_.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
            serial_port_.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
            RCLCPP_INFO(this->get_logger(), "UART opened: %s @ %d baud", port.c_str(), baud);
        } catch (const boost::system::system_error& e) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open UART: %s", e.what());
        }
        
        // Подписки
        cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10, std::bind(&STM32BridgeNode::cmd_vel_callback, this, std::placeholders::_1));
        
        brake_sub_ = this->create_subscription<std_msgs::msg::Bool>(
            "/brake/control", 10, std::bind(&STM32BridgeNode::brake_callback, this, std::placeholders::_1));
        
        lights_sub_ = this->create_subscription<std_msgs::msg::UInt16>(
            "/lights/control", 10, std::bind(&STM32BridgeNode::lights_callback, this, std::placeholders::_1));
        
        horn_sub_ = this->create_subscription<std_msgs::msg::Bool>(
            "/horn/control", 10, std::bind(&STM32BridgeNode::horn_callback, this, std::placeholders::_1));
        
        // Таймер отправки команд моторам (50 Гц)
        send_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(20),
            std::bind(&STM32BridgeNode::send_callback, this));
        
        // Watchdog таймер (300 мс)
        watchdog_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(300),
            std::bind(&STM32BridgeNode::watchdog_callback, this));
        
        last_cmd_time_ = this->now();
        current_left_pct_ = 0;
        current_right_pct_ = 0;
        brake_active_ = false;
        lights_bitmask_ = 0;
        horn_active_ = false;
        reverse_active_ = false;
        
        RCLCPP_INFO(this->get_logger(), "STM32 Bridge initialized. Max speed: %.2f m/s", max_speed_);
    }

    ~STM32BridgeNode() {
        if (serial_port_.is_open()) {
            try {
                serial_port_.close();
            } catch (const boost::system::system_error&) {
                // Игнорируем ошибки при закрытии
            }
        }
    }

private:
    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        if (!rclcpp::ok()) return;
        
        last_cmd_time_ = this->now();
        
        // Преобразование Twist в проценты мощности
        // linear.x: -max_speed до +max_speed м/с → -100 до +100%
        // angular.z: дифференциальное управление
        
        double linear_pct = (msg->linear.x / max_speed_) * 100.0;
        double angular_pct = (msg->angular.z * wheel_base_ / max_speed_) * 100.0;
        
        current_left_pct_ = clamp(linear_pct - angular_pct, -100.0, 100.0);
        current_right_pct_ = clamp(linear_pct + angular_pct, -100.0, 100.0);
        
        // Определение направления (для флага reverse)
        reverse_active_ = (msg->linear.x < 0);
        
        RCLCPP_DEBUG(this->get_logger(), 
            "cmd_vel: linear=%.2f, angular=%.2f → left=%.1f%%, right=%.1f%%",
            msg->linear.x, msg->angular.z, current_left_pct_, current_right_pct_);
    }
    
    void brake_callback(const std_msgs::msg::Bool::SharedPtr msg) {
        brake_active_ = msg->data;
        send_brake_command();
    }
    
    void lights_callback(const std_msgs::msg::UInt16::SharedPtr msg) {
        lights_bitmask_ = msg->data;
        send_lights_command();
    }
    
    void horn_callback(const std_msgs::msg::Bool::SharedPtr msg) {
        horn_active_ = msg->data;
        send_horn_command();
    }
    
    void send_callback() {
        if (!rclcpp::ok()) return;
        if (!serial_port_.is_open()) return;
        
        // Отправка команды моторам (50 Гц)
        send_motor_command(current_left_pct_, current_right_pct_);
    }
    
    void watchdog_callback() {
        if (!rclcpp::ok()) return;
        
        double elapsed = (this->now() - last_cmd_time_).seconds();
        
        if (elapsed > 0.3) {
            RCLCPP_WARN(this->get_logger(), "Watchdog timeout! Stopping motors...");
            current_left_pct_ = 0;
            current_right_pct_ = 0;
            send_motor_command(0, 0);
        }
    }
    
    void send_motor_command(double left_pct, double right_pct) {
        if (!serial_port_.is_open()) return;
        uint8_t left = static_cast<uint8_t>(clamp(std::abs(left_pct), 0.0, 100.0));
        uint8_t right = static_cast<uint8_t>(clamp(std::abs(right_pct), 0.0, 100.0));
        
        // Формирование пакета CMD_BUD (из Protokol_BUD.docx)
        // [0xDE][left][right][flags][CRC16][0x0D][0x0A]
        std::vector<uint8_t> packet = {
            0xDE,  // Идентификатор
            left,  // Акселератор левый борт (0-100%)
            right, // Акселератор правый борт (0-100%)
            0x00   // Флаги (будут заполнены ниже)
        };
        
        // Установка флагов в байте 3
        uint8_t flags = 0x00;
        if (left_pct < 0) flags |= 0x01;  // Направление левый (1=назад)
        if (right_pct < 0) flags |= 0x02; // Направление правый (1=назад)
        flags |= 0x04;  // Зажигание (всегда включено при работе)
        if (brake_active_) flags |= 0x08;  // Тормоз 1
        // Бит 4: Подрыв заряда (не используется)
        // Биты 5-6: Резерв
        if (brake_active_) flags |= 0x80;  // Тормоз 2 (дублирование для безопасности)
        
        packet[3] = flags;
        
        // Вычисление CRC16 (из Protokol_BUD.docx)
        uint16_t crc = calculate_crc16(packet.data(), packet.size());
        packet.push_back((crc >> 8) & 0xFF);
        packet.push_back(crc & 0xFF);
        
        // Завершающие байты
        packet.push_back(0x0D);
        packet.push_back(0x0A);
        
        // Отправка
        try {
            serial_port_.write_some(boost::asio::buffer(packet));
        } catch (const boost::system::system_error& e) {
            if (e.code() == boost::asio::error::interrupted) {
                RCLCPP_WARN(this->get_logger(), "UART write interrupted");
                return;
            }
            RCLCPP_ERROR_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                "UART write error: %s", e.what());
        }
    }
    
    void send_brake_command() {
        if (!serial_port_.is_open()) return;
        uint8_t brake_val = brake_active_ ? static_cast<uint8_t>(1) : static_cast<uint8_t>(0);
        std::vector<uint8_t> packet = {
            0xAA, 0x55, 0x02, 0x01, brake_val
        };
        append_crc(packet);
        send_packet(packet);
    }
    
    void send_lights_command() {
        if (!serial_port_.is_open()) return;
        uint8_t hi = static_cast<uint8_t>((lights_bitmask_ >> 8) & 0xFF);
        uint8_t lo = static_cast<uint8_t>(lights_bitmask_ & 0xFF);
        std::vector<uint8_t> packet = {
            0xAA, 0x55, 0x04, 0x02, hi, lo
        };
        append_crc(packet);
        send_packet(packet);
    }
    
    void send_horn_command() {
        if (!serial_port_.is_open()) return;
        uint8_t horn_val = horn_active_ ? static_cast<uint8_t>(1) : static_cast<uint8_t>(0);
        std::vector<uint8_t> packet = {
            0xAA, 0x55, 0x05, 0x01, horn_val
        };
        append_crc(packet);
        send_packet(packet);
    }
    
    void send_packet(const std::vector<uint8_t>& packet) {
        if (!serial_port_.is_open()) return;
        try {
            serial_port_.write_some(boost::asio::buffer(packet));
        } catch (const boost::system::system_error& e) {
            if (e.code() == boost::asio::error::interrupted) {
                return;
            }
            RCLCPP_ERROR_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                "UART write error: %s", e.what());
        }
    }
    
    void append_crc(std::vector<uint8_t>& packet) {
        uint16_t crc = calculate_crc16(packet.data(), packet.size());
        packet.push_back((crc >> 8) & 0xFF);
        packet.push_back(crc & 0xFF);
    }
    
    uint16_t calculate_crc16(const uint8_t* data, size_t length) {
        // CRC16 из Protokol_BUD.docx
        uint16_t crc = 0xFFFF;
        for (size_t i = 0; i < length; i++) {
            crc = (crc << 8) ^ cx_datagram_crc16_table[(crc >> 8) ^ data[i]];
        }
        return crc;
    }
    
    double clamp(double value, double min, double max) {
        return std::max(min, std::min(max, value));
    }
    
    // CRC16 таблица из Protokol_BUD.docx
    static const uint16_t cx_datagram_crc16_table[256];
    
    boost::asio::io_context io_context_;
    boost::asio::serial_port serial_port_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr brake_sub_;
    rclcpp::Subscription<std_msgs::msg::UInt16>::SharedPtr lights_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr horn_sub_;
    rclcpp::TimerBase::SharedPtr send_timer_;
    rclcpp::TimerBase::SharedPtr watchdog_timer_;
    
    rclcpp::Time last_cmd_time_;
    double max_speed_;
    double wheel_base_;
    double current_left_pct_;
    double current_right_pct_;
    bool brake_active_;
    uint16_t lights_bitmask_;
    bool horn_active_;
    bool reverse_active_;
};

// Инициализация CRC16 таблицы из Protokol_BUD.docx
const uint16_t STM32BridgeNode::cx_datagram_crc16_table[256] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
    0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
    0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
    0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
    0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
    0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
    0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
    0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
    0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
    0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
    0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
    0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
    0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
    0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
    0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
    0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
    0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
    0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
    0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
    0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
    0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
    0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
    0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<STM32BridgeNode>());
    rclcpp::shutdown();
    return 0;
}