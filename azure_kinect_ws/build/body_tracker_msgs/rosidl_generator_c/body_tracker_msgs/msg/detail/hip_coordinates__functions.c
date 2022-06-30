// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from body_tracker_msgs:msg/HipCoordinates.idl
// generated code does not contain a copyright notice
#include "body_tracker_msgs/msg/detail/hip_coordinates__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
body_tracker_msgs__msg__HipCoordinates__init(body_tracker_msgs__msg__HipCoordinates * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
body_tracker_msgs__msg__HipCoordinates__fini(body_tracker_msgs__msg__HipCoordinates * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
}

body_tracker_msgs__msg__HipCoordinates *
body_tracker_msgs__msg__HipCoordinates__create()
{
  body_tracker_msgs__msg__HipCoordinates * msg = (body_tracker_msgs__msg__HipCoordinates *)malloc(sizeof(body_tracker_msgs__msg__HipCoordinates));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(body_tracker_msgs__msg__HipCoordinates));
  bool success = body_tracker_msgs__msg__HipCoordinates__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
body_tracker_msgs__msg__HipCoordinates__destroy(body_tracker_msgs__msg__HipCoordinates * msg)
{
  if (msg) {
    body_tracker_msgs__msg__HipCoordinates__fini(msg);
  }
  free(msg);
}


bool
body_tracker_msgs__msg__HipCoordinates__Sequence__init(body_tracker_msgs__msg__HipCoordinates__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  body_tracker_msgs__msg__HipCoordinates * data = NULL;
  if (size) {
    data = (body_tracker_msgs__msg__HipCoordinates *)calloc(size, sizeof(body_tracker_msgs__msg__HipCoordinates));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = body_tracker_msgs__msg__HipCoordinates__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        body_tracker_msgs__msg__HipCoordinates__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
body_tracker_msgs__msg__HipCoordinates__Sequence__fini(body_tracker_msgs__msg__HipCoordinates__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      body_tracker_msgs__msg__HipCoordinates__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

body_tracker_msgs__msg__HipCoordinates__Sequence *
body_tracker_msgs__msg__HipCoordinates__Sequence__create(size_t size)
{
  body_tracker_msgs__msg__HipCoordinates__Sequence * array = (body_tracker_msgs__msg__HipCoordinates__Sequence *)malloc(sizeof(body_tracker_msgs__msg__HipCoordinates__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = body_tracker_msgs__msg__HipCoordinates__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
body_tracker_msgs__msg__HipCoordinates__Sequence__destroy(body_tracker_msgs__msg__HipCoordinates__Sequence * array)
{
  if (array) {
    body_tracker_msgs__msg__HipCoordinates__Sequence__fini(array);
  }
  free(array);
}
