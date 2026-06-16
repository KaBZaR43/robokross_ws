// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/gkv2_status.hpp"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__BUILDER_HPP_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gkv2_motor_bridge/msg/detail/gkv2_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gkv2_motor_bridge
{

namespace msg
{

namespace builder
{

class Init_GKV2Status_heading_from_dual_antenna
{
public:
  explicit Init_GKV2Status_heading_from_dual_antenna(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  ::gkv2_motor_bridge::msg::GKV2Status heading_from_dual_antenna(::gkv2_motor_bridge::msg::GKV2Status::_heading_from_dual_antenna_type arg)
  {
    msg_.heading_from_dual_antenna = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gps_rel_length
{
public:
  explicit Init_GKV2Status_gps_rel_length(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_heading_from_dual_antenna gps_rel_length(::gkv2_motor_bridge::msg::GKV2Status::_gps_rel_length_type arg)
  {
    msg_.gps_rel_length = std::move(arg);
    return Init_GKV2Status_heading_from_dual_antenna(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gps_rel_heading
{
public:
  explicit Init_GKV2Status_gps_rel_heading(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gps_rel_length gps_rel_heading(::gkv2_motor_bridge::msg::GKV2Status::_gps_rel_heading_type arg)
  {
    msg_.gps_rel_heading = std::move(arg);
    return Init_GKV2Status_gps_rel_length(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_var_phi
{
public:
  explicit Init_GKV2Status_alg_var_phi(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gps_rel_heading alg_var_phi(::gkv2_motor_bridge::msg::GKV2Status::_alg_var_phi_type arg)
  {
    msg_.alg_var_phi = std::move(arg);
    return Init_GKV2Status_gps_rel_heading(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_var_theta
{
public:
  explicit Init_GKV2Status_alg_var_theta(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_var_phi alg_var_theta(::gkv2_motor_bridge::msg::GKV2Status::_alg_var_theta_type arg)
  {
    msg_.alg_var_theta = std::move(arg);
    return Init_GKV2Status_alg_var_phi(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_var_psi
{
public:
  explicit Init_GKV2Status_alg_var_psi(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_var_theta alg_var_psi(::gkv2_motor_bridge::msg::GKV2Status::_alg_var_psi_type arg)
  {
    msg_.alg_var_psi = std::move(arg);
    return Init_GKV2Status_alg_var_theta(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_var_vz
{
public:
  explicit Init_GKV2Status_alg_var_vz(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_var_psi alg_var_vz(::gkv2_motor_bridge::msg::GKV2Status::_alg_var_vz_type arg)
  {
    msg_.alg_var_vz = std::move(arg);
    return Init_GKV2Status_alg_var_psi(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_var_vy
{
public:
  explicit Init_GKV2Status_alg_var_vy(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_var_vz alg_var_vy(::gkv2_motor_bridge::msg::GKV2Status::_alg_var_vy_type arg)
  {
    msg_.alg_var_vy = std::move(arg);
    return Init_GKV2Status_alg_var_vz(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_var_vx
{
public:
  explicit Init_GKV2Status_alg_var_vx(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_var_vy alg_var_vx(::gkv2_motor_bridge::msg::GKV2Status::_alg_var_vx_type arg)
  {
    msg_.alg_var_vx = std::move(arg);
    return Init_GKV2Status_alg_var_vy(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_var_z
{
public:
  explicit Init_GKV2Status_alg_var_z(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_var_vx alg_var_z(::gkv2_motor_bridge::msg::GKV2Status::_alg_var_z_type arg)
  {
    msg_.alg_var_z = std::move(arg);
    return Init_GKV2Status_alg_var_vx(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_var_y
{
public:
  explicit Init_GKV2Status_alg_var_y(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_var_z alg_var_y(::gkv2_motor_bridge::msg::GKV2Status::_alg_var_y_type arg)
  {
    msg_.alg_var_y = std::move(arg);
    return Init_GKV2Status_alg_var_z(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_var_x
{
public:
  explicit Init_GKV2Status_alg_var_x(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_var_y alg_var_x(::gkv2_motor_bridge::msg::GKV2Status::_alg_var_x_type arg)
  {
    msg_.alg_var_x = std::move(arg);
    return Init_GKV2Status_alg_var_y(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gnss_sig_alt
{
public:
  explicit Init_GKV2Status_gnss_sig_alt(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_var_x gnss_sig_alt(::gkv2_motor_bridge::msg::GKV2Status::_gnss_sig_alt_type arg)
  {
    msg_.gnss_sig_alt = std::move(arg);
    return Init_GKV2Status_alg_var_x(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gnss_sig_lon
{
public:
  explicit Init_GKV2Status_gnss_sig_lon(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gnss_sig_alt gnss_sig_lon(::gkv2_motor_bridge::msg::GKV2Status::_gnss_sig_lon_type arg)
  {
    msg_.gnss_sig_lon = std::move(arg);
    return Init_GKV2Status_gnss_sig_alt(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gnss_sig_lat
{
public:
  explicit Init_GKV2Status_gnss_sig_lat(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gnss_sig_lon gnss_sig_lat(::gkv2_motor_bridge::msg::GKV2Status::_gnss_sig_lat_type arg)
  {
    msg_.gnss_sig_lat = std::move(arg);
    return Init_GKV2Status_gnss_sig_lon(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gps_num_satellites
{
public:
  explicit Init_GKV2Status_gps_num_satellites(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gnss_sig_lat gps_num_satellites(::gkv2_motor_bridge::msg::GKV2Status::_gps_num_satellites_type arg)
  {
    msg_.gps_num_satellites = std::move(arg);
    return Init_GKV2Status_gnss_sig_lat(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_navigation_ready
{
public:
  explicit Init_GKV2Status_alg_navigation_ready(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gps_num_satellites alg_navigation_ready(::gkv2_motor_bridge::msg::GKV2Status::_alg_navigation_ready_type arg)
  {
    msg_.alg_navigation_ready = std::move(arg);
    return Init_GKV2Status_gps_num_satellites(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_fails
{
public:
  explicit Init_GKV2Status_alg_fails(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_navigation_ready alg_fails(::gkv2_motor_bridge::msg::GKV2Status::_alg_fails_type arg)
  {
    msg_.alg_fails = std::move(arg);
    return Init_GKV2Status_alg_navigation_ready(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_correction
{
public:
  explicit Init_GKV2Status_alg_correction(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_fails alg_correction(::gkv2_motor_bridge::msg::GKV2Status::_alg_correction_type arg)
  {
    msg_.alg_correction = std::move(arg);
    return Init_GKV2Status_alg_fails(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_stage
{
public:
  explicit Init_GKV2Status_alg_stage(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_correction alg_stage(::gkv2_motor_bridge::msg::GKV2Status::_alg_stage_type arg)
  {
    msg_.alg_stage = std::move(arg);
    return Init_GKV2Status_alg_correction(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_alg_state_status
{
public:
  explicit Init_GKV2Status_alg_state_status(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_stage alg_state_status(::gkv2_motor_bridge::msg::GKV2Status::_alg_state_status_type arg)
  {
    msg_.alg_state_status = std::move(arg);
    return Init_GKV2Status_alg_stage(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_rel_heading_valid
{
public:
  explicit Init_GKV2Status_rel_heading_valid(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_alg_state_status rel_heading_valid(::gkv2_motor_bridge::msg::GKV2Status::_rel_heading_valid_type arg)
  {
    msg_.rel_heading_valid = std::move(arg);
    return Init_GKV2Status_alg_state_status(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_rel_heading_mode
{
public:
  explicit Init_GKV2Status_rel_heading_mode(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_rel_heading_valid rel_heading_mode(::gkv2_motor_bridge::msg::GKV2Status::_rel_heading_mode_type arg)
  {
    msg_.rel_heading_mode = std::move(arg);
    return Init_GKV2Status_rel_heading_valid(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_rel_ambiguity_status
{
public:
  explicit Init_GKV2Status_rel_ambiguity_status(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_rel_heading_mode rel_ambiguity_status(::gkv2_motor_bridge::msg::GKV2Status::_rel_ambiguity_status_type arg)
  {
    msg_.rel_ambiguity_status = std::move(arg);
    return Init_GKV2Status_rel_heading_mode(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_rel_coords_valid
{
public:
  explicit Init_GKV2Status_rel_coords_valid(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_rel_ambiguity_status rel_coords_valid(::gkv2_motor_bridge::msg::GKV2Status::_rel_coords_valid_type arg)
  {
    msg_.rel_coords_valid = std::move(arg);
    return Init_GKV2Status_rel_ambiguity_status(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_rel_diff_applied
{
public:
  explicit Init_GKV2Status_rel_diff_applied(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_rel_coords_valid rel_diff_applied(::gkv2_motor_bridge::msg::GKV2Status::_rel_diff_applied_type arg)
  {
    msg_.rel_diff_applied = std::move(arg);
    return Init_GKV2Status_rel_coords_valid(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_rel_nav_valid
{
public:
  explicit Init_GKV2Status_rel_nav_valid(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_rel_diff_applied rel_nav_valid(::gkv2_motor_bridge::msg::GKV2Status::_rel_nav_valid_type arg)
  {
    msg_.rel_nav_valid = std::move(arg);
    return Init_GKV2Status_rel_diff_applied(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gps_rel_status
{
public:
  explicit Init_GKV2Status_gps_rel_status(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_rel_nav_valid gps_rel_status(::gkv2_motor_bridge::msg::GKV2Status::_gps_rel_status_type arg)
  {
    msg_.gps_rel_status = std::move(arg);
    return Init_GKV2Status_rel_nav_valid(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_rtk_status
{
public:
  explicit Init_GKV2Status_rtk_status(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gps_rel_status rtk_status(::gkv2_motor_bridge::msg::GKV2Status::_rtk_status_type arg)
  {
    msg_.rtk_status = std::move(arg);
    return Init_GKV2Status_gps_rel_status(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gnss_fix_type
{
public:
  explicit Init_GKV2Status_gnss_fix_type(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_rtk_status gnss_fix_type(::gkv2_motor_bridge::msg::GKV2Status::_gnss_fix_type_type arg)
  {
    msg_.gnss_fix_type = std::move(arg);
    return Init_GKV2Status_rtk_status(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gnss_diff_corrections
{
public:
  explicit Init_GKV2Status_gnss_diff_corrections(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gnss_fix_type gnss_diff_corrections(::gkv2_motor_bridge::msg::GKV2Status::_gnss_diff_corrections_type arg)
  {
    msg_.gnss_diff_corrections = std::move(arg);
    return Init_GKV2Status_gnss_fix_type(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gnss_coords_valid
{
public:
  explicit Init_GKV2Status_gnss_coords_valid(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gnss_diff_corrections gnss_coords_valid(::gkv2_motor_bridge::msg::GKV2Status::_gnss_coords_valid_type arg)
  {
    msg_.gnss_coords_valid = std::move(arg);
    return Init_GKV2Status_gnss_diff_corrections(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gnss_ambiguity_resolved
{
public:
  explicit Init_GKV2Status_gnss_ambiguity_resolved(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gnss_coords_valid gnss_ambiguity_resolved(::gkv2_motor_bridge::msg::GKV2Status::_gnss_ambiguity_resolved_type arg)
  {
    msg_.gnss_ambiguity_resolved = std::move(arg);
    return Init_GKV2Status_gnss_coords_valid(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gnss_time_valid
{
public:
  explicit Init_GKV2Status_gnss_time_valid(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gnss_ambiguity_resolved gnss_time_valid(::gkv2_motor_bridge::msg::GKV2Status::_gnss_time_valid_type arg)
  {
    msg_.gnss_time_valid = std::move(arg);
    return Init_GKV2Status_gnss_ambiguity_resolved(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gnss_date_valid
{
public:
  explicit Init_GKV2Status_gnss_date_valid(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  Init_GKV2Status_gnss_time_valid gnss_date_valid(::gkv2_motor_bridge::msg::GKV2Status::_gnss_date_valid_type arg)
  {
    msg_.gnss_date_valid = std::move(arg);
    return Init_GKV2Status_gnss_time_valid(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

class Init_GKV2Status_gps_state_status
{
public:
  Init_GKV2Status_gps_state_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GKV2Status_gnss_date_valid gps_state_status(::gkv2_motor_bridge::msg::GKV2Status::_gps_state_status_type arg)
  {
    msg_.gps_state_status = std::move(arg);
    return Init_GKV2Status_gnss_date_valid(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2Status msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkv2_motor_bridge::msg::GKV2Status>()
{
  return gkv2_motor_bridge::msg::builder::Init_GKV2Status_gps_state_status();
}

}  // namespace gkv2_motor_bridge

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__BUILDER_HPP_
