import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('gkv2_motor_bridge')
    params_file = os.path.join(pkg_share, 'config', 'params.yaml')
    waypoints_file = os.path.join(pkg_share, 'config', 'waypoints.yaml')
    
    # 1. Создание и настройка директории для логов
    log_dir = os.path.expanduser('~/robokross_ws/logs')
    os.makedirs(log_dir, exist_ok=True)
    
    # Принудительно задаем переменную окружения ROS_LOG_DIR
    set_log_dir = SetEnvironmentVariable('ROS_LOG_DIR', log_dir)

    # 2. Аргументы launch-файла
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation time'
    )

    # 3. Определение узлов (output='both' пишет и в терминал, и в файл)
    gkv2_driver_node = Node(
        package='gkv2_motor_bridge',
        executable='gkv2_driver_node',
        name='gkv2_driver',
        output='both',
        parameters=[params_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )
    
    cmd_vel_bridge_node = Node(
        package='gkv2_motor_bridge',
        executable='cmd_vel_bridge_node',
        name='cmd_vel_bridge',
        output='both',
        parameters=[params_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )
    
    gkv2_nav_parser_node = Node(
        package='gkv2_motor_bridge',
        executable='gkv2_nav_parser_node',
        name='gkv2_nav_parser',
        output='both',
        parameters=[params_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )
    
    navigation_controller_node = Node(
        package='gkv2_motor_bridge',
        executable='navigation_controller_node',
        name='navigation_controller',
        output='both',
        parameters=[params_file, waypoints_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )

    # Узел 5: Эмулятор одометра

    odometer_node = Node(
        package='gkv2_motor_bridge',
        executable='odometer_node',
        name='odometer',
        output='both',
        parameters=[params_file]
    )

    # Узел 6: Слияние навигационных данных

    navigation_fusion_node = Node(
        package='gkv2_motor_bridge',
        executable='navigation_fusion_node',
        name='navigation_fusion',
        output='both',
        parameters=[params_file]
    )

    return LaunchDescription([
        set_log_dir,               
        use_sim_time_arg,
        gkv2_driver_node,
        cmd_vel_bridge_node,
        gkv2_nav_parser_node,
        odometer_node,
        navigation_fusion_node,
        navigation_controller_node
    ])