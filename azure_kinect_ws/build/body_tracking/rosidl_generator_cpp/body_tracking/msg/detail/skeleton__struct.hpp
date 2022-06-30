// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from body_tracking:msg/Skeleton.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKING__MSG__DETAIL__SKELETON__STRUCT_HPP_
#define BODY_TRACKING__MSG__DETAIL__SKELETON__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'joint_position_head'
// Member 'joint_position_neck'
// Member 'joint_position_shoulder'
// Member 'joint_position_spine_top'
// Member 'joint_position_spine_mid'
// Member 'joint_position_spine_bottom'
// Member 'joint_position_left_shoulder'
// Member 'joint_position_left_elbow'
// Member 'joint_position_left_hand'
// Member 'joint_position_right_shoulder'
// Member 'joint_position_right_elbow'
// Member 'joint_position_right_hand'
// Member 'joint_position_right_hip'
// Member 'joint_position_right_knee'
// Member 'joint_position_right_ankle'
// Member 'joint_position_left_hip'
// Member 'joint_position_left_knee'
// Member 'joint_position_left_ankle'
#include "geometry_msgs/msg/detail/point32__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__body_tracking__msg__Skeleton __attribute__((deprecated))
#else
# define DEPRECATED__body_tracking__msg__Skeleton __declspec(deprecated)
#endif

