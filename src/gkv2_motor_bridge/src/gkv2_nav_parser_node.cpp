#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <std_msgs/msg/header.hpp>
#include "gkv2_motor_bridge/msg/gkv2_status.hpp"
#include <boost/asio.hpp>
#include <vector>
#include <cstdint>
#include <cstring>
#include <cmath>

// Таблица CRC32 из приложения А протокола ЛМАП.402131.009Д1
static const uint32_t crc32_tab[256] = {
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
    0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988, 0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
    0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
    0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
    0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172, 0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
    0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
    0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
    0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924, 0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
    0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
    0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
    0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e, 0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
    0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
    0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
    0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0, 0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
    0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
    0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
    0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a, 0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
    0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
    0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
    0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc, 0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
    0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
    0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
    0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236, 0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
    0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
    0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
    0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38, 0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
    0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
    0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
    0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2, 0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
    0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
    0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
    0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94, 0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

uint32_t calculate_crc32(const uint8_t* data, size_t length) {
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < length; i++) {
        crc = crc32_tab[(crc ^ data[i]) & 0xFF] ^ (crc >> 8);
    }
    return crc ^ 0xFFFFFFFF;
}

class GKV2NavParser : public rclcpp::Node {
public:
    GKV2NavParser() : Node("gkv2_nav_parser"), io_context_(), serial_port_(io_context_) {
        // Параметры
        this->declare_parameter<std::string>("uart_port", "/dev/ttyV0");
        this->declare_parameter<int>("baudrate", 921600);
        this->declare_parameter<int>("qos_depth", 10);
        
        std::string port_name = this->get_parameter("uart_port").as_string();
        int baudrate = this->get_parameter("baudrate").as_int();
        int qos_depth = this->get_parameter("qos_depth").as_int();

        // Создание QoS профиля (auto + фигурные скобки для избежания Most Vexing Parse)
        auto qos = rclcpp::QoS{rclcpp::KeepLast(qos_depth)};
        qos.reliability(rclcpp::ReliabilityPolicy::Reliable);

        // Создание издателей
        pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/nav/pose", qos);
        imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>("/nav/imu", qos);
        status_pub_ = this->create_publisher<gkv2_motor_bridge::msg::GKV2Status>("/gkv2/status", qos);
        
        // UART
        try {
            serial_port_.open(port_name);
            serial_port_.set_option(boost::asio::serial_port_base::baud_rate(baudrate));
            serial_port_.set_option(boost::asio::serial_port_base::character_size(8));
            serial_port_.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
            serial_port_.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
            serial_port_.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
            RCLCPP_INFO(this->get_logger(), "UART opened: %s @ %d baud", port_name.c_str(), baudrate);
        } catch (const boost::system::system_error& e) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open UART: %s", e.what());
            return;
        }
        
        start_async_read();
        io_thread_ = std::make_unique<std::thread>([this]() { io_context_.run(); });
        
        RCLCPP_INFO(this->get_logger(), "GKV2 Nav Parser initialized");
    }
    
    ~GKV2NavParser() {
        io_context_.stop();
        if (io_thread_ && io_thread_->joinable()) io_thread_->join();
        if (serial_port_.is_open()) serial_port_.close();
    }

