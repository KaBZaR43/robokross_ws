// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/gkv2_status.hpp"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__STRUCT_HPP_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gkv2_motor_bridge__msg__GKV2Status __attribute__((deprecated))
#else
# define DEPRECATED__gkv2_motor_bridge__msg__GKV2Status __declspec(deprecated)
#endif

namespace gkv2_motor_bridge
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GKV2Status_
{
  using Type = GKV2Status_<ContainerAllocator>;

  explicit GKV2Status_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gps_state_status = 0ul;
      this->gnss_date_valid = false;
      this->gnss_time_valid = false;
      this->gnss_ambiguity_resolved = false;
      this->gnss_coords_valid = false;
      this->gnss_diff_corrections = false;
      this->gnss_fix_type = 0;
      this->rtk_status = 0;
      this->gps_rel_status = 0ul;
      this->rel_nav_valid = false;
      this->rel_diff_applied = false;
      this->rel_coords_valid = false;
      this->rel_ambiguity_status = 0;
      this->rel_heading_mode = false;
      this->rel_heading_valid = false;
      this->alg_state_status = 0ul;
      this->alg_stage = 0;
      this->alg_correction = 0;
      this->alg_fails = 0;
      this->alg_navigation_ready = false;
      this->gps_num_satellites = 0;
      this->gnss_sig_lat = 0.0f;
      this->gnss_sig_lon = 0.0f;
      this->gnss_sig_alt = 0.0f;
      this->alg_var_x = 0.0f;
      this->alg_var_y = 0.0f;
      this->alg_var_z = 0.0f;
      this->alg_var_vx = 0.0f;
      this->alg_var_vy = 0.0f;
      this->alg_var_vz = 0.0f;
      this->alg_var_psi = 0.0f;
      this->alg_var_theta = 0.0f;
      this->alg_var_phi = 0.0f;
      this->gps_rel_heading = 0.0f;
      this->gps_rel_length = 0.0f;
      this->heading_from_dual_antenna = false;
    }
  }

  explicit GKV2Status_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gps_state_status = 0ul;
      this->gnss_date_valid = false;
      this->gnss_time_valid = false;
      this->gnss_ambiguity_resolved = false;
      this->gnss_coords_valid = false;
      this->gnss_diff_corrections = false;
      this->gnss_fix_type = 0;
      this->rtk_status = 0;
      this->gps_rel_status = 0ul;
      this->rel_nav_valid = false;
      this->rel_diff_applied = false;
      this->rel_coords_valid = false;
      this->rel_ambiguity_status = 0;
      this->rel_heading_mode = false;
      this->rel_heading_valid = false;
      this->alg_state_status = 0ul;
      this->alg_stage = 0;
      this->alg_correction = 0;
      this->alg_fails = 0;
      this->alg_navigation_ready = false;
      this->gps_num_satellites = 0;
      this->gnss_sig_lat = 0.0f;
      this->gnss_sig_lon = 0.0f;
      this->gnss_sig_alt = 0.0f;
      this->alg_var_x = 0.0f;
      this->alg_var_y = 0.0f;
      this->alg_var_z = 0.0f;
      this->alg_var_vx = 0.0f;
      this->alg_var_vy = 0.0f;
      this->alg_var_vz = 0.0f;
      this->alg_var_psi = 0.0f;
      this->alg_var_theta = 0.0f;
      this->alg_var_phi = 0.0f;
      this->gps_rel_heading = 0.0f;
      this->gps_rel_length = 0.0f;
      this->heading_from_dual_antenna = false;
    }
  }

  // field types and members
  using _gps_state_status_type =
    uint32_t;
  _gps_state_status_type gps_state_status;
  using _gnss_date_valid_type =
    bool;
  _gnss_date_valid_type gnss_date_valid;
  using _gnss_time_valid_type =
    bool;
  _gnss_time_valid_type gnss_time_valid;
  using _gnss_ambiguity_resolved_type =
    bool;
  _gnss_ambiguity_resolved_type gnss_ambiguity_resolved;
  using _gnss_coords_valid_type =
    bool;
  _gnss_coords_valid_type gnss_coords_valid;
  using _gnss_diff_corrections_type =
    bool;
  _gnss_diff_corrections_type gnss_diff_corrections;
  using _gnss_fix_type_type =
    uint8_t;
  _gnss_fix_type_type gnss_fix_type;
  using _rtk_status_type =
    uint8_t;
  _rtk_status_type rtk_status;
  using _gps_rel_status_type =
    uint32_t;
  _gps_rel_status_type gps_rel_status;
  using _rel_nav_valid_type =
    bool;
  _rel_nav_valid_type rel_nav_valid;
  using _rel_diff_applied_type =
    bool;
  _rel_diff_applied_type rel_diff_applied;
  using _rel_coords_valid_type =
    bool;
  _rel_coords_valid_type rel_coords_valid;
  using _rel_ambiguity_status_type =
    uint8_t;
  _rel_ambiguity_status_type rel_ambiguity_status;
  using _rel_heading_mode_type =
    bool;
  _rel_heading_mode_type rel_heading_mode;
  using _rel_heading_valid_type =
    bool;
  _rel_heading_valid_type rel_heading_valid;
  using _alg_state_status_type =
    uint32_t;
  _alg_state_status_type alg_state_status;
  using _alg_stage_type =
    uint8_t;
  _alg_stage_type alg_stage;
  using _alg_correction_type =
    uint8_t;
  _alg_correction_type alg_correction;
  using _alg_fails_type =
    uint16_t;
  _alg_fails_type alg_fails;
  using _alg_navigation_ready_type =
    bool;
  _alg_navigation_ready_type alg_navigation_ready;
  using _gps_num_satellites_type =
    uint16_t;
  _gps_num_satellites_type gps_num_satellites;
  using _gnss_sig_lat_type =
    float;
  _gnss_sig_lat_type gnss_sig_lat;
  using _gnss_sig_lon_type =
    float;
  _gnss_sig_lon_type gnss_sig_lon;
  using _gnss_sig_alt_type =
    float;
  _gnss_sig_alt_type gnss_sig_alt;
  using _alg_var_x_type =
    float;
  _alg_var_x_type alg_var_x;
  using _alg_var_y_type =
    float;
  _alg_var_y_type alg_var_y;
  using _alg_var_z_type =
    float;
  _alg_var_z_type alg_var_z;
  using _alg_var_vx_type =
    float;
  _alg_var_vx_type alg_var_vx;
  using _alg_var_vy_type =
    float;
  _alg_var_vy_type alg_var_vy;
  using _alg_var_vz_type =
    float;
  _alg_var_vz_type alg_var_vz;
  using _alg_var_psi_type =
    float;
  _alg_var_psi_type alg_var_psi;
  using _alg_var_theta_type =
    float;
  _alg_var_theta_type alg_var_theta;
  using _alg_var_phi_type =
    float;
  _alg_var_phi_type alg_var_phi;
  using _gps_rel_heading_type =
    float;
  _gps_rel_heading_type gps_rel_heading;
  using _gps_rel_length_type =
    float;
  _gps_rel_length_type gps_rel_length;
  using _heading_from_dual_antenna_type =
    bool;
  _heading_from_dual_antenna_type heading_from_dual_antenna;

  // setters for named parameter idiom
  Type & set__gps_state_status(
    const uint32_t & _arg)
  {
    this->gps_state_status = _arg;
    return *this;
  }
  Type & set__gnss_date_valid(
    const bool & _arg)
  {
    this->gnss_date_valid = _arg;
    return *this;
  }
  Type & set__gnss_time_valid(
    const bool & _arg)
  {
    this->gnss_time_valid = _arg;
    return *this;
  }
  Type & set__gnss_ambiguity_resolved(
    const bool & _arg)
  {
    this->gnss_ambiguity_resolved = _arg;
    return *this;
  }
  Type & set__gnss_coords_valid(
    const bool & _arg)
  {
    this->gnss_coords_valid = _arg;
    return *this;
  }
  Type & set__gnss_diff_corrections(
    const bool & _arg)
  {
    this->gnss_diff_corrections = _arg;
    return *this;
  }
  Type & set__gnss_fix_type(
    const uint8_t & _arg)
  {
    this->gnss_fix_type = _arg;
    return *this;
  }
  Type & set__rtk_status(
    const uint8_t & _arg)
  {
    this->rtk_status = _arg;
    return *this;
  }
  Type & set__gps_rel_status(
    const uint32_t & _arg)
  {
    this->gps_rel_status = _arg;
    return *this;
  }
  Type & set__rel_nav_valid(
    const bool & _arg)
  {
    this->rel_nav_valid = _arg;
    return *this;
  }
  Type & set__rel_diff_applied(
    const bool & _arg)
  {
    this->rel_diff_applied = _arg;
    return *this;
  }
  Type & set__rel_coords_valid(
    const bool & _arg)
  {
    this->rel_coords_valid = _arg;
    return *this;
  }
  Type & set__rel_ambiguity_status(
    const uint8_t & _arg)
  {
    this->rel_ambiguity_status = _arg;
    return *this;
  }
  Type & set__rel_heading_mode(
    const bool & _arg)
  {
    this->rel_heading_mode = _arg;
    return *this;
  }
  Type & set__rel_heading_valid(
    const bool & _arg)
  {
    this->rel_heading_valid = _arg;
    return *this;
  }
  Type & set__alg_state_status(
    const uint32_t & _arg)
  {
    this->alg_state_status = _arg;
    return *this;
  }
  Type & set__alg_stage(
    const uint8_t & _arg)
  {
    this->alg_stage = _arg;
    return *this;
  }
  Type & set__alg_correction(
    const uint8_t & _arg)
  {
    this->alg_correction = _arg;
    return *this;
  }
  Type & set__alg_fails(
    const uint16_t & _arg)
  {
    this->alg_fails = _arg;
    return *this;
  }
  Type & set__alg_navigation_ready(
    const bool & _arg)
  {
    this->alg_navigation_ready = _arg;
    return *this;
  }
  Type & set__gps_num_satellites(
    const uint16_t & _arg)
  {
    this->gps_num_satellites = _arg;
    return *this;
  }
  Type & set__gnss_sig_lat(
    const float & _arg)
  {
    this->gnss_sig_lat = _arg;
    return *this;
  }
  Type & set__gnss_sig_lon(
    const float & _arg)
  {
    this->gnss_sig_lon = _arg;
    return *this;
  }
  Type & set__gnss_sig_alt(
    const float & _arg)
  {
    this->gnss_sig_alt = _arg;
    return *this;
  }
  Type & set__alg_var_x(
    const float & _arg)
  {
    this->alg_var_x = _arg;
    return *this;
  }
  Type & set__alg_var_y(
    const float & _arg)
  {
    this->alg_var_y = _arg;
    return *this;
  }
  Type & set__alg_var_z(
    const float & _arg)
  {
    this->alg_var_z = _arg;
    return *this;
  }
  Type & set__alg_var_vx(
    const float & _arg)
  {
    this->alg_var_vx = _arg;
    return *this;
  }
  Type & set__alg_var_vy(
    const float & _arg)
  {
    this->alg_var_vy = _arg;
    return *this;
  }
  Type & set__alg_var_vz(
    const float & _arg)
  {
    this->alg_var_vz = _arg;
    return *this;
  }
  Type & set__alg_var_psi(
    const float & _arg)
  {
    this->alg_var_psi = _arg;
    return *this;
  }
  Type & set__alg_var_theta(
    const float & _arg)
  {
    this->alg_var_theta = _arg;
    return *this;
  }
  Type & set__alg_var_phi(
    const float & _arg)
  {
    this->alg_var_phi = _arg;
    return *this;
  }
  Type & set__gps_rel_heading(
    const float & _arg)
  {
    this->gps_rel_heading = _arg;
    return *this;
  }
  Type & set__gps_rel_length(
    const float & _arg)
  {
    this->gps_rel_length = _arg;
    return *this;
  }
  Type & set__heading_from_dual_antenna(
    const bool & _arg)
  {
    this->heading_from_dual_antenna = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator> *;
  using ConstRawPtr =
    const gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gkv2_motor_bridge__msg__GKV2Status
    std::shared_ptr<gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gkv2_motor_bridge__msg__GKV2Status
    std::shared_ptr<gkv2_motor_bridge::msg::GKV2Status_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GKV2Status_ & other) const
  {
    if (this->gps_state_status != other.gps_state_status) {
      return false;
    }
    if (this->gnss_date_valid != other.gnss_date_valid) {
      return false;
    }
    if (this->gnss_time_valid != other.gnss_time_valid) {
      return false;
    }
    if (this->gnss_ambiguity_resolved != other.gnss_ambiguity_resolved) {
      return false;
    }
    if (this->gnss_coords_valid != other.gnss_coords_valid) {
      return false;
    }
    if (this->gnss_diff_corrections != other.gnss_diff_corrections) {
      return false;
    }
    if (this->gnss_fix_type != other.gnss_fix_type) {
      return false;
    }
    if (this->rtk_status != other.rtk_status) {
      return false;
    }
    if (this->gps_rel_status != other.gps_rel_status) {
      return false;
    }
    if (this->rel_nav_valid != other.rel_nav_valid) {
      return false;
    }
    if (this->rel_diff_applied != other.rel_diff_applied) {
      return false;
    }
    if (this->rel_coords_valid != other.rel_coords_valid) {
      return false;
    }
    if (this->rel_ambiguity_status != other.rel_ambiguity_status) {
      return false;
    }
    if (this->rel_heading_mode != other.rel_heading_mode) {
      return false;
    }
    if (this->rel_heading_valid != other.rel_heading_valid) {
      return false;
    }
    if (this->alg_state_status != other.alg_state_status) {
      return false;
    }
    if (this->alg_stage != other.alg_stage) {
      return false;
    }
    if (this->alg_correction != other.alg_correction) {
      return false;
    }
    if (this->alg_fails != other.alg_fails) {
      return false;
    }
    if (this->alg_navigation_ready != other.alg_navigation_ready) {
      return false;
    }
    if (this->gps_num_satellites != other.gps_num_satellites) {
      return false;
    }
    if (this->gnss_sig_lat != other.gnss_sig_lat) {
      return false;
    }
    if (this->gnss_sig_lon != other.gnss_sig_lon) {
      return false;
    }
    if (this->gnss_sig_alt != other.gnss_sig_alt) {
      return false;
    }
    if (this->alg_var_x != other.alg_var_x) {
      return false;
    }
    if (this->alg_var_y != other.alg_var_y) {
      return false;
    }
    if (this->alg_var_z != other.alg_var_z) {
      return false;
    }
    if (this->alg_var_vx != other.alg_var_vx) {
      return false;
    }
    if (this->alg_var_vy != other.alg_var_vy) {
      return false;
    }
    if (this->alg_var_vz != other.alg_var_vz) {
      return false;
    }
    if (this->alg_var_psi != other.alg_var_psi) {
      return false;
    }
    if (this->alg_var_theta != other.alg_var_theta) {
      return false;
    }
    if (this->alg_var_phi != other.alg_var_phi) {
      return false;
    }
    if (this->gps_rel_heading != other.gps_rel_heading) {
      return false;
    }
    if (this->gps_rel_length != other.gps_rel_length) {
      return false;
    }
    if (this->heading_from_dual_antenna != other.heading_from_dual_antenna) {
      return false;
    }
    return true;
  }
  bool operator!=(const GKV2Status_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GKV2Status_

// alias to use template instance with default allocator
using GKV2Status =
  gkv2_motor_bridge::msg::GKV2Status_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gkv2_motor_bridge

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__STRUCT_HPP_
