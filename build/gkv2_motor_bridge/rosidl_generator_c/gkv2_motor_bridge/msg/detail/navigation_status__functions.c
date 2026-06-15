// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice
#include "gkv2_motor_bridge/msg/detail/navigation_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `status_message`
#include "rosidl_runtime_c/string_functions.h"

bool
gkv2_motor_bridge__msg__NavigationStatus__init(gkv2_motor_bridge__msg__NavigationStatus * msg)
{
  if (!msg) {
    return false;
  }
  // current_mode
  // gnss_available
  // rtk_fixed
  // gnss_satellites
  // gnss_quality
  // odometry_drift
  // time_since_gnss
  // status_message
  if (!rosidl_runtime_c__String__init(&msg->status_message)) {
    gkv2_motor_bridge__msg__NavigationStatus__fini(msg);
    return false;
  }
  return true;
}

void
gkv2_motor_bridge__msg__NavigationStatus__fini(gkv2_motor_bridge__msg__NavigationStatus * msg)
{
  if (!msg) {
    return;
  }
  // current_mode
  // gnss_available
  // rtk_fixed
  // gnss_satellites
  // gnss_quality
  // odometry_drift
  // time_since_gnss
  // status_message
  rosidl_runtime_c__String__fini(&msg->status_message);
}

bool
gkv2_motor_bridge__msg__NavigationStatus__are_equal(const gkv2_motor_bridge__msg__NavigationStatus * lhs, const gkv2_motor_bridge__msg__NavigationStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_mode
  if (lhs->current_mode != rhs->current_mode) {
    return false;
  }
  // gnss_available
  if (lhs->gnss_available != rhs->gnss_available) {
    return false;
  }
  // rtk_fixed
  if (lhs->rtk_fixed != rhs->rtk_fixed) {
    return false;
  }
  // gnss_satellites
  if (lhs->gnss_satellites != rhs->gnss_satellites) {
    return false;
  }
  // gnss_quality
  if (lhs->gnss_quality != rhs->gnss_quality) {
    return false;
  }
  // odometry_drift
  if (lhs->odometry_drift != rhs->odometry_drift) {
    return false;
  }
  // time_since_gnss
  if (lhs->time_since_gnss != rhs->time_since_gnss) {
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
gkv2_motor_bridge__msg__NavigationStatus__copy(
  const gkv2_motor_bridge__msg__NavigationStatus * input,
  gkv2_motor_bridge__msg__NavigationStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // current_mode
  output->current_mode = input->current_mode;
  // gnss_available
  output->gnss_available = input->gnss_available;
  // rtk_fixed
  output->rtk_fixed = input->rtk_fixed;
  // gnss_satellites
  output->gnss_satellites = input->gnss_satellites;
  // gnss_quality
  output->gnss_quality = input->gnss_quality;
  // odometry_drift
  output->odometry_drift = input->odometry_drift;
  // time_since_gnss
  output->time_since_gnss = input->time_since_gnss;
  // status_message
  if (!rosidl_runtime_c__String__copy(
      &(input->status_message), &(output->status_message)))
  {
    return false;
  }
  return true;
}

gkv2_motor_bridge__msg__NavigationStatus *
gkv2_motor_bridge__msg__NavigationStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkv2_motor_bridge__msg__NavigationStatus * msg = (gkv2_motor_bridge__msg__NavigationStatus *)allocator.allocate(sizeof(gkv2_motor_bridge__msg__NavigationStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gkv2_motor_bridge__msg__NavigationStatus));
  bool success = gkv2_motor_bridge__msg__NavigationStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gkv2_motor_bridge__msg__NavigationStatus__destroy(gkv2_motor_bridge__msg__NavigationStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gkv2_motor_bridge__msg__NavigationStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gkv2_motor_bridge__msg__NavigationStatus__Sequence__init(gkv2_motor_bridge__msg__NavigationStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkv2_motor_bridge__msg__NavigationStatus * data = NULL;

  if (size) {
    data = (gkv2_motor_bridge__msg__NavigationStatus *)allocator.zero_allocate(size, sizeof(gkv2_motor_bridge__msg__NavigationStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gkv2_motor_bridge__msg__NavigationStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gkv2_motor_bridge__msg__NavigationStatus__fini(&data[i - 1]);
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
gkv2_motor_bridge__msg__NavigationStatus__Sequence__fini(gkv2_motor_bridge__msg__NavigationStatus__Sequence * array)
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
      gkv2_motor_bridge__msg__NavigationStatus__fini(&array->data[i]);
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

gkv2_motor_bridge__msg__NavigationStatus__Sequence *
gkv2_motor_bridge__msg__NavigationStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gkv2_motor_bridge__msg__NavigationStatus__Sequence * array = (gkv2_motor_bridge__msg__NavigationStatus__Sequence *)allocator.allocate(sizeof(gkv2_motor_bridge__msg__NavigationStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gkv2_motor_bridge__msg__NavigationStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gkv2_motor_bridge__msg__NavigationStatus__Sequence__destroy(gkv2_motor_bridge__msg__NavigationStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gkv2_motor_bridge__msg__NavigationStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gkv2_motor_bridge__msg__NavigationStatus__Sequence__are_equal(const gkv2_motor_bridge__msg__NavigationStatus__Sequence * lhs, const gkv2_motor_bridge__msg__NavigationStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gkv2_motor_bridge__msg__NavigationStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gkv2_motor_bridge__msg__NavigationStatus__Sequence__copy(
  const gkv2_motor_bridge__msg__NavigationStatus__Sequence * input,
  gkv2_motor_bridge__msg__NavigationStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gkv2_motor_bridge__msg__NavigationStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gkv2_motor_bridge__msg__NavigationStatus * data =
      (gkv2_motor_bridge__msg__NavigationStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gkv2_motor_bridge__msg__NavigationStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gkv2_motor_bridge__msg__NavigationStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gkv2_motor_bridge__msg__NavigationStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
