// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from body_tracker_msgs:msg/HipCoordinates.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKER_MSGS__MSG__DETAIL__HIP_COORDINATES__BUILDER_HPP_
#define BODY_TRACKER_MSGS__MSG__DETAIL__HIP_COORDINATES__BUILDER_HPP_

#include "body_tracker_msgs/msg/detail/hip_coordinates__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace body_tracker_msgs
{

namespace msg
{

namespace builder
{

class Init_HipCoordinates_z
{
public:
  explicit Init_HipCoordinates_z(::body_tracker_msgs::msg::HipCoordinates & msg)
  : msg_(msg)
  {}
  ::body_tracker_msgs::msg::HipCoordinates z(::body_tracker_msgs::msg::HipCoordinates::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::body_tracker_msgs::msg::HipCoordinates msg_;
};

class Init_HipCoordinates_y
{
public:
  explicit Init_HipCoordinates_y(::body_tracker_msgs::msg::HipCoordinates & msg)
  : msg_(msg)
  {}
  Init_HipCoordinates_z y(::body_tracker_msgs::msg::HipCoordinates::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_HipCoordinates_z(msg_);
  }

private:
  ::body_tracker_msgs::msg::HipCoordinates msg_;
};

class Init_HipCoordinates_x
{
public:
  Init_HipCoordinates_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HipCoordinates_y x(::body_tracker_msgs::msg::HipCoordinates::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_HipCoordinates_y(msg_);
  }

private:
  ::body_tracker_msgs::msg::HipCoordinates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::body_tracker_msgs::msg::HipCoordinates>()
{
  return body_tracker_msgs::msg::builder::Init_HipCoordinates_x();
}

}  // namespace body_tracker_msgs

#endif  // BODY_TRACKER_MSGS__MSG__DETAIL__HIP_COORDINATES__BUILDER_HPP_
