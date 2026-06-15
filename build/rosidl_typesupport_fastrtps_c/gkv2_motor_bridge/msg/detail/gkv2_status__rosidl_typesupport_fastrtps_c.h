// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice
#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "gkv2_motor_bridge/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_serialize_gkv2_motor_bridge__msg__GKV2Status(
  const gkv2_motor_bridge__msg__GKV2Status * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_deserialize_gkv2_motor_bridge__msg__GKV2Status(
  eprosima::fastcdr::Cdr &,
  gkv2_motor_bridge__msg__GKV2Status * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t get_serialized_size_gkv2_motor_bridge__msg__GKV2Status(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t max_serialized_size_gkv2_motor_bridge__msg__GKV2Status(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_serialize_key_gkv2_motor_bridge__msg__GKV2Status(
  const gkv2_motor_bridge__msg__GKV2Status * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t get_serialized_size_key_gkv2_motor_bridge__msg__GKV2Status(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t max_serialized_size_key_gkv2_motor_bridge__msg__GKV2Status(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gkv2_motor_bridge, msg, GKV2Status)();

#ifdef __cplusplus
}
#endif

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
