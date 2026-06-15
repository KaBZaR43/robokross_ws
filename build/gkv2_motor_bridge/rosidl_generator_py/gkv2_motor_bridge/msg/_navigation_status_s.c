// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "gkv2_motor_bridge/msg/detail/navigation_status__struct.h"
#include "gkv2_motor_bridge/msg/detail/navigation_status__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool gkv2_motor_bridge__msg__navigation_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("gkv2_motor_bridge.msg._navigation_status.NavigationStatus", full_classname_dest, 57) == 0);
  }
  gkv2_motor_bridge__msg__NavigationStatus * ros_message = _ros_message;
  {  // current_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gnss_available
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_available");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->gnss_available = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rtk_fixed
    PyObject * field = PyObject_GetAttrString(_pymsg, "rtk_fixed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rtk_fixed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gnss_satellites
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_satellites");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gnss_satellites = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gnss_quality
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_quality");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gnss_quality = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // odometry_drift
    PyObject * field = PyObject_GetAttrString(_pymsg, "odometry_drift");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->odometry_drift = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // time_since_gnss
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_since_gnss");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->time_since_gnss = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // status_message
    PyObject * field = PyObject_GetAttrString(_pymsg, "status_message");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->status_message, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * gkv2_motor_bridge__msg__navigation_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavigationStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("gkv2_motor_bridge.msg._navigation_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavigationStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  gkv2_motor_bridge__msg__NavigationStatus * ros_message = (gkv2_motor_bridge__msg__NavigationStatus *)raw_ros_message;
  {  // current_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->current_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_available
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->gnss_available ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_available", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rtk_fixed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rtk_fixed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rtk_fixed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_satellites
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gnss_satellites);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_satellites", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_quality
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gnss_quality);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_quality", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // odometry_drift
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->odometry_drift);
    {
      int rc = PyObject_SetAttrString(_pymessage, "odometry_drift", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // time_since_gnss
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->time_since_gnss);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_since_gnss", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // status_message
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->status_message.data,
      strlen(ros_message->status_message.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "status_message", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
