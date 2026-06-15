// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice
#include "gkv2_motor_bridge/msg/detail/gkv2_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "gkv2_motor_bridge/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__struct.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GKV2Status__ros_msg_type = gkv2_motor_bridge__msg__GKV2Status;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_serialize_gkv2_motor_bridge__msg__GKV2Status(
  const gkv2_motor_bridge__msg__GKV2Status * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: gps_state_status
  {
    cdr << ros_message->gps_state_status;
  }

  // Field name: gps_num_satellites
  {
    cdr << ros_message->gps_num_satellites;
  }

  // Field name: alg_state_status
  {
    cdr << ros_message->alg_state_status;
  }

  // Field name: rtk_fixed
  {
    cdr << (ros_message->rtk_fixed ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_deserialize_gkv2_motor_bridge__msg__GKV2Status(
  eprosima::fastcdr::Cdr & cdr,
  gkv2_motor_bridge__msg__GKV2Status * ros_message)
{
  // Field name: gps_state_status
  {
    cdr >> ros_message->gps_state_status;
  }

  // Field name: gps_num_satellites
  {
    cdr >> ros_message->gps_num_satellites;
  }

  // Field name: alg_state_status
  {
    cdr >> ros_message->alg_state_status;
  }

  // Field name: rtk_fixed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->rtk_fixed = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t get_serialized_size_gkv2_motor_bridge__msg__GKV2Status(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GKV2Status__ros_msg_type * ros_message = static_cast<const _GKV2Status__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: gps_state_status
  {
    size_t item_size = sizeof(ros_message->gps_state_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gps_num_satellites
  {
    size_t item_size = sizeof(ros_message->gps_num_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: alg_state_status
  {
    size_t item_size = sizeof(ros_message->alg_state_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rtk_fixed
  {
    size_t item_size = sizeof(ros_message->rtk_fixed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t max_serialized_size_gkv2_motor_bridge__msg__GKV2Status(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: gps_state_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: gps_num_satellites
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: alg_state_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rtk_fixed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gkv2_motor_bridge__msg__GKV2Status;
    is_plain =
      (
      offsetof(DataType, rtk_fixed) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_serialize_key_gkv2_motor_bridge__msg__GKV2Status(
  const gkv2_motor_bridge__msg__GKV2Status * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: gps_state_status
  {
    cdr << ros_message->gps_state_status;
  }

  // Field name: gps_num_satellites
  {
    cdr << ros_message->gps_num_satellites;
  }

  // Field name: alg_state_status
  {
    cdr << ros_message->alg_state_status;
  }

  // Field name: rtk_fixed
  {
    cdr << (ros_message->rtk_fixed ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t get_serialized_size_key_gkv2_motor_bridge__msg__GKV2Status(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GKV2Status__ros_msg_type * ros_message = static_cast<const _GKV2Status__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: gps_state_status
  {
    size_t item_size = sizeof(ros_message->gps_state_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gps_num_satellites
  {
    size_t item_size = sizeof(ros_message->gps_num_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: alg_state_status
  {
    size_t item_size = sizeof(ros_message->alg_state_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rtk_fixed
  {
    size_t item_size = sizeof(ros_message->rtk_fixed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t max_serialized_size_key_gkv2_motor_bridge__msg__GKV2Status(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: gps_state_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: gps_num_satellites
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: alg_state_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rtk_fixed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gkv2_motor_bridge__msg__GKV2Status;
    is_plain =
      (
      offsetof(DataType, rtk_fixed) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GKV2Status__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const gkv2_motor_bridge__msg__GKV2Status * ros_message = static_cast<const gkv2_motor_bridge__msg__GKV2Status *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_gkv2_motor_bridge__msg__GKV2Status(ros_message, cdr);
}

static bool _GKV2Status__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  gkv2_motor_bridge__msg__GKV2Status * ros_message = static_cast<gkv2_motor_bridge__msg__GKV2Status *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_gkv2_motor_bridge__msg__GKV2Status(cdr, ros_message);
}

static uint32_t _GKV2Status__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gkv2_motor_bridge__msg__GKV2Status(
      untyped_ros_message, 0));
}

static size_t _GKV2Status__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gkv2_motor_bridge__msg__GKV2Status(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GKV2Status = {
  "gkv2_motor_bridge::msg",
  "GKV2Status",
  _GKV2Status__cdr_serialize,
  _GKV2Status__cdr_deserialize,
  _GKV2Status__get_serialized_size,
  _GKV2Status__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GKV2Status__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GKV2Status,
  get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_hash,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_description,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gkv2_motor_bridge, msg, GKV2Status)() {
  return &_GKV2Status__type_support;
}

#if defined(__cplusplus)
}
#endif
