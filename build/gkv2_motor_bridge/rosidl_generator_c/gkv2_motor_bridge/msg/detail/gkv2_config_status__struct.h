// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/gkv2_config_status.h"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__STRUCT_H_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'device_name'
// Member 'serial_number'
// Member 'status_message'
#include "rosidl_runtime_c/string.h"
// Member 'packet_param_ids'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/GKV2ConfigStatus in the package gkv2_motor_bridge.
/**
  * Статус конфигурации ГКВ2
 */
typedef struct gkv2_motor_bridge__msg__GKV2ConfigStatus
{
  /// Общая информация
  /// Название изделия
  rosidl_runtime_c__String device_name;
  /// Серийный номер
  rosidl_runtime_c__String serial_number;
  /// Версия прошивки
  uint16_t firmware_version;
  /// Текущий алгоритм (9 = навигация)
  uint8_t algorithm_mode;
  /// Статус соединения
  /// Соединение с ГКВ2 установлено
  bool connection_ok;
  /// Данные готовы (бит 11 статуса)
  bool data_ready;
  /// Переполнение очереди АЦП (бит 1)
  bool adc_overflow;
  /// Пропуск данных АЦП (бит 2)
  bool adc_skip;
  /// Отказ гироскопа (бит 4)
  bool gyroscope_fail;
  /// Отказ акселерометра (бит 5)
  bool accelerometer_fail;
  /// Конфигурация наборного пакета
  /// Количество параметров в наборном пакете
  uint8_t packet_param_count;
  /// ID параметров в наборном пакете
  rosidl_runtime_c__int32__Sequence packet_param_ids;
  /// Структура пакета соответствует ожидаемой
  bool packet_structure_match;
  /// Текстовое описание статуса
  rosidl_runtime_c__String status_message;
} gkv2_motor_bridge__msg__GKV2ConfigStatus;

// Struct for a sequence of gkv2_motor_bridge__msg__GKV2ConfigStatus.
typedef struct gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence
{
  gkv2_motor_bridge__msg__GKV2ConfigStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__STRUCT_H_
