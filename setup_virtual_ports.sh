#!/bin/bash
# Скрипт для создания виртуальных UART портов для тестирования
# Создаёт 3 независимые пары портов для трёх каналов связи

echo "=== Создание виртуальных UART портов ==="

# Остановка старых процессов socat
echo "Stopping old socat processes..."
pkill socat 2>/dev/null
sleep 1

# Пара 1: ПДУ -> БУД (команды CMD_BUD)
# gkv2_driver_node читает из /dev/ttyV0
echo "Creating pair 1: PDU -> BUD (CMD_BUD)..."
sudo socat -d -d pty,raw,echo=0,link=/dev/ttyV0,mode=666 pty,raw,echo=0,link=/dev/ttyV2,mode=666 &
sleep 0.5

# Пара 2: ГКВ2 -> Jetson (навигационные данные)
# gkv2_nav_parser_node читает из /dev/ttyV1
echo "Creating pair 2: GKV2 -> Jetson (navigation)..."
sudo socat -d -d pty,raw,echo=0,link=/dev/ttyV1,mode=666 pty,raw,echo=0,link=/dev/ttyV3,mode=666 &
sleep 0.5

# Пара 3: БУД -> Моторы (команды управления)
# cmd_vel_bridge_node пишет в /dev/ttyV4
echo "Creating pair 3: BUD -> Motors (control)..."
sudo socat -d -d pty,raw,echo=0,link=/dev/ttyV4,mode=666 pty,raw,echo=0,link=/dev/ttyV5,mode=666 &
sleep 1

echo ""
echo "=== Проверка созданных портов ==="
ls -l /dev/ttyV*

echo ""
echo "=== Схема подключения ==="
echo "ttyV0 (ПК) <-> ttyV2 (mock ПДУ)      : gkv2_driver_node читает из ttyV0"
echo "ttyV1 (ПК) <-> ttyV3 (mock ГКВ2)     : gkv2_nav_parser_node читает из ttyV1"
echo "ttyV4 (ПК) <-> ttyV5 (mock моторов)  : cmd_vel_bridge_node пишет в ttyV4"
echo ""
echo "Virtual ports created successfully!"