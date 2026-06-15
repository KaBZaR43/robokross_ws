// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/navigation_status.hpp"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__BUILDER_HPP_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gkv2_motor_bridge/msg/detail/navigation_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gkv2_motor_bridge
{

namespace msg
{

namespace builder
{

class Init_NavigationStatus_status_message
{
public:
  explicit Init_NavigationStatus_status_message(::gkv2_motor_bridge::msg::NavigationStatus & msg)
  : msg_(msg)
  {}
  ::gkv2_motor_bridge::msg::NavigationStatus status_message(::gkv2_motor_bridge::msg::NavigationStatus::_status_message_type arg)
  {
    msg_.status_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::NavigationStatus msg_;
};

class Init_NavigationStatus_time_since_gnss
{
public:
  explicit Init_NavigationStatus_time_since_gnss(::gkv2_motor_bridge::msg::NavigationStatus & msg)
  : msg_(msg)
  {}
  Init_NavigationStatus_status_message time_since_gnss(::gkv2_motor_bridge::msg::NavigationStatus::_time_since_gnss_type arg)
  {
    msg_.time_since_gnss = std::move(arg);
    return Init_NavigationStatus_status_message(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::NavigationStatus msg_;
};

class Init_NavigationStatus_odometry_drift
{
public:
  explicit Init_NavigationStatus_odometry_drift(::gkv2_motor_bridge::msg::NavigationStatus & msg)
  : msg_(msg)
  {}
  Init_NavigationStatus_time_since_gnss odometry_drift(::gkv2_motor_bridge::msg::NavigationStatus::_odometry_drift_type arg)
  {
    msg_.odometry_drift = std::move(arg);
    return Init_NavigationStatus_time_since_gnss(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::NavigationStatus msg_;
};

class Init_NavigationStatus_gnss_quality
{
public:
  explicit Init_NavigationStatus_gnss_quality(::gkv2_motor_bridge::msg::NavigationStatus & msg)
  : msg_(msg)
  {}
  Init_NavigationStatus_odometry_drift gnss_quality(::gkv2_motor_bridge::msg::NavigationStatus::_gnss_quality_type arg)
  {
    msg_.gnss_quality = std::move(arg);
    return Init_NavigationStatus_odometry_drift(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::NavigationStatus msg_;
};

class Init_NavigationStatus_gnss_satellites
{
public:
  explicit Init_NavigationStatus_gnss_satellites(::gkv2_motor_bridge::msg::NavigationStatus & msg)
  : msg_(msg)
  {}
  Init_NavigationStatus_gnss_quality gnss_satellites(::gkv2_motor_bridge::msg::NavigationStatus::_gnss_satellites_type arg)
  {
    msg_.gnss_satellites = std::move(arg);
    return Init_NavigationStatus_gnss_quality(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::NavigationStatus msg_;
};

class Init_NavigationStatus_rtk_fixed
{
public:
  explicit Init_NavigationStatus_rtk_fixed(::gkv2_motor_bridge::msg::NavigationStatus & msg)
  : msg_(msg)
  {}
  Init_NavigationStatus_gnss_satellites rtk_fixed(::gkv2_motor_bridge::msg::NavigationStatus::_rtk_fixed_type arg)
  {
    msg_.rtk_fixed = std::move(arg);
    return Init_NavigationStatus_gnss_satellites(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::NavigationStatus msg_;
};

class Init_NavigationStatus_gnss_available
{
public:
  explicit Init_NavigationStatus_gnss_available(::gkv2_motor_bridge::msg::NavigationStatus & msg)
  : msg_(msg)
  {}
  Init_NavigationStatus_rtk_fixed gnss_available(::gkv2_motor_bridge::msg::NavigationStatus::_gnss_available_type arg)
  {
    msg_.gnss_available = std::move(arg);
    return Init_NavigationStatus_rtk_fixed(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::NavigationStatus msg_;
};

class Init_NavigationStatus_current_mode
{
public:
  Init_NavigationStatus_current_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationStatus_gnss_available current_mode(::gkv2_motor_bridge::msg::NavigationStatus::_current_mode_type arg)
  {
    msg_.current_mode = std::move(arg);
    return Init_NavigationStatus_gnss_available(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::NavigationStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkv2_motor_bridge::msg::NavigationStatus>()
{
  return gkv2_motor_bridge::msg::builder::Init_NavigationStatus_current_mode();
}

}  // namespace gkv2_motor_bridge

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__BUILDER_HPP_