namespace body_tracking
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Skeleton_
{
  using Type = Skeleton_<ContainerAllocator>;

  explicit Skeleton_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint_position_head(_init),
    joint_position_neck(_init),
    joint_position_shoulder(_init),
    joint_position_spine_top(_init),
    joint_position_spine_mid(_init),
    joint_position_spine_bottom(_init),
    joint_position_left_shoulder(_init),
    joint_position_left_elbow(_init),
    joint_position_left_hand(_init),
    joint_position_right_shoulder(_init),
    joint_position_right_elbow(_init),
    joint_position_right_hand(_init),
    joint_position_right_hip(_init),
    joint_position_right_knee(_init),
    joint_position_right_ankle(_init),
    joint_position_left_hip(_init),
    joint_position_left_knee(_init),
    joint_position_left_ankle(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->body_id = 0l;
      this->tiempo = 0.0;
    }
  }

  explicit Skeleton_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint_position_head(_alloc, _init),
    joint_position_neck(_alloc, _init),
    joint_position_shoulder(_alloc, _init),
    joint_position_spine_top(_alloc, _init),
    joint_position_spine_mid(_alloc, _init),
    joint_position_spine_bottom(_alloc, _init),
    joint_position_left_shoulder(_alloc, _init),
    joint_position_left_elbow(_alloc, _init),
    joint_position_left_hand(_alloc, _init),
    joint_position_right_shoulder(_alloc, _init),
    joint_position_right_elbow(_alloc, _init),
    joint_position_right_hand(_alloc, _init),
    joint_position_right_hip(_alloc, _init),
    joint_position_right_knee(_alloc, _init),
    joint_position_right_ankle(_alloc, _init),
    joint_position_left_hip(_alloc, _init),
    joint_position_left_knee(_alloc, _init),
    joint_position_left_ankle(_alloc, _init)
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
  using _joint_position_head_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_head_type joint_position_head;
  using _joint_position_neck_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_neck_type joint_position_neck;
  using _joint_position_shoulder_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_shoulder_type joint_position_shoulder;
  using _joint_position_spine_top_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_spine_top_type joint_position_spine_top;
  using _joint_position_spine_mid_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_spine_mid_type joint_position_spine_mid;
  using _joint_position_spine_bottom_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_spine_bottom_type joint_position_spine_bottom;
  using _joint_position_left_shoulder_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_left_shoulder_type joint_position_left_shoulder;
  using _joint_position_left_elbow_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_left_elbow_type joint_position_left_elbow;
  using _joint_position_left_hand_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_left_hand_type joint_position_left_hand;
  using _joint_position_right_shoulder_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_right_shoulder_type joint_position_right_shoulder;
  using _joint_position_right_elbow_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_right_elbow_type joint_position_right_elbow;
  using _joint_position_right_hand_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_right_hand_type joint_position_right_hand;
  using _joint_position_right_hip_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_right_hip_type joint_position_right_hip;
  using _joint_position_right_knee_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_right_knee_type joint_position_right_knee;
  using _joint_position_right_ankle_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_right_ankle_type joint_position_right_ankle;
  using _joint_position_left_hip_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_left_hip_type joint_position_left_hip;
  using _joint_position_left_knee_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_left_knee_type joint_position_left_knee;
  using _joint_position_left_ankle_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _joint_position_left_ankle_type joint_position_left_ankle;

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
  Type & set__joint_position_head(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_head = _arg;
    return *this;
  }
  Type & set__joint_position_neck(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_neck = _arg;
    return *this;
  }
  Type & set__joint_position_shoulder(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_shoulder = _arg;
    return *this;
  }
  Type & set__joint_position_spine_top(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_spine_top = _arg;
    return *this;
  }
  Type & set__joint_position_spine_mid(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_spine_mid = _arg;
    return *this;
  }
  Type & set__joint_position_spine_bottom(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_spine_bottom = _arg;
    return *this;
  }
  Type & set__joint_position_left_shoulder(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_left_shoulder = _arg;
    return *this;
  }
  Type & set__joint_position_left_elbow(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_left_elbow = _arg;
    return *this;
  }
  Type & set__joint_position_left_hand(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_left_hand = _arg;
    return *this;
  }
  Type & set__joint_position_right_shoulder(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_right_shoulder = _arg;
    return *this;
  }
  Type & set__joint_position_right_elbow(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_right_elbow = _arg;
    return *this;
  }
  Type & set__joint_position_right_hand(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_right_hand = _arg;
    return *this;
  }
  Type & set__joint_position_right_hip(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_right_hip = _arg;
    return *this;
  }
  Type & set__joint_position_right_knee(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_right_knee = _arg;
    return *this;
  }
  Type & set__joint_position_right_ankle(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_right_ankle = _arg;
    return *this;
  }
  Type & set__joint_position_left_hip(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_left_hip = _arg;
    return *this;
  }
  Type & set__joint_position_left_knee(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_left_knee = _arg;
    return *this;
  }
  Type & set__joint_position_left_ankle(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->joint_position_left_ankle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    body_tracking::msg::Skeleton_<ContainerAllocator> *;
  using ConstRawPtr =
    const body_tracking::msg::Skeleton_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<body_tracking::msg::Skeleton_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<body_tracking::msg::Skeleton_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      body_tracking::msg::Skeleton_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<body_tracking::msg::Skeleton_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      body_tracking::msg::Skeleton_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<body_tracking::msg::Skeleton_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<body_tracking::msg::Skeleton_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<body_tracking::msg::Skeleton_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__body_tracking__msg__Skeleton
    std::shared_ptr<body_tracking::msg::Skeleton_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__body_tracking__msg__Skeleton
    std::shared_ptr<body_tracking::msg::Skeleton_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Skeleton_ & other) const
  {
    if (this->body_id != other.body_id) {
      return false;
    }
    if (this->tiempo != other.tiempo) {
      return false;
    }
    if (this->joint_position_head != other.joint_position_head) {
      return false;
    }
    if (this->joint_position_neck != other.joint_position_neck) {
      return false;
    }
    if (this->joint_position_shoulder != other.joint_position_shoulder) {
      return false;
    }
    if (this->joint_position_spine_top != other.joint_position_spine_top) {
      return false;
    }
    if (this->joint_position_spine_mid != other.joint_position_spine_mid) {
      return false;
    }
    if (this->joint_position_spine_bottom != other.joint_position_spine_bottom) {
      return false;
    }
    if (this->joint_position_left_shoulder != other.joint_position_left_shoulder) {
      return false;
    }
    if (this->joint_position_left_elbow != other.joint_position_left_elbow) {
      return false;
    }
    if (this->joint_position_left_hand != other.joint_position_left_hand) {
      return false;
    }
    if (this->joint_position_right_shoulder != other.joint_position_right_shoulder) {
      return false;
    }
    if (this->joint_position_right_elbow != other.joint_position_right_elbow) {
      return false;
    }
    if (this->joint_position_right_hand != other.joint_position_right_hand) {
      return false;
    }
    if (this->joint_position_right_hip != other.joint_position_right_hip) {
      return false;
    }
    if (this->joint_position_right_knee != other.joint_position_right_knee) {
      return false;
    }
    if (this->joint_position_right_ankle != other.joint_position_right_ankle) {
      return false;
    }
    if (this->joint_position_left_hip != other.joint_position_left_hip) {
      return false;
    }
    if (this->joint_position_left_knee != other.joint_position_left_knee) {
      return false;
    }
    if (this->joint_position_left_ankle != other.joint_position_left_ankle) {
      return false;
    }
    return true;
  }
  bool operator!=(const Skeleton_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Skeleton_

// alias to use template instance with default allocator
using Skeleton =
  body_tracking::msg::Skeleton_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace body_tracking

#endif  // BODY_TRACKING__MSG__DETAIL__SKELETON__STRUCT_HPP_
