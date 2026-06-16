#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include "gkv2_motor_bridge/msg/gkv2_status.hpp"
#include "gkv2_motor_bridge/msg/navigation_status.hpp"
#include <cmath>
#include <string>

class NavigationFusionNode : public rclcpp::Node {
public:
    NavigationFusionNode() : Node("navigation_fusion") {
        // Параметры
        this->declare_parameter<double>("gnss_timeout_sec", 2.0);
        this->declare_parameter<double>("gnss_quality_threshold", 0.7);
        this->declare_parameter<int>("min_satellites", 8);
        this->declare_parameter<bool>("require_rtk", true);
        
        gnss_timeout_ = this->get_parameter("gnss_timeout_sec").as_double();
        gnss_quality_threshold_ = this->get_parameter("gnss_quality_threshold").as_double();
        min_satellites_ = this->get_parameter("min_satellites").as_int();
        require_rtk_ = this->get_parameter("require_rtk").as_bool();
        
        // Publishers
        fused_pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/nav/fused_pose", 10);
        fused_odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("/nav/fused_odom", 10);
        status_pub_ = this->create_publisher<gkv2_motor_bridge::msg::NavigationStatus>("/nav/status", 10);
        
        // Subscribers
        auto qos = rclcpp::QoS{rclcpp::KeepLast(10)};
        qos.reliability(rclcpp::ReliabilityPolicy::BestEffort);

        gnss_pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "/nav/pose", qos, std::bind(&NavigationFusionNode::gnss_pose_callback, this, std::placeholders::_1));

        gnss_status_sub_ = this->create_subscription<gkv2_motor_bridge::msg::GKV2Status>(
            "/gkv2/status", qos, std::bind(&NavigationFusionNode::gnss_status_callback, this, std::placeholders::_1));

        odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/odom/raw", qos, std::bind(&NavigationFusionNode::odometry_callback, this, std::placeholders::_1));
        
        // Таймер слияния (50 Гц)
        fusion_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(20), std::bind(&NavigationFusionNode::fusion_loop, this));
        
        
        tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);    
        
        // Инициализация состояния
        current_mode_ = MODE_GNSS;
        gnss_available_ = false;
        last_gnss_time_ = this->now();
        last_gnss_pose_ = geometry_msgs::msg::PoseStamped();
        last_odom_ = nav_msgs::msg::Odometry();
        odom_offset_x_ = 0.0;
        odom_offset_y_ = 0.0;
        odom_offset_yaw_ = 0.0;
        odometry_drift_ = 0.0;
        
        RCLCPP_INFO(this->get_logger(), "Navigation fusion node initialized");
        RCLCPP_INFO(this->get_logger(), "GNSS timeout: %.1f sec, Min satellites: %d", 
                    gnss_timeout_, min_satellites_);
    }

