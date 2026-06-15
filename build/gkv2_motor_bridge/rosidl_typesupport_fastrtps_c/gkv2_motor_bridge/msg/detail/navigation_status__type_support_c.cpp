// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice
#include "gkv2_motor_bridge/msg/detail/navigation_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "gkv2_motor_bridge/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gkv2_motor_bridge/msg/detail/navigation_status__struct.h"
#include "gkv2_motor_bridge/msg/detail/navigation_status__functions.h"
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

#include "rosidl_runtime_c/string.h"  // status_message
#include "rosidl_runtime_c/string_functions.h"  // status_message

// forward declare type support functions


using _NavigationStatus__ros_msg_type = gkv2_motor_bridge__msg__NavigationStatus;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_serialize_gkv2_motor_bridge__msg__NavigationStatus(
  const gkv2_motor_bridge__msg__NavigationStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: current_mode
  {
    cdr << ros_message->current_mode;
  }

  // Field name: gnss_available
  {
    cdr << (ros_message->gnss_available ? true : false);
  }

  // Field name: rtk_fixed
  {
    cdr << (ros_message->rtk_fixed ? true : false);
  }

  // Field name: gnss_satellites
  {
    cdr << ros_message->gnss_satellites;
  }

  // Field name: gnss_quality
  {
    cdr << ros_message->gnss_quality;
  }

  // Field name: odometry_drift
  {
    cdr << ros_message->odometry_drift;
  }

  // Field name: time_since_gnss
  {
    cdr << ros_message->time_since_gnss;
  }

  // Field name: status_message
  {
    const rosidl_runtime_c__String * str = &ros_message->status_message;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_deserialize_gkv2_motor_bridge__msg__NavigationStatus(
  eprosima::fastcdr::Cdr & cdr,
  gkv2_motor_bridge__msg__NavigationStatus * ros_message)
{
  // Field name: current_mode
  {
    cdr >> ros_message->current_mode;
  }

  // Field name: gnss_available
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->gnss_available = tmp ? true : false;
  }

  // Field name: rtk_fixed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->rtk_fixed = tmp ? true : false;
  }

  // Field name: gnss_satellites
  {
    cdr >> ros_message->gnss_satellites;
  }

  // Field name: gnss_quality
  {
    cdr >> ros_message->gnss_quality;
  }

  // Field name: odometry_drift
  {
    cdr >> ros_message->odometry_drift;
  }

  // Field name: time_since_gnss
  {
    cdr >> ros_message->time_since_gnss;
  }

  // Field name: status_message
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->status_message.data) {
      rosidl_runtime_c__String__init(&ros_message->status_message);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->status_message,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'status_message'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t get_serialized_size_gkv2_motor_bridge__msg__NavigationStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavigationStatus__ros_msg_type * ros_message = static_cast<const _NavigationStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: current_mode
  {
    size_t item_size = sizeof(ros_message->current_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gnss_available
  {
    size_t item_size = sizeof(ros_message->gnss_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rtk_fixed
  {
    size_t item_size = sizeof(ros_message->rtk_fixed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gnss_satellites
  {
    size_t item_size = sizeof(ros_message->gnss_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gnss_quality
  {
    size_t item_size = sizeof(ros_message->gnss_quality);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: odometry_drift
  {
    size_t item_size = sizeof(ros_message->odometry_drift);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: time_since_gnss
  {
    size_t item_size = sizeof(ros_message->time_since_gnss);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: status_message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->status_message.size + 1);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t max_serialized_size_gkv2_motor_bridge__msg__NavigationStatus(
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

  // Field name: current_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gnss_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: rtk_fixed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gnss_satellites
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: gnss_quality
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: odometry_drift
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: time_since_gnss
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: status_message
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gkv2_motor_bridge__msg__NavigationStatus;
    is_plain =
      (
      offsetof(DataType, status_message) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_serialize_key_gkv2_motor_bridge__msg__NavigationStatus(
  const gkv2_motor_bridge__msg__NavigationStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: current_mode
  {
    cdr << ros_message->current_mode;
  }

  // Field name: gnss_available
  {
    cdr << (ros_message->gnss_available ? true : false);
  }

  // Field name: rtk_fixed
  {
    cdr << (ros_message->rtk_fixed ? true : false);
  }

  // Field name: gnss_satellites
  {
    cdr << ros_message->gnss_satellites;
  }

  // Field name: gnss_quality
  {
    cdr << ros_message->gnss_quality;
  }

  // Field name: odometry_drift
  {
    cdr << ros_message->odometry_drift;
  }

  // Field name: time_since_gnss
  {
    cdr << ros_message->time_since_gnss;
  }

  // Field name: status_message
  {
    const rosidl_runtime_c__String * str = &ros_message->status_message;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t get_serialized_size_key_gkv2_motor_bridge__msg__NavigationStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavigationStatus__ros_msg_type * ros_message = static_cast<const _NavigationStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: current_mode
  {
    size_t item_size = sizeof(ros_message->current_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gnss_available
  {
    size_t item_size = sizeof(ros_message->gnss_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rtk_fixed
  {
    size_t item_size = sizeof(ros_message->rtk_fixed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gnss_satellites
  {
    size_t item_size = sizeof(ros_message->gnss_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gnss_quality
  {
    size_t item_size = sizeof(ros_message->gnss_quality);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: odometry_drift
  {
    size_t item_size = sizeof(ros_message->odometry_drift);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: time_since_gnss
  {
    size_t item_size = sizeof(ros_message->time_since_gnss);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: status_message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->status_message.size + 1);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
size_t max_serialized_size_key_gkv2_motor_bridge__msg__NavigationStatus(
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
  // Field name: current_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gnss_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: rtk_fixed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gnss_satellites
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: gnss_quality
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: odometry_drift
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: time_since_gnss
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: status_message
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gkv2_motor_bridge__msg__NavigationStatus;
    is_plain =
      (
      offsetof(DataType, status_message) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _NavigationStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const gkv2_motor_bridge__msg__NavigationStatus * ros_message = static_cast<const gkv2_motor_bridge__msg__NavigationStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_gkv2_motor_bridge__msg__NavigationStatus(ros_message, cdr);
}

static bool _NavigationStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  gkv2_motor_bridge__msg__NavigationStatus * ros_message = static_cast<gkv2_motor_bridge__msg__NavigationStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_gkv2_motor_bridge__msg__NavigationStatus(cdr, ros_message);
}

static uint32_t _NavigationStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gkv2_motor_bridge__msg__NavigationStatus(
      untyped_ros_message, 0));
}

static size_t _NavigationStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gkv2_motor_bridge__msg__NavigationStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_NavigationStatus = {
  "gkv2_motor_bridge::msg",
  "NavigationStatus",
  _NavigationStatus__cdr_serialize,
  _NavigationStatus__cdr_deserialize,
  _NavigationStatus__get_serialized_size,
  _NavigationStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _NavigationStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NavigationStatus,
  get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__NavigationStatus__get_type_hash,
  &gkv2_motor_bridge__msg__NavigationStatus__get_type_description,
  &gkv2_motor_bridge__msg__NavigationStatus__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gkv2_motor_bridge, msg, NavigationStatus)() {
  return &_NavigationStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
