// ~/robokross_ws/src/robokross_navigation/src/nav_parser_udp_node.cpp
#include <rclcpp/rclcpp.hpp>
#include <boost/asio.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/float32.hpp>
#include "robokross_navigation/EthDatagramm.h"
#include <cmath>

using boost::asio::ip::udp;

class NavParserUDPNode : public rclcpp::Node {
public:
    NavParserUDPNode() : Node("nav_parser_udp"), io_context_(), socket_(io_context_, udp::endpoint(udp::v4(), 5000)) {
        RCLCPP_INFO(this->get_logger(), "NavParserUDPNode initialized, listening on UDP port 5000");
        
        // Publishers
        gnss_pub_ = this->create_publisher<sensor_msgs::msg::NavSatFix>("/nav/gnss_raw", 10);
        pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/nav/pose_local", 10);
        velocity_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/nav/velocity", 10);
        heading_pub_ = this->create_publisher<std_msgs::msg::Float32>("/nav/heading", 10);
        
        // Reference point for ENU conversion (will be set on first valid fix)
        ref_lat_ = 0.0;
        ref_lon_ = 0.0;
        ref_alt_ = 0.0;
        ref_set_ = false;
        
        start_receive();
        
        // Run io_context in separate thread
        io_thread_ = std::thread([this]() {
            io_context_.run();
        });
    }

    ~NavParserUDPNode() {
        io_context_.stop();
        if (io_thread_.joinable()) {
            io_thread_.join();
        }
    }

private:
    void start_receive() {
        socket_.async_receive_from(
            boost::asio::buffer(receive_buffer_),
            remote_endpoint_,
            std::bind(&NavParserUDPNode::receive_callback, this,
                      std::placeholders::_1, std::placeholders::_2));
    }

    void receive_callback(const boost::system::error_code& error, size_t bytes_received) {
        if (!error && bytes_received >= sizeof(SystemData)) {
            SystemData sys_data;
            memcpy(&sys_data, receive_buffer_.data(), sizeof(SystemData));
            
            process_system_data(sys_data);
        }
        
        start_receive();
    }

    void process_system_data(const SystemData& data) {
        // Check if GNSS module is OK
        if (!data.status.gnssModuleStatus) {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
                "GNSS module status: NOT OK");
            return;
        }

        // 1. Publish NavSatFix (WGS-84)
        sensor_msgs::msg::NavSatFix fix;
        fix.header.stamp = this->now();
        fix.header.frame_id = "map";
        fix.latitude = data.gData.latitudeSelf;
        fix.longitude = data.gData.longitudeSelf;
        fix.altitude = data.gData.altitudeSelf;
        
        // RTK status mapping
        switch (data.gData.statusSolution) {
            case FIXED:
                fix.status.status = 0;  // RTK Fixed
                break;
            case FLOAT:
                fix.status.status = 1;  // RTK Float
                break;
            case SINGLE_POINT:
                fix.status.status = 2;  // GPS
                break;
            default:
                fix.status.status = -1; // No fix
                break;
        }
        
        gnss_pub_->publish(fix);

        // 2. Set reference point on first valid fix
        if (!ref_set_ && data.gData.statusSolution >= SINGLE_POINT) {
            ref_lat_ = data.gData.latitudeSelf;
            ref_lon_ = data.gData.longitudeSelf;
            ref_alt_ = data.gData.altitudeSelf;
            ref_set_ = true;
            RCLCPP_INFO(this->get_logger(), "Reference point set: lat=%.6f, lon=%.6f, alt=%.2f",
                       ref_lat_, ref_lon_, ref_alt_);
        }