private:
    void gnss_pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
        last_gnss_pose_ = *msg;
        last_gnss_time_ = this->now();
        gnss_pose_received_ = true;
    }
    
    void gnss_status_callback(const gkv2_motor_bridge::msg::GKV2Status::SharedPtr msg) {
        gnss_status_ = *msg;
        
        // Оценка качества ГНСС
        gnss_quality_ = calculate_gnss_quality(msg);
    }
    
    void odometry_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
        last_odom_ = *msg;
        odom_received_ = true;
    }
    
    double calculate_gnss_quality(const gkv2_motor_bridge::msg::GKV2Status::SharedPtr status) {
        double quality = 0.0;
    
        // RTK Fixed (rtk_status == 2 согласно п. 7.7.8.3 протокола)
        if (status->rtk_status == 2) {
            quality += 0.5;
        }
        
        // Количество спутников (максимум 20)
        quality += 0.3 * std::min(status->gps_num_satellites / 20.0, 1.0);
        
        // Состояние алгоритма: alg_navigation_ready = (alg_stage == 50 && alg_fails == 0)
        if (status->alg_navigation_ready) {
            quality += 0.2;
        }
        
        return quality;
}
    
    void fusion_loop() {

        gkv2_motor_bridge::msg::NavigationStatus status;
       
        // Проверка доступности ГНСС
        double time_since_gnss = (this->now() - last_gnss_time_).seconds();
        bool gnss_good = gnss_pose_received_ && 
                 gnss_quality_ >= gnss_quality_threshold_ &&
                 gnss_status_.gps_num_satellites >= min_satellites_ &&
                 (!require_rtk_ || gnss_status_.rtk_status == 2) &&
                 time_since_gnss < gnss_timeout_;
        
        // Переключение режимов
        if (gnss_good && current_mode_ != MODE_GNSS) {
            // Переключение на ГНСС
            RCLCPP_INFO(this->get_logger(), "Switching to GNSS mode (quality: %.2f, sats: %d)", 
                        gnss_quality_, gnss_status_.gps_num_satellites);
            current_mode_ = MODE_GNSS;
            gnss_available_ = true;
            
            // Сброс смещения одометрии
            if (odom_received_) {
                odom_offset_x_ = last_gnss_pose_.pose.position.x - last_odom_.pose.pose.position.x;
                odom_offset_y_ = last_gnss_pose_.pose.position.y - last_odom_.pose.pose.position.y;
                odometry_drift_ = 0.0;
            }
        } else if (!gnss_good && current_mode_ == MODE_GNSS) {
            // Переключение на одометрию
            RCLCPP_WARN(this->get_logger(), "GNSS lost! Switching to odometry mode (time: %.1f sec)", 
                        time_since_gnss);
            current_mode_ = MODE_ODOMETRY;
            gnss_available_ = false;
            
            // Сохранение смещения для плавного перехода
            if (odom_received_) {
                odom_offset_x_ = last_gnss_pose_.pose.position.x - last_odom_.pose.pose.position.x;
                odom_offset_y_ = last_gnss_pose_.pose.position.y - last_odom_.pose.pose.position.y;
            }
        }
        
        // Формирование fused позиции
        geometry_msgs::msg::PoseStamped fused_pose;
        fused_pose.header.stamp = this->now();
        fused_pose.header.frame_id = "map";
        
        if (current_mode_ == MODE_GNSS) {
            // Используем ГНСС напрямую
            fused_pose = last_gnss_pose_;
            fused_pose.header.stamp = this->now();
        } else if (current_mode_ == MODE_ODOMETRY && odom_received_) {
            // Используем одометрию со смещением
            fused_pose.pose.position.x = last_odom_.pose.pose.position.x + odom_offset_x_;
            fused_pose.pose.position.y = last_odom_.pose.pose.position.y + odom_offset_y_;
            fused_pose.pose.position.z = 0.0;
            fused_pose.pose.orientation = last_odom_.pose.pose.orientation;
            
            // Накопление ошибки одометрии (упрощенно)
            odometry_drift_ += 0.01;  // 1 см/сек дрейф
        }
        
        // Публикация fused позиции
        fused_pose_pub_->publish(fused_pose);
        
        // Публикация fused одометрии
        nav_msgs::msg::Odometry fused_odom;
        fused_odom.header.stamp = this->now();
        fused_odom.header.frame_id = "map";
        fused_odom.child_frame_id = "base_link";
        fused_odom.pose.pose = fused_pose.pose;

        // Публикация tf2 transform (map -> base_link)
        geometry_msgs::msg::TransformStamped transform_stamped;
        transform_stamped.header.stamp = this->now();
        transform_stamped.header.frame_id = "map";
        transform_stamped.child_frame_id = "base_link";
        
        transform_stamped.transform.translation.x = fused_pose.pose.position.x;
        transform_stamped.transform.translation.y = fused_pose.pose.position.y;
        transform_stamped.transform.translation.z = fused_pose.pose.position.z;
        transform_stamped.transform.rotation = fused_pose.pose.orientation;
        
        tf_broadcaster_->sendTransform(transform_stamped);
        
        if (odom_received_) {
            fused_odom.twist.twist = last_odom_.twist.twist;
        }
        
        fused_odom_pub_->publish(fused_odom);
        
        // Публикация статуса
        status.current_mode = current_mode_;
        status.gnss_available = gnss_available_;
        status.rtk_fixed = gnss_good ? (gnss_status_.rtk_status == 2) : false;
        status.gnss_satellites = gnss_good ? gnss_status_.gps_num_satellites : 0;
        status.gnss_quality = gnss_good ? gnss_quality_ : 0.0f;
        status.odometry_drift = odometry_drift_;
        status.time_since_gnss = time_since_gnss;

        switch (current_mode_) {
            case MODE_GNSS:
                status.status_message = "GNSS (RTK Fixed)";
                break;
            case MODE_ODOMETRY:
                status.status_message = "Odometry (GNSS lost)";
                break;
            default:
                status.status_message = "Unknown";
        }

        status_pub_->publish(status);

        // Логирование каждые 5 секунд
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
            "Mode: %s | GNSS: %.1f%% | Sats: %d | Drift: %.2f m | Time: %.1f sec",
            status.status_message.c_str(), status.gnss_quality * 100, 
            status.gnss_satellites, odometry_drift_, time_since_gnss);
    }
    
    // Константы режимов
    static constexpr uint8_t MODE_GNSS = 0;
    static constexpr uint8_t MODE_ODOMETRY = 1;
    static constexpr uint8_t MODE_FUSION = 2;
    
    // Параметры
    double gnss_timeout_;
    double gnss_quality_threshold_;
    int min_satellites_;
    bool require_rtk_;
    
    // Состояние
    uint8_t current_mode_;
    bool gnss_available_;
    bool gnss_pose_received_ = false;
    bool odom_received_ = false;
    rclcpp::Time last_gnss_time_;
    geometry_msgs::msg::PoseStamped last_gnss_pose_;
    nav_msgs::msg::Odometry last_odom_;
    gkv2_motor_bridge::msg::GKV2Status gnss_status_;
    double gnss_quality_ = 0.0;
    
    // Смещение одометрии
    double odom_offset_x_;
    double odom_offset_y_;
    double odom_offset_yaw_;
    double odometry_drift_;
    
    // ROS 2 интерфейсы
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr fused_pose_pub_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr fused_odom_pub_;
    rclcpp::Publisher<gkv2_motor_bridge::msg::NavigationStatus>::SharedPtr status_pub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr gnss_pose_sub_;
    rclcpp::Subscription<gkv2_motor_bridge::msg::GKV2Status>::SharedPtr gnss_status_sub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::TimerBase::SharedPtr fusion_timer_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NavigationFusionNode>());
    rclcpp::shutdown();
    return 0;
}