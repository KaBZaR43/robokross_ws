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
#include <unordered_map>
#include <algorithm>

// ============================================================================
// CRC32 из приложения А протокола ЛМАП.402131.009Д1
// ============================================================================
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

// ============================================================================
// Структура навигационных данных
// ============================================================================
struct NavData {
    // Позиция NED (ID 43-45), метры
    float x = 0.0f, y = 0.0f, z = 0.0f;
    // Ориентация (ID 36-38), радианы
    float pitch = 0.0f, roll = 0.0f, yaw = 0.0f;
    // Скорости (ID 46-48), м/с
    float vx = 0.0f, vy = 0.0f, vz = 0.0f;
    // Линейные ускорения (ID 64-66), м/с²
    float lax = 0.0f, lay = 0.0f, laz = 0.0f;
    
    // Статусы
    uint32_t gps_state_status = 0;   // ID 72
    uint16_t gps_num_satellites = 0; // ID 79
    uint32_t gps_rel_status = 0;     // ID 29
    uint32_t alg_state_status = 0;   // ID 96
    
    // Двухантенное решение (ID 13-14)
    float gps_rel_heading = 0.0f;
    float gps_rel_length = 0.0f;
    
    // СКО координат (ID 85-87), метры
    float gnss_sig_lat = 0.0f, gnss_sig_lon = 0.0f, gnss_sig_alt = 0.0f;
    
    // Дисперсии ошибки алгоритма (ID 98-106)
    float alg_var_x = 0.0f, alg_var_y = 0.0f, alg_var_z = 0.0f;
    float alg_var_vx = 0.0f, alg_var_vy = 0.0f, alg_var_vz = 0.0f;
    float alg_var_psi = 0.0f, alg_var_theta = 0.0f, alg_var_phi = 0.0f;
    
    // Флаги валидности
    bool has_position = false;
    bool has_orientation = false;
    bool has_velocity = false;
    bool has_acceleration = false;
    bool has_gnss_status = false;
    bool has_alg_status = false;
    bool has_rel_status = false;
    bool has_dual_antenna = false;
    bool has_sigmas = false;
    bool has_variances = false;
};

// ============================================================================
// УЗЕЛ ПАРСЕРА НАВИГАЦИИ ГКВ2
// ============================================================================
class GKV2NavParser : public rclcpp::Node {
public:
    GKV2NavParser() : Node("gkv2_nav_parser"), io_context_(), serial_port_(io_context_) {
        // Параметры
        this->declare_parameter<std::string>("uart_port", "/dev/ttyV1");
        this->declare_parameter<int>("baudrate", 921600);
        this->declare_parameter<int>("qos_depth", 10);
        this->declare_parameter<std::vector<int64_t>>("packet_parameter_ids", 
            std::vector<int64_t>{43, 44, 45, 36, 37, 38, 46, 47, 48, 64, 65, 66, 72, 79, 29, 13, 14, 85, 86, 87, 96, 98, 99, 100, 101, 102, 103, 104, 105, 106});
        
        std::string port_name = this->get_parameter("uart_port").as_string();
        int baudrate = this->get_parameter("baudrate").as_int();
        int qos_depth = this->get_parameter("qos_depth").as_int();
        
        // Чтение порядка ID параметров из YAML
        auto ids_param = this->get_parameter("packet_parameter_ids").as_integer_array();
        for (auto id : ids_param) {
            if (id < 0 || id > 255) {
                RCLCPP_ERROR(this->get_logger(), "Invalid parameter ID: %ld", id);
                continue;
            }
            packet_ids_.push_back(static_cast<uint8_t>(id));
        }
        
        if (packet_ids_.empty()) {
            RCLCPP_FATAL(this->get_logger(), "No parameter IDs configured! Check 'packet_parameter_ids' in YAML.");
            return;
        }
        
        RCLCPP_INFO(this->get_logger(), "Loaded %zu parameter IDs from config", packet_ids_.size());
        
        // Publishers
        auto qos = rclcpp::QoS{rclcpp::KeepLast(qos_depth)};
        qos.reliability(rclcpp::ReliabilityPolicy::BestEffort);  // BEST_EFFORT для высокочастотных данных
        
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
        
        // Статистика
        packets_received_ = 0;
        crc_errors_ = 0;
        short_packets_ = 0;
        
        start_async_read();
        io_thread_ = std::make_unique<std::thread>([this]() { io_context_.run(); });
        
        RCLCPP_INFO(this->get_logger(), "GKV2 Nav Parser initialized");
        RCLCPP_INFO(this->get_logger(), "Expected packet size: %zu bytes (header 4 + data %zu + CRC 4)", 
                    4 + packet_ids_.size() * 4 + 4, packet_ids_.size() * 4);
    }
    
