#include <rclcpp/rclcpp.hpp>
#include "gkv2_motor_bridge/msg/gkv2_config_status.hpp"
#include <boost/asio.hpp>
#include <vector>
#include <cstdint>
#include <cstring>
#include <chrono>
#include <thread>

// CRC32 таблица (из протокола ЛМАП.402131.009Д1)
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

struct GKV2DeviceInfo {
    uint16_t bootloader_version;
    uint16_t firmware_version;
    uint32_t production_date;
    char serial_number[17];
    char device_name[17];
    uint8_t device_mode;
    uint16_t data_status;
};

class GKV2ConfigNode : public rclcpp::Node {
public:
    GKV2ConfigNode() : Node("gkv2_config"), io_context_(), serial_port_(io_context_) {
        this->declare_parameter<std::string>("uart_port", "/dev/ttyV1");
        this->declare_parameter<int>("baudrate", 921600);
        this->declare_parameter<int>("device_address", 1);
        this->declare_parameter<int>("timeout_sec", 5);
        this->declare_parameter<std::vector<int64_t>>("expected_packet_ids", 
            std::vector<int64_t>{43, 44, 45, 36, 37, 38, 46, 47, 48, 64, 65, 66, 72, 79, 29, 13, 14, 85, 86, 87, 96, 98, 99, 100, 101, 102, 103, 104, 105, 106});
        
        std::string port_name = this->get_parameter("uart_port").as_string();
        int baudrate = this->get_parameter("baudrate").as_int();
        device_address_ = this->get_parameter("device_address").as_int();
        
        auto ids_param = this->get_parameter("expected_packet_ids").as_integer_array();
        for (auto id : ids_param) {
            if (id >= 0 && id <= 255) expected_packet_ids_.push_back(static_cast<uint8_t>(id));
        }
        
        config_status_pub_ = this->create_publisher<gkv2_motor_bridge::msg::GKV2ConfigStatus>("/gkv2/config_status", 10);
        
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
            finished_ = true; // Завершаем узел при ошибке инициализации
            return;
        }
        
        // Запуск проверки через таймер
        startup_timer_ = this->create_wall_timer(std::chrono::milliseconds(200), [this]() {
            startup_timer_->cancel();
            run_configuration();
        });
    }

    ~GKV2ConfigNode() {
        if (serial_port_.is_open()) serial_port_.close();
    }

    bool is_finished() const { return finished_; }

