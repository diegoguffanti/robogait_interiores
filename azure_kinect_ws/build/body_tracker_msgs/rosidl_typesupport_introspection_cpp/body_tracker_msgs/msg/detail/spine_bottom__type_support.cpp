// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from body_tracker_msgs:msg/SpineBottom.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "body_tracker_msgs/msg/detail/spine_bottom__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace body_tracker_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SpineBottom_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) body_tracker_msgs::msg::SpineBottom(_init);
}

void SpineBottom_fini_function(void * message_memory)
{
  auto typed_message = static_cast<body_tracker_msgs::msg::SpineBottom *>(message_memory);
  typed_message->~SpineBottom();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SpineBottom_message_member_array[3] = {
  {
    "body_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracker_msgs::msg::SpineBottom, body_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tiempo",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracker_msgs::msg::SpineBottom, tiempo),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_position_spine_bottom",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point32>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracker_msgs::msg::SpineBottom, joint_position_spine_bottom),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SpineBottom_message_members = {
  "body_tracker_msgs::msg",  // message namespace
  "SpineBottom",  // message name
  3,  // number of fields
  sizeof(body_tracker_msgs::msg::SpineBottom),
  SpineBottom_message_member_array,  // message members
  SpineBottom_init_function,  // function to initialize message memory (memory has to be allocated)
  SpineBottom_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SpineBottom_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SpineBottom_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace body_tracker_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<body_tracker_msgs::msg::SpineBottom>()
{
  return &::body_tracker_msgs::msg::rosidl_typesupport_introspection_cpp::SpineBottom_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, body_tracker_msgs, msg, SpineBottom)() {
  return &::body_tracker_msgs::msg::rosidl_typesupport_introspection_cpp::SpineBottom_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
