// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/gkv2_config_status.hpp"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__STRUCT_HPP_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gkv2_motor_bridge__msg__GKV2ConfigStatus __attribute__((deprecated))
#else
# define DEPRECATED__gkv2_motor_bridge__msg__GKV2ConfigStatus __declspec(deprecated)
#endif

namespace gkv2_motor_bridge
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GKV2ConfigStatus_
{
  using Type = GKV2ConfigStatus_<ContainerAllocator>;

  explicit GKV2ConfigStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_name = "";
      this->serial_number = "";
      this->firmware_version = 0;
      this->algorithm_mode = 0;
      this->connection_ok = false;
      this->data_ready = false;
      this->adc_overflow = false;
      this->adc_skip = false;
      this->gyroscope_fail = false;
      this->accelerometer_fail = false;
      this->packet_param_count = 0;
      this->packet_structure_match = false;
      this->status_message = "";
    }
  }

  explicit GKV2ConfigStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : device_name(_alloc),
    serial_number(_alloc),
    status_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_name = "";
      this->serial_number = "";
      this->firmware_version = 0;
      this->algorithm_mode = 0;
      this->connection_ok = false;
      this->data_ready = false;
      this->adc_overflow = false;
      this->adc_skip = false;
      this->gyroscope_fail = false;
      this->accelerometer_fail = false;
      this->packet_param_count = 0;
      this->packet_structure_match = false;
      this->status_message = "";
    }
  }

  // field types and members
  using _device_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_name_type device_name;
  using _serial_number_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _serial_number_type serial_number;
  using _firmware_version_type =
    uint16_t;
  _firmware_version_type firmware_version;
  using _algorithm_mode_type =
    uint8_t;
  _algorithm_mode_type algorithm_mode;
  using _connection_ok_type =
    bool;
  _connection_ok_type connection_ok;
  using _data_ready_type =
    bool;
  _data_ready_type data_ready;
  using _adc_overflow_type =
    bool;
  _adc_overflow_type adc_overflow;
  using _adc_skip_type =
    bool;
  _adc_skip_type adc_skip;
  using _gyroscope_fail_type =
    bool;
  _gyroscope_fail_type gyroscope_fail;
  using _accelerometer_fail_type =
    bool;
  _accelerometer_fail_type accelerometer_fail;
  using _packet_param_count_type =
    uint8_t;
  _packet_param_count_type packet_param_count;
  using _packet_param_ids_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _packet_param_ids_type packet_param_ids;
  using _packet_structure_match_type =
    bool;
  _packet_structure_match_type packet_structure_match;
  using _status_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_message_type status_message;

  // setters for named parameter idiom
  Type & set__device_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_name = _arg;
    return *this;
  }
  Type & set__serial_number(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->serial_number = _arg;
    return *this;
  }
  Type & set__firmware_version(
    const uint16_t & _arg)
  {
    this->firmware_version = _arg;
    return *this;
  }
  Type & set__algorithm_mode(
    const uint8_t & _arg)
  {
    this->algorithm_mode = _arg;
    return *this;
  }
  Type & set__connection_ok(
    const bool & _arg)
  {
    this->connection_ok = _arg;
    return *this;
  }
  Type & set__data_ready(
    const bool & _arg)
  {
    this->data_ready = _arg;
    return *this;
  }
  Type & set__adc_overflow(
    const bool & _arg)
  {
    this->adc_overflow = _arg;
    return *this;
  }
  Type & set__adc_skip(
    const bool & _arg)
  {
    this->adc_skip = _arg;
    return *this;
  }
  Type & set__gyroscope_fail(
    const bool & _arg)
  {
    this->gyroscope_fail = _arg;
    return *this;
  }
  Type & set__accelerometer_fail(
    const bool & _arg)
  {
    this->accelerometer_fail = _arg;
    return *this;
  }
  Type & set__packet_param_count(
    const uint8_t & _arg)
  {
    this->packet_param_count = _arg;
    return *this;
  }
  Type & set__packet_param_ids(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->packet_param_ids = _arg;
    return *this;
  }
  Type & set__packet_structure_match(
    const bool & _arg)
  {
    this->packet_structure_match = _arg;
    return *this;
  }
  Type & set__status_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status_message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gkv2_motor_bridge__msg__GKV2ConfigStatus
    std::shared_ptr<gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gkv2_motor_bridge__msg__GKV2ConfigStatus
    std::shared_ptr<gkv2_motor_bridge::msg::GKV2ConfigStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GKV2ConfigStatus_ & other) const
  {
    if (this->device_name != other.device_name) {
      return false;
    }
    if (this->serial_number != other.serial_number) {
      return false;
    }
    if (this->firmware_version != other.firmware_version) {
      return false;
    }
    if (this->algorithm_mode != other.algorithm_mode) {
      return false;
    }
    if (this->connection_ok != other.connection_ok) {
      return false;
    }
    if (this->data_ready != other.data_ready) {
      return false;
    }
    if (this->adc_overflow != other.adc_overflow) {
      return false;
    }
    if (this->adc_skip != other.adc_skip) {
      return false;
    }
    if (this->gyroscope_fail != other.gyroscope_fail) {
      return false;
    }
    if (this->accelerometer_fail != other.accelerometer_fail) {
      return false;
    }
    if (this->packet_param_count != other.packet_param_count) {
      return false;
    }
    if (this->packet_param_ids != other.packet_param_ids) {
      return false;
    }
    if (this->packet_structure_match != other.packet_structure_match) {
      return false;
    }
    if (this->status_message != other.status_message) {
      return false;
    }
    return true;
  }
  bool operator!=(const GKV2ConfigStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GKV2ConfigStatus_

// alias to use template instance with default allocator
using GKV2ConfigStatus =
  gkv2_motor_bridge::msg::GKV2ConfigStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gkv2_motor_bridge

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__STRUCT_HPP_
