import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Получение пути к пакету
    pkg_share = get_package_share_directory('gkv2_motor_bridge')
    
    # Путь к файлу конфигурации
    config_file = os.path.join(pkg_share, 'config', 'params.yaml')
    
    # Аргументы launch-файла (можно переопределять при запуске)
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation time'
    )
    
    # Узел драйвера ГКВ2 (входящий канал)
    gkv2_driver_node = Node(
        package='gkv2_motor_bridge',
        executable='gkv2_driver_node',
        name='gkv2_driver',
        output='screen',
        parameters=[
            config_file,
            {'use_sim_time': LaunchConfiguration('use_sim_time')}
        ],
        # QoS настройки для высокочастотных данных
        arguments=['--ros-args', '--log-level', 'INFO']
    )
    
    # Узел управления моторами (исходящий канал)
    cmd_vel_bridge_node = Node(
        package='gkv2_motor_bridge',
        executable='cmd_vel_bridge_node',
        name='cmd_vel_bridge',
        output='screen',
        parameters=[
            config_file,
            {'use_sim_time': LaunchConfiguration('use_sim_time')}
        ],
        arguments=['--ros-args', '--log-level', 'INFO']
    )
    
    return LaunchDescription([
        use_sim_time_arg,
        gkv2_driver_node,
        cmd_vel_bridge_node
    ])