// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from body_tracker_msgs:msg/HipCoordinates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "body_tracker_msgs/msg/detail/hip_coordinates__rosidl_typesupport_introspection_c.h"
#include "body_tracker_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "body_tracker_msgs/msg/detail/hip_coordinates__functions.h"
#include "body_tracker_msgs/msg/detail/hip_coordinates__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  body_tracker_msgs__msg__HipCoordinates__init(message_memory);
}

void HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_fini_function(void * message_memory)
{
  body_tracker_msgs__msg__HipCoordinates__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracker_msgs__msg__HipCoordinates, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracker_msgs__msg__HipCoordinates, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracker_msgs__msg__HipCoordinates, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_message_members = {
  "body_tracker_msgs__msg",  // message namespace
  "HipCoordinates",  // message name
  3,  // number of fields
  sizeof(body_tracker_msgs__msg__HipCoordinates),
  HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_message_member_array,  // message members
  HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_message_type_support_handle = {
  0,
  &HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_body_tracker_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, body_tracker_msgs, msg, HipCoordinates)() {
  if (!HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_message_type_support_handle.typesupport_identifier) {
    HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HipCoordinates__rosidl_typesupport_introspection_c__HipCoordinates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
