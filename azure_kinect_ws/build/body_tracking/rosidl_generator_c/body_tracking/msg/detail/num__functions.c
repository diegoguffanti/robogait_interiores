// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from body_tracking:msg/Num.idl
// generated code does not contain a copyright notice
#include "body_tracking/msg/detail/num__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
body_tracking__msg__Num__init(body_tracking__msg__Num * msg)
{
  if (!msg) {
    return false;
  }
  // num
  return true;
}

void
body_tracking__msg__Num__fini(body_tracking__msg__Num * msg)
{
  if (!msg) {
    return;
  }
  // num
}

body_tracking__msg__Num *
body_tracking__msg__Num__create()
{
  body_tracking__msg__Num * msg = (body_tracking__msg__Num *)malloc(sizeof(body_tracking__msg__Num));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(body_tracking__msg__Num));
  bool success = body_tracking__msg__Num__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
body_tracking__msg__Num__destroy(body_tracking__msg__Num * msg)
{
  if (msg) {
    body_tracking__msg__Num__fini(msg);
  }
  free(msg);
}


bool
body_tracking__msg__Num__Sequence__init(body_tracking__msg__Num__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  body_tracking__msg__Num * data = NULL;
  if (size) {
    data = (body_tracking__msg__Num *)calloc(size, sizeof(body_tracking__msg__Num));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = body_tracking__msg__Num__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        body_tracking__msg__Num__fini(&data[i - 1]);
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
body_tracking__msg__Num__Sequence__fini(body_tracking__msg__Num__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      body_tracking__msg__Num__fini(&array->data[i]);
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

body_tracking__msg__Num__Sequence *
body_tracking__msg__Num__Sequence__create(size_t size)
{
  body_tracking__msg__Num__Sequence * array = (body_tracking__msg__Num__Sequence *)malloc(sizeof(body_tracking__msg__Num__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = body_tracking__msg__Num__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
body_tracking__msg__Num__Sequence__destroy(body_tracking__msg__Num__Sequence * array)
{
  if (array) {
    body_tracking__msg__Num__Sequence__fini(array);
  }
  free(array);
}
