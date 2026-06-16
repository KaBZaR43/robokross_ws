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
  // gnss_date_valid
  // gnss_time_valid
  // gnss_ambiguity_resolved
  // gnss_coords_valid
  // gnss_diff_corrections
  // gnss_fix_type
  // rtk_status
  // gps_rel_status
  // rel_nav_valid
  // rel_diff_applied
  // rel_coords_valid
  // rel_ambiguity_status
  // rel_heading_mode
  // rel_heading_valid
  // alg_state_status
  // alg_stage
  // alg_correction
  // alg_fails
  // alg_navigation_ready
  // gps_num_satellites
  // gnss_sig_lat
  // gnss_sig_lon
  // gnss_sig_alt
  // alg_var_x
  // alg_var_y
  // alg_var_z
  // alg_var_vx
  // alg_var_vy
  // alg_var_vz
  // alg_var_psi
  // alg_var_theta
  // alg_var_phi
  // gps_rel_heading
  // gps_rel_length
  // heading_from_dual_antenna
  return true;
}

void
gkv2_motor_bridge__msg__GKV2Status__fini(gkv2_motor_bridge__msg__GKV2Status * msg)
{
  if (!msg) {
    return;
  }
  // gps_state_status
  // gnss_date_valid
  // gnss_time_valid
  // gnss_ambiguity_resolved
  // gnss_coords_valid
  // gnss_diff_corrections
  // gnss_fix_type
  // rtk_status
  // gps_rel_status
  // rel_nav_valid
  // rel_diff_applied
  // rel_coords_valid
  // rel_ambiguity_status
  // rel_heading_mode
  // rel_heading_valid
  // alg_state_status
  // alg_stage
  // alg_correction
  // alg_fails
  // alg_navigation_ready
  // gps_num_satellites
  // gnss_sig_lat
  // gnss_sig_lon
  // gnss_sig_alt
  // alg_var_x
  // alg_var_y
  // alg_var_z
  // alg_var_vx
  // alg_var_vy
  // alg_var_vz
  // alg_var_psi
  // alg_var_theta
  // alg_var_phi
  // gps_rel_heading
  // gps_rel_length
  // heading_from_dual_antenna
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
  // gnss_date_valid
  if (lhs->gnss_date_valid != rhs->gnss_date_valid) {
    return false;
  }
  // gnss_time_valid
  if (lhs->gnss_time_valid != rhs->gnss_time_valid) {
    return false;
  }
  // gnss_ambiguity_resolved
  if (lhs->gnss_ambiguity_resolved != rhs->gnss_ambiguity_resolved) {
    return false;
  }
  // gnss_coords_valid
  if (lhs->gnss_coords_valid != rhs->gnss_coords_valid) {
    return false;
  }
  // gnss_diff_corrections
  if (lhs->gnss_diff_corrections != rhs->gnss_diff_corrections) {
    return false;
  }
  // gnss_fix_type
  if (lhs->gnss_fix_type != rhs->gnss_fix_type) {
    return false;
  }
  // rtk_status
  if (lhs->rtk_status != rhs->rtk_status) {
    return false;
  }
  // gps_rel_status
  if (lhs->gps_rel_status != rhs->gps_rel_status) {
    return false;
  }
  // rel_nav_valid
  if (lhs->rel_nav_valid != rhs->rel_nav_valid) {
    return false;
  }
  // rel_diff_applied
  if (lhs->rel_diff_applied != rhs->rel_diff_applied) {
    return false;
  }
  // rel_coords_valid
  if (lhs->rel_coords_valid != rhs->rel_coords_valid) {
    return false;
  }
  // rel_ambiguity_status
  if (lhs->rel_ambiguity_status != rhs->rel_ambiguity_status) {
    return false;
  }
  // rel_heading_mode
  if (lhs->rel_heading_mode != rhs->rel_heading_mode) {
    return false;
  }
  // rel_heading_valid
  if (lhs->rel_heading_valid != rhs->rel_heading_valid) {
    return false;
  }
  // alg_state_status
  if (lhs->alg_state_status != rhs->alg_state_status) {
    return false;
  }
  // alg_stage
  if (lhs->alg_stage != rhs->alg_stage) {
    return false;
  }
  // alg_correction
  if (lhs->alg_correction != rhs->alg_correction) {
    return false;
  }
  // alg_fails
  if (lhs->alg_fails != rhs->alg_fails) {
    return false;
  }
  // alg_navigation_ready
  if (lhs->alg_navigation_ready != rhs->alg_navigation_ready) {
    return false;
  }
  // gps_num_satellites
  if (lhs->gps_num_satellites != rhs->gps_num_satellites) {
    return false;
  }
  // gnss_sig_lat
  if (lhs->gnss_sig_lat != rhs->gnss_sig_lat) {
    return false;
  }
  // gnss_sig_lon
  if (lhs->gnss_sig_lon != rhs->gnss_sig_lon) {
    return false;
  }
  // gnss_sig_alt
  if (lhs->gnss_sig_alt != rhs->gnss_sig_alt) {
    return false;
  }
  // alg_var_x
  if (lhs->alg_var_x != rhs->alg_var_x) {
    return false;
  }
  // alg_var_y
  if (lhs->alg_var_y != rhs->alg_var_y) {
    return false;
  }
  // alg_var_z
  if (lhs->alg_var_z != rhs->alg_var_z) {
    return false;
  }
  // alg_var_vx
  if (lhs->alg_var_vx != rhs->alg_var_vx) {
    return false;
  }
  // alg_var_vy
  if (lhs->alg_var_vy != rhs->alg_var_vy) {
    return false;
  }
  // alg_var_vz
  if (lhs->alg_var_vz != rhs->alg_var_vz) {
    return false;
  }
  // alg_var_psi
  if (lhs->alg_var_psi != rhs->alg_var_psi) {
    return false;
  }
  // alg_var_theta
  if (lhs->alg_var_theta != rhs->alg_var_theta) {
    return false;
  }
  // alg_var_phi
  if (lhs->alg_var_phi != rhs->alg_var_phi) {
    return false;
  }
  // gps_rel_heading
  if (lhs->gps_rel_heading != rhs->gps_rel_heading) {
    return false;
  }
  // gps_rel_length
  if (lhs->gps_rel_length != rhs->gps_rel_length) {
    return false;
  }
  // heading_from_dual_antenna
  if (lhs->heading_from_dual_antenna != rhs->heading_from_dual_antenna) {
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
  // gnss_date_valid
  output->gnss_date_valid = input->gnss_date_valid;
  // gnss_time_valid
  output->gnss_time_valid = input->gnss_time_valid;
  // gnss_ambiguity_resolved
  output->gnss_ambiguity_resolved = input->gnss_ambiguity_resolved;
  // gnss_coords_valid
  output->gnss_coords_valid = input->gnss_coords_valid;
  // gnss_diff_corrections
  output->gnss_diff_corrections = input->gnss_diff_corrections;
  // gnss_fix_type
  output->gnss_fix_type = input->gnss_fix_type;
  // rtk_status
  output->rtk_status = input->rtk_status;
  // gps_rel_status
  output->gps_rel_status = input->gps_rel_status;
  // rel_nav_valid
  output->rel_nav_valid = input->rel_nav_valid;
  // rel_diff_applied
  output->rel_diff_applied = input->rel_diff_applied;
  // rel_coords_valid
  output->rel_coords_valid = input->rel_coords_valid;
  // rel_ambiguity_status
  output->rel_ambiguity_status = input->rel_ambiguity_status;
  // rel_heading_mode
  output->rel_heading_mode = input->rel_heading_mode;
  // rel_heading_valid
  output->rel_heading_valid = input->rel_heading_valid;
  // alg_state_status
  output->alg_state_status = input->alg_state_status;
  // alg_stage
  output->alg_stage = input->alg_stage;
  // alg_correction
  output->alg_correction = input->alg_correction;
  // alg_fails
  output->alg_fails = input->alg_fails;
  // alg_navigation_ready
  output->alg_navigation_ready = input->alg_navigation_ready;
  // gps_num_satellites
  output->gps_num_satellites = input->gps_num_satellites;
  // gnss_sig_lat
  output->gnss_sig_lat = input->gnss_sig_lat;
  // gnss_sig_lon
  output->gnss_sig_lon = input->gnss_sig_lon;
  // gnss_sig_alt
  output->gnss_sig_alt = input->gnss_sig_alt;
  // alg_var_x
  output->alg_var_x = input->alg_var_x;
  // alg_var_y
  output->alg_var_y = input->alg_var_y;
  // alg_var_z
  output->alg_var_z = input->alg_var_z;
  // alg_var_vx
  output->alg_var_vx = input->alg_var_vx;
  // alg_var_vy
  output->alg_var_vy = input->alg_var_vy;
  // alg_var_vz
  output->alg_var_vz = input->alg_var_vz;
  // alg_var_psi
  output->alg_var_psi = input->alg_var_psi;
  // alg_var_theta
  output->alg_var_theta = input->alg_var_theta;
  // alg_var_phi
  output->alg_var_phi = input->alg_var_phi;
  // gps_rel_heading
  output->gps_rel_heading = input->gps_rel_heading;
  // gps_rel_length
  output->gps_rel_length = input->gps_rel_length;
  // heading_from_dual_antenna
  output->heading_from_dual_antenna = input->heading_from_dual_antenna;
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