    ~GKV2NavParser() {
        io_context_.stop();
        if (io_thread_ && io_thread_->joinable()) io_thread_->join();
        if (serial_port_.is_open()) serial_port_.close();
    }

private:
    // ========================================================================
    // АСИНХРОННОЕ ЧТЕНИЕ UART
    // ========================================================================
    void start_async_read() {
        serial_port_.async_read_some(
            boost::asio::buffer(read_buffer_, 512),
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
    
    // ========================================================================
    // ОБРАБОТКА БУФЕРА: ПОИСК ПАКЕТА 0x13
    // ========================================================================
    void process_buffer() {
        buffer_.insert(buffer_.end(), read_buffer_.begin(), read_buffer_.end());
        
        // Ожидаемый размер пакета: 4 (заголовок) + N*4 (данные) + 4 (CRC32)
        const size_t expected_size = 4 + packet_ids_.size() * 4 + 4;
        
        while (buffer_.size() >= expected_size) {
            // Поиск заголовка 0xFF
            if (buffer_[0] != 0xFF) {
                buffer_.erase(buffer_.begin());
                continue;
            }
            
            // Проверка типа пакета
            if (buffer_[2] != 0x13) {
                // Не наборный пакет — пропускаем байт
                buffer_.erase(buffer_.begin());
                continue;
            }
            
            // Проверка длины поля данных
            uint8_t data_length = buffer_[3];
            size_t actual_packet_size = 4 + data_length + 4;
            
            if (buffer_.size() < actual_packet_size) {
                break;  // Ждем остальных байтов
            }
            
            // Проверка CRC32
            uint32_t recv_crc = *reinterpret_cast<uint32_t*>(&buffer_[4 + data_length]);
            uint32_t calc_crc = calculate_crc32(buffer_.data(), 4 + data_length);
            
            if (recv_crc != calc_crc) {
                crc_errors_++;
                RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
                    "CRC32 mismatch: recv=0x%08X, calc=0x%08X (total errors: %lu)", 
                    recv_crc, calc_crc, crc_errors_);
                buffer_.erase(buffer_.begin(), buffer_.begin() + actual_packet_size);
                continue;
            }
            
            // Парсинг данных
            if (data_length == packet_ids_.size() * 4) {
                parse_nav_packet(&buffer_[4], data_length);
                packets_received_++;
            } else {
                short_packets_++;
                RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
                    "Unexpected data length: %d (expected %zu)", 
                    data_length, packet_ids_.size() * 4);
            }
            
            buffer_.erase(buffer_.begin(), buffer_.begin() + actual_packet_size);
        }
        
        // Ограничение размера буфера (защита от переполнения)
        if (buffer_.size() > 4096) {
            RCLCPP_WARN(this->get_logger(), "Buffer overflow, clearing %zu bytes", buffer_.size());
            buffer_.clear();
        }
    }
    
