// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from body_tracking:msg/HipCoordinates.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__STRUCT_H_
#define BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/HipCoordinates in the package body_tracking.
typedef struct body_tracking__msg__HipCoordinates
{
  double x;
  double y;
  double z;
} body_tracking__msg__HipCoordinates;

// Struct for a sequence of body_tracking__msg__HipCoordinates.
typedef struct body_tracking__msg__HipCoordinates__Sequence
{
  body_tracking__msg__HipCoordinates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} body_tracking__msg__HipCoordinates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__STRUCT_H_
