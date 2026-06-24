// ~/robocross_all/robokross_ws/src/robokross_navigation/src/nav_logger_node.cpp
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/float32.hpp>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>

class NavLoggerNode : public rclcpp::Node {
public:
    NavLoggerNode() : Node("nav_logger") {
        // Параметры
        this->declare_parameter<std::string>("log_directory", "/tmp/nav_logs");
        this->declare_parameter<bool>("log_to_file", true);
        this->declare_parameter<bool>("log_to_console", true);
        
        log_directory_ = this->get_parameter("log_directory").as_string();
        log_to_file_ = this->get_parameter("log_to_file").as_bool();
        log_to_console_ = this->get_parameter("log_to_console").as_bool();
        
        // Создание директории для логов
        std::string mkdir_cmd = "mkdir -p " + log_directory_;
        system(mkdir_cmd.c_str());
        
        // Инициализация лог-файла
        if (log_to_file_) {
            auto now = std::time(nullptr);
            auto tm = *std::localtime(&now);
            std::ostringstream oss;
            oss << log_directory_ << "/nav_log_" 
                << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S") << ".csv";
            log_file_.open(oss.str(), std::ios::out);
            
            if (log_file_.is_open()) {
                // Заголовок CSV
                log_file_ << "timestamp,ros_time,latitude,longitude,altitude,"
                         << "heading,pitch,roll,speed,rtk_status,gps_sats,"
                         << "gnss_module_ok\n";
                RCLCPP_INFO(this->get_logger(), "Log file opened: %s", oss.str().c_str());
            } else {
                RCLCPP_ERROR(this->get_logger(), "Failed to open log file!");
                log_to_file_ = false;
            }
        }
        
        // Подписки на топики навигации
        gnss_sub_ = this->create_subscription<sensor_msgs::msg::NavSatFix>(
            "/nav/gnss_raw", 10,
            std::bind(&NavLoggerNode::gnss_callback, this, std::placeholders::_1));
        
        pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "/nav/pose_local", 10,
            std::bind(&NavLoggerNode::pose_callback, this, std::placeholders::_1));
        
        velocity_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/nav/velocity", 10,
            std::bind(&NavLoggerNode::velocity_callback, this, std::placeholders::_1));
        
        // Таймер для периодического вывода статистики
        stats_timer_ = this->create_wall_timer(
            std::chrono::seconds(5),
            std::bind(&NavLoggerNode::print_stats, this));
        
        // Счётчики
        gnss_msg_count_ = 0;
        pose_msg_count_ = 0;
        velocity_msg_count_ = 0;
        last_rtk_status_ = -1;
        
        RCLCPP_INFO(this->get_logger(), "Nav Logger initialized. Waiting for data...");
    }
    
    ~NavLoggerNode() {
        if (log_file_.is_open()) {
            log_file_.close();
        }
    }

private:
    void gnss_callback(const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
        gnss_msg_count_++;
        
        // Извлечение RTK статуса из status.status
        int rtk_status = msg->status.status;
        
        if (log_to_console_ && gnss_msg_count_ % 10 == 1) {
            RCLCPP_INFO(this->get_logger(), 
                "[GNSS] Lat: %.6f, Lon: %.6f, Alt: %.2f m, "
                "RTK: %d, Sats: %d",
                msg->latitude, msg->longitude, msg->altitude,
                rtk_status, 0); // Количество спутников будет из другого топика
        }
        
        if (log_to_file_) {
            // Здесь мы логируем базовые данные, полные данные будут из других callback'ов
            // Это упрощённая версия
        }
        
        last_gnss_ = msg;
    }
    
    void pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
        pose_msg_count_++;
        
        if (log_to_console_ && pose_msg_count_ % 10 == 1) {
            RCLCPP_INFO(this->get_logger(),
                "[POSE] X: %.3f, Y: %.3f, Z: %.3f",
                msg->pose.position.x, msg->pose.position.y, msg->pose.position.z);
        }
        
        if (log_to_file_ && last_gnss_) {
            auto now = std::time(nullptr);
            auto tm = *std::localtime(&now);
            
            log_file_ << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << ","
                     << msg->header.stamp.sec << "." << msg->header.stamp.nanosec << ","
                     << last_gnss_->latitude << ","
                     << last_gnss_->longitude << ","
                     << last_gnss_->altitude << ","
                     << "0,0,0,0,"  // heading, pitch, roll, speed (будут из других топиков)
                     << last_gnss_->status.status << ","
                     << "0,"  // gps_sats
                     << (last_gnss_->status.status >= 0 ? "OK" : "FAIL")
                     << "\n";
            log_file_.flush();
        }
    }
    
    void velocity_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        velocity_msg_count_++;
        
        if (log_to_console_ && velocity_msg_count_ % 10 == 1) {
            RCLCPP_INFO(this->get_logger(),
                "[VELOCITY] Linear: %.3f m/s, Angular: %.3f rad/s",
                msg->linear.x, msg->angular.z);
        }
    }
    
    void print_stats() {
        RCLCPP_INFO(this->get_logger(),
            "\n========== NAVIGATION STATS ==========\n"
            "GNSS messages: %d\n"
            "Pose messages: %d\n"
            "Velocity messages: %d\n"
            "========================================\n",
            gnss_msg_count_, pose_msg_count_, velocity_msg_count_);
    }
    
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr gnss_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_sub_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr velocity_sub_;
    rclcpp::TimerBase::SharedPtr stats_timer_;
    
    std::ofstream log_file_;
    std::string log_directory_;
    bool log_to_file_;
    bool log_to_console_;
    
    sensor_msgs::msg::NavSatFix::SharedPtr last_gnss_;
    int gnss_msg_count_;
    int pose_msg_count_;
    int velocity_msg_count_;
    int last_rtk_status_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NavLoggerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}