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

class Init_GKV2Status_rtk_fixed
{
public:
  explicit Init_GKV2Status_rtk_fixed(::gkv2_motor_bridge::msg::GKV2Status & msg)
  : msg_(msg)
  {}
  ::gkv2_motor_bridge::msg::GKV2Status rtk_fixed(::gkv2_motor_bridge::msg::GKV2Status::_rtk_fixed_type arg)
  {
    msg_.rtk_fixed = std::move(arg);
    return std::move(msg_);
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
  Init_GKV2Status_rtk_fixed alg_state_status(::gkv2_motor_bridge::msg::GKV2Status::_alg_state_status_type arg)
  {
    msg_.alg_state_status = std::move(arg);
    return Init_GKV2Status_rtk_fixed(msg_);
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
  Init_GKV2Status_alg_state_status gps_num_satellites(::gkv2_motor_bridge::msg::GKV2Status::_gps_num_satellites_type arg)
  {
    msg_.gps_num_satellites = std::move(arg);
    return Init_GKV2Status_alg_state_status(msg_);
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
  Init_GKV2Status_gps_num_satellites gps_state_status(::gkv2_motor_bridge::msg::GKV2Status::_gps_state_status_type arg)
  {
    msg_.gps_state_status = std::move(arg);
    return Init_GKV2Status_gps_num_satellites(msg_);
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
