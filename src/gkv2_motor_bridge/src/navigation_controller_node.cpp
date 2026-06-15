#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <cmath>
#include <vector>
#include <string>

struct Waypoint {
    double x;
    double y;
    double yaw;
};

class NavigationController : public rclcpp::Node {
public:
    NavigationController() : Node("navigation_controller") {
        // Объявление параметров
        this->declare_parameter<double>("target_velocity", 1.5);
        this->declare_parameter<double>("lookahead_distance", 2.0);
        this->declare_parameter<double>("waypoint_threshold", 0.5);
        this->declare_parameter<std::vector<double>>("waypoints_x", std::vector<double>{0.0, 10.0});
        this->declare_parameter<std::vector<double>>("waypoints_y", std::vector<double>{0.0, 0.0});
        this->declare_parameter<std::vector<double>>("waypoints_yaw", std::vector<double>{0.0, 0.0});

        target_velocity_ = this->get_parameter("target_velocity").as_double();
        lookahead_distance_ = this->get_parameter("lookahead_distance").as_double();
        waypoint_threshold_ = this->get_parameter("waypoint_threshold").as_double();

        // Загрузка waypoints (в реальном проекте лучше парсить YAML через yaml-cpp, 
        // здесь используем плоские списки для простоты)
        auto x_vals = this->get_parameter("waypoints_x").as_double_array();
        auto y_vals = this->get_parameter("waypoints_y").as_double_array();
        auto yaw_vals = this->get_parameter("waypoints_yaw").as_double_array();

        for (size_t i = 0; i < x_vals.size(); ++i) {
            waypoints_.push_back({x_vals[i], y_vals[i], yaw_vals[i]});
        }

        RCLCPP_INFO(this->get_logger(), "Loaded %zu waypoints.", waypoints_.size());

        // Publishers и Subscribers
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "/nav/pose", 10, std::bind(&NavigationController::pose_callback, this, std::placeholders::_1));

        // Таймер публикации команд (50 Гц для совместимости с watchdog cmd_vel_bridge)
        control_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(20), std::bind(&NavigationController::control_loop, this));

        current_waypoint_idx_ = 0;
        mission_completed_ = false;
    }

private:
    void pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
        current_x_ = msg->pose.position.x;
        current_y_ = msg->pose.position.y;
        
        // Извлечение yaw из кватерниона
        double siny_cosp = 2.0 * (msg->pose.orientation.w * msg->pose.orientation.z + 
                                  msg->pose.orientation.x * msg->pose.orientation.y);
        double cosy_cosp = 1.0 - 2.0 * (msg->pose.orientation.y * msg->pose.orientation.y + 
                                        msg->pose.orientation.z * msg->pose.orientation.z);
        current_yaw_ = std::atan2(siny_cosp, cosy_cosp);
        
        pose_received_ = true;
    }

    void control_loop() {
        if (!pose_received_ || mission_completed_ || waypoints_.empty()) {
            publish_stop();
            return;
        }

        // Если достигли последней точки
        if (current_waypoint_idx_ >= waypoints_.size()) {
            RCLCPP_INFO(this->get_logger(), "Mission completed.");
            mission_completed_ = true;
            publish_stop();
            return;
        }

        const auto& target = waypoints_[current_waypoint_idx_];
        double dx = target.x - current_x_;
        double dy = target.y - current_y_;
        double distance = std::hypot(dx, dy);

        // Переход к следующей точке
        if (distance < waypoint_threshold_) {
            current_waypoint_idx_++;
            if (current_waypoint_idx_ >= waypoints_.size()) {
                mission_completed_ = true;
                publish_stop();
                return;
            }
        }

        // Pure Pursuit расчет
    

        // Угол до целевой точки
        double alpha = std::atan2(target.y - current_y_, target.x - current_x_) - current_yaw_;
        
        // Нормализация угла [-pi, pi]
        alpha = std::atan2(std::sin(alpha), std::cos(alpha));

        // Кривизна и угловая скорость
        double curvature = (2.0 * std::sin(alpha)) / lookahead_distance_;
        double angular_z = curvature * target_velocity_;

        // Ограничение угловой скорости (для безопасности)
        angular_z = std::clamp(angular_z, -1.5, 1.5);

        // Формирование команды
        geometry_msgs::msg::Twist cmd;
        cmd.linear.x = target_velocity_;
        cmd.angular.z = angular_z;

        cmd_vel_pub_->publish(cmd);
        
        RCLCPP_DEBUG(this->get_logger(), "WP: %zu, Dist: %.2f, Alpha: %.2f, V: %.2f, W: %.2f",
                     current_waypoint_idx_, distance, alpha, cmd.linear.x, cmd.angular.z);
    }

    void publish_stop() {
        geometry_msgs::msg::Twist cmd;
        cmd.linear.x = 0.0;
        cmd.angular.z = 0.0;
        cmd_vel_pub_->publish(cmd);
    }

    // Параметры
    double target_velocity_;
    double lookahead_distance_;
    double waypoint_threshold_;
    std::vector<Waypoint> waypoints_;
    size_t current_waypoint_idx_;
    bool mission_completed_;

    // Состояние
    double current_x_ = 0.0;
    double current_y_ = 0.0;
    double current_yaw_ = 0.0;
    bool pose_received_ = false;

    // ROS 2 интерфейсы
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_sub_;
    rclcpp::TimerBase::SharedPtr control_timer_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NavigationController>());
    rclcpp::shutdown();
    return 0;
}