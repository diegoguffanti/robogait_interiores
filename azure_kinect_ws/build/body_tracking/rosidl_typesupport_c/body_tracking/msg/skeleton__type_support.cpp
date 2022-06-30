// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from body_tracking:msg/Skeleton.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "body_tracking/msg/rosidl_typesupport_c__visibility_control.h"
#include "body_tracking/msg/detail/skeleton__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace body_tracking
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _Skeleton_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Skeleton_type_support_ids_t;

static const _Skeleton_type_support_ids_t _Skeleton_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Skeleton_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Skeleton_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Skeleton_type_support_symbol_names_t _Skeleton_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, body_tracking, msg, Skeleton)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, body_tracking, msg, Skeleton)),
  }
};

typedef struct _Skeleton_type_support_data_t
{
  void * data[2];
} _Skeleton_type_support_data_t;

static _Skeleton_type_support_data_t _Skeleton_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Skeleton_message_typesupport_map = {
  2,
  "body_tracking",
  &_Skeleton_message_typesupport_ids.typesupport_identifier[0],
  &_Skeleton_message_typesupport_symbol_names.symbol_name[0],
  &_Skeleton_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Skeleton_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Skeleton_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace body_tracking

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_body_tracking
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, body_tracking, msg, Skeleton)() {
  return &::body_tracking::msg::rosidl_typesupport_c::Skeleton_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
