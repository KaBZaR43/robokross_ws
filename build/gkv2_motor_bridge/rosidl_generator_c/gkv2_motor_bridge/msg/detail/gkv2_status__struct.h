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
  * Согласно ЛМАП.402131.009Д1 п. 7.7.8.3 (ZED-F9P) и п. 7.5 (alg_state_status)
 */
typedef struct gkv2_motor_bridge__msg__GKV2Status
{
  /// Слово состояния ГНСС приёмника (gps_state_status, ID 72)
  uint32_t gps_state_status;
  /// Бит 0: годность даты
  bool gnss_date_valid;
  /// Бит 1: годность времени
  bool gnss_time_valid;
  /// Бит 2: временная неоднозначность решена
  bool gnss_ambiguity_resolved;
  /// Бит 16: годность координат, DOP и оценок точности
  bool gnss_coords_valid;
  /// Бит 17: применяются дифференциальные поправки
  bool gnss_diff_corrections;
  /// Биты 8-15: 0=нет, 2=2D, 3=3D, 5=time
  uint8_t gnss_fix_type;
  /// Биты 22-23: 0=нет, 1=float, 2=fixed
  uint8_t rtk_status;
  /// Слово состояния ровера (gps_rel_status, ID 29) — для двух антенн
  uint32_t gps_rel_status;
  /// Бит 0: годность навигационного решения
  bool rel_nav_valid;
  /// Бит 1: диф. поправки применены
  bool rel_diff_applied;
  /// Бит 2: годность точности относительных координат
  bool rel_coords_valid;
  /// Биты 3-4: 0=не решена, 1=diff, 2=fixed
  uint8_t rel_ambiguity_status;
  /// Бит 5: режим вычисления курса по двум антеннам
  bool rel_heading_mode;
  /// Бит 8: годность вычисления курса
  bool rel_heading_valid;
  /// Состояние навигационного алгоритма (alg_state_status, ID 96)
  uint32_t alg_state_status;
  /// Биты 7-0: этап (0=сброс, 1-2=поиск, 10=ожидание курса, 30=преднавигация, 50=полная навигация)
  uint8_t alg_stage;
  /// Биты 15-8: тип коррекции (0=нет, 1=по скорости ГНСС, 3=по положению и скорости, 18=по курсу ГНСС)
  uint8_t alg_correction;
  /// Биты 31-16: ошибки алгоритма
  uint16_t alg_fails;
  /// stage == 50 && fails == 0
  bool alg_navigation_ready;
  /// Количество спутников (ID 79)
  uint16_t gps_num_satellites;
  /// СКО координат от ГНСС (ID 85-87), метры
  /// СКО по оси X (север)
  float gnss_sig_lat;
  /// СКО по оси Y (восток)
  float gnss_sig_lon;
  /// СКО по оси Z (вниз)
  float gnss_sig_alt;
  /// Дисперсии ошибки навигационного алгоритма (ID 98-106)
  /// Дисперсия ошибки положения X, м²
  float alg_var_x;
  /// Дисперсия ошибки положения Y, м²
  float alg_var_y;
  /// Дисперсия ошибки положения Z, м²
  float alg_var_z;
  /// Дисперсия ошибки скорости X, (м/с)²
  float alg_var_vx;
  /// Дисперсия ошибки скорости Y, (м/с)²
  float alg_var_vy;
  /// Дисперсия ошибки скорости Z, (м/с)²
  float alg_var_vz;
  /// Дисперсия ошибки курса, рад²
  float alg_var_psi;
  /// Дисперсия ошибки тангажа, рад²
  float alg_var_theta;
  /// Дисперсия ошибки крена, рад²
  float alg_var_phi;
  /// Двухантенное решение (ID 13-14)
  /// Курс между антеннами, рад
  float gps_rel_heading;
  /// Расстояние между антеннами, м
  float gps_rel_length;
  /// rel_heading_valid && rel_heading_mode
  bool heading_from_dual_antenna;
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
