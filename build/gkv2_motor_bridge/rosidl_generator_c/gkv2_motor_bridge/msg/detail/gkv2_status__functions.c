// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice
#include "gkv2_motor_bridge/msg/detail/gkv2_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
gkv2_motor_bridge__msg__GKV2Status__init(gkv2_motor_bridge__msg__GKV2Status * msg)
{
  if (!msg) {
    return false;
  }
  // gps_state_status
  // gps_num_satellites
  // alg_state_status
  // rtk_fixed
  return true;
}

void
gkv2_motor_bridge__msg__GKV2Status__fini(gkv2_motor_bridge__msg__GKV2Status * msg)
{
  if (!msg) {
    return;
  }
  // gps_state_status
  // gps_num_satellites
  // alg_state_status
  // rtk_fixed
}

bool
gkv2_motor_bridge__msg__GKV2Status__are_equal(const gkv2_motor_bridge__msg__GKV2Status * lhs, const gkv2_motor_bridge__msg__GKV2Status * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // gps_state_status
  if (lhs->gps_state_status != rhs->gps_state_status) {
    return false;
  }
  // gps_num_satellites
  if (lhs->gps_num_satellites != rhs->gps_num_satellites) {
    return false;
  }
  // alg_state_status
  if (lhs->alg_state_status != rhs->alg_state_status) {
    return false;
  }
  // rtk_fixed
  if (lhs->rtk_fixed != rhs->rtk_fixed) {
    return false;
  }
  return true;
}

bool
gkv2_motor_bridge__msg__GKV2Status__copy(
  const gkv2_motor_bridge__msg__GKV2Status * input,
  gkv2_motor_bridge__msg__GKV2Status * output)
{
  if (!input || !output) {
    return false;
  }
  // gps_state_status
  output->gps_state_status = input->gps_state_status;
  // gps_num_satellites
  output->gps_num_satellites = input->gps_num_satellites;
  // alg_state_status
  output->alg_state_status = input->alg_state_status;
  // rtk_fixed
  output->rtk_fixed = input->rtk_fixed;
  return true;
}

gkv2_motor_bridge__msg__GKV2Status *
gkv2_motor_bridge__msg__GKV2Status__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkv2_motor_bridge__msg__GKV2Status * msg = (gkv2_motor_bridge__msg__GKV2Status *)allocator.allocate(sizeof(gkv2_motor_bridge__msg__GKV2Status), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gkv2_motor_bridge__msg__GKV2Status));
  bool success = gkv2_motor_bridge__msg__GKV2Status__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gkv2_motor_bridge__msg__GKV2Status__destroy(gkv2_motor_bridge__msg__GKV2Status * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gkv2_motor_bridge__msg__GKV2Status__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gkv2_motor_bridge__msg__GKV2Status__Sequence__init(gkv2_motor_bridge__msg__GKV2Status__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkv2_motor_bridge__msg__GKV2Status * data = NULL;

  if (size) {
    data = (gkv2_motor_bridge__msg__GKV2Status *)allocator.zero_allocate(size, sizeof(gkv2_motor_bridge__msg__GKV2Status), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gkv2_motor_bridge__msg__GKV2Status__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gkv2_motor_bridge__msg__GKV2Status__fini(&data[i - 1]);
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
gkv2_motor_bridge__msg__GKV2Status__Sequence__fini(gkv2_motor_bridge__msg__GKV2Status__Sequence * array)
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
      gkv2_motor_bridge__msg__GKV2Status__fini(&array->data[i]);
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

gkv2_motor_bridge__msg__GKV2Status__Sequence *
gkv2_motor_bridge__msg__GKV2Status__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkv2_motor_bridge__msg__GKV2Status__Sequence * array = (gkv2_motor_bridge__msg__GKV2Status__Sequence *)allocator.allocate(sizeof(gkv2_motor_bridge__msg__GKV2Status__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gkv2_motor_bridge__msg__GKV2Status__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gkv2_motor_bridge__msg__GKV2Status__Sequence__destroy(gkv2_motor_bridge__msg__GKV2Status__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gkv2_motor_bridge__msg__GKV2Status__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gkv2_motor_bridge__msg__GKV2Status__Sequence__are_equal(const gkv2_motor_bridge__msg__GKV2Status__Sequence * lhs, const gkv2_motor_bridge__msg__GKV2Status__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gkv2_motor_bridge__msg__GKV2Status__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gkv2_motor_bridge__msg__GKV2Status__Sequence__copy(
  const gkv2_motor_bridge__msg__GKV2Status__Sequence * input,
  gkv2_motor_bridge__msg__GKV2Status__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gkv2_motor_bridge__msg__GKV2Status);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gkv2_motor_bridge__msg__GKV2Status * data =
      (gkv2_motor_bridge__msg__GKV2Status *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gkv2_motor_bridge__msg__GKV2Status__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gkv2_motor_bridge__msg__GKV2Status__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gkv2_motor_bridge__msg__GKV2Status__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
