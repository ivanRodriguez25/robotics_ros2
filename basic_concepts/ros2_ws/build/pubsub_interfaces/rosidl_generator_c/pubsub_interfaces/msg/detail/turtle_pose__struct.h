// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pubsub_interfaces:msg/TurtlePose.idl
// generated code does not contain a copyright notice

#ifndef PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__STRUCT_H_
#define PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/TurtlePose in the package pubsub_interfaces.
typedef struct pubsub_interfaces__msg__TurtlePose
{
  double x;
  double y;
  double theta;
  double linear_velocity;
  double angular_velocity;
} pubsub_interfaces__msg__TurtlePose;

// Struct for a sequence of pubsub_interfaces__msg__TurtlePose.
typedef struct pubsub_interfaces__msg__TurtlePose__Sequence
{
  pubsub_interfaces__msg__TurtlePose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pubsub_interfaces__msg__TurtlePose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__STRUCT_H_
