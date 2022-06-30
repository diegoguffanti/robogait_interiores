// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from body_tracker_msgs:msg/SpineBottom.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__STRUCT_HPP_
#define BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'joint_position_spine_bottom'
#include "geometry_msgs/msg/detail/point32__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__body_tracker_msgs__msg__SpineBottom __attribute__((deprecated))
#else
# define DEPRECATED__body_tracker_msgs__msg__SpineBottom __declspec(deprecated)
#endif

namespace body_tracker_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SpineBottom_
{
  using Type = SpineBottom_<ContainerAllocator>;

  explicit SpineBottom_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint_position_spine_bottom(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->body_id = 0l;
      this->tiempo = 0.0;
    }
  }

  explicit SpineBottom_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint_position_spine_bottom(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->body_id = 0l;
      this->tiempo = 0.0;
    }
  }

  // field types and members
  using _body_id_type =
    int32_t;
  _body_id_type body_id;
  using _tiempo_type =
    double;
  _tiempo_type tiempo;
  using _joint_position_spine_bottom_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_spine_bottom_type joint_position_spine_bottom;

  // setters for named parameter idiom
  Type & set__body_id(
    const int32_t & _arg)
  {
    this->body_id = _arg;
    return *this;
  }
  Type & set__tiempo(
    const double & _arg)
  {
    this->tiempo = _arg;
    return *this;
  }
  Type & set__joint_position_spine_bottom(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_spine_bottom = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    body_tracker_msgs::msg::SpineBottom_<ContainerAllocator> *;
  using ConstRawPtr =
    const body_tracker_msgs::msg::SpineBottom_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<body_tracker_msgs::msg::SpineBottom_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<body_tracker_msgs::msg::SpineBottom_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      body_tracker_msgs::msg::SpineBottom_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<body_tracker_msgs::msg::SpineBottom_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      body_tracker_msgs::msg::SpineBottom_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<body_tracker_msgs::msg::SpineBottom_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<body_tracker_msgs::msg::SpineBottom_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<body_tracker_msgs::msg::SpineBottom_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__body_tracker_msgs__msg__SpineBottom
    std::shared_ptr<body_tracker_msgs::msg::SpineBottom_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__body_tracker_msgs__msg__SpineBottom
    std::shared_ptr<body_tracker_msgs::msg::SpineBottom_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SpineBottom_ & other) const
  {
    if (this->body_id != other.body_id) {
      return false;
    }
    if (this->tiempo != other.tiempo) {
      return false;
    }
    if (this->joint_position_spine_bottom != other.joint_position_spine_bottom) {
      return false;
    }
    return true;
  }
  bool operator!=(const SpineBottom_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SpineBottom_

// alias to use template instance with default allocator
using SpineBottom =
  body_tracker_msgs::msg::SpineBottom_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace body_tracker_msgs

#endif  // BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__STRUCT_HPP_
