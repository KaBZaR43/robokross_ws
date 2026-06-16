#!/usr/bin/env python3
"""
Комплексный тест навигационной системы gkv2_motor_bridge.
Имитирует работу ГКВ2, внедряет сбои (потеря ГНСС, аварийный стоп, обрыв связи)
и проверяет реакцию системы управления.
"""

import rclpy
from rclpy.node import Node
from rclpy.clock import Clock
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

from geometry_msgs.msg import PoseStamped, Twist
from std_msgs.msg import Bool, Header
# Импорт кастомных сообщений (требует source install/setup.bash)
from gkv2_motor_bridge.msg import GKV2Status, NavigationStatus

import math
import time
import logging
import sys

# ============================================================================
# НАСТРОЙКА ЛОГИРОВАНИЯ
# ============================================================================
class ColoredFormatter(logging.Formatter):
    COLORS = {
        'DEBUG': '\033[94m',    # Синий
        'INFO': '\033[92m',     # Зеленый
        'WARNING': '\033[93m',  # Желтый
        'ERROR': '\033[91m',    # Красный
        'CRITICAL': '\033[95m', # Фиолетовый
        'RESET': '\033[0m'
    }

    def format(self, record):
        color = self.COLORS.get(record.levelname, self.COLORS['RESET'])
        reset = self.COLORS['RESET']
        log_fmt = f"{color}[%(asctime)s] [%(levelname)-8s]{reset} %(message)s"
        formatter = logging.Formatter(log_fmt, datefmt='%H:%M:%S')
        return formatter.format(record)

logger = logging.getLogger('NavTestSuite')
logger.setLevel(logging.INFO)
handler = logging.StreamHandler(sys.stdout)
handler.setFormatter(ColoredFormatter())
logger.addHandler(handler)

