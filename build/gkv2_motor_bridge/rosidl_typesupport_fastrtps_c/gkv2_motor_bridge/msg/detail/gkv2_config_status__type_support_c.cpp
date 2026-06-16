// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
// generated code does not contain a copyright notice
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "gkv2_motor_bridge/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__struct.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // packet_param_ids
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // packet_param_ids
#include "rosidl_runtime_c/string.h"  // device_name, serial_number, status_message
#include "rosidl_runtime_c/string_functions.h"  // device_name, serial_number, status_message

// forward declare type support functions


using _GKV2ConfigStatus__ros_msg_type = gkv2_motor_bridge__msg__GKV2ConfigStatus;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_serialize_gkv2_motor_bridge__msg__GKV2ConfigStatus(
  const gkv2_motor_bridge__msg__GKV2ConfigStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: device_name
  {
    const rosidl_runtime_c__String * str = &ros_message->device_name;
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

  // Field name: serial_number
  {
    const rosidl_runtime_c__String * str = &ros_message->serial_number;
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

  // Field name: firmware_version
  {
    cdr << ros_message->firmware_version;
  }

  // Field name: algorithm_mode
  {
    cdr << ros_message->algorithm_mode;
  }

  // Field name: connection_ok
  {
    cdr << (ros_message->connection_ok ? true : false);
  }

  // Field name: data_ready
  {
    cdr << (ros_message->data_ready ? true : false);
  }

  // Field name: adc_overflow
  {
    cdr << (ros_message->adc_overflow ? true : false);
  }

  // Field name: adc_skip
  {
    cdr << (ros_message->adc_skip ? true : false);
  }

  // Field name: gyroscope_fail
  {
    cdr << (ros_message->gyroscope_fail ? true : false);
  }

  // Field name: accelerometer_fail
  {
    cdr << (ros_message->accelerometer_fail ? true : false);
  }

  // Field name: packet_param_count
  {
    cdr << ros_message->packet_param_count;
  }

  // Field name: packet_param_ids
  {
    size_t size = ros_message->packet_param_ids.size;
    auto array_ptr = ros_message->packet_param_ids.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: packet_structure_match
  {
    cdr << (ros_message->packet_structure_match ? true : false);
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
bool cdr_deserialize_gkv2_motor_bridge__msg__GKV2ConfigStatus(
  eprosima::fastcdr::Cdr & cdr,
  gkv2_motor_bridge__msg__GKV2ConfigStatus * ros_message)
{
  // Field name: device_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->device_name.data) {
      rosidl_runtime_c__String__init(&ros_message->device_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->device_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'device_name'\n");
      return false;
    }
  }

  // Field name: serial_number
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->serial_number.data) {
      rosidl_runtime_c__String__init(&ros_message->serial_number);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->serial_number,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'serial_number'\n");
      return false;
    }
  }

  // Field name: firmware_version
  {
    cdr >> ros_message->firmware_version;
  }

  // Field name: algorithm_mode
  {
    cdr >> ros_message->algorithm_mode;
  }

  // Field name: connection_ok
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->connection_ok = tmp ? true : false;
  }

  // Field name: data_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->data_ready = tmp ? true : false;
  }

  // Field name: adc_overflow
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->adc_overflow = tmp ? true : false;
  }

  // Field name: adc_skip
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->adc_skip = tmp ? true : false;
  }

  // Field name: gyroscope_fail
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->gyroscope_fail = tmp ? true : false;
  }

  // Field name: accelerometer_fail
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->accelerometer_fail = tmp ? true : false;
  }

  // Field name: packet_param_count
  {
    cdr >> ros_message->packet_param_count;
  }

  // Field name: packet_param_ids
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->packet_param_ids.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->packet_param_ids);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->packet_param_ids, size)) {
      fprintf(stderr, "failed to create array for field 'packet_param_ids'");
      return false;
    }
    auto array_ptr = ros_message->packet_param_ids.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: packet_structure_match
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->packet_structure_match = tmp ? true : false;
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
size_t get_serialized_size_gkv2_motor_bridge__msg__GKV2ConfigStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GKV2ConfigStatus__ros_msg_type * ros_message = static_cast<const _GKV2ConfigStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: device_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->device_name.size + 1);

  // Field name: serial_number
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->serial_number.size + 1);

  // Field name: firmware_version
  {
    size_t item_size = sizeof(ros_message->firmware_version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: algorithm_mode
  {
    size_t item_size = sizeof(ros_message->algorithm_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: connection_ok
  {
    size_t item_size = sizeof(ros_message->connection_ok);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: data_ready
  {
    size_t item_size = sizeof(ros_message->data_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: adc_overflow
  {
    size_t item_size = sizeof(ros_message->adc_overflow);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: adc_skip
  {
    size_t item_size = sizeof(ros_message->adc_skip);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gyroscope_fail
  {
    size_t item_size = sizeof(ros_message->gyroscope_fail);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: accelerometer_fail
  {
    size_t item_size = sizeof(ros_message->accelerometer_fail);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: packet_param_count
  {
    size_t item_size = sizeof(ros_message->packet_param_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: packet_param_ids
  {
    size_t array_size = ros_message->packet_param_ids.size;
    auto array_ptr = ros_message->packet_param_ids.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: packet_structure_match
  {
    size_t item_size = sizeof(ros_message->packet_structure_match);
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
size_t max_serialized_size_gkv2_motor_bridge__msg__GKV2ConfigStatus(
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

  // Field name: device_name
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

  // Field name: serial_number
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

  // Field name: firmware_version
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: algorithm_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: connection_ok
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: data_ready
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: adc_overflow
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: adc_skip
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gyroscope_fail
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: accelerometer_fail
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: packet_param_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: packet_param_ids
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: packet_structure_match
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
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
    using DataType = gkv2_motor_bridge__msg__GKV2ConfigStatus;
    is_plain =
      (
      offsetof(DataType, status_message) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gkv2_motor_bridge
bool cdr_serialize_key_gkv2_motor_bridge__msg__GKV2ConfigStatus(
  const gkv2_motor_bridge__msg__GKV2ConfigStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: device_name
  {
    const rosidl_runtime_c__String * str = &ros_message->device_name;
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

  // Field name: serial_number
  {
    const rosidl_runtime_c__String * str = &ros_message->serial_number;
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

  // Field name: firmware_version
  {
    cdr << ros_message->firmware_version;
  }

  // Field name: algorithm_mode
  {
    cdr << ros_message->algorithm_mode;
  }

  // Field name: connection_ok
  {
    cdr << (ros_message->connection_ok ? true : false);
  }

  // Field name: data_ready
  {
    cdr << (ros_message->data_ready ? true : false);
  }

  // Field name: adc_overflow
  {
    cdr << (ros_message->adc_overflow ? true : false);
  }

  // Field name: adc_skip
  {
    cdr << (ros_message->adc_skip ? true : false);
  }

  // Field name: gyroscope_fail
  {
    cdr << (ros_message->gyroscope_fail ? true : false);
  }

  // Field name: accelerometer_fail
  {
    cdr << (ros_message->accelerometer_fail ? true : false);
  }

  // Field name: packet_param_count
  {
    cdr << ros_message->packet_param_count;
  }

  // Field name: packet_param_ids
  {
    size_t size = ros_message->packet_param_ids.size;
    auto array_ptr = ros_message->packet_param_ids.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: packet_structure_match
  {
    cdr << (ros_message->packet_structure_match ? true : false);
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
size_t get_serialized_size_key_gkv2_motor_bridge__msg__GKV2ConfigStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GKV2ConfigStatus__ros_msg_type * ros_message = static_cast<const _GKV2ConfigStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: device_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->device_name.size + 1);

  // Field name: serial_number
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->serial_number.size + 1);

  // Field name: firmware_version
  {
    size_t item_size = sizeof(ros_message->firmware_version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: algorithm_mode
  {
    size_t item_size = sizeof(ros_message->algorithm_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: connection_ok
  {
    size_t item_size = sizeof(ros_message->connection_ok);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: data_ready
  {
    size_t item_size = sizeof(ros_message->data_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: adc_overflow
  {
    size_t item_size = sizeof(ros_message->adc_overflow);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: adc_skip
  {
    size_t item_size = sizeof(ros_message->adc_skip);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gyroscope_fail
  {
    size_t item_size = sizeof(ros_message->gyroscope_fail);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: accelerometer_fail
  {
    size_t item_size = sizeof(ros_message->accelerometer_fail);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: packet_param_count
  {
    size_t item_size = sizeof(ros_message->packet_param_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: packet_param_ids
  {
    size_t array_size = ros_message->packet_param_ids.size;
    auto array_ptr = ros_message->packet_param_ids.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: packet_structure_match
  {
    size_t item_size = sizeof(ros_message->packet_structure_match);
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
size_t max_serialized_size_key_gkv2_motor_bridge__msg__GKV2ConfigStatus(
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
  // Field name: device_name
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

  // Field name: serial_number
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

  // Field name: firmware_version
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: algorithm_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: connection_ok
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: data_ready
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: adc_overflow
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: adc_skip
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gyroscope_fail
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: accelerometer_fail
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: packet_param_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: packet_param_ids
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: packet_structure_match
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
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
    using DataType = gkv2_motor_bridge__msg__GKV2ConfigStatus;
    is_plain =
      (
      offsetof(DataType, status_message) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GKV2ConfigStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const gkv2_motor_bridge__msg__GKV2ConfigStatus * ros_message = static_cast<const gkv2_motor_bridge__msg__GKV2ConfigStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_gkv2_motor_bridge__msg__GKV2ConfigStatus(ros_message, cdr);
}

static bool _GKV2ConfigStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  gkv2_motor_bridge__msg__GKV2ConfigStatus * ros_message = static_cast<gkv2_motor_bridge__msg__GKV2ConfigStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_gkv2_motor_bridge__msg__GKV2ConfigStatus(cdr, ros_message);
}

static uint32_t _GKV2ConfigStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gkv2_motor_bridge__msg__GKV2ConfigStatus(
      untyped_ros_message, 0));
}

static size_t _GKV2ConfigStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gkv2_motor_bridge__msg__GKV2ConfigStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GKV2ConfigStatus = {
  "gkv2_motor_bridge::msg",
  "GKV2ConfigStatus",
  _GKV2ConfigStatus__cdr_serialize,
  _GKV2ConfigStatus__cdr_deserialize,
  _GKV2ConfigStatus__get_serialized_size,
  _GKV2ConfigStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GKV2ConfigStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GKV2ConfigStatus,
  get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_hash,
  &gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_description,
  &gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gkv2_motor_bridge, msg, GKV2ConfigStatus)() {
  return &_GKV2ConfigStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
