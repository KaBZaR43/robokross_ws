# ~/robocross_all/robokross_ws/src/robokross_navigation/launch/nav_test.launch.py
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os

def generate_launch_description():
    # Аргументы
    udp_ip_arg = DeclareLaunchArgument(
        'udp_ip',
        default_value='0.0.0.0',
        description='IP address to bind UDP socket'
    )
    
    udp_port_arg = DeclareLaunchArgument(
        'udp_port',
        default_value='5000',
        description='UDP port to listen on'
    )
    
    log_dir_arg = DeclareLaunchArgument(
        'log_directory',
        default_value='/tmp/nav_logs',
        description='Directory for log files'
    )
    
    # Узел парсера навигации
    nav_parser_node = Node(
        package='robokross_navigation',
        executable='nav_parser_udp_node',
        name='nav_parser_udp',
        output='screen',
        parameters=[{
            'udp_ip': LaunchConfiguration('udp_ip'),
            'udp_port': LaunchConfiguration('udp_port'),
        }]
    )
    
    # Узел логгера
    nav_logger_node = Node(
        package='robokross_navigation',
        executable='nav_logger_node',
        name='nav_logger',
        output='screen',
        parameters=[{
            'log_directory': LaunchConfiguration('log_directory'),
            'log_to_file': True,
            'log_to_console': True,
        }]
    )
    
    return LaunchDescription([
        udp_ip_arg,
        udp_port_arg,
        log_dir_arg,
        nav_parser_node,
        nav_logger_node,
    ])