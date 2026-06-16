
# README.md

## 1. Список файлов проекта

### Корневая структура воркспейса `~/robokross_ws/`

``` markdown
robokross_ws/
├── setup_virtual_ports.sh          # Скрипт создания виртуальных UART-портов через socat
├── mock_gkv2_nav.py                # Mock-эмулятор ГКВ2 (отправляет пакет 0x13 на 50 Гц)
├── mock_motor_receiver.py          # Mock-приёмник команд моторов (читает пакеты CMD_BUD)
├── .vscode/
│   └── settings.json               # Настройки VS Code (отключает автоконфиг CMake)
└── src/
    └── gkv2_motor_bridge/          # Основной ROS 2 пакет
        ├── CMakeLists.txt          # Конфигурация сборки (colcon)
        ├── package.xml             # Манифест пакета (зависимости)
        ├── launch/
        │   └── main.launch.py      # Launch-файл последовательного запуска всех узлов
        ├── config/
        │   ├── params.yaml         # Параметры всех узлов (порты, baudrate, ID пакетов)
        │   └── waypoints.yaml      # Контрольные точки для навигационного контроллера
        ├── msg/
        │   ├── GKV2Status.msg      # Сообщение статуса ГКВ2 (статусы ГНСС, алгоритма, дисперсии)
        │   ├── GKV2ConfigStatus.msg# Сообщение статуса конфигурации ГКВ2
        │   └── NavigationStatus.msg# Сообщение статуса системы слияния навигации
        └── src/
            ├── gkv2_driver_node.cpp       # Драйвер ПДУ (приём CMD_BUD через LoRa 433)
            ├── cmd_vel_bridge_node.cpp    # Мост команд моторов (cmd_vel → UART, Watchdog)
            ├── gkv2_nav_parser_node.cpp   # Парсер навигации ГКВ2 (пакет 0x13, CRC32)
            ├── gkv2_config_node.cpp       # Узел конфигурации ГКВ2 (проверка при старте)
            ├── odometer_node.cpp          # Эмулятор одометра (интеграция cmd_vel)
            ├── navigation_fusion_node.cpp # Слияние ГНСС + одометрия (автопереключение)
            └── navigation_controller_node.cpp # Pure Pursuit контроллер по waypoints
```
# gkv2_motor_bridge

ROS 2 пакет управления мобильной робототехнической системой для соревнований «РобоКросс-2026».

## Архитектура

Система состоит из 7 узлов ROS 2, взаимодействующих через UART и топики:
- **gkv2_driver_node** — приём команд от ПДУ (LoRa 433 → UART)
- **gkv2_nav_parser_node** — парсер навигации ГКВ2 (UART → ROS топики)
- **gkv2_config_node** — проверка конфигурации ГКВ2 при старте
- **cmd_vel_bridge_node** — мост команд моторов (ROS → UART БУД)
- **odometer_node** — эмулятор одометра
- **navigation_fusion_node** — слияние ГНСС + одометрия
- **navigation_controller_node** — Pure Pursuit контроллер

## Зависимости

- ROS 2 Jazzy
- Boost.Asio
- Python 3 с библиотекой `pyserial`
- `socat` (для виртуальных портов)

Установка зависимостей:
```bash
sudo apt update
sudo apt install ros-jazzy-ros-base python3-serial socat
```

## Сборка

```bash
cd ~/robokross_ws
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select gkv2_motor_bridge
source install/setup.bash
```

Для автоматической активации ROS 2 при открытии терминала:
```bash
echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

## Создание виртуальных UART-портов

Виртуальные порты необходимы для тестирования на ПК без реального железа. Создаются через `socat`.

```bash
sudo ~/robokross_ws/setup_virtual_ports.sh
```

Схема портов:
- `ttyV0` ↔ `ttyV2`: ПДУ → Jetson (gkv2_driver_node читает из ttyV0)
- `ttyV1` ↔ `ttyV3`: ГКВ2 → Jetson (gkv2_nav_parser_node читает из ttyV1)
- `ttyV4` ↔ `ttyV5`: Jetson → Моторы (cmd_vel_bridge_node пишет в ttyV4)

Порты существуют до перезагрузки или завершения `socat`. После перезагрузки необходимо запускать скрипт заново.

## Запуск системы

### Полный запуск (все узлы)

```bash
cd ~/robokross_ws
source install/setup.bash
ros2 launch gkv2_motor_bridge main.launch.py
```

Launch-файл запускает узлы последовательно:
1. `gkv2_config_node` — проверяет конфигурацию ГКВ2 и завершается
2. После его завершения запускаются остальные 6 узлов параллельно

### Запуск отдельных узлов (для отладки)

```bash
# Драйвер ПДУ
ros2 run gkv2_motor_bridge gkv2_driver_node --ros-args --params-file install/gkv2_motor_bridge/share/gkv2_motor_bridge/config/params.yaml

# Парсер навигации ГКВ2
ros2 run gkv2_motor_bridge gkv2_nav_parser_node --ros-args --params-file install/gkv2_motor_bridge/share/gkv2_motor_bridge/config/params.yaml

# Мост моторов
ros2 run gkv2_motor_bridge cmd_vel_bridge_node --ros-args --params-file install/gkv2_motor_bridge/share/gkv2_motor_bridge/config/params.yaml

