#include <rclcpp/rclcpp.hpp>
#include <boost/asio.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <vector>
#include <algorithm>
#include <memory>
#include <thread>

// Таблица CRC16 из Protokol_BUD.docx
const uint16_t cx_datagram_crc16_table[256] = {
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

uint16_t calculate_crc16(const uint8_t* start, int length) {
    uint8_t v;
    int counter = 0;
    uint16_t crc = 0xFFFF;
    while (length--) {
        if ((counter != 8) && (counter != 9)) {
            v = *start++;
        } else {
            v = 0; start++;
        }
        crc = (crc << 8) ^ cx_datagram_crc16_table[(crc >> 8) ^ v];
        counter++;
    }
    return crc;
}

class GKV2Driver : public rclcpp::Node {
public:
    GKV2Driver() : Node("gkv2_driver"), 
                   io_context_(),
                   serial_port_(io_context_) 
    {
        RCLCPP_INFO(this->get_logger(), "GKV2 Driver Node initialized with Boost.Asio.");
        
        // Чтение параметров из YAML
        this->declare_parameter<std::string>("uart_port", "/dev/ttyV0");
        this->declare_parameter<int>("baudrate", 921600);
        this->declare_parameter<int>("publish_rate_hz", 50);
        this->declare_parameter<int>("qos_depth", 10);
        
        std::string port_name = this->get_parameter("uart_port").as_string();
        int baudrate = this->get_parameter("baudrate").as_int();
        int qos_depth = this->get_parameter("qos_depth").as_int();
        
        rclcpp::QoS qos{rclcpp::KeepLast(qos_depth)};
        qos.reliability(rclcpp::ReliabilityPolicy::Reliable);
        cmd_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/parsed_cmd_bud", qos);

        // Инициализация UART
        try {
            serial_port_.open(port_name);
            serial_port_.set_option(boost::asio::serial_port_base::baud_rate(baudrate));
            serial_port_.set_option(boost::asio::serial_port_base::character_size(8));
            serial_port_.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
            serial_port_.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
            serial_port_.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));

            RCLCPP_INFO(this->get_logger(), "UART port %s opened at %d baud.", port_name.c_str(), baudrate);
            
            start_async_read();
            io_thread_ = std::make_unique<std::thread>([this]() {
                io_context_.run();
            });
        } catch (const boost::system::system_error& e) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open UART port: %s", e.what());
        }
    }

    ~GKV2Driver() {
        io_context_.stop();
        if (io_thread_ && io_thread_->joinable()) {
            io_thread_->join();
        }
        if (serial_port_.is_open()) {
            serial_port_.close();
        }
    }

private:
    void start_async_read() {
        serial_port_.async_read_some(
            boost::asio::buffer(read_buffer_, 64),
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

        while (buffer_.size() >= 8) {
            auto it = std::find(buffer_.begin(), buffer_.end(), 0xDE);
            
            if (it == buffer_.end()) {
                buffer_.clear();
                break;
            }

            buffer_.erase(buffer_.begin(), it);

            if (buffer_.size() < 8) {
                break;
            }

            if (buffer_[6] != 0x0D || buffer_[7] != 0x0A) {
                buffer_.erase(buffer_.begin());
                continue;
            }

            uint16_t calc_crc = calculate_crc16(buffer_.data(), 4);
            uint16_t recv_crc = (static_cast<uint16_t>(buffer_[4]) << 8) | buffer_[5];

            if (calc_crc == recv_crc) {
                uint8_t left_accel = buffer_[1];
                uint8_t right_accel = buffer_[2];
                uint8_t flags = buffer_[3];

                RCLCPP_INFO(this->get_logger(), 
                    "Valid CMD_BUD packet! Left: %d%%, Right: %d%%, Flags: 0x%02X", 
                    left_accel, right_accel, flags);

                geometry_msgs::msg::Twist twist;
                twist.linear.x = left_accel / 100.0;
                twist.linear.y = right_accel / 100.0;
                cmd_pub_->publish(twist);

                buffer_.erase(buffer_.begin(), buffer_.begin() + 8);
            } else {
                RCLCPP_WARN(this->get_logger(), "CRC mismatch! Calc: 0x%04X, Recv: 0x%04X", calc_crc, recv_crc);
                buffer_.erase(buffer_.begin());
            }
        }
    }

    boost::asio::io_context io_context_;
    boost::asio::serial_port serial_port_;
    std::array<uint8_t, 64> read_buffer_;
    std::vector<uint8_t> buffer_;
    std::unique_ptr<std::thread> io_thread_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_pub_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GKV2Driver>());
    rclcpp::shutdown();
    return 0;
}