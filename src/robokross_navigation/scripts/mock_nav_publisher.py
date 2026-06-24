#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import PoseStamped, Twist
from std_msgs.msg import Float32
import math

class MockNavPublisher(Node):
    def __init__(self):
        super().__init__('mock_nav_publisher')
        
        self.gnss_pub = self.create_publisher(NavSatFix, '/nav/gnss_raw', 10)
        self.pose_pub = self.create_publisher(PoseStamped, '/nav/pose_local', 10)
        self.vel_pub = self.create_publisher(Twist, '/nav/velocity', 10)
        
        self.timer = self.create_timer(0.02, self.timer_callback)  # 50 Hz
        self.time = 0.0
        
        # Начальная позиция (примерно Нижний Новгород)
        self.base_lat = 56.2965
        self.base_lon = 43.9361
        self.base_alt = 100.0
        
        self.get_logger().info("Mock navigation publisher started")
    
    def timer_callback(self):
        self.time += 0.02
        
        # Имитация движения по кругу
        radius = 10.0  # метров
        speed = 2.0    # м/с
        
        # GNSS данные
        gnss_msg = NavSatFix()
        gnss_msg.header.stamp = self.get_clock().now().to_msg()
        gnss_msg.header.frame_id = 'map'
        
        # Небольшое смещение от базовой позиции
        lat_offset = (radius * math.sin(self.time * speed / radius)) / 111320.0
        lon_offset = (radius * math.cos(self.time * speed / radius)) / (111320.0 * math.cos(math.radians(self.base_lat)))
        
        gnss_msg.latitude = self.base_lat + lat_offset
        gnss_msg.longitude = self.base_lon + lon_offset
        gnss_msg.altitude = self.base_alt
        
        # RTK Fixed статус
        gnss_msg.status.status = 0  # RTK Fixed
        gnss_msg.status.service = 1
        
        self.gnss_pub.publish(gnss_msg)
        
        # Pose данные (ENU)
        pose_msg = PoseStamped()
        pose_msg.header.stamp = self.get_clock().now().to_msg()
        pose_msg.header.frame_id = 'map'
        pose_msg.pose.position.x = radius * math.sin(self.time * speed / radius)
        pose_msg.pose.position.y = radius * (1.0 - math.cos(self.time * speed / radius))
        pose_msg.pose.position.z = 0.0
        pose_msg.pose.orientation.w = 1.0
        
        self.pose_pub.publish(pose_msg)
        
        # Velocity данные
        vel_msg = Twist()
        vel_msg.linear.x = speed * math.cos(self.time * speed / radius)
        vel_msg.linear.y = speed * math.sin(self.time * speed / radius)
        vel_msg.angular.z = speed / radius
        
        self.vel_pub.publish(vel_msg)

def main(args=None):
    rclpy.init(args=args)
    node = MockNavPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()