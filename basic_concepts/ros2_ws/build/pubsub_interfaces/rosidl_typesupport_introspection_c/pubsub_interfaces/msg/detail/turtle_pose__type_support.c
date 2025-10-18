// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pubsub_interfaces:msg/TurtlePose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pubsub_interfaces/msg/detail/turtle_pose__rosidl_typesupport_introspection_c.h"
#include "pubsub_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pubsub_interfaces/msg/detail/turtle_pose__functions.h"
#include "pubsub_interfaces/msg/detail/turtle_pose__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pubsub_interfaces__msg__TurtlePose__init(message_memory);
}

void pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_fini_function(void * message_memory)
{
  pubsub_interfaces__msg__TurtlePose__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_message_member_array[5] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pubsub_interfaces__msg__TurtlePose, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
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
    offsetof(pubsub_interfaces__msg__TurtlePose, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pubsub_interfaces__msg__TurtlePose, theta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "linear_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pubsub_interfaces__msg__TurtlePose, linear_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pubsub_interfaces__msg__TurtlePose, angular_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_message_members = {
  "pubsub_interfaces__msg",  // message namespace
  "TurtlePose",  // message name
  5,  // number of fields
  sizeof(pubsub_interfaces__msg__TurtlePose),
  pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_message_member_array,  // message members
  pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_init_function,  // function to initialize message memory (memory has to be allocated)
  pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_message_type_support_handle = {
  0,
  &pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pubsub_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pubsub_interfaces, msg, TurtlePose)() {
  if (!pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_message_type_support_handle.typesupport_identifier) {
    pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pubsub_interfaces__msg__TurtlePose__rosidl_typesupport_introspection_c__TurtlePose_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
