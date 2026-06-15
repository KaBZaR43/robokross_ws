// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/navigation_status.h"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__STRUCT_H_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'MODE_GNSS'.
enum
{
  gkv2_motor_bridge__msg__NavigationStatus__MODE_GNSS = 0
};

/// Constant 'MODE_ODOMETRY'.
enum
{
  gkv2_motor_bridge__msg__NavigationStatus__MODE_ODOMETRY = 1
};

/// Constant 'MODE_FUSION'.
enum
{
  gkv2_motor_bridge__msg__NavigationStatus__MODE_FUSION = 2
};

// Include directives for member types
// Member 'status_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/NavigationStatus in the package gkv2_motor_bridge.
/**
  * Статус навигационной системы
 */
typedef struct gkv2_motor_bridge__msg__NavigationStatus
{
  /// Текущий режим навигации (0=ГНСС, 1=Одометрия, 2=Слияние)
  uint8_t current_mode;
  /// ГНСС доступен и имеет хорошее качество
  bool gnss_available;
  /// RTK Fixed (сантиметровая точность)
  bool rtk_fixed;
  /// Количество спутников ГНСС
  uint16_t gnss_satellites;
  /// Качество ГНСС (0.0-1.0)
  float gnss_quality;
  /// Накопленная ошибка одометрии (метры)
  float odometry_drift;
  /// Время с последней хорошей ГНСС позиции (секунды)
  float time_since_gnss;
  /// Текстовое описание статуса
  rosidl_runtime_c__String status_message;
} gkv2_motor_bridge__msg__NavigationStatus;

// Struct for a sequence of gkv2_motor_bridge__msg__NavigationStatus.
typedef struct gkv2_motor_bridge__msg__NavigationStatus__Sequence
{
  gkv2_motor_bridge__msg__NavigationStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gkv2_motor_bridge__msg__NavigationStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__STRUCT_H_
