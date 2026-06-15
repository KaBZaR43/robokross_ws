#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/bool.hpp>
#include <boost/asio.hpp>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory>
#include <thread>
#include <mutex>

// ============================================================================
// АБСТРАКТНЫЙ ИНТЕРФЕЙС ПРОТОКОЛА ДРАЙВЕРОВ МОТОРОВ
// ============================================================================
// ЗАМЕНИТЕ MockMotorProtocol НА РЕАЛЬНУЮ РЕАЛИЗАЦИЮ ПОСЛЕ ПОЛУЧЕНИЯ DATASHEET
// ============================================================================
class IMotorProtocol {
public:
    virtual ~IMotorProtocol() = default;
    
    // Упаковка команды в байтовый массив
    // left_pct, right_pct: 0-100 (проценты мощности)
    // flags: битовая маска флагов
    virtual std::vector<uint8_t> pack(uint8_t left_pct, uint8_t right_pct, uint8_t flags) = 0;
    
    // Расчет CRC (если требуется протоколом)
    virtual uint16_t calculate_crc(const std::vector<uint8_t>& data) = 0;
};

// ============================================================================
// ЗАГЛУШКА ДЛЯ ТЕСТИРОВАНИЯ (MOCK)
// ============================================================================
class MockMotorProtocol : public IMotorProtocol {
public:
    std::vector<uint8_t> pack(uint8_t left_pct, uint8_t right_pct, uint8_t flags) override {
        // Пример структуры пакета: [ID, Left, Right, Flags, CRC_H, CRC_L, 0x0D, 0x0A]
        std::vector<uint8_t> payload = {0xAA, left_pct, right_pct, flags};
        uint16_t crc = calculate_crc(payload);
        
        std::vector<uint8_t> packet;
        packet.insert(packet.end(), payload.begin(), payload.end());
        packet.push_back((crc >> 8) & 0xFF);
        packet.push_back(crc & 0xFF);
        packet.push_back(0x0D);
        packet.push_back(0x0A);
        
        return packet;
    }
    
    uint16_t calculate_crc(const std::vector<uint8_t>& data) override {
        // Простая CRC16 для тестирования
        uint16_t crc = 0xFFFF;
        for (auto byte : data) {
            crc ^= byte;
            for (int i = 0; i < 8; i++) {
                if (crc & 1) crc = (crc >> 1) ^ 0xA001;
                else crc >>= 1;
            }
        }
        return crc;
    }
};

// ============================================================================
// УЗЕЛ УПРАВЛЕНИЯ МОТОРАМИ
// ============================================================================
class CmdVelBridge : public rclcpp::Node {
public:
    CmdVelBridge() : Node("cmd_vel_bridge"), io_context_(), serial_port_(io_context_) {
        // Параметры кинематики
        this->declare_parameter<double>("wheel_base", 0.7);
        this->declare_parameter<double>("max_speed_ms", 2.78); // 10 км/ч
        this->declare_parameter<std::string>("motor_uart_port", "/dev/ttyV4");
        this->declare_parameter<int>("motor_baudrate", 115200);
        this->declare_parameter<double>("watchdog_timeout_sec", 0.3);
        
        wheel_base_ = this->get_parameter("wheel_base").as_double();
        max_speed_ = this->get_parameter("max_speed_ms").as_double();
        watchdog_timeout_ = this->get_parameter("watchdog_timeout_sec").as_double();
        
        // Инициализация UART для моторов
        std::string port_name = this->get_parameter("motor_uart_port").as_string();
        int baudrate = this->get_parameter("motor_baudrate").as_int();
        
        try {
            serial_port_.open(port_name);
            serial_port_.set_option(boost::asio::serial_port_base::baud_rate(baudrate));
            serial_port_.set_option(boost::asio::serial_port_base::character_size(8));
            serial_port_.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
            serial_port_.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
            serial_port_.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
            RCLCPP_INFO(this->get_logger(), "Motor UART opened: %s @ %d baud", port_name.c_str(), baudrate);
        } catch (const boost::system::system_error& e) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open motor UART: %s", e.what());
        }
        