        // 3. Convert WGS-84 to ENU and publish PoseStamped
        if (ref_set_) {
            double enu_x, enu_y, enu_z;
            wgs84_to_enu(data.gData.latitudeSelf, data.gData.longitudeSelf, 
                        data.gData.altitudeSelf, enu_x, enu_y, enu_z);
            
            geometry_msgs::msg::PoseStamped pose;
            pose.header.stamp = this->now();
            pose.header.frame_id = "map";
            pose.pose.position.x = enu_x;
            pose.pose.position.y = enu_y;
            pose.pose.position.z = enu_z;
            
            // Convert heading, pitch, roll to quaternion
            double yaw = data.gData.heading * M_PI / 180.0;
            double pitch = data.gData.pitch * M_PI / 180.0;
            double roll = data.gData.roll * M_PI / 180.0;
            
            pose.pose.orientation = euler_to_quaternion(roll, pitch, yaw);
            
            pose_pub_->publish(pose);
        }

        // 4. Publish velocity
        geometry_msgs::msg::Twist velocity;
        velocity.linear.x = data.gData.speed;  // Forward speed
        velocity.linear.y = 0.0;
        velocity.linear.z = data.gData.velocity[1];  // Vertical velocity
        
        // Angular velocity (if available from imuExchange)
        velocity.angular.x = 0.0;  // Roll rate
        velocity.angular.y = 0.0;  // Pitch rate
        velocity.angular.z = 0.0;  // Yaw rate (need to calculate from heading change)
        
        velocity_pub_->publish(velocity);

        // 5. Publish heading
        std_msgs::msg::Float32 heading_msg;
        heading_msg.data = data.gData.heading;
        heading_pub_->publish(heading_msg);

        // Debug logging every 5 seconds
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
            "GNSS: lat=%.6f lon=%.6f alt=%.2f | RTK=%d | Sats: GPS=%d BDS=%d GLO=%d GAL=%d | "
            "Speed=%.2f m/s | Heading=%.1f°",
            data.gData.latitudeSelf, data.gData.longitudeSelf, data.gData.altitudeSelf,
            data.gData.statusSolution,
            data.gData.GPS_SIU, data.gData.BDS_SIU, data.gData.GLO_SIU, data.gData.GAL_SIU,
            data.gData.speed, data.gData.heading);
    }

    void wgs84_to_enu(double lat, double lon, double alt, double& enu_x, double& enu_y, double& enu_z) {
        // Simple ENU conversion using reference point
        const double DEG_TO_RAD = M_PI / 180.0;
        const double EARTH_RADIUS = 6371000.0;  // meters
        
        double dlat = (lat - ref_lat_) * DEG_TO_RAD;
        double dlon = (lon - ref_lon_) * DEG_TO_RAD;
        
        double avg_lat = (ref_lat_ + lat) / 2.0 * DEG_TO_RAD;
        
        enu_x = dlon * EARTH_RADIUS * cos(avg_lat);  // East
        enu_y = dlat * EARTH_RADIUS;                  // North
        enu_z = alt - ref_alt_;                       // Up
    }

    geometry_msgs::msg::Quaternion euler_to_quaternion(double roll, double pitch, double yaw) {
        geometry_msgs::msg::Quaternion q;
        
        double cy = cos(yaw * 0.5);
        double sy = sin(yaw * 0.5);
        double cp = cos(pitch * 0.5);
        double sp = sin(pitch * 0.5);
        double cr = cos(roll * 0.5);
        double sr = sin(roll * 0.5);
        
        q.w = cr * cp * cy + sr * sp * sy;
        q.x = sr * cp * cy - cr * sp * sy;
        q.y = cr * sp * cy + sr * cp * sy;
        q.z = cr * cp * sy - sr * sp * cy;
        
        return q;
    }

    boost::asio::io_context io_context_;
    udp::socket socket_;
    udp::endpoint remote_endpoint_;
    std::array<uint8_t, 1024> receive_buffer_;
    std::thread io_thread_;
    
    rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr gnss_pub_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_pub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_pub_;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr heading_pub_;
    
    double ref_lat_, ref_lon_, ref_alt_;
    bool ref_set_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NavParserUDPNode>());
    rclcpp::shutdown();
    return 0;
}