# Эмулятор одометра
ros2 run gkv2_motor_bridge odometer_node --ros-args --params-file install/gkv2_motor_bridge/share/gkv2_motor_bridge/config/params.yaml

# Слияние навигации
ros2 run gkv2_motor_bridge navigation_fusion_node --ros-args --params-file install/gkv2_motor_bridge/share/gkv2_motor_bridge/config/params.yaml

# Навигационный контроллер
ros2 run gkv2_motor_bridge navigation_controller_node --ros-args --params-file install/gkv2_motor_bridge/share/gkv2_motor_bridge/config/params.yaml --ros-args -p waypoints_file:=$(pwd)/install/gkv2_motor_bridge/share/gkv2_motor_bridge/config/waypoints.yaml
```

## Запуск mock-скриптов

Mock-скрипты эмулируют внешние устройства для тестирования без реального железа.

### Mock ГКВ2 (эмуляция навигационных данных)

```bash
python3 ~/robokross_ws/mock_gkv2_nav.py
```

Отправляет пакет 0x13 с частотой 50 Гц на порт `/dev/ttyV3`. Эмулирует:
- Позицию NED (10.0, 5.0, 0.0) м
- Ориентацию yaw = 1.57 рад (90°)
- RTK Fixed статус
- 15 спутников
- Полную навигацию (alg_stage = 50)
- Двухантенное решение (heading valid)

### Mock приёмника моторов

```bash
python3 ~/robokross_ws/mock_motor_receiver.py
```

Читает пакеты CMD_BUD с порта `/dev/ttyV5` и выводит расшифровку в консоль.

## Тестирование

### 1. Проверка публикации топиков

```bash
# Список всех топиков
ros2 topic list

# Статус навигации
ros2 topic echo /nav/status

# Статус ГКВ2 (полный)
ros2 topic echo /gkv2/status

# Отдельные поля статуса
ros2 topic echo /gkv2/status --field rtk_status
ros2 topic echo /gkv2/status --field rel_ambiguity_status
ros2 topic echo /gkv2/status --field alg_navigation_ready

# Слитая позиция
ros2 topic echo /nav/fused_pose

# Статус конфигурации
ros2 topic echo /gkv2/config_status
```

### 2. Проверка tf2

```bash
# Мониторинг transform map → base_link
ros2 run tf2_ros tf2_monitor map base_link

# Просмотр дерева tf
ros2 run tf2_tools view_frames
```

### 3. Проверка частоты публикации

```bash
ros2 topic hz /gkv2/status
ros2 topic hz /nav/fused_pose
ros2 topic hz /cmd_vel
```

Ожидаемая частота: ~50 Гц.

### 4. Тестирование резервирования одометрии

1. Запустите систему и mock ГКВ2
2. Убедитесь, что `/nav/status` показывает `current_mode: 0` (GNSS)
3. Остановите `mock_gkv2_nav.py` (Ctrl+C)
4. Через 2 секунды система переключится в режим одометрии (`current_mode: 1`)
5. Запустите `mock_gkv2_nav.py` снова — система вернётся в режим GNSS

### 5. Переключение режимов работы

```bash
# Переход в режим ДВИЖЕНИЕ
ros2 topic pub --once /mode_switch std_msgs/msg/Bool "{data: true}"

# Переход в режим ПАУЗА
ros2 topic pub --once /mode_switch std_msgs/msg/Bool "{data: false}"
```

### 6. Публикация команд вручную

```bash
# Движение вперёд
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "{linear: {x: 1.0}, angular: {z: 0.0}}"

# Поворот на месте
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0}, angular: {z: 0.5}}"

# Остановка
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0}, angular: {z: 0.0}}"
```

## Диагностика

### Логи в файлах

Все узлы пишут логи в `~/robokross_ws/logs/`:
```bash
ls -la ~/robokross_ws/logs/
tail -f ~/robokross_ws/logs/navigation_fusion*.log
```

### Проверка UART-портов

```bash
# Список виртуальных портов
ls -l /dev/ttyV*

# Проверка, какие процессы держат порты
lsof /dev/ttyV1
lsof /dev/ttyV4

# Проверка процессов socat
ps aux | grep socat
```

### Очистка и пересборка

```bash
cd ~/robokross_ws
rm -rf build/ install/ log/
colcon build --symlink-install --packages-select gkv2_motor_bridge
source install/setup.bash
```

## Структура проекта

```
gkv2_motor_bridge/
├── CMakeLists.txt          # Сборка пакета
├── package.xml             # Зависимости
├── launch/
│   └── main.launch.py      # Последовательный запуск узлов
├── config/
│   ├── params.yaml         # Параметры узлов
│   └── waypoints.yaml      # Контрольные точки
├── msg/                    # Кастомные сообщения ROS 2
│   ├── GKV2Status.msg
│   ├── GKV2ConfigStatus.msg
│   └── NavigationStatus.msg
└── src/                    # Исходный код узлов
    ├── gkv2_driver_node.cpp
    ├── gkv2_nav_parser_node.cpp
    ├── gkv2_config_node.cpp
    ├── cmd_vel_bridge_node.cpp
    ├── odometer_node.cpp
    ├── navigation_fusion_node.cpp
    └── navigation_controller_node.cpp
```
