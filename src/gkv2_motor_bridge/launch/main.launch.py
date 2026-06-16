import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('gkv2_motor_bridge')
    params_file = os.path.join(pkg_share, 'config', 'params.yaml')
    waypoints_file = os.path.join(pkg_share, 'config', 'waypoints.yaml')
    
    log_dir = os.path.expanduser('~/robokross_ws/logs')
    os.makedirs(log_dir, exist_ok=True)
    set_log_dir = SetEnvironmentVariable('ROS_LOG_DIR', log_dir)

    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time', default_value='false', description='Use simulation time'
    )

    # 1. Узел конфигурации ГКВ2 (запускается первым)
    gkv2_config_node = Node(
        package='gkv2_motor_bridge',
        executable='gkv2_config_node',
        name='gkv2_config',
        output='both',
        parameters=[params_file]
    )

    # 2. Остальные узлы системы
    gkv2_driver_node = Node(
        package='gkv2_motor_bridge', executable='gkv2_driver_node', name='gkv2_driver',
        output='both', parameters=[params_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )
    
    cmd_vel_bridge_node = Node(
        package='gkv2_motor_bridge', executable='cmd_vel_bridge_node', name='cmd_vel_bridge',
        output='both', parameters=[params_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )
    
    gkv2_nav_parser_node = Node(
        package='gkv2_motor_bridge', executable='gkv2_nav_parser_node', name='gkv2_nav_parser',
        output='both', parameters=[params_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )
    
    odometer_node = Node(
        package='gkv2_motor_bridge', executable='odometer_node', name='odometer',
        output='both', parameters=[params_file]
    )
    
    navigation_fusion_node = Node(
        package='gkv2_motor_bridge', executable='navigation_fusion_node', name='navigation_fusion',
        output='both', parameters=[params_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )
    
    navigation_controller_node = Node(
        package='gkv2_motor_bridge', executable='navigation_controller_node', name='navigation_controller',
        output='both', parameters=[params_file, waypoints_file, {'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )

    main_system_nodes = [
        gkv2_driver_node, cmd_vel_bridge_node, gkv2_nav_parser_node,
        odometer_node, navigation_fusion_node, navigation_controller_node
    ]

    # 3. Механизм последовательного запуска
    config_exit_handler = RegisterEventHandler(
        OnProcessExit(
            target_action=gkv2_config_node,
            on_exit=main_system_nodes
        )
    )

    return LaunchDescription([
        set_log_dir,
        use_sim_time_arg,
        gkv2_config_node,      # Сначала запускается конфигуратор
        config_exit_handler    # Остальные узлы запускаются после его завершения
    ])