    // ========================================================================
    // ПАРСИНГ НАБОРНОГО ПАКЕТА ПО ID ПАРАМЕТРОВ
    // ========================================================================
    void parse_nav_packet(const uint8_t* data, uint8_t length) {
        NavData nav;
        
        // Идем по порядку ID из конфигурации
        for (size_t i = 0; i < packet_ids_.size(); i++) {
            uint8_t id = packet_ids_[i];
            size_t offset = i * 4;
            
            if (offset + 4 > length) break;
            
            float value = *reinterpret_cast<const float*>(&data[offset]);
            
            switch (id) {
                // Позиция NED
                case 43: nav.x = value; nav.has_position = true; break;
                case 44: nav.y = value; break;
                case 45: nav.z = value; break;
                
                // Ориентация
                case 36: nav.pitch = value; nav.has_orientation = true; break;
                case 37: nav.roll = value; break;
                case 38: nav.yaw = value; break;
                
                // Скорости
                case 46: nav.vx = value; nav.has_velocity = true; break;
                case 47: nav.vy = value; break;
                case 48: nav.vz = value; break;
                
                // Линейные ускорения
                case 64: nav.lax = value; nav.has_acceleration = true; break;
                case 65: nav.lay = value; break;
                case 66: nav.laz = value; break;
                
                // Статусы (целочисленные, но передаются как float32 в наборном пакете)
                case 72: nav.gps_state_status = static_cast<uint32_t>(value); nav.has_gnss_status = true; break;
                case 79: nav.gps_num_satellites = static_cast<uint16_t>(value); break;
                case 29: nav.gps_rel_status = static_cast<uint32_t>(value); nav.has_rel_status = true; break;
                case 96: nav.alg_state_status = static_cast<uint32_t>(value); nav.has_alg_status = true; break;
                
                // Двухантенное решение
                case 13: nav.gps_rel_heading = value; nav.has_dual_antenna = true; break;
                case 14: nav.gps_rel_length = value; break;
                
                // СКО координат
                case 85: nav.gnss_sig_lat = value; nav.has_sigmas = true; break;
                case 86: nav.gnss_sig_lon = value; break;
                case 87: nav.gnss_sig_alt = value; break;
                
                // Дисперсии ошибки алгоритма
                case 98:  nav.alg_var_x = value; nav.has_variances = true; break;
                case 99:  nav.alg_var_y = value; break;
                case 100: nav.alg_var_z = value; break;
                case 101: nav.alg_var_vx = value; break;
                case 102: nav.alg_var_vy = value; break;
                case 103: nav.alg_var_vz = value; break;
                case 104: nav.alg_var_psi = value; break;
                case 105: nav.alg_var_theta = value; break;
                case 106: nav.alg_var_phi = value; break;
                
                default:
                    RCLCPP_DEBUG(this->get_logger(), "Unknown parameter ID: %d", id);
                    break;
            }
        }
        
        // Публикация PoseStamped (NED → ENU для ROS)
        if (nav.has_position && nav.has_orientation) {
            geometry_msgs::msg::PoseStamped pose;
            pose.header.stamp = this->now();
            pose.header.frame_id = "map";
            
            // NED → ENU: X_ros = Y_ned (East), Y_ros = X_ned (North), Z_ros = -Z_ned (Up)
            pose.pose.position.x = nav.y;   // East
            pose.pose.position.y = nav.x;   // North
            pose.pose.position.z = -nav.z;  // Up
            
            // Преобразование Euler NED → кватернион ENU
            // yaw_ned: от North к East (по часовой)
            // В ROS (ENU): yaw_ros = yaw_ned - π/2, roll_ros = -roll_ned
            double yaw_ros = nav.yaw - M_PI / 2.0;
            double pitch_ros = nav.pitch;
            double roll_ros = -nav.roll;
            
            double cy = std::cos(yaw_ros * 0.5);
            double sy = std::sin(yaw_ros * 0.5);
            double cp = std::cos(pitch_ros * 0.5);
            double sp = std::sin(pitch_ros * 0.5);
            double cr = std::cos(roll_ros * 0.5);
            double sr = std::sin(roll_ros * 0.5);
            
            pose.pose.orientation.w = cr * cp * cy + sr * sp * sy;
            pose.pose.orientation.x = sr * cp * cy - cr * sp * sy;
            pose.pose.orientation.y = cr * sp * cy + sr * cp * sy;
            pose.pose.orientation.z = cr * cp * sy - sr * sp * cy;
            
            pose_pub_->publish(pose);
        }
        
        // Публикация Imu
        if (nav.has_acceleration) {
            sensor_msgs::msg::Imu imu;
            imu.header.stamp = this->now();
            imu.header.frame_id = "base_link";
            
            // NED → ENU для ускорений
            imu.linear_acceleration.x = nav.lay;   // East
            imu.linear_acceleration.y = nav.lax;   // North
            imu.linear_acceleration.z = -nav.laz;  // Up
            
            // Заполняем covariance нулями (ГКВ2 не выдает covariance напрямую)
            // Но можем использовать дисперсии из alg_var_* если доступны
            if (nav.has_variances) {
                imu.linear_acceleration_covariance[0] = nav.alg_var_vx;
                imu.linear_acceleration_covariance[4] = nav.alg_var_vy;
                imu.linear_acceleration_covariance[8] = nav.alg_var_vz;
            }
            
            imu_pub_->publish(imu);
        }
        
        // Публикация статуса
        if (nav.has_gnss_status || nav.has_alg_status) {
            gkv2_motor_bridge::msg::GKV2Status status;
            
            // gps_state_status (ID 72, ZED-F9P)
            status.gps_state_status = nav.gps_state_status;
            status.gnss_date_valid = (nav.gps_state_status & 0x00000001) != 0;          // Бит 0
            status.gnss_time_valid = (nav.gps_state_status & 0x00000002) != 0;          // Бит 1
            status.gnss_ambiguity_resolved = (nav.gps_state_status & 0x00000004) != 0;  // Бит 2
            status.gnss_coords_valid = (nav.gps_state_status & 0x00010000) != 0;        // Бит 16
            status.gnss_diff_corrections = (nav.gps_state_status & 0x00020000) != 0;    // Бит 17
            status.gnss_fix_type = (nav.gps_state_status >> 8) & 0xFF;                  // Биты 8-15
            status.rtk_status = (nav.gps_state_status >> 22) & 0x03;                    // Биты 22-23
            
            // gps_rel_status (ID 29, ZED-F9P ровер)
            status.gps_rel_status = nav.gps_rel_status;
            status.rel_nav_valid = (nav.gps_rel_status & 0x00000001) != 0;              // Бит 0
            status.rel_diff_applied = (nav.gps_rel_status & 0x00000002) != 0;           // Бит 1
            status.rel_coords_valid = (nav.gps_rel_status & 0x00000004) != 0;           // Бит 2
            status.rel_ambiguity_status = (nav.gps_rel_status >> 3) & 0x03;             // Биты 3-4
            status.rel_heading_mode = (nav.gps_rel_status & 0x00000020) != 0;           // Бит 5
            status.rel_heading_valid = (nav.gps_rel_status & 0x00000100) != 0;          // Бит 8
            
            // alg_state_status (ID 96)
            status.alg_state_status = nav.alg_state_status;
            status.alg_stage = nav.alg_state_status & 0xFF;                             // Биты 7-0
            status.alg_correction = (nav.alg_state_status >> 8) & 0xFF;                 // Биты 15-8
            status.alg_fails = (nav.alg_state_status >> 16) & 0xFFFF;                   // Биты 31-16
            status.alg_navigation_ready = (status.alg_stage == 50) && (status.alg_fails == 0);
            
            // Спутники
            status.gps_num_satellites = nav.gps_num_satellites;
            
            // СКО координат
            status.gnss_sig_lat = nav.gnss_sig_lat;
            status.gnss_sig_lon = nav.gnss_sig_lon;
            status.gnss_sig_alt = nav.gnss_sig_alt;
            
            // Дисперсии
            status.alg_var_x = nav.alg_var_x;
            status.alg_var_y = nav.alg_var_y;
            status.alg_var_z = nav.alg_var_z;
            status.alg_var_vx = nav.alg_var_vx;
            status.alg_var_vy = nav.alg_var_vy;
            status.alg_var_vz = nav.alg_var_vz;
            status.alg_var_psi = nav.alg_var_psi;
            status.alg_var_theta = nav.alg_var_theta;
            status.alg_var_phi = nav.alg_var_phi;
            
            // Двухантенное решение
            status.gps_rel_heading = nav.gps_rel_heading;
            status.gps_rel_length = nav.gps_rel_length;
            status.heading_from_dual_antenna = status.rel_heading_valid && status.rel_heading_mode;
            
            status_pub_->publish(status);
        }
        
        // Отладочный лог каждые 100 пакетов
        if (packets_received_ % 100 == 0) {
            bool rtk_fixed = (nav.gps_state_status & 0x00C00000) == 0x00800000;
            bool coords_valid = (nav.gps_state_status & 0x00010000) != 0;
            uint8_t stage = nav.alg_state_status & 0xFF;
            uint16_t fails = (nav.alg_state_status >> 16) & 0xFFFF;
            
            RCLCPP_INFO(this->get_logger(), 
                "Packets: %lu | CRC errors: %lu | Pos(%.2f,%.2f,%.2f) | Yaw:%.2f | Sats:%d | "
                "RTK:%s | CoordsValid:%s | Stage:%d | Fails:0x%04X | DualAnt:%s",
                packets_received_, crc_errors_,
                nav.x, nav.y, nav.z, nav.yaw, nav.gps_num_satellites,
                rtk_fixed ? "FIXED" : (rtk_status_str(nav.gps_state_status)),
                coords_valid ? "Y" : "N",
                stage, fails,
                status.rel_heading_valid && status.rel_heading_mode ? "Y" : "N");
        }
    }
    
    const char* rtk_status_str(uint32_t gps_state_status) {
        uint8_t rtk = (gps_state_status >> 22) & 0x03;
        switch (rtk) {
            case 0: return "NONE";
            case 1: return "FLOAT";
            case 2: return "FIXED";
            default: return "RSV";
        }
    }
    
    // ========================================================================
    // ПАРАМЕТРЫ И СОСТОЯНИЕ
    // ========================================================================
    std::vector<uint8_t> packet_ids_;  // Порядок ID параметров в наборном пакете
    
    boost::asio::io_context io_context_;
    boost::asio::serial_port serial_port_;
    std::array<uint8_t, 512> read_buffer_;
    std::vector<uint8_t> buffer_;
    std::unique_ptr<std::thread> io_thread_;
    
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_pub_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
    rclcpp::Publisher<gkv2_motor_bridge::msg::GKV2Status>::SharedPtr status_pub_;
    
    // Статистика
    uint64_t packets_received_;
    uint64_t crc_errors_;
    uint64_t short_packets_;
    
    // Для логов
    gkv2_motor_bridge::msg::GKV2Status status;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GKV2NavParser>());
    rclcpp::shutdown();
    return 0;
}