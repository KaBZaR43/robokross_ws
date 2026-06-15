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
      this->gps_num_satellites = 0;
      this->alg_state_status = 0.0f;
      this->rtk_fixed = false;
    }
  }

  explicit GKV2Status_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gps_state_status = 0ul;
      this->gps_num_satellites = 0;
      this->alg_state_status = 0.0f;
      this->rtk_fixed = false;
    }
  }

  // field types and members
  using _gps_state_status_type =
    uint32_t;
  _gps_state_status_type gps_state_status;
  using _gps_num_satellites_type =
    uint16_t;
  _gps_num_satellites_type gps_num_satellites;
  using _alg_state_status_type =
    float;
  _alg_state_status_type alg_state_status;
  using _rtk_fixed_type =
    bool;
  _rtk_fixed_type rtk_fixed;

  // setters for named parameter idiom
  Type & set__gps_state_status(
    const uint32_t & _arg)
  {
    this->gps_state_status = _arg;
    return *this;
  }
  Type & set__gps_num_satellites(
    const uint16_t & _arg)
  {
    this->gps_num_satellites = _arg;
    return *this;
  }
  Type & set__alg_state_status(
    const float & _arg)
  {
    this->alg_state_status = _arg;
    return *this;
  }
  Type & set__rtk_fixed(
    const bool & _arg)
  {
    this->rtk_fixed = _arg;
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
    if (this->gps_num_satellites != other.gps_num_satellites) {
      return false;
    }
    if (this->alg_state_status != other.alg_state_status) {
      return false;
    }
    if (this->rtk_fixed != other.rtk_fixed) {
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