private:
    void run_configuration() {
        RCLCPP_INFO(this->get_logger(), "Starting GKV2 configuration check...");
        gkv2_motor_bridge::msg::GKV2ConfigStatus status;
        status.connection_ok = false;
        status.packet_structure_match = false;

        if (!check_connection()) {
            status.status_message = "Connection failed: no response from GKV2";
            RCLCPP_ERROR(this->get_logger(), "%s", status.status_message.c_str());
        } else {
            status.connection_ok = true;
            RCLCPP_INFO(this->get_logger(), "Connection established");
            
            GKV2DeviceInfo device_info;
            if (read_device_info(device_info)) {
                status.device_name = std::string(device_info.device_name);
                status.serial_number = std::string(device_info.serial_number);
                status.firmware_version = device_info.firmware_version;
                status.data_ready = (device_info.data_status & 0x0800) != 0;
                RCLCPP_INFO(this->get_logger(), "Device: %s, SN: %s, FW: %u", 
                            status.device_name.c_str(), status.serial_number.c_str(), status.firmware_version);
            }

            uint8_t param_count = 0;
            std::vector<int32_t> param_ids;
            if (read_packet_configuration(param_count, param_ids)) {
                status.packet_param_count = param_count;
                status.packet_param_ids = param_ids;
                status.packet_structure_match = check_packet_structure(param_ids);
                if (status.packet_structure_match) {
                    status.status_message = "Configuration OK: " + std::to_string(param_count) + " parameters";
                    RCLCPP_INFO(this->get_logger(), "%s", status.status_message.c_str());
                } else {
                    status.status_message = "WARNING: Packet structure mismatch!";
                    RCLCPP_WARN(this->get_logger(), "%s", status.status_message.c_str());
                }
            }
        }

        config_status_pub_->publish(status);
        RCLCPP_INFO(this->get_logger(), "Configuration check completed. Exiting.");
        finished_ = true; // Естественное завершение работы
    }

    bool check_connection() {
        std::vector<uint8_t> request = {0xFF, static_cast<uint8_t>(device_address_), 0x00, 0x00};
        uint32_t crc = calculate_crc32(request.data(), request.size());
        request.insert(request.end(), reinterpret_cast<uint8_t*>(&crc), reinterpret_cast<uint8_t*>(&crc) + 4);
        return send_and_receive(request, 0x00, 100);
    }

    bool read_device_info(GKV2DeviceInfo& info) {
        std::vector<uint8_t> request = {0xFF, static_cast<uint8_t>(device_address_), 0x04, 0x00};
        uint32_t crc = calculate_crc32(request.data(), request.size());
        request.insert(request.end(), reinterpret_cast<uint8_t*>(&crc), reinterpret_cast<uint8_t*>(&crc) + 4);
        std::vector<uint8_t> response;
        if (!send_and_receive(request, 0x05, 100, &response)) return false;
        if (response.size() < 43) return false;
        
        size_t offset = 0;
        info.bootloader_version = *reinterpret_cast<uint16_t*>(&response[offset]); offset += 2;
        info.firmware_version = *reinterpret_cast<uint16_t*>(&response[offset]); offset += 2;
        info.production_date = *reinterpret_cast<uint32_t*>(&response[offset]); offset += 4;
        std::memcpy(info.serial_number, &response[offset], 16); offset += 16;
        info.serial_number[16] = '\0';
        std::memcpy(info.device_name, &response[offset], 16); offset += 16;
        info.device_name[16] = '\0';
        info.device_mode = response[offset++];
        info.data_status = *reinterpret_cast<uint16_t*>(&response[offset]);
        return true;
    }

    bool read_packet_configuration(uint8_t& param_count, std::vector<int32_t>& param_ids) {
        std::vector<uint8_t> request = {0xFF, static_cast<uint8_t>(device_address_), 0x26, 0x00};
        uint32_t crc = calculate_crc32(request.data(), request.size());
        request.insert(request.end(), reinterpret_cast<uint8_t*>(&crc), reinterpret_cast<uint8_t*>(&crc) + 4);
        std::vector<uint8_t> response;
        if (!send_and_receive(request, 0x27, 200, &response)) return false;
        if (response.size() < 64) return false;
        
        param_count = response[0];
        param_ids.resize(64);
        for (int i = 0; i < 64; i++) param_ids[i] = response[1 + i];
        param_ids.resize(param_count);
        return true;
    }

    bool check_packet_structure(const std::vector<int32_t>& actual_ids) {
        if (actual_ids.size() != expected_packet_ids_.size()) return false;
        for (size_t i = 0; i < expected_packet_ids_.size(); i++) {
            if (actual_ids[i] != expected_packet_ids_[i]) return false;
        }
        return true;
    }

    bool send_and_receive(const std::vector<uint8_t>& request, uint8_t expected_type, 
                         int timeout_ms, std::vector<uint8_t>* response = nullptr) {
        try { serial_port_.write_some(boost::asio::buffer(request)); } 
        catch (const boost::system::system_error& e) { return false; }
        
        std::vector<uint8_t> buffer(256);
        boost::asio::deadline_timer timer(io_context_);
        timer.expires_from_now(boost::posix_time::milliseconds(timeout_ms));
        
        bool read_completed = false;
        size_t bytes_read = 0;

        serial_port_.async_read_some(boost::asio::buffer(buffer),
            [&](const boost::system::error_code& error, size_t size) {
                if (!error) { bytes_read = size; read_completed = true; }
                timer.cancel();
            });

        timer.async_wait([&](const boost::system::error_code& error) {
            if (!error) serial_port_.cancel();
        });

        io_context_.reset();
        io_context_.run();

        if (!read_completed) {
            RCLCPP_ERROR(this->get_logger(), "Timeout waiting for response type 0x%02X", expected_type);
            return false;
        }
        
        for (size_t i = 0; i + 4 <= bytes_read; i++) {
            if (buffer[i] == 0xFF) {
                uint8_t address = buffer[i + 1];
                uint8_t type = buffer[i + 2];
                uint8_t length = buffer[i + 3];
                if (type != expected_type || address != device_address_) continue;
                size_t packet_size = 4 + length + 4;
                if (i + packet_size > bytes_read) continue;
                
                uint32_t recv_crc = *reinterpret_cast<uint32_t*>(&buffer[i + 4 + length]);
                uint32_t calc_crc = calculate_crc32(&buffer[i], 4 + length);
                if (recv_crc != calc_crc) continue;
                
                if (response && length > 0) response->assign(&buffer[i + 4], &buffer[i + 4 + length]);
                return true;
            }
        }
        return false;
    }

    boost::asio::io_context io_context_;
    boost::asio::serial_port serial_port_;
    int device_address_;
    std::vector<uint8_t> expected_packet_ids_;
    rclcpp::Publisher<gkv2_motor_bridge::msg::GKV2ConfigStatus>::SharedPtr config_status_pub_;
    rclcpp::TimerBase::SharedPtr startup_timer_;
    bool finished_ = false;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<GKV2ConfigNode>();
    rclcpp::Rate rate(10);
    while (rclcpp::ok() && !node->is_finished()) {
        rclcpp::spin_some(node);
        rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}