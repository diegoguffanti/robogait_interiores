// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from body_tracker_msgs:msg/SpineBottom.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__BUILDER_HPP_
#define BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__BUILDER_HPP_

#include "body_tracker_msgs/msg/detail/spine_bottom__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace body_tracker_msgs
{

namespace msg
{

namespace builder
{

class Init_SpineBottom_joint_position_spine_bottom
{
public:
  explicit Init_SpineBottom_joint_position_spine_bottom(::body_tracker_msgs::msg::SpineBottom & msg)
  : msg_(msg)
  {}
  ::body_tracker_msgs::msg::SpineBottom joint_position_spine_bottom(::body_tracker_msgs::msg::SpineBottom::_joint_position_spine_bottom_type arg)
  {
    msg_.joint_position_spine_bottom = std::move(arg);
    return std::move(msg_);
  }

private:
  ::body_tracker_msgs::msg::SpineBottom msg_;
};

class Init_SpineBottom_tiempo
{
public:
  explicit Init_SpineBottom_tiempo(::body_tracker_msgs::msg::SpineBottom & msg)
  : msg_(msg)
  {}
  Init_SpineBottom_joint_position_spine_bottom tiempo(::body_tracker_msgs::msg::SpineBottom::_tiempo_type arg)
  {
    msg_.tiempo = std::move(arg);
    return Init_SpineBottom_joint_position_spine_bottom(msg_);
  }

private:
  ::body_tracker_msgs::msg::SpineBottom msg_;
};

class Init_SpineBottom_body_id
{
public:
  Init_SpineBottom_body_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpineBottom_tiempo body_id(::body_tracker_msgs::msg::SpineBottom::_body_id_type arg)
  {
    msg_.body_id = std::move(arg);
    return Init_SpineBottom_tiempo(msg_);
  }

private:
  ::body_tracker_msgs::msg::SpineBottom msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::body_tracker_msgs::msg::SpineBottom>()
{
  return body_tracker_msgs::msg::builder::Init_SpineBottom_body_id();
}

}  // namespace body_tracker_msgs

#endif  // BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__BUILDER_HPP_