        // Инициализация протокола (ЗАМЕНИТЕ НА РЕАЛЬНЫЙ)
        protocol_ = std::make_shared<MockMotorProtocol>();
        
        // Подписка на /cmd_vel
        cmd_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10, std::bind(&CmdVelBridge::cmd_vel_callback, this, std::placeholders::_1));
        
        // Подписка на управление режимами (ПАУЗА/ДВИЖЕНИЕ/СТОП)
        mode_sub_ = this->create_subscription<std_msgs::msg::Bool>(
            "/mode_switch", 10, std::bind(&CmdVelBridge::mode_callback, this, std::placeholders::_1));
        
        // Таймер отправки команд (50 Гц согласно Protokol_BUD.docx п. 3.1.1)
        send_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(20), std::bind(&CmdVelBridge::send_callback, this));
        
        // Таймер watchdog (аварийная остановка при потере связи)
        watchdog_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(static_cast<int>(watchdog_timeout_ * 1000)),
            std::bind(&CmdVelBridge::watchdog_callback, this));
        
        // Начальное состояние: ПАУЗА (согласно регламенту п. 8.2)
        current_mode_ = MODE_PAUSE;
        last_cmd_time_ = this->now();
        target_left_pct_ = 0;
        target_right_pct_ = 0;
        current_flags_ = 0x00;
        
        RCLCPP_INFO(this->get_logger(), "CmdVelBridge initialized. Mode: PAUSE");
        RCLCPP_INFO(this->get_logger(), "Wheel base: %.2f m, Max speed: %.2f m/s", wheel_base_, max_speed_);
    }

