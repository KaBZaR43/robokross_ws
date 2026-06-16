# Статус конфигурации ГКВ2

# Общая информация
string device_name           # Название изделия
string serial_number         # Серийный номер
uint16 firmware_version      # Версия прошивки
uint8 algorithm_mode         # Текущий алгоритм (9 = навигация)

# Статус соединения
bool connection_ok           # Соединение с ГКВ2 установлено
bool data_ready              # Данные готовы (бит 11 статуса)
bool adc_overflow            # Переполнение очереди АЦП (бит 1)
bool adc_skip                # Пропуск данных АЦП (бит 2)
bool gyroscope_fail          # Отказ гироскопа (бит 4)
bool accelerometer_fail      # Отказ акселерометра (бит 5)

# Конфигурация наборного пакета
uint8 packet_param_count     # Количество параметров в наборном пакете
int32[] packet_param_ids     # ID параметров в наборном пакете
bool packet_structure_match  # Структура пакета соответствует ожидаемой

# Текстовое описание статуса
string status_message