// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/gkv2_config_status.hpp"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__BUILDER_HPP_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gkv2_motor_bridge
{

namespace msg
{

namespace builder
{

class Init_GKV2ConfigStatus_status_message
{
public:
  explicit Init_GKV2ConfigStatus_status_message(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus status_message(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_status_message_type arg)
  {
    msg_.status_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_packet_structure_match
{
public:
  explicit Init_GKV2ConfigStatus_packet_structure_match(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_status_message packet_structure_match(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_packet_structure_match_type arg)
  {
    msg_.packet_structure_match = std::move(arg);
    return Init_GKV2ConfigStatus_status_message(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_packet_param_ids
{
public:
  explicit Init_GKV2ConfigStatus_packet_param_ids(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_packet_structure_match packet_param_ids(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_packet_param_ids_type arg)
  {
    msg_.packet_param_ids = std::move(arg);
    return Init_GKV2ConfigStatus_packet_structure_match(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_packet_param_count
{
public:
  explicit Init_GKV2ConfigStatus_packet_param_count(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_packet_param_ids packet_param_count(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_packet_param_count_type arg)
  {
    msg_.packet_param_count = std::move(arg);
    return Init_GKV2ConfigStatus_packet_param_ids(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_accelerometer_fail
{
public:
  explicit Init_GKV2ConfigStatus_accelerometer_fail(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_packet_param_count accelerometer_fail(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_accelerometer_fail_type arg)
  {
    msg_.accelerometer_fail = std::move(arg);
    return Init_GKV2ConfigStatus_packet_param_count(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_gyroscope_fail
{
public:
  explicit Init_GKV2ConfigStatus_gyroscope_fail(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_accelerometer_fail gyroscope_fail(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_gyroscope_fail_type arg)
  {
    msg_.gyroscope_fail = std::move(arg);
    return Init_GKV2ConfigStatus_accelerometer_fail(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_adc_skip
{
public:
  explicit Init_GKV2ConfigStatus_adc_skip(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_gyroscope_fail adc_skip(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_adc_skip_type arg)
  {
    msg_.adc_skip = std::move(arg);
    return Init_GKV2ConfigStatus_gyroscope_fail(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_adc_overflow
{
public:
  explicit Init_GKV2ConfigStatus_adc_overflow(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_adc_skip adc_overflow(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_adc_overflow_type arg)
  {
    msg_.adc_overflow = std::move(arg);
    return Init_GKV2ConfigStatus_adc_skip(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_data_ready
{
public:
  explicit Init_GKV2ConfigStatus_data_ready(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_adc_overflow data_ready(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_data_ready_type arg)
  {
    msg_.data_ready = std::move(arg);
    return Init_GKV2ConfigStatus_adc_overflow(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_connection_ok
{
public:
  explicit Init_GKV2ConfigStatus_connection_ok(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_data_ready connection_ok(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_connection_ok_type arg)
  {
    msg_.connection_ok = std::move(arg);
    return Init_GKV2ConfigStatus_data_ready(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_algorithm_mode
{
public:
  explicit Init_GKV2ConfigStatus_algorithm_mode(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_connection_ok algorithm_mode(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_algorithm_mode_type arg)
  {
    msg_.algorithm_mode = std::move(arg);
    return Init_GKV2ConfigStatus_connection_ok(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_firmware_version
{
public:
  explicit Init_GKV2ConfigStatus_firmware_version(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_algorithm_mode firmware_version(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_firmware_version_type arg)
  {
    msg_.firmware_version = std::move(arg);
    return Init_GKV2ConfigStatus_algorithm_mode(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_serial_number
{
public:
  explicit Init_GKV2ConfigStatus_serial_number(::gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
  : msg_(msg)
  {}
  Init_GKV2ConfigStatus_firmware_version serial_number(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return Init_GKV2ConfigStatus_firmware_version(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

class Init_GKV2ConfigStatus_device_name
{
public:
  Init_GKV2ConfigStatus_device_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GKV2ConfigStatus_serial_number device_name(::gkv2_motor_bridge::msg::GKV2ConfigStatus::_device_name_type arg)
  {
    msg_.device_name = std::move(arg);
    return Init_GKV2ConfigStatus_serial_number(msg_);
  }

private:
  ::gkv2_motor_bridge::msg::GKV2ConfigStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gkv2_motor_bridge::msg::GKV2ConfigStatus>()
{
  return gkv2_motor_bridge::msg::builder::Init_GKV2ConfigStatus_device_name();
}

}  // namespace gkv2_motor_bridge

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__BUILDER_HPP_
