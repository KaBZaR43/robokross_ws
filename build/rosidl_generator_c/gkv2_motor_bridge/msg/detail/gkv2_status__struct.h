// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/gkv2_status.h"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__STRUCT_H_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/GKV2Status in the package gkv2_motor_bridge.
/**
  * Статус навигационного решения ГКВ2
 */
typedef struct gkv2_motor_bridge__msg__GKV2Status
{
  /// Слово состояния ГНСС приёмника (битовое поле)
  uint32_t gps_state_status;
  /// Количество спутников в решении
  uint16_t gps_num_satellites;
  /// Состояние навигационного алгоритма (0-50: сброс, поиск, навигация)
  float alg_state_status;
  /// RTK Fixed (сантиметровая точность)
  bool rtk_fixed;
} gkv2_motor_bridge__msg__GKV2Status;

// Struct for a sequence of gkv2_motor_bridge__msg__GKV2Status.
typedef struct gkv2_motor_bridge__msg__GKV2Status__Sequence
{
  gkv2_motor_bridge__msg__GKV2Status * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gkv2_motor_bridge__msg__GKV2Status__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__STRUCT_H_
