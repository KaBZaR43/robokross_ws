#!/bin/bash
set -e

echo "=== Создание виртуальных UART портов ==="

# Проверка прав root
if [ "$EUID" -ne 0 ]; then
  echo "Ошибка: Запустите скрипт с sudo: sudo $0"
  exit 1
fi

# Очистка старых процессов и ссылок
echo "Stopping old socat processes..."
pkill -f "socat.*ttyV" 2>/dev/null || true
sleep 0.5
rm -f /dev/ttyV{0,1,2,3,4,5}

echo "Creating virtual ports..."
# Запуск socat в фоне с перенаправлением вывода
socat -d -d pty,raw,echo=0,link=/dev/ttyV0,mode=666 pty,raw,echo=0,link=/dev/ttyV2,mode=666 &>/dev/null &
socat -d -d pty,raw,echo=0,link=/dev/ttyV1,mode=666 pty,raw,echo=0,link=/dev/ttyV3,mode=666 &>/dev/null &
socat -d -d pty,raw,echo=0,link=/dev/ttyV4,mode=666 pty,raw,echo=0,link=/dev/ttyV5,mode=666 &>/dev/null &

# Ожидание появления ссылок (до 5 сек)
for i in {1..10}; do
    if [ -e /dev/ttyV0 ] && [ -e /dev/ttyV1 ] && [ -e /dev/ttyV4 ]; then
        break
    fi
    sleep 0.5
done

echo ""
echo "=== Проверка созданных портов ==="
ls -l /dev/ttyV*

if [ ! -e /dev/ttyV0 ] || [ ! -e /dev/ttyV1 ] || [ ! -e /dev/ttyV4 ]; then
    echo "ERROR: Ports were not created. Check socat logs or permissions."
    exit 1
fi

echo ""
echo "=== Схема подключения ==="
echo "ttyV0 (ПК) <-> ttyV2 (mock ПДУ)      : gkv2_driver_node читает из ttyV0"
echo "ttyV1 (ПК) <-> ttyV3 (mock ГКВ2)     : gkv2_nav_parser_node читает из ttyV1"
echo "ttyV4 (ПК) <-> ttyV5 (mock моторов)  : cmd_vel_bridge_node пишет в ttyV4"
echo "Virtual ports created successfully!"