private:
    void start_async_read() {
        serial_port_.async_read_some(
            boost::asio::buffer(read_buffer_, 256),
            [this](const boost::system::error_code& error, std::size_t /*bytes_transferred*/) {
                if (!error) {
                    process_buffer();
                    start_async_read();
                } else {
                    RCLCPP_ERROR(this->get_logger(), "Read error: %s", error.message().c_str());
                }
            }
        );
    }
    
    void process_buffer() {
        buffer_.insert(buffer_.end(), read_buffer_.begin(), read_buffer_.end());
        
        // Поиск заголовка 0xFF
        while (buffer_.size() >= 4) {
            if (buffer_[0] != 0xFF) {
                buffer_.erase(buffer_.begin());
                continue;
            }
            
            uint8_t address = buffer_[1];
            uint8_t packet_type = buffer_[2];
            uint8_t data_length = buffer_[3];
            
            // Ожидание полного пакета: 4 (заголовок) + data_length + 4 (CRC32)
            size_t packet_size = 4 + data_length + 4;
            if (buffer_.size() < packet_size) break;
            
            // Проверка типа пакета (0x13 - наборный пакет)
            if (packet_type == 0x13) {
                // Проверка CRC32
                uint32_t recv_crc = *reinterpret_cast<uint32_t*>(&buffer_[4 + data_length]);
                uint32_t calc_crc = calculate_crc32(buffer_.data(), 4 + data_length);
                
                if (recv_crc == calc_crc) {
                    parse_nav_packet(&buffer_[4], data_length);
                } else {
                    RCLCPP_WARN(this->get_logger(), "CRC32 mismatch: recv=0x%08X, calc=0x%08X", recv_crc, calc_crc);
                }
            }
            
            buffer_.erase(buffer_.begin(), buffer_.begin() + packet_size);
        }
    }
    
    void parse_nav_packet(const uint8_t* data, uint8_t length) {
        // Параметры наборного пакета (float32, little-endian)
        // 43: x, 44: y, 45: z, 36: pitch, 37: roll, 38: yaw
        // 46: vx, 47: vy, 48: vz, 64: lax, 65: lay, 66: laz
        // 72: gps_state_status (uint32), 79: gps_num_ss (uint16)
        
        if (length < 54) {
            RCLCPP_WARN(this->get_logger(), "Packet too short: %d bytes", length);
            return;
        }
        
        float x = *reinterpret_cast<const float*>(&data[0]);
        float y = *reinterpret_cast<const float*>(&data[4]);
        float z = *reinterpret_cast<const float*>(&data[8]);
        float pitch = *reinterpret_cast<const float*>(&data[12]);
        float roll = *reinterpret_cast<const float*>(&data[16]);
        float yaw = *reinterpret_cast<const float*>(&data[20]);
        float vx = *reinterpret_cast<const float*>(&data[24]);
        float vy = *reinterpret_cast<const float*>(&data[28]);
        float vz = *reinterpret_cast<const float*>(&data[32]);
        float lax = *reinterpret_cast<const float*>(&data[36]);
        float lay = *reinterpret_cast<const float*>(&data[40]);
        float laz = *reinterpret_cast<const float*>(&data[44]);
        uint32_t gps_state_status = *reinterpret_cast<const uint32_t*>(&data[48]);
        uint16_t gps_num_satellites = *reinterpret_cast<const uint16_t*>(&data[52]);
        
        // Публикация PoseStamped
        geometry_msgs::msg::PoseStamped pose;
        pose.header.stamp = this->now();
        pose.header.frame_id = "map";
        pose.pose.position.x = x;
        pose.pose.position.y = y;
        pose.pose.position.z = z;
        
        // Преобразование Euler (yaw, pitch, roll) в кватернион
        float cy = cos(yaw * 0.5f);
        float sy = sin(yaw * 0.5f);
        float cp = cos(pitch * 0.5f);
        float sp = sin(pitch * 0.5f);
        float cr = cos(roll * 0.5f);
        float sr = sin(roll * 0.5f);
        
        pose.pose.orientation.w = cy * cp * cr + sy * sp * sr;
        pose.pose.orientation.x = cy * cp * sr - sy * sp * cr;
        pose.pose.orientation.y = sy * cp * sr + cy * sp * cr;
        pose.pose.orientation.z = sy * cp * cr - cy * sp * sr;
        
        pose_pub_->publish(pose);
        
        // Публикация Imu
        sensor_msgs::msg::Imu imu;
        imu.header.stamp = this->now();
        imu.header.frame_id = "base_link";
        imu.linear_acceleration.x = lax;
        imu.linear_acceleration.y = lay;
        imu.linear_acceleration.z = laz;
        imu_pub_->publish(imu);
        
        // Публикация статуса
        gkv2_motor_bridge::msg::GKV2Status status;
        status.gps_state_status = gps_state_status;
        status.gps_num_satellites = gps_num_satellites;
        status.alg_state_status = 50.0f; // Полная навигация (этап 50)
        status.rtk_fixed = (gps_state_status & 0x00C00000) == 0x00800000; // Биты 22-23: RTK Fixed
        status_pub_->publish(status);
        
        RCLCPP_DEBUG(this->get_logger(), "Nav: x=%.2f, y=%.2f, yaw=%.2f, sats=%d, RTK=%s",
            x, y, yaw, gps_num_satellites, status.rtk_fixed ? "FIXED" : "FLOAT");
    }
    
    boost::asio::io_context io_context_;
    boost::asio::serial_port serial_port_;
    std::array<uint8_t, 256> read_buffer_;
    std::vector<uint8_t> buffer_;
    std::unique_ptr<std::thread> io_thread_;
    
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_pub_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
    rclcpp::Publisher<gkv2_motor_bridge::msg::GKV2Status>::SharedPtr status_pub_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GKV2NavParser>());
    rclcpp::shutdown();
    return 0;
}