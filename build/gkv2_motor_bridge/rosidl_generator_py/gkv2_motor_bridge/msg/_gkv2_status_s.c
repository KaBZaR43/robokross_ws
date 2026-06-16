// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
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
#include "gkv2_motor_bridge/msg/detail/gkv2_status__struct.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool gkv2_motor_bridge__msg__gkv2_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
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
    assert(strncmp("gkv2_motor_bridge.msg._gkv2_status.GKV2Status", full_classname_dest, 45) == 0);
  }
  gkv2_motor_bridge__msg__GKV2Status * ros_message = _ros_message;
  {  // gps_state_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_state_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gps_state_status = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gnss_date_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_date_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->gnss_date_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gnss_time_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_time_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->gnss_time_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gnss_ambiguity_resolved
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_ambiguity_resolved");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->gnss_ambiguity_resolved = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gnss_coords_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_coords_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->gnss_coords_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gnss_diff_corrections
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_diff_corrections");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->gnss_diff_corrections = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gnss_fix_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_fix_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gnss_fix_type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rtk_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "rtk_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rtk_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gps_rel_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_rel_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gps_rel_status = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rel_nav_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_nav_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rel_nav_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rel_diff_applied
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_diff_applied");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rel_diff_applied = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rel_coords_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_coords_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rel_coords_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rel_ambiguity_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_ambiguity_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rel_ambiguity_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rel_heading_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_heading_mode");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rel_heading_mode = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rel_heading_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_heading_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rel_heading_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // alg_state_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_state_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->alg_state_status = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // alg_stage
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_stage");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->alg_stage = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // alg_correction
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_correction");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->alg_correction = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // alg_fails
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_fails");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->alg_fails = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // alg_navigation_ready
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_navigation_ready");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->alg_navigation_ready = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gps_num_satellites
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_num_satellites");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gps_num_satellites = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gnss_sig_lat
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_sig_lat");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gnss_sig_lat = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gnss_sig_lon
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_sig_lon");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gnss_sig_lon = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gnss_sig_alt
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_sig_alt");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gnss_sig_alt = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alg_var_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_var_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alg_var_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alg_var_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_var_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alg_var_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alg_var_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_var_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alg_var_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alg_var_vx
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_var_vx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alg_var_vx = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alg_var_vy
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_var_vy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alg_var_vy = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alg_var_vz
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_var_vz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alg_var_vz = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alg_var_psi
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_var_psi");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alg_var_psi = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alg_var_theta
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_var_theta");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alg_var_theta = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alg_var_phi
    PyObject * field = PyObject_GetAttrString(_pymsg, "alg_var_phi");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alg_var_phi = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gps_rel_heading
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_rel_heading");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gps_rel_heading = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gps_rel_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_rel_length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gps_rel_length = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // heading_from_dual_antenna
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading_from_dual_antenna");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->heading_from_dual_antenna = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * gkv2_motor_bridge__msg__gkv2_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GKV2Status */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("gkv2_motor_bridge.msg._gkv2_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GKV2Status");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  gkv2_motor_bridge__msg__GKV2Status * ros_message = (gkv2_motor_bridge__msg__GKV2Status *)raw_ros_message;
  {  // gps_state_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gps_state_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_state_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_date_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->gnss_date_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_date_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_time_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->gnss_time_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_time_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_ambiguity_resolved
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->gnss_ambiguity_resolved ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_ambiguity_resolved", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_coords_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->gnss_coords_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_coords_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_diff_corrections
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->gnss_diff_corrections ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_diff_corrections", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_fix_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gnss_fix_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_fix_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rtk_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rtk_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rtk_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gps_rel_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gps_rel_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_rel_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_nav_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rel_nav_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_nav_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_diff_applied
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rel_diff_applied ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_diff_applied", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_coords_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rel_coords_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_coords_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_ambiguity_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rel_ambiguity_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_ambiguity_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_heading_mode
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rel_heading_mode ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_heading_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_heading_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rel_heading_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_heading_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_state_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->alg_state_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_state_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_stage
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->alg_stage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_stage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_correction
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->alg_correction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_correction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_fails
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->alg_fails);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_fails", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_navigation_ready
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->alg_navigation_ready ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_navigation_ready", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gps_num_satellites
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gps_num_satellites);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_num_satellites", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_sig_lat
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gnss_sig_lat);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_sig_lat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_sig_lon
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gnss_sig_lon);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_sig_lon", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_sig_alt
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gnss_sig_alt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_sig_alt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_var_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alg_var_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_var_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_var_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alg_var_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_var_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_var_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alg_var_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_var_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_var_vx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alg_var_vx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_var_vx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_var_vy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alg_var_vy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_var_vy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_var_vz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alg_var_vz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_var_vz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_var_psi
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alg_var_psi);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_var_psi", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_var_theta
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alg_var_theta);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_var_theta", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alg_var_phi
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alg_var_phi);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alg_var_phi", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gps_rel_heading
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gps_rel_heading);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_rel_heading", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gps_rel_length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gps_rel_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_rel_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading_from_dual_antenna
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->heading_from_dual_antenna ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading_from_dual_antenna", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
