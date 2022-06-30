// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from body_tracking:msg/HipCoordinates.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "body_tracking/msg/detail/hip_coordinates__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace body_tracking
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void HipCoordinates_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) body_tracking::msg::HipCoordinates(_init);
}

void HipCoordinates_fini_function(void * message_memory)
{
  auto typed_message = static_cast<body_tracking::msg::HipCoordinates *>(message_memory);
  typed_message->~HipCoordinates();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HipCoordinates_message_member_array[3] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracking::msg::HipCoordinates, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracking::msg::HipCoordinates, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "z",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracking::msg::HipCoordinates, z),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HipCoordinates_message_members = {
  "body_tracking::msg",  // message namespace
  "HipCoordinates",  // message name
  3,  // number of fields
  sizeof(body_tracking::msg::HipCoordinates),
  HipCoordinates_message_member_array,  // message members
  HipCoordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  HipCoordinates_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HipCoordinates_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HipCoordinates_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace body_tracking


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<body_tracking::msg::HipCoordinates>()
{
  return &::body_tracking::msg::rosidl_typesupport_introspection_cpp::HipCoordinates_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, body_tracking, msg, HipCoordinates)() {
  return &::body_tracking::msg::rosidl_typesupport_introspection_cpp::HipCoordinates_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
