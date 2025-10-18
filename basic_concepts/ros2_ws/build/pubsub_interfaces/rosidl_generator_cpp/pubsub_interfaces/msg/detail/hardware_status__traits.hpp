// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pubsub_interfaces:msg/HardwareStatus.idl
// generated code does not contain a copyright notice

#ifndef PUBSUB_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__TRAITS_HPP_
#define PUBSUB_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pubsub_interfaces/msg/detail/hardware_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pubsub_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HardwareStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: are_motors_ready
  {
    out << "are_motors_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.are_motors_ready, out);
    out << ", ";
  }

  // member: debug_message
  {
    out << "debug_message: ";
    rosidl_generator_traits::value_to_yaml(msg.debug_message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HardwareStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: are_motors_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "are_motors_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.are_motors_ready, out);
    out << "\n";
  }

  // member: debug_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "debug_message: ";
    rosidl_generator_traits::value_to_yaml(msg.debug_message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HardwareStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace pubsub_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use pubsub_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pubsub_interfaces::msg::HardwareStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  pubsub_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pubsub_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pubsub_interfaces::msg::HardwareStatus & msg)
{
  return pubsub_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pubsub_interfaces::msg::HardwareStatus>()
{
  return "pubsub_interfaces::msg::HardwareStatus";
}

template<>
inline const char * name<pubsub_interfaces::msg::HardwareStatus>()
{
  return "pubsub_interfaces/msg/HardwareStatus";
}

template<>
struct has_fixed_size<pubsub_interfaces::msg::HardwareStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pubsub_interfaces::msg::HardwareStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pubsub_interfaces::msg::HardwareStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PUBSUB_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__TRAITS_HPP_
