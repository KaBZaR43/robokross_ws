# ~/robocross_all/robokross_ws/src/robokross_control/launch/main.launch.py
"""
Главный launch-файл для запуска всей системы управления ТС РобоКросс-2026.

Запускает:
1. Навигационные узлы (приём UDP, логирование)
2. Узлы управления (мост STM32, менеджер режимов)

Параметры настраиваются через аргументы командной строки.
"""

from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    GroupAction,
    IncludeLaunchDescription,
    LogInfo,
    RegisterEventHandler,
    EmitEvent
)
from launch.conditions import IfCondition, UnlessCondition
from launch.event_handlers import OnProcessStart, OnProcessExit
from launch.events import Shutdown
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import os


def generate_launch_description():
    # =========================================================================
    # АРГУМЕНТЫ ЗАПУСКА
    # =========================================================================
    
    # Навигация
    nav_enabled_arg = DeclareLaunchArgument(
        'nav_enabled',
        default_value='true',
        description='Включить навигационные узлы'
    )
    
    udp_ip_arg = DeclareLaunchArgument(
        'udp_ip',
        default_value='0.0.0.0',
        description='IP адрес для UDP сокета навигации'
    )
    
    udp_port_arg = DeclareLaunchArgument(
        'udp_port',
        default_value='5000',
        description='UDP порт для приёма навигационных данных'
    )
    
    log_enabled_arg = DeclareLaunchArgument(
        'log_enabled',
        default_value='true',
        description='Включить логирование навигации'
    )
    
    log_directory_arg = DeclareLaunchArgument(
        'log_directory',
        default_value='/tmp/nav_logs',
        description='Директория для лог-файлов навигации'
    )
    
    # Управление
    control_enabled_arg = DeclareLaunchArgument(
        'control_enabled',
        default_value='true',
        description='Включить узлы управления'
    )
    
    uart_port_arg = DeclareLaunchArgument(
        'uart_port',
        default_value='/dev/ttyTHS1',
        description='UART порт для связи с STM32'
    )
    
    baudrate_arg = DeclareLaunchArgument(
        'baudrate',
        default_value='115200',
        description='Скорость UART'
    )
    
    max_speed_arg = DeclareLaunchArgument(
        'max_speed_ms',
        default_value='2.5',
        description='Максимальная скорость ТС (м/с). 2.5 без помощника, 5.0 с помощником'
    )
    
    wheel_base_arg = DeclareLaunchArgument(
        'wheel_base',
        default_value='0.7',
        description='База колёс (м)'
    )
    
    watchdog_timeout_arg = DeclareLaunchArgument(
        'watchdog_timeout_sec',
        default_value='0.3',
        description='Таймаут watchdog (сек)'
    )
    
    # Режим работы
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Использовать симулированное время'
    )
    
    # =========================================================================
    # УЗЛЫ НАВИГАЦИИ
    # =========================================================================
    
    nav_parser_node = Node(
        package='robokross_navigation',
        executable='nav_parser_udp_node',
        name='nav_parser_udp',
        output='screen',
        condition=IfCondition(LaunchConfiguration('nav_enabled')),
        parameters=[{
            'udp_ip': LaunchConfiguration('udp_ip'),
            'udp_port': LaunchConfiguration('udp_port'),
            'use_sim_time': LaunchConfiguration('use_sim_time'),
        }],
        arguments=['--ros-args', '--log-level', 'info'],
    )
    
    nav_logger_node = Node(
        package='robokross_navigation',
        executable='nav_logger_node',
        name='nav_logger',
        output='screen',
        condition=IfCondition(
            PythonExpression([
                "'", LaunchConfiguration('nav_enabled'), "' == 'true' and '",
                LaunchConfiguration('log_enabled'), "' == 'true'"
            ])
        ),
        parameters=[{
            'log_directory': LaunchConfiguration('log_directory'),
            'log_to_file': True,
            'log_to_console': True,
            'use_sim_time': LaunchConfiguration('use_sim_time'),
        }],
    )
    
    # =========================================================================
    # УЗЛЫ УПРАВЛЕНИЯ
    # =========================================================================
    
    stm32_bridge_node = Node(
        package='robokross_control',
        executable='stm32_bridge_node',
        name='stm32_bridge',
        output='screen',
        condition=IfCondition(LaunchConfiguration('control_enabled')),
        parameters=[{
            'uart_port': LaunchConfiguration('uart_port'),
            'baudrate': LaunchConfiguration('baudrate'),
            'max_speed_ms': LaunchConfiguration('max_speed_ms'),
            'wheel_base': LaunchConfiguration('wheel_base'),
            'watchdog_timeout_sec': LaunchConfiguration('watchdog_timeout_sec'),
            'use_sim_time': LaunchConfiguration('use_sim_time'),
        }],
    )
    
    vehicle_mode_manager_node = Node(
        package='robokross_control',
        executable='vehicle_mode_manager_node',
        name='vehicle_mode_manager',
        output='screen',
        condition=IfCondition(LaunchConfiguration('control_enabled')),
        parameters=[{
            'use_sim_time': LaunchConfiguration('use_sim_time'),
        }],
    )
    
    # =========================================================================
    # ПОСЛЕДОВАТЕЛЬНОСТЬ ЗАПУСКА
    # =========================================================================
    
    # Группа навигации
    nav_group = GroupAction(
        [
            LogInfo(msg='[LAUNCH] Запуск навигационных узлов...'),
            nav_parser_node,
            nav_logger_node,
        ],
        condition=IfCondition(LaunchConfiguration('nav_enabled')),
    )
    
    # Группа управления
    control_group = GroupAction(
        [
            LogInfo(msg='[LAUNCH] Запуск узлов управления...'),
            stm32_bridge_node,
            vehicle_mode_manager_node,
        ],
        condition=IfCondition(LaunchConfiguration('control_enabled')),
    )
    
    # =========================================================================
    # ОБРАБОТЧИКИ СОБЫТИЙ
    # =========================================================================
    
    # Логирование при завершении узлов
    on_nav_parser_exit = RegisterEventHandler(
        OnProcessExit(
            target_action=nav_parser_node,
            on_exit=[
                LogInfo(msg='[LAUNCH] Навигационный парсер завершён'),
            ],
        )
    )
    
    on_stm32_bridge_exit = RegisterEventHandler(
        OnProcessExit(
            target_action=stm32_bridge_node,
            on_exit=[
                LogInfo(msg='[LAUNCH] Мост STM32 завершён'),
                LogInfo(msg='[LAUNCH] АВАРИЙНАЯ ОСТАНОВКА: Отправка нулевых команд моторам'),
            ],
        )
    )
    
    # =========================================================================
    # ВОЗВРАТ LAUNCH DESCRIPTION
    # =========================================================================
    
    return LaunchDescription([
        # Аргументы
        nav_enabled_arg,
        udp_ip_arg,
        udp_port_arg,
        log_enabled_arg,
        log_directory_arg,
        control_enabled_arg,
        uart_port_arg,
        baudrate_arg,
        max_speed_arg,
        wheel_base_arg,
        watchdog_timeout_arg,
        use_sim_time_arg,
        
        # Обработчики событий
        on_nav_parser_exit,
        on_stm32_bridge_exit,
        
        # Группы узлов
        nav_group,
        control_group,
        
        # Финальное сообщение
        LogInfo(msg='[LAUNCH] =========================================='),
        LogInfo(msg='[LAUNCH] Система РобоКросс-2026 запущена'),
        LogInfo(msg='[LAUNCH] =========================================='),
    ])