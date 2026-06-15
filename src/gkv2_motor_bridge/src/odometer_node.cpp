#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <cmath>

class OdometerNode : public rclcpp::Node {
public:
    OdometerNode() : Node("odometer") {
        // Параметры одометра
        this->declare_parameter<double>("wheel_base", 0.7);
        this->declare_parameter<double>("wheel_radius", 0.3);
        this->declare_parameter<double>("encoder_ticks_per_rev", 1024.0);
        this->declare_parameter<bool>("use_mock", true);  // Режим эмуляции
        
        wheel_base_ = this->get_parameter("wheel_base").as_double();
        wheel_radius_ = this->get_parameter("wheel_radius").as_double();
        use_mock_ = this->get_parameter("use_mock").as_bool();
        
        // Publishers
        odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("/odom/raw", 10);
        
        // Subscribers
        cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10, std::bind(&OdometerNode::cmd_vel_callback, this, std::placeholders::_1));
        
        // Таймер обновления одометрии (100 Гц)
        update_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(10), std::bind(&OdometerNode::update_odometry, this));
        
        // Начальное состояние
        current_x_ = 0.0;
        current_y_ = 0.0;
        current_yaw_ = 0.0;
        current_vx_ = 0.0;
        current_vy_ = 0.0;
        current_wz_ = 0.0;
        
        RCLCPP_INFO(this->get_logger(), "Odometer node initialized (mock mode: %s)", 
                    use_mock_ ? "ON" : "OFF");
    }

private:
    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        // Сохраняем последнюю команду для эмуляции
        last_cmd_vel_ = *msg;
    }
    
    void update_odometry() {
        nav_msgs::msg::Odometry odom;
        odom.header.stamp = this->now();
        odom.header.frame_id = "odom";
        odom.child_frame_id = "base_link";
        
        if (use_mock_) {
            // Эмуляция одометра на основе cmd_vel
            double dt = 0.01;  // 100 Гц
            
            // Интегрирование скорости
            current_x_ += last_cmd_vel_.linear.x * std::cos(current_yaw_) * dt;
            current_y_ += last_cmd_vel_.linear.x * std::sin(current_yaw_) * dt;
            current_yaw_ += last_cmd_vel_.angular.z * dt;
            
            // Добавляем небольшой шум для реалистичности
            double noise = 0.01;
            current_x_ += (rand() % 100 - 50) / 10000.0 * noise;
            current_y_ += (rand() % 100 - 50) / 10000.0 * noise;
            
            odom.pose.pose.position.x = current_x_;
            odom.pose.pose.position.y = current_y_;
            odom.pose.pose.position.z = 0.0;
            
            // Кватернион из yaw
            odom.pose.pose.orientation.z = std::sin(current_yaw_ / 2.0);
            odom.pose.pose.orientation.w = std::cos(current_yaw_ / 2.0);
            
            odom.twist.twist.linear.x = last_cmd_vel_.linear.x;
            odom.twist.twist.angular.z = last_cmd_vel_.angular.z;
        } else {
            // Здесь будет чтение реальных данных с энкодеров
            // TODO: Интеграция с драйвером энкодеров
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
                "Real odometer not implemented yet, using mock");
        }
        
        odom_pub_->publish(odom);
    }
    
    // Параметры
    double wheel_base_;
    double wheel_radius_;
    bool use_mock_;
    
    // Состояние
    double current_x_;
    double current_y_;
    double current_yaw_;
    double current_vx_;
    double current_vy_;
    double current_wz_;
    geometry_msgs::msg::Twist last_cmd_vel_;
    
    // ROS 2 интерфейсы
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
    rclcpp::TimerBase::SharedPtr update_timer_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OdometerNode>());
    rclcpp::shutdown();
    return 0;
}