# ============================================================================
# УЗЕЛ ТЕСТИРОВАНИЯ
# ============================================================================
class NavigationTestSuite(Node):
    def __init__(self):
        super().__init__('navigation_test_suite')
        self.test_completed = False 
        
        # QoS для высокочастотных данных (как в реальном парсере)
        sensor_qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        reliable_qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.RELIABLE)

        # Издатели (Имитация датчиков и оператора)
        self.pose_pub = self.create_publisher(PoseStamped, '/nav/pose', sensor_qos)
        self.gkv2_status_pub = self.create_publisher(GKV2Status, '/gkv2/status', sensor_qos)
        self.mode_pub = self.create_publisher(Bool, '/mode_switch', reliable_qos)

        # Подписчики (Мониторинг реакции системы)
        self.cmd_vel_sub = self.create_subscription(Twist, '/cmd_vel', self.cmd_vel_callback, 10)
        self.nav_status_sub = self.create_subscription(NavigationStatus, '/nav/status', self.nav_status_callback, 10)

        # Состояние теста
        self.test_phase = 0
        self.phase_start_time = self.get_clock().now()
        self.sim_time = 0.0
        self.current_mode = 0 # 0=GNSS, 1=Odometry
        
        # Флаги мониторинга
        self.last_cmd_vel_time = self.get_clock().now()
        self.cmd_vel_received = False
        self.fusion_mode_verified = False

        # Таймер основного цикла симуляции (50 Гц)
        self.sim_timer = self.create_timer(0.02, self.simulation_loop)
        # Таймер управления тестовыми фазами (1 Гц)
        self.test_timer = self.create_timer(1.0, self.test_sequence_manager)

        # Флаг завершения теста
        self.test_completed = False

        logger.info("=== Инициализация тестового стенда завершена ===")
        logger.info("Ожидание запуска системы...")

    # ========================================================================
    # CALLBACK'И МОНИТОРИНГА
    # ========================================================================
    def cmd_vel_callback(self, msg: Twist):
        self.cmd_vel_received = True
        self.last_cmd_vel_time = self.get_clock().now()
        # Логируем только значимые изменения для уменьшения шума
        if abs(msg.linear.x) > 0.1 or abs(msg.angular.z) > 0.1:
            logger.debug(f"Получена команда моторам: lin={msg.linear.x:.2f} м/с, ang={msg.angular.z:.2f} рад/с")

    def nav_status_callback(self, msg: NavigationStatus):
        if msg.current_mode != self.current_mode:
            self.current_mode = msg.current_mode
            mode_str = "ГНСС (RTK)" if msg.current_mode == 0 else "ОДОМЕТРИЯ"
            logger.info(f">>> Смена режима слияния: {mode_str} | Дрейф: {msg.odometry_drift:.2f} м | Спутники: {msg.gnss_satellites}")
            self.fusion_mode_verified = True

    # ========================================================================
    # МЕНЕДЖЕР ТЕСТОВЫХ ФАЗ (ВНЕДРЕНИЕ СБОЕВ)
    # ========================================================================
    def test_sequence_manager(self):
        elapsed = (self.get_clock().now() - self.phase_start_time).nanoseconds / 1e9

        if self.test_phase == 0:
            # Фаза 0: Инициализация и переход в режим ДВИЖЕНИЕ
            logger.info("[ФАЗА 1] Переключение в режим ПАУЗА, затем ДВИЖЕНИЕ...")
            self.mode_pub.publish(Bool(data=False)) # PAUSE
            time.sleep(1.0)
            self.mode_pub.publish(Bool(data=True))  # DRIVE
            self.test_phase = 1
            self.phase_start_time = self.get_clock().now()

        elif self.test_phase == 1:
            # Фаза 1: Штатная работа (5 секунд)
            if elapsed > 5.0:
                logger.warning("[ФАЗА 2] ВНЕДРЕНИЕ СБОЯ: Обрыв связи с ГКВ2 (имитация потери UART/LoRa)...")
                self.test_phase = 2
                self.phase_start_time = self.get_clock().now()

        elif self.test_phase == 2:
            # Фаза 2: Потеря ГНСС (5 секунд). Данные не публикуются.
            if elapsed > 5.0:
                logger.info("[ФАЗА 3] ВОССТАНОВЛЕНИЕ: Связь с ГКВ2 восстановлена...")
                self.test_phase = 3
                self.phase_start_time = self.get_clock().now()

        elif self.test_phase == 3:
            # Фаза 3: Работа после восстановления (5 секунд)
            if elapsed > 5.0:
                logger.error("[ФАЗА 4] КРИТИЧЕСКИЙ СБОЙ: Симуляция перегрева батареи / Аварийный стоп...")
                self.mode_pub.publish(Bool(data=False)) # Принудительный СТОП/ПАУЗА
                self.test_phase = 4
                self.phase_start_time = self.get_clock().now()

        elif self.test_phase == 4:
            # Фаза 4: Проверка остановки (3 секунды)
            if elapsed > 3.0:
                logger.critical("[ФАЗА 5] ПОЛНЫЙ ОБРЫВ СВЯЗИ: Имитация падения узла Jetson или обрыва всех UART...")
                self.test_phase = 5
                self.phase_start_time = self.get_clock().now()

        elif self.test_phase == 5:
            # Фаза 5: Полный обрыв (ничего не публикуем, ждем срабатывания Watchdog моторов)
            if elapsed > 5.0:
                logger.info("=== ТЕСТ ЗАВЕРШЕН ===")
                logger.info("Анализ результатов...")
                self.analyze_results()
                

    # ========================================================================
    # ЦИКЛ СИМУЛЯЦИИ ДАТЧИКОВ (50 Гц)
    # ========================================================================
    def simulation_loop(self):
        # Не публикуем данные в фазах 2 (потеря ГНСС) и 5 (полный обрыв)
        if self.test_phase in [2, 5]:
            return

        self.sim_time += 0.02
        
        # 1. Формирование PoseStamped (Движение по дуге)
        pose = PoseStamped()
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.header.frame_id = 'map'
        
        # Имитация движения: радиус 10м, скорость ~1 м/с
        radius = 10.0
        angular_speed = 0.1 # рад/с
        x = radius * math.sin(self.sim_time * angular_speed)
        y = radius * (1.0 - math.cos(self.sim_time * angular_speed))
        yaw = self.sim_time * angular_speed

        pose.pose.position.x = x
        pose.pose.position.y = y
        pose.pose.position.z = 0.0
        
        # Euler to Quaternion (Yaw only)
        pose.pose.orientation.z = math.sin(yaw / 2.0)
        pose.pose.orientation.w = math.cos(yaw / 2.0)
        
        self.pose_pub.publish(pose)

        # 2. Формирование GKV2Status (RTK Fixed, 15 спутников, полная навигация)
        status = GKV2Status()
        status.gps_state_status = 0x00830003  # RTK Fixed + Coords Valid + Time Valid
        status.rtk_status = 2                 # Fixed
        status.gps_num_satellites = 15
        status.alg_state_status = 50          # Stage 50 (Full Nav)
        status.alg_navigation_ready = True
        status.rel_heading_valid = True
        status.heading_from_dual_antenna = True
        
        # Заполнение дисперсий (для качества слияния)
        status.alg_var_x = 0.01
        status.alg_var_y = 0.01
        status.alg_var_psi = 0.001
        
        self.gkv2_status_pub.publish(status)

    # ========================================================================
    # АНАЛИЗ РЕЗУЛЬТАТОВ
    # ========================================================================
    def analyze_results(self):
        logger.info("-" * 50)
        logger.info("ОТЧЕТ ПО ТЕСТИРОВАНИЮ:")
        
        # Проверка 1: Реакция на потерю ГНСС
        # (В логах должно быть переключение в режим ОДОМЕТРИЯ)
        logger.info("[ПРОВЕРКА 1] Переключение на одометрию при потере ГНСС: " 
                    + ("ПРОЙДЕНА (см. лог выше)" if self.fusion_mode_verified else "ТРЕБУЕТ РУЧНОЙ ПРОВЕРКИ"))

        # Проверка 2: Аварийный стоп
        # (В логах cmd_vel_bridge_node должны быть нулевые команды после ФАЗЫ 4)
        logger.info("[ПРОВЕРКА 2] Аварийный стоп при перегреве: ТРЕБУЕТ ПРОВЕРКИ ЛОГОВ cmd_vel_bridge_node")

        # Проверка 3: Watchdog моторов
        # (В логах cmd_vel_bridge_node должно быть "Watchdog timeout" после ФАЗЫ 5)
        logger.info("[ПРОВЕРКА 3] Срабатывание Watchdog при обрыве связи: ТРЕБУЕТ ПРОВЕРКИ ЛОГОВ cmd_vel_bridge_node")
        logger.info("-" * 50)
        
        self.test_completed = True

def main(args=None):
    rclpy.init(args=args)
    node = NavigationTestSuite()
    try:
        # Ждем либо внешнего прерывания (Ctrl+C), либо завершения теста
        while rclpy.ok() and not node.test_completed:
            rclpy.spin_once(node, timeout_sec=0.1)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == '__main__':
    main()