private:
    // ========================================================================
    // ОБРАБОТЧИК /cmd_vel
    // ========================================================================
    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        last_cmd_time_ = this->now();
        
        // Переход в режим ДВИЖЕНИЕ только из ПАУЗА (согласно п. 8.3 регламента)
        if (current_mode_ != MODE_DRIVE) {
            RCLCPP_WARN(this->get_logger(), "Received cmd_vel but not in DRIVE mode. Ignoring.");
            return;
        }
        
        // Кинематика Skid-Steer (4WD)
        double v_left = msg->linear.x - msg->angular.z * (wheel_base_ / 2.0);
        double v_right = msg->linear.x + msg->angular.z * (wheel_base_ / 2.0);
        
        // Нормализация в проценты [0, 100]
        double pct_left = std::abs(v_left / max_speed_) * 100.0;
        double pct_right = std::abs(v_right / max_speed_) * 100.0;
        
        // Ограничение диапазона
        pct_left = std::clamp(pct_left, 0.0, 100.0);
        pct_right = std::clamp(pct_right, 0.0, 100.0);
        
        // Формирование флагов (байт 3 из Protokol_BUD.docx)
        uint8_t flags = 0x00;
        flags |= 0x04; // Бит 3.2: Зажигание = 1 (всегда включено в режиме ДВИЖЕНИЕ)
        
        // Бит 3.0: Направление левого борта (0=вперед, 1=назад)
        if (v_left < 0) flags |= 0x01;
        // Бит 3.1: Направление правого борта
        if (v_right < 0) flags |= 0x02;
        
        // Биты 3.3, 3.6: Тормоза = 0 (отпущены)
        // Бит 3.4: Подрыв заряда = 0
        // Бит 3.7: Разрешение на подрыв = 0
        
        target_left_pct_ = static_cast<uint8_t>(pct_left);
        target_right_pct_ = static_cast<uint8_t>(pct_right);
        current_flags_ = flags;
        
        RCLCPP_DEBUG(this->get_logger(), 
            "Cmd: Left=%d%%, Right=%d%%, Flags=0x%02X", 
            target_left_pct_, target_right_pct_, current_flags_);
    }
    
    // ========================================================================
    // УПРАВЛЕНИЕ РЕЖИМАМИ (ПАУЗА/ДВИЖЕНИЕ/СТОП)
    // ========================================================================
    void mode_callback(const std_msgs::msg::Bool::SharedPtr msg) {
        bool enable_drive = msg->data;
        
        if (enable_drive && current_mode_ == MODE_PAUSE) {
            // Переход ПАУЗА → ДВИЖЕНИЕ (п. 8.3)
            current_mode_ = MODE_DRIVE;
            RCLCPP_INFO(this->get_logger(), "Mode: PAUSE → DRIVE");
        } else if (!enable_drive && current_mode_ == MODE_DRIVE) {
            // Переход ДВИЖЕНИЕ → СТОП → ПАУЗА (п. 8.3)
            emergency_stop();
            current_mode_ = MODE_PAUSE;
            RCLCPP_INFO(this->get_logger(), "Mode: DRIVE → STOP → PAUSE");
        }
    }
    
    // ========================================================================
    // WATCHDOG (АВАРИЙНАЯ ОСТАНОВКА ПРИ ПОТЕРЕ СВЯЗИ)
    // ========================================================================
    void watchdog_callback() {
        auto elapsed = (this->now() - last_cmd_time_).seconds();
        
        if (elapsed > watchdog_timeout_ && current_mode_ == MODE_DRIVE) {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                "WATCHDOG: No cmd_vel for %.2f sec. Emergency STOP!", elapsed);
            emergency_stop();
            current_mode_ = MODE_PAUSE;
        }
    }
    
    // ========================================================================
    // АВАРИЙНАЯ ОСТАНОВКА
    // ========================================================================
    void emergency_stop() {
        target_left_pct_ = 0;
        target_right_pct_ = 0;
        current_flags_ = 0x00;
        current_flags_ |= 0x08; // Бит 3.3: Тормоз 1 = 1
        current_flags_ |= 0x40; // Бит 3.6: Тормоз 2 = 1
        // Зажигание остается включенным (0x04)
        current_flags_ |= 0x04;
        
        RCLCPP_ERROR(this->get_logger(), "EMERGENCY STOP activated!");
    }
    
    // ========================================================================
    // ОТПРАВКА КОМАНД НА МОТОРЫ (50 Гц)
    // ========================================================================
    void send_callback() {
        if (!serial_port_.is_open()) return;
        
        // Упаковка пакета через абстрактный интерфейс
        std::vector<uint8_t> packet = protocol_->pack(target_left_pct_, target_right_pct_, current_flags_);
        
        // Асинхронная отправка
        boost::system::error_code ec;
        boost::asio::write(serial_port_, boost::asio::buffer(packet), ec);
        
        if (ec) {
            RCLCPP_ERROR_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                "UART write error: %s", ec.message().c_str());
        }
    }
    
    // ========================================================================
    // ПАРАМЕТРЫ И СОСТОЯНИЕ
    // ========================================================================
    enum Mode { MODE_OFF, MODE_PAUSE, MODE_DRIVE, MODE_STOP };
    
    double wheel_base_;
    double max_speed_;
    double watchdog_timeout_;
    
    Mode current_mode_;
    rclcpp::Time last_cmd_time_;
    uint8_t target_left_pct_;
    uint8_t target_right_pct_;
    uint8_t current_flags_;
    
    // ROS 2 интерфейсы
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr mode_sub_;
    rclcpp::TimerBase::SharedPtr send_timer_;
    rclcpp::TimerBase::SharedPtr watchdog_timer_;
    
    // Аппаратные интерфейсы
    boost::asio::io_context io_context_;
    boost::asio::serial_port serial_port_;
    std::shared_ptr<IMotorProtocol> protocol_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CmdVelBridge>());
    rclcpp::shutdown();
    return 0;
}