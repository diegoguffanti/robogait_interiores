// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from body_tracker_msgs:msg/SpineBottom.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "body_tracker_msgs/msg/detail/spine_bottom__rosidl_typesupport_introspection_c.h"
#include "body_tracker_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "body_tracker_msgs/msg/detail/spine_bottom__functions.h"
#include "body_tracker_msgs/msg/detail/spine_bottom__struct.h"


// Include directives for member types
// Member `joint_position_spine_bottom`
#include "geometry_msgs/msg/point32.h"
// Member `joint_position_spine_bottom`
#include "geometry_msgs/msg/detail/point32__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  body_tracker_msgs__msg__SpineBottom__init(message_memory);
}

void SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_fini_function(void * message_memory)
{
  body_tracker_msgs__msg__SpineBottom__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_message_member_array[3] = {
  {
    "body_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracker_msgs__msg__SpineBottom, body_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tiempo",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracker_msgs__msg__SpineBottom, tiempo),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_position_spine_bottom",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(body_tracker_msgs__msg__SpineBottom, joint_position_spine_bottom),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_message_members = {
  "body_tracker_msgs__msg",  // message namespace
  "SpineBottom",  // message name
  3,  // number of fields
  sizeof(body_tracker_msgs__msg__SpineBottom),
  SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_message_member_array,  // message members
  SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_init_function,  // function to initialize message memory (memory has to be allocated)
  SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_message_type_support_handle = {
  0,
  &SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_body_tracker_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, body_tracker_msgs, msg, SpineBottom)() {
  SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point32)();
  if (!SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_message_type_support_handle.typesupport_identifier) {
    SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SpineBottom__rosidl_typesupport_introspection_c__SpineBottom_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
