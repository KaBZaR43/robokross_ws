// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
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
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__struct.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool gkv2_motor_bridge__msg__gkv2_config_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[59];
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
    assert(strncmp("gkv2_motor_bridge.msg._gkv2_config_status.GKV2ConfigStatus", full_classname_dest, 58) == 0);
  }
  gkv2_motor_bridge__msg__GKV2ConfigStatus * ros_message = _ros_message;
  {  // device_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->device_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // serial_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "serial_number");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->serial_number, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // firmware_version
    PyObject * field = PyObject_GetAttrString(_pymsg, "firmware_version");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->firmware_version = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // algorithm_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "algorithm_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->algorithm_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // connection_ok
    PyObject * field = PyObject_GetAttrString(_pymsg, "connection_ok");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->connection_ok = (Py_True == field);
    Py_DECREF(field);
  }
  {  // data_ready
    PyObject * field = PyObject_GetAttrString(_pymsg, "data_ready");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->data_ready = (Py_True == field);
    Py_DECREF(field);
  }
  {  // adc_overflow
    PyObject * field = PyObject_GetAttrString(_pymsg, "adc_overflow");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->adc_overflow = (Py_True == field);
    Py_DECREF(field);
  }
  {  // adc_skip
    PyObject * field = PyObject_GetAttrString(_pymsg, "adc_skip");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->adc_skip = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gyroscope_fail
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyroscope_fail");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->gyroscope_fail = (Py_True == field);
    Py_DECREF(field);
  }
  {  // accelerometer_fail
    PyObject * field = PyObject_GetAttrString(_pymsg, "accelerometer_fail");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->accelerometer_fail = (Py_True == field);
    Py_DECREF(field);
  }
  {  // packet_param_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "packet_param_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->packet_param_count = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // packet_param_ids
    PyObject * field = PyObject_GetAttrString(_pymsg, "packet_param_ids");
    if (!field) {
      return false;
    }
    if (PyObject_CheckBuffer(field)) {
      // Optimization for converting arrays of primitives
      Py_buffer view;
      int rc = PyObject_GetBuffer(field, &view, PyBUF_SIMPLE);
      if (rc < 0) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = view.len / sizeof(int32_t);
      if (!rosidl_runtime_c__int32__Sequence__init(&(ros_message->packet_param_ids), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create int32__Sequence ros_message");
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      int32_t * dest = ros_message->packet_param_ids.data;
      rc = PyBuffer_ToContiguous(dest, &view, view.len, 'C');
      if (rc < 0) {
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      PyBuffer_Release(&view);
    } else {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'packet_param_ids'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = PySequence_Size(field);
      if (-1 == size) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      if (!rosidl_runtime_c__int32__Sequence__init(&(ros_message->packet_param_ids), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create int32__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      int32_t * dest = ros_message->packet_param_ids.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyLong_Check(item));
        int32_t tmp = (int32_t)PyLong_AsLong(item);
        memcpy(&dest[i], &tmp, sizeof(int32_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // packet_structure_match
    PyObject * field = PyObject_GetAttrString(_pymsg, "packet_structure_match");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->packet_structure_match = (Py_True == field);
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
PyObject * gkv2_motor_bridge__msg__gkv2_config_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GKV2ConfigStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("gkv2_motor_bridge.msg._gkv2_config_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GKV2ConfigStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  gkv2_motor_bridge__msg__GKV2ConfigStatus * ros_message = (gkv2_motor_bridge__msg__GKV2ConfigStatus *)raw_ros_message;
  {  // device_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->device_name.data,
      strlen(ros_message->device_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // serial_number
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->serial_number.data,
      strlen(ros_message->serial_number.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "serial_number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // firmware_version
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->firmware_version);
    {
      int rc = PyObject_SetAttrString(_pymessage, "firmware_version", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // algorithm_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->algorithm_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "algorithm_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // connection_ok
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->connection_ok ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "connection_ok", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // data_ready
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->data_ready ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "data_ready", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // adc_overflow
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->adc_overflow ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "adc_overflow", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // adc_skip
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->adc_skip ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "adc_skip", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyroscope_fail
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->gyroscope_fail ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyroscope_fail", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // accelerometer_fail
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->accelerometer_fail ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "accelerometer_fail", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // packet_param_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->packet_param_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "packet_param_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // packet_param_ids
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "packet_param_ids");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "array.array") == 0);
    // ensure that itemsize matches the sizeof of the ROS message field
    PyObject * itemsize_attr = PyObject_GetAttrString(field, "itemsize");
    assert(itemsize_attr != NULL);
    size_t itemsize = PyLong_AsSize_t(itemsize_attr);
    Py_DECREF(itemsize_attr);
    if (itemsize != sizeof(int32_t)) {
      PyErr_SetString(PyExc_RuntimeError, "itemsize doesn't match expectation");
      Py_DECREF(field);
      return NULL;
    }
    // clear the array, poor approach to remove potential default values
    Py_ssize_t length = PyObject_Length(field);
    if (-1 == length) {
      Py_DECREF(field);
      return NULL;
    }
    if (length > 0) {
      PyObject * pop = PyObject_GetAttrString(field, "pop");
      assert(pop != NULL);
      for (Py_ssize_t i = 0; i < length; ++i) {
        PyObject * ret = PyObject_CallFunctionObjArgs(pop, NULL);
        if (!ret) {
          Py_DECREF(pop);
          Py_DECREF(field);
          return NULL;
        }
        Py_DECREF(ret);
      }
      Py_DECREF(pop);
    }
    if (ros_message->packet_param_ids.size > 0) {
      // populating the array.array using the frombytes method
      PyObject * frombytes = PyObject_GetAttrString(field, "frombytes");
      assert(frombytes != NULL);
      int32_t * src = &(ros_message->packet_param_ids.data[0]);
      PyObject * data = PyBytes_FromStringAndSize((const char *)src, ros_message->packet_param_ids.size * sizeof(int32_t));
      assert(data != NULL);
      PyObject * ret = PyObject_CallFunctionObjArgs(frombytes, data, NULL);
      Py_DECREF(data);
      Py_DECREF(frombytes);
      if (!ret) {
        Py_DECREF(field);
        return NULL;
      }
      Py_DECREF(ret);
    }
    Py_DECREF(field);
  }
  {  // packet_structure_match
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->packet_structure_match ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "packet_structure_match", field);
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
