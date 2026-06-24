#!/usr/bin/env python3
"""
UDP Mock-генератор навигационных данных.
Формирует бинарный пакет строго по структуре SystemData из EthDatagramm.h
и отправляет его по UDP на порт 5000.
"""

import ctypes
import socket
import time
import math
import sys

# ============================================================================
# Дублирование структур из EthDatagramm.h для точного совпадения размеров
# ============================================================================
class SystemStatus(ctypes.Structure):
    _pack_ = 1
    _fields_ = [
        ("flags", ctypes.c_uint8)  # Все биты в 1 = все модули OK
    ]

class SystemConfig(ctypes.Structure):
    _pack_ = 1
    _fields_ = [
        ("wrkMode", ctypes.c_uint8),
        ("baseId", ctypes.c_uint8),
        ("roverId", ctypes.c_uint8),
        ("varParam1", ctypes.c_float),
        ("varParam2", ctypes.c_float),
        ("varParam3", ctypes.c_float),
        ("searchInBaseMode", ctypes.c_uint8),
        ("resetGnss", ctypes.c_uint8),
        ("configCrc", ctypes.c_uint8),
    ]

class UserGnssData(ctypes.Structure):
    _pack_ = 1
    _fields_ = [
        ("year", ctypes.c_uint16),
        ("month", ctypes.c_uint8),
        ("day", ctypes.c_uint8),
        ("hour", ctypes.c_uint8),
        ("minute", ctypes.c_uint8),
        ("second", ctypes.c_uint8),
        ("statusSolution", ctypes.c_uint8),  # 4 = FIXED
        ("headingStatus", ctypes.c_uint8),
        ("GPS_SIU", ctypes.c_uint8),
        ("BDS_SIU", ctypes.c_uint8),
        ("GLO_SIU", ctypes.c_uint8),
        ("GAL_SIU", ctypes.c_uint8),
        ("baseline", ctypes.c_float * 3),
        ("baselineDev", ctypes.c_float * 3),
        ("heading", ctypes.c_float),
        ("pitch", ctypes.c_float),
        ("roll", ctypes.c_float),
        ("speed", ctypes.c_float),
        ("speedHeading", ctypes.c_float),
        ("speedSolStat", ctypes.c_uint8),
        ("velocity", ctypes.c_float * 3),
        ("velocityDev", ctypes.c_float * 3),
        ("latitudeSelf", ctypes.c_double),
        ("longitudeSelf", ctypes.c_double),
        ("altitudeSelf", ctypes.c_double),
        ("ecefXself", ctypes.c_double),
        ("ecefYself", ctypes.c_double),
        ("ecefZself", ctypes.c_double),
        ("latitudeSelfDev", ctypes.c_float),
        ("longitudeSelfDev", ctypes.c_float),
        ("altitudeSelfDev", ctypes.c_float),
        ("ecefXselfDev", ctypes.c_float),
        ("ecefYselfDev", ctypes.c_float),
        ("ecefZselfDev", ctypes.c_float),
        ("latitudeBase", ctypes.c_double),
        ("longitudeBase", ctypes.c_double),
        ("altitudeBase", ctypes.c_double),
        ("latitudeSelfSlave", ctypes.c_double),
        ("longitudeSelfSlave", ctypes.c_double),
        ("altitudeSelfSlave", ctypes.c_double),
        ("undulation", ctypes.c_float),
    ]

class SystemData(ctypes.Structure):
    _pack_ = 1
    _fields_ = [
        ("status", SystemStatus),
        ("cfg", SystemConfig),
        ("gData", UserGnssData),
        ("remoteCfg", SystemConfig),
    ]

def main():
    # Настройка UDP сокета
    UDP_IP = "127.0.0.1"  # Или IP вашего Jetson, если тестируете по сети
    UDP_PORT = 5000
    
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    # Инициализация структуры
    sys_data = SystemData()
    
    # Заполнение статусов (все модули OK)
    sys_data.status.flags = 0xFF 
    
    # Конфигурация (режим ровера)
    sys_data.cfg.wrkMode = 0  # SYS_MODE_ROVER
    sys_data.cfg.varParam1 = 50.0  # Частота 50 Гц
    
    # Начальные координаты (Нижний Новгород)
    base_lat = 56.2965
    base_lon = 43.9361
    base_alt = 100.0
    
    sys_data.gData.latitudeBase = base_lat
    sys_data.gData.longitudeBase = base_lon
    sys_data.gData.altitudeBase = base_alt
    
    # Статус RTK Fixed
    sys_data.gData.statusSolution = 4  # FIXED
    
    # Спутники
    sys_data.gData.GPS_SIU = 12
    sys_data.gData.BDS_SIU = 8
    sys_data.gData.GLO_SIU = 6
    sys_data.gData.GAL_SIU = 4
    
    print(f"=== UDP Mock Publisher Started ===")
    print(f"Sending SystemData ({ctypes.sizeof(sys_data)} bytes) to {UDP_IP}:{UDP_PORT}")
    print(f"Press Ctrl+C to stop.\n")
    
    sim_time = 0.0
    rate = 50  # Гц
    
    try:
        while True:
            sim_time += 1.0 / rate
            
            # Имитация движения по кругу (радиус 10м, скорость ~2 м/с)
            radius = 10.0
            angular_speed = 0.2  # рад/с
            
            lat_offset = (radius * math.sin(sim_time * angular_speed)) / 111320.0
            lon_offset = (radius * math.cos(sim_time * angular_speed)) / (111320.0 * math.cos(math.radians(base_lat)))
            
            sys_data.gData.latitudeSelf = base_lat + lat_offset
            sys_data.gData.longitudeSelf = base_lon + lon_offset
            sys_data.gData.altitudeSelf = base_alt
            
            # Ориентация
            sys_data.gData.heading = math.degrees(sim_time * angular_speed) % 360.0
            sys_data.gData.pitch = 2.5 * math.sin(sim_time)  # Небольшой крен
            sys_data.gData.roll = 1.0 * math.cos(sim_time)
            
            # Скорость
            sys_data.gData.speed = 2.0  # м/с
            sys_data.gData.speedSolStat = 0  # valid
            
            # Вектор скорости (Север, Вверх, Восток)
            sys_data.gData.velocity[0] = 2.0 * math.cos(sim_time * angular_speed)
            sys_data.gData.velocity[1] = 0.0
            sys_data.gData.velocity[2] = 2.0 * math.sin(sim_time * angular_speed)
            
            # Время UTC
            sys_data.gData.year = 2026
            sys_data.gData.month = 6
            sys_data.gData.day = 25
            sys_data.gData.hour = 12
            sys_data.gData.minute = 0
            sys_data.gData.second = int(sim_time) % 60
            
            # Отправка пакета
            packet = ctypes.string_at(ctypes.byref(sys_data), ctypes.sizeof(sys_data))
            sock.sendto(packet, (UDP_IP, UDP_PORT))
            
            if int(sim_time * rate) % 50 == 0:  # Лог каждые 1 секунду
                print(f"[{sim_time:.1f}s] Sent: Lat={sys_data.gData.latitudeSelf:.6f}, "
                      f"Lon={sys_data.gData.longitudeSelf:.6f}, "
                      f"Speed={sys_data.gData.speed:.2f} m/s, "
                      f"Heading={sys_data.gData.heading:.1f} deg")
            
            time.sleep(1.0 / rate)
            
    except KeyboardInterrupt:
        print("\n=== UDP Mock Publisher Stopped ===")
    finally:
        sock.close()

if __name__ == '__main__':
    main()