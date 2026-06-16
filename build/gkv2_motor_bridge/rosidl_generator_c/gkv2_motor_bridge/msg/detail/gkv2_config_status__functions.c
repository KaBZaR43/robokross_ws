// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
// generated code does not contain a copyright notice
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `device_name`
// Member `serial_number`
// Member `status_message`
#include "rosidl_runtime_c/string_functions.h"
// Member `packet_param_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
gkv2_motor_bridge__msg__GKV2ConfigStatus__init(gkv2_motor_bridge__msg__GKV2ConfigStatus * msg)
{
  if (!msg) {
    return false;
  }
  // device_name
  if (!rosidl_runtime_c__String__init(&msg->device_name)) {
    gkv2_motor_bridge__msg__GKV2ConfigStatus__fini(msg);
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__init(&msg->serial_number)) {
    gkv2_motor_bridge__msg__GKV2ConfigStatus__fini(msg);
    return false;
  }
  // firmware_version
  // algorithm_mode
  // connection_ok
  // data_ready
  // adc_overflow
  // adc_skip
  // gyroscope_fail
  // accelerometer_fail
  // packet_param_count
  // packet_param_ids
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->packet_param_ids, 0)) {
    gkv2_motor_bridge__msg__GKV2ConfigStatus__fini(msg);
    return false;
  }
  // packet_structure_match
  // status_message
  if (!rosidl_runtime_c__String__init(&msg->status_message)) {
    gkv2_motor_bridge__msg__GKV2ConfigStatus__fini(msg);
    return false;
  }
  return true;
}

void
gkv2_motor_bridge__msg__GKV2ConfigStatus__fini(gkv2_motor_bridge__msg__GKV2ConfigStatus * msg)
{
  if (!msg) {
    return;
  }
  // device_name
  rosidl_runtime_c__String__fini(&msg->device_name);
  // serial_number
  rosidl_runtime_c__String__fini(&msg->serial_number);
  // firmware_version
  // algorithm_mode
  // connection_ok
  // data_ready
  // adc_overflow
  // adc_skip
  // gyroscope_fail
  // accelerometer_fail
  // packet_param_count
  // packet_param_ids
  rosidl_runtime_c__int32__Sequence__fini(&msg->packet_param_ids);
  // packet_structure_match
  // status_message
  rosidl_runtime_c__String__fini(&msg->status_message);
}

bool
gkv2_motor_bridge__msg__GKV2ConfigStatus__are_equal(const gkv2_motor_bridge__msg__GKV2ConfigStatus * lhs, const gkv2_motor_bridge__msg__GKV2ConfigStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // device_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_name), &(rhs->device_name)))
  {
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->serial_number), &(rhs->serial_number)))
  {
    return false;
  }
  // firmware_version
  if (lhs->firmware_version != rhs->firmware_version) {
    return false;
  }
  // algorithm_mode
  if (lhs->algorithm_mode != rhs->algorithm_mode) {
    return false;
  }
  // connection_ok
  if (lhs->connection_ok != rhs->connection_ok) {
    return false;
  }
  // data_ready
  if (lhs->data_ready != rhs->data_ready) {
    return false;
  }
  // adc_overflow
  if (lhs->adc_overflow != rhs->adc_overflow) {
    return false;
  }
  // adc_skip
  if (lhs->adc_skip != rhs->adc_skip) {
    return false;
  }
  // gyroscope_fail
  if (lhs->gyroscope_fail != rhs->gyroscope_fail) {
    return false;
  }
  // accelerometer_fail
  if (lhs->accelerometer_fail != rhs->accelerometer_fail) {
    return false;
  }
  // packet_param_count
  if (lhs->packet_param_count != rhs->packet_param_count) {
    return false;
  }
  // packet_param_ids
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->packet_param_ids), &(rhs->packet_param_ids)))
  {
    return false;
  }
  // packet_structure_match
  if (lhs->packet_structure_match != rhs->packet_structure_match) {
    return false;
  }
  // status_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status_message), &(rhs->status_message)))
  {
    return false;
  }
  return true;
}

bool
gkv2_motor_bridge__msg__GKV2ConfigStatus__copy(
  const gkv2_motor_bridge__msg__GKV2ConfigStatus * input,
  gkv2_motor_bridge__msg__GKV2ConfigStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // device_name
  if (!rosidl_runtime_c__String__copy(
      &(input->device_name), &(output->device_name)))
  {
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__copy(
      &(input->serial_number), &(output->serial_number)))
  {
    return false;
  }
  // firmware_version
  output->firmware_version = input->firmware_version;
  // algorithm_mode
  output->algorithm_mode = input->algorithm_mode;
  // connection_ok
  output->connection_ok = input->connection_ok;
  // data_ready
  output->data_ready = input->data_ready;
  // adc_overflow
  output->adc_overflow = input->adc_overflow;
  // adc_skip
  output->adc_skip = input->adc_skip;
  // gyroscope_fail
  output->gyroscope_fail = input->gyroscope_fail;
  // accelerometer_fail
  output->accelerometer_fail = input->accelerometer_fail;
  // packet_param_count
  output->packet_param_count = input->packet_param_count;
  // packet_param_ids
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->packet_param_ids), &(output->packet_param_ids)))
  {
    return false;
  }
  // packet_structure_match
  output->packet_structure_match = input->packet_structure_match;
  // status_message
  if (!rosidl_runtime_c__String__copy(
      &(input->status_message), &(output->status_message)))
  {
    return false;
  }
  return true;
}

gkv2_motor_bridge__msg__GKV2ConfigStatus *
gkv2_motor_bridge__msg__GKV2ConfigStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkv2_motor_bridge__msg__GKV2ConfigStatus * msg = (gkv2_motor_bridge__msg__GKV2ConfigStatus *)allocator.allocate(sizeof(gkv2_motor_bridge__msg__GKV2ConfigStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gkv2_motor_bridge__msg__GKV2ConfigStatus));
  bool success = gkv2_motor_bridge__msg__GKV2ConfigStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gkv2_motor_bridge__msg__GKV2ConfigStatus__destroy(gkv2_motor_bridge__msg__GKV2ConfigStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gkv2_motor_bridge__msg__GKV2ConfigStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__init(gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkv2_motor_bridge__msg__GKV2ConfigStatus * data = NULL;

  if (size) {
    data = (gkv2_motor_bridge__msg__GKV2ConfigStatus *)allocator.zero_allocate(size, sizeof(gkv2_motor_bridge__msg__GKV2ConfigStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gkv2_motor_bridge__msg__GKV2ConfigStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gkv2_motor_bridge__msg__GKV2ConfigStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__fini(gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      gkv2_motor_bridge__msg__GKV2ConfigStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence *
gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence * array = (gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence *)allocator.allocate(sizeof(gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__destroy(gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__are_equal(const gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence * lhs, const gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gkv2_motor_bridge__msg__GKV2ConfigStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__copy(
  const gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence * input,
  gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gkv2_motor_bridge__msg__GKV2ConfigStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gkv2_motor_bridge__msg__GKV2ConfigStatus * data =
      (gkv2_motor_bridge__msg__GKV2ConfigStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gkv2_motor_bridge__msg__GKV2ConfigStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gkv2_motor_bridge__msg__GKV2ConfigStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gkv2_motor_bridge__msg__GKV2ConfigStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
