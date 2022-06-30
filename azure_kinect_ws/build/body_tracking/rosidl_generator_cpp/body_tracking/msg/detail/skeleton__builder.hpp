// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from body_tracking:msg/Skeleton.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKING__MSG__DETAIL__SKELETON__BUILDER_HPP_
#define BODY_TRACKING__MSG__DETAIL__SKELETON__BUILDER_HPP_

#include "body_tracking/msg/detail/skeleton__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace body_tracking
{

namespace msg
{

namespace builder
{

class Init_Skeleton_joint_position_left_ankle
{
public:
  explicit Init_Skeleton_joint_position_left_ankle(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  ::body_tracking::msg::Skeleton joint_position_left_ankle(::body_tracking::msg::Skeleton::_joint_position_left_ankle_type arg)
  {
    msg_.joint_position_left_ankle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_left_knee
{
public:
  explicit Init_Skeleton_joint_position_left_knee(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_left_ankle joint_position_left_knee(::body_tracking::msg::Skeleton::_joint_position_left_knee_type arg)
  {
    msg_.joint_position_left_knee = std::move(arg);
    return Init_Skeleton_joint_position_left_ankle(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_left_hip
{
public:
  explicit Init_Skeleton_joint_position_left_hip(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_left_knee joint_position_left_hip(::body_tracking::msg::Skeleton::_joint_position_left_hip_type arg)
  {
    msg_.joint_position_left_hip = std::move(arg);
    return Init_Skeleton_joint_position_left_knee(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_right_ankle
{
public:
  explicit Init_Skeleton_joint_position_right_ankle(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_left_hip joint_position_right_ankle(::body_tracking::msg::Skeleton::_joint_position_right_ankle_type arg)
  {
    msg_.joint_position_right_ankle = std::move(arg);
    return Init_Skeleton_joint_position_left_hip(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_right_knee
{
public:
  explicit Init_Skeleton_joint_position_right_knee(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_right_ankle joint_position_right_knee(::body_tracking::msg::Skeleton::_joint_position_right_knee_type arg)
  {
    msg_.joint_position_right_knee = std::move(arg);
    return Init_Skeleton_joint_position_right_ankle(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_right_hip
{
public:
  explicit Init_Skeleton_joint_position_right_hip(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_right_knee joint_position_right_hip(::body_tracking::msg::Skeleton::_joint_position_right_hip_type arg)
  {
    msg_.joint_position_right_hip = std::move(arg);
    return Init_Skeleton_joint_position_right_knee(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_right_hand
{
public:
  explicit Init_Skeleton_joint_position_right_hand(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_right_hip joint_position_right_hand(::body_tracking::msg::Skeleton::_joint_position_right_hand_type arg)
  {
    msg_.joint_position_right_hand = std::move(arg);
    return Init_Skeleton_joint_position_right_hip(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_right_elbow
{
public:
  explicit Init_Skeleton_joint_position_right_elbow(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_right_hand joint_position_right_elbow(::body_tracking::msg::Skeleton::_joint_position_right_elbow_type arg)
  {
    msg_.joint_position_right_elbow = std::move(arg);
    return Init_Skeleton_joint_position_right_hand(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_right_shoulder
{
public:
  explicit Init_Skeleton_joint_position_right_shoulder(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_right_elbow joint_position_right_shoulder(::body_tracking::msg::Skeleton::_joint_position_right_shoulder_type arg)
  {
    msg_.joint_position_right_shoulder = std::move(arg);
    return Init_Skeleton_joint_position_right_elbow(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_left_hand
{
public:
  explicit Init_Skeleton_joint_position_left_hand(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_right_shoulder joint_position_left_hand(::body_tracking::msg::Skeleton::_joint_position_left_hand_type arg)
  {
    msg_.joint_position_left_hand = std::move(arg);
    return Init_Skeleton_joint_position_right_shoulder(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_left_elbow
{
public:
  explicit Init_Skeleton_joint_position_left_elbow(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_left_hand joint_position_left_elbow(::body_tracking::msg::Skeleton::_joint_position_left_elbow_type arg)
  {
    msg_.joint_position_left_elbow = std::move(arg);
    return Init_Skeleton_joint_position_left_hand(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_left_shoulder
{
public:
  explicit Init_Skeleton_joint_position_left_shoulder(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_left_elbow joint_position_left_shoulder(::body_tracking::msg::Skeleton::_joint_position_left_shoulder_type arg)
  {
    msg_.joint_position_left_shoulder = std::move(arg);
    return Init_Skeleton_joint_position_left_elbow(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_spine_bottom
{
public:
  explicit Init_Skeleton_joint_position_spine_bottom(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_left_shoulder joint_position_spine_bottom(::body_tracking::msg::Skeleton::_joint_position_spine_bottom_type arg)
  {
    msg_.joint_position_spine_bottom = std::move(arg);
    return Init_Skeleton_joint_position_left_shoulder(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_spine_mid
{
public:
  explicit Init_Skeleton_joint_position_spine_mid(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_spine_bottom joint_position_spine_mid(::body_tracking::msg::Skeleton::_joint_position_spine_mid_type arg)
  {
    msg_.joint_position_spine_mid = std::move(arg);
    return Init_Skeleton_joint_position_spine_bottom(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_spine_top
{
public:
  explicit Init_Skeleton_joint_position_spine_top(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_spine_mid joint_position_spine_top(::body_tracking::msg::Skeleton::_joint_position_spine_top_type arg)
  {
    msg_.joint_position_spine_top = std::move(arg);
    return Init_Skeleton_joint_position_spine_mid(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_shoulder
{
public:
  explicit Init_Skeleton_joint_position_shoulder(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_spine_top joint_position_shoulder(::body_tracking::msg::Skeleton::_joint_position_shoulder_type arg)
  {
    msg_.joint_position_shoulder = std::move(arg);
    return Init_Skeleton_joint_position_spine_top(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_neck
{
public:
  explicit Init_Skeleton_joint_position_neck(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_shoulder joint_position_neck(::body_tracking::msg::Skeleton::_joint_position_neck_type arg)
  {
    msg_.joint_position_neck = std::move(arg);
    return Init_Skeleton_joint_position_shoulder(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_joint_position_head
{
public:
  explicit Init_Skeleton_joint_position_head(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_neck joint_position_head(::body_tracking::msg::Skeleton::_joint_position_head_type arg)
  {
    msg_.joint_position_head = std::move(arg);
    return Init_Skeleton_joint_position_neck(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_tiempo
{
public:
  explicit Init_Skeleton_tiempo(::body_tracking::msg::Skeleton & msg)
  : msg_(msg)
  {}
  Init_Skeleton_joint_position_head tiempo(::body_tracking::msg::Skeleton::_tiempo_type arg)
  {
    msg_.tiempo = std::move(arg);
    return Init_Skeleton_joint_position_head(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

class Init_Skeleton_body_id
{
public:
  Init_Skeleton_body_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Skeleton_tiempo body_id(::body_tracking::msg::Skeleton::_body_id_type arg)
  {
    msg_.body_id = std::move(arg);
    return Init_Skeleton_tiempo(msg_);
  }

private:
  ::body_tracking::msg::Skeleton msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::body_tracking::msg::Skeleton>()
{
  return body_tracking::msg::builder::Init_Skeleton_body_id();
}

}  // namespace body_tracking

#endif  // BODY_TRACKING__MSG__DETAIL__SKELETON__BUILDER_HPP_
