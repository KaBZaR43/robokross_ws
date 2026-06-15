import serial
import sys
import time

# ============================================================================
# РАСЧЕТ CRC-16/ARC (Modbus)
# Полностью идентичен реализации в MockMotorProtocol (C++)
# ============================================================================
def calculate_crc16(data):
    crc = 0xFFFF
    for byte in data:
        crc ^= byte
        for _ in range(8):
            if crc & 1:
                crc = (crc >> 1) ^ 0xA001
            else:
                crc >>= 1
    return crc

# ============================================================================
# ДЕШИФРАТОР ФЛАГОВ
# ============================================================================
def decode_flags(flags_byte):
    left_dir = "REVERSE" if (flags_byte & 0x01) else "FORWARD"
    right_dir = "REVERSE" if (flags_byte & 0x02) else "FORWARD"
    ignition = "ON" if (flags_byte & 0x04) else "OFF"
    brake1 = "ACTIVE" if (flags_byte & 0x08) else "RELEASED"
    brake2 = "ACTIVE" if (flags_byte & 0x40) else "RELEASED"
    return f"L:{left_dir}, R:{right_dir}, IGN:{ignition}, B1:{brake1}, B2:{brake2}"

def main():
    port = '/dev/ttyV0'
    baudrate = 115200
    
    try:
        ser = serial.Serial(port, baudrate, timeout=1)
        print(f"[INFO] Listening on {port} @ {baudrate} baud...")
    except serial.SerialException as e:
        print(f"[ERROR] Failed to open port: {e}")
        sys.exit(1)

    buffer = bytearray()
    PACKET_SIZE = 8
    SYNC_BYTE = 0xAA
    TAIL_1 = 0x0D
    TAIL_2 = 0x0A

    try:
        while True:
            if ser.in_waiting > 0:
                data = ser.read(ser.in_waiting)
                buffer.extend(data)

            while len(buffer) >= PACKET_SIZE:
                # Поиск синхробайта
                idx = buffer.find(SYNC_BYTE)
                if idx == -1:
                    buffer.clear()
                    break
                
                # Удаление мусора до синхробайта
                if idx > 0:
                    del buffer[:idx]

                if len(buffer) < PACKET_SIZE:
                    break # Ожидание остальных байтов

                # Проверка хвоста пакета
                if buffer[6] != TAIL_1 or buffer[7] != TAIL_2:
                    del buffer[0]
                    continue

                # Извлечение payload и проверка CRC
                payload = buffer[:4]
                recv_crc = (buffer[4] << 8) | buffer[5]
                calc_crc = calculate_crc16(payload)

                if calc_crc == recv_crc:
                    left_pct = payload[1]
                    right_pct = payload[2]
                    flags = payload[3]
                    
                    flags_str = decode_flags(flags)
                    timestamp = time.strftime('%H:%M:%S')
                    
                    print(f"[{timestamp}] VALID | L: {left_pct:3d}% | R: {right_pct:3d}% | Flags: 0x{flags:02X} ({flags_str})")
                    
                    del buffer[:PACKET_SIZE]
                else:
                    print(f"[WARN] CRC Mismatch! Calc: 0x{calc_crc:04X}, Recv: 0x{recv_crc:04X}")
                    del buffer[0]

            time.sleep(0.01) # Снижение нагрузки на CPU

    except KeyboardInterrupt:
        print("\n[INFO] Stopping receiver...")
    finally:
        ser.close()

if __name__ == '__main__':
    main()