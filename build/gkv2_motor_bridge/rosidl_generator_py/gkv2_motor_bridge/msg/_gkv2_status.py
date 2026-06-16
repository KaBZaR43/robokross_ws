# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gkv2_motor_bridge:msg/GKV2Status.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GKV2Status(type):
    """Metaclass of message 'GKV2Status'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('gkv2_motor_bridge')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'gkv2_motor_bridge.msg.GKV2Status')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gkv2_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gkv2_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gkv2_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gkv2_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gkv2_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GKV2Status(metaclass=Metaclass_GKV2Status):
    """Message class 'GKV2Status'."""

    __slots__ = [
        '_gps_state_status',
        '_gnss_date_valid',
        '_gnss_time_valid',
        '_gnss_ambiguity_resolved',
        '_gnss_coords_valid',
        '_gnss_diff_corrections',
        '_gnss_fix_type',
        '_rtk_status',
        '_gps_rel_status',
        '_rel_nav_valid',
        '_rel_diff_applied',
        '_rel_coords_valid',
        '_rel_ambiguity_status',
        '_rel_heading_mode',
        '_rel_heading_valid',
        '_alg_state_status',
        '_alg_stage',
        '_alg_correction',
        '_alg_fails',
        '_alg_navigation_ready',
        '_gps_num_satellites',
        '_gnss_sig_lat',
        '_gnss_sig_lon',
        '_gnss_sig_alt',
        '_alg_var_x',
        '_alg_var_y',
        '_alg_var_z',
        '_alg_var_vx',
        '_alg_var_vy',
        '_alg_var_vz',
        '_alg_var_psi',
        '_alg_var_theta',
        '_alg_var_phi',
        '_gps_rel_heading',
        '_gps_rel_length',
        '_heading_from_dual_antenna',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'gps_state_status': 'uint32',
        'gnss_date_valid': 'boolean',
        'gnss_time_valid': 'boolean',
        'gnss_ambiguity_resolved': 'boolean',
        'gnss_coords_valid': 'boolean',
        'gnss_diff_corrections': 'boolean',
        'gnss_fix_type': 'uint8',
        'rtk_status': 'uint8',
        'gps_rel_status': 'uint32',
        'rel_nav_valid': 'boolean',
        'rel_diff_applied': 'boolean',
        'rel_coords_valid': 'boolean',
        'rel_ambiguity_status': 'uint8',
        'rel_heading_mode': 'boolean',
        'rel_heading_valid': 'boolean',
        'alg_state_status': 'uint32',
        'alg_stage': 'uint8',
        'alg_correction': 'uint8',
        'alg_fails': 'uint16',
        'alg_navigation_ready': 'boolean',
        'gps_num_satellites': 'uint16',
        'gnss_sig_lat': 'float',
        'gnss_sig_lon': 'float',
        'gnss_sig_alt': 'float',
        'alg_var_x': 'float',
        'alg_var_y': 'float',
        'alg_var_z': 'float',
        'alg_var_vx': 'float',
        'alg_var_vy': 'float',
        'alg_var_vz': 'float',
        'alg_var_psi': 'float',
        'alg_var_theta': 'float',
        'alg_var_phi': 'float',
        'gps_rel_heading': 'float',
        'gps_rel_length': 'float',
        'heading_from_dual_antenna': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.gps_state_status = kwargs.get('gps_state_status', int())
        self.gnss_date_valid = kwargs.get('gnss_date_valid', bool())
        self.gnss_time_valid = kwargs.get('gnss_time_valid', bool())
        self.gnss_ambiguity_resolved = kwargs.get('gnss_ambiguity_resolved', bool())
        self.gnss_coords_valid = kwargs.get('gnss_coords_valid', bool())
        self.gnss_diff_corrections = kwargs.get('gnss_diff_corrections', bool())
        self.gnss_fix_type = kwargs.get('gnss_fix_type', int())
        self.rtk_status = kwargs.get('rtk_status', int())
        self.gps_rel_status = kwargs.get('gps_rel_status', int())
        self.rel_nav_valid = kwargs.get('rel_nav_valid', bool())
        self.rel_diff_applied = kwargs.get('rel_diff_applied', bool())
        self.rel_coords_valid = kwargs.get('rel_coords_valid', bool())
        self.rel_ambiguity_status = kwargs.get('rel_ambiguity_status', int())
        self.rel_heading_mode = kwargs.get('rel_heading_mode', bool())
        self.rel_heading_valid = kwargs.get('rel_heading_valid', bool())
        self.alg_state_status = kwargs.get('alg_state_status', int())
        self.alg_stage = kwargs.get('alg_stage', int())
        self.alg_correction = kwargs.get('alg_correction', int())
        self.alg_fails = kwargs.get('alg_fails', int())
        self.alg_navigation_ready = kwargs.get('alg_navigation_ready', bool())
        self.gps_num_satellites = kwargs.get('gps_num_satellites', int())
        self.gnss_sig_lat = kwargs.get('gnss_sig_lat', float())
        self.gnss_sig_lon = kwargs.get('gnss_sig_lon', float())
        self.gnss_sig_alt = kwargs.get('gnss_sig_alt', float())
        self.alg_var_x = kwargs.get('alg_var_x', float())
        self.alg_var_y = kwargs.get('alg_var_y', float())
        self.alg_var_z = kwargs.get('alg_var_z', float())
        self.alg_var_vx = kwargs.get('alg_var_vx', float())
        self.alg_var_vy = kwargs.get('alg_var_vy', float())
        self.alg_var_vz = kwargs.get('alg_var_vz', float())
        self.alg_var_psi = kwargs.get('alg_var_psi', float())
        self.alg_var_theta = kwargs.get('alg_var_theta', float())
        self.alg_var_phi = kwargs.get('alg_var_phi', float())
        self.gps_rel_heading = kwargs.get('gps_rel_heading', float())
        self.gps_rel_length = kwargs.get('gps_rel_length', float())
        self.heading_from_dual_antenna = kwargs.get('heading_from_dual_antenna', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.gps_state_status != other.gps_state_status:
            return False
        if self.gnss_date_valid != other.gnss_date_valid:
            return False
        if self.gnss_time_valid != other.gnss_time_valid:
            return False
        if self.gnss_ambiguity_resolved != other.gnss_ambiguity_resolved:
            return False
        if self.gnss_coords_valid != other.gnss_coords_valid:
            return False
        if self.gnss_diff_corrections != other.gnss_diff_corrections:
            return False
        if self.gnss_fix_type != other.gnss_fix_type:
            return False
        if self.rtk_status != other.rtk_status:
            return False
        if self.gps_rel_status != other.gps_rel_status:
            return False
        if self.rel_nav_valid != other.rel_nav_valid:
            return False
        if self.rel_diff_applied != other.rel_diff_applied:
            return False
        if self.rel_coords_valid != other.rel_coords_valid:
            return False
        if self.rel_ambiguity_status != other.rel_ambiguity_status:
            return False
        if self.rel_heading_mode != other.rel_heading_mode:
            return False
        if self.rel_heading_valid != other.rel_heading_valid:
            return False
        if self.alg_state_status != other.alg_state_status:
            return False
        if self.alg_stage != other.alg_stage:
            return False
        if self.alg_correction != other.alg_correction:
            return False
        if self.alg_fails != other.alg_fails:
            return False
        if self.alg_navigation_ready != other.alg_navigation_ready:
            return False
        if self.gps_num_satellites != other.gps_num_satellites:
            return False
        if self.gnss_sig_lat != other.gnss_sig_lat:
            return False
        if self.gnss_sig_lon != other.gnss_sig_lon:
            return False
        if self.gnss_sig_alt != other.gnss_sig_alt:
            return False
        if self.alg_var_x != other.alg_var_x:
            return False
        if self.alg_var_y != other.alg_var_y:
            return False
        if self.alg_var_z != other.alg_var_z:
            return False
        if self.alg_var_vx != other.alg_var_vx:
            return False
        if self.alg_var_vy != other.alg_var_vy:
            return False
        if self.alg_var_vz != other.alg_var_vz:
            return False
        if self.alg_var_psi != other.alg_var_psi:
            return False
        if self.alg_var_theta != other.alg_var_theta:
            return False
        if self.alg_var_phi != other.alg_var_phi:
            return False
        if self.gps_rel_heading != other.gps_rel_heading:
            return False
        if self.gps_rel_length != other.gps_rel_length:
            return False
        if self.heading_from_dual_antenna != other.heading_from_dual_antenna:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def gps_state_status(self):
        """Message field 'gps_state_status'."""
        return self._gps_state_status

    @gps_state_status.setter
    def gps_state_status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'gps_state_status' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'gps_state_status' field must be an unsigned integer in [0, 4294967295]"
        self._gps_state_status = value

    @builtins.property
    def gnss_date_valid(self):
        """Message field 'gnss_date_valid'."""
        return self._gnss_date_valid

    @gnss_date_valid.setter
    def gnss_date_valid(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'gnss_date_valid' field must be of type 'bool'"
        self._gnss_date_valid = value

    @builtins.property
    def gnss_time_valid(self):
        """Message field 'gnss_time_valid'."""
        return self._gnss_time_valid

    @gnss_time_valid.setter
    def gnss_time_valid(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'gnss_time_valid' field must be of type 'bool'"
        self._gnss_time_valid = value

    @builtins.property
    def gnss_ambiguity_resolved(self):
        """Message field 'gnss_ambiguity_resolved'."""
        return self._gnss_ambiguity_resolved

    @gnss_ambiguity_resolved.setter
    def gnss_ambiguity_resolved(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'gnss_ambiguity_resolved' field must be of type 'bool'"
        self._gnss_ambiguity_resolved = value

    @builtins.property
    def gnss_coords_valid(self):
        """Message field 'gnss_coords_valid'."""
        return self._gnss_coords_valid

    @gnss_coords_valid.setter
    def gnss_coords_valid(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'gnss_coords_valid' field must be of type 'bool'"
        self._gnss_coords_valid = value

    @builtins.property
    def gnss_diff_corrections(self):
        """Message field 'gnss_diff_corrections'."""
        return self._gnss_diff_corrections

    @gnss_diff_corrections.setter
    def gnss_diff_corrections(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'gnss_diff_corrections' field must be of type 'bool'"
        self._gnss_diff_corrections = value

    @builtins.property
    def gnss_fix_type(self):
        """Message field 'gnss_fix_type'."""
        return self._gnss_fix_type

    @gnss_fix_type.setter
    def gnss_fix_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'gnss_fix_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gnss_fix_type' field must be an unsigned integer in [0, 255]"
        self._gnss_fix_type = value

    @builtins.property
    def rtk_status(self):
        """Message field 'rtk_status'."""
        return self._rtk_status

    @rtk_status.setter
    def rtk_status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'rtk_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rtk_status' field must be an unsigned integer in [0, 255]"
        self._rtk_status = value

    @builtins.property
    def gps_rel_status(self):
        """Message field 'gps_rel_status'."""
        return self._gps_rel_status

    @gps_rel_status.setter
    def gps_rel_status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'gps_rel_status' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'gps_rel_status' field must be an unsigned integer in [0, 4294967295]"
        self._gps_rel_status = value

    @builtins.property
    def rel_nav_valid(self):
        """Message field 'rel_nav_valid'."""
        return self._rel_nav_valid

    @rel_nav_valid.setter
    def rel_nav_valid(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'rel_nav_valid' field must be of type 'bool'"
        self._rel_nav_valid = value

    @builtins.property
    def rel_diff_applied(self):
        """Message field 'rel_diff_applied'."""
        return self._rel_diff_applied

    @rel_diff_applied.setter
    def rel_diff_applied(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'rel_diff_applied' field must be of type 'bool'"
        self._rel_diff_applied = value

    @builtins.property
    def rel_coords_valid(self):
        """Message field 'rel_coords_valid'."""
        return self._rel_coords_valid

    @rel_coords_valid.setter
    def rel_coords_valid(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'rel_coords_valid' field must be of type 'bool'"
        self._rel_coords_valid = value

    @builtins.property
    def rel_ambiguity_status(self):
        """Message field 'rel_ambiguity_status'."""
        return self._rel_ambiguity_status

    @rel_ambiguity_status.setter
    def rel_ambiguity_status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'rel_ambiguity_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rel_ambiguity_status' field must be an unsigned integer in [0, 255]"
        self._rel_ambiguity_status = value

    @builtins.property
    def rel_heading_mode(self):
        """Message field 'rel_heading_mode'."""
        return self._rel_heading_mode

    @rel_heading_mode.setter
    def rel_heading_mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'rel_heading_mode' field must be of type 'bool'"
        self._rel_heading_mode = value

    @builtins.property
    def rel_heading_valid(self):
        """Message field 'rel_heading_valid'."""
        return self._rel_heading_valid

    @rel_heading_valid.setter
    def rel_heading_valid(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'rel_heading_valid' field must be of type 'bool'"
        self._rel_heading_valid = value

    @builtins.property
    def alg_state_status(self):
        """Message field 'alg_state_status'."""
        return self._alg_state_status

    @alg_state_status.setter
    def alg_state_status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'alg_state_status' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'alg_state_status' field must be an unsigned integer in [0, 4294967295]"
        self._alg_state_status = value

    @builtins.property
    def alg_stage(self):
        """Message field 'alg_stage'."""
        return self._alg_stage

    @alg_stage.setter
    def alg_stage(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'alg_stage' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'alg_stage' field must be an unsigned integer in [0, 255]"
        self._alg_stage = value

    @builtins.property
    def alg_correction(self):
        """Message field 'alg_correction'."""
        return self._alg_correction

    @alg_correction.setter
    def alg_correction(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'alg_correction' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'alg_correction' field must be an unsigned integer in [0, 255]"
        self._alg_correction = value

    @builtins.property
    def alg_fails(self):
        """Message field 'alg_fails'."""
        return self._alg_fails

    @alg_fails.setter
    def alg_fails(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'alg_fails' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'alg_fails' field must be an unsigned integer in [0, 65535]"
        self._alg_fails = value

    @builtins.property
    def alg_navigation_ready(self):
        """Message field 'alg_navigation_ready'."""
        return self._alg_navigation_ready

    @alg_navigation_ready.setter
    def alg_navigation_ready(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'alg_navigation_ready' field must be of type 'bool'"
        self._alg_navigation_ready = value

    @builtins.property
    def gps_num_satellites(self):
        """Message field 'gps_num_satellites'."""
        return self._gps_num_satellites

    @gps_num_satellites.setter
    def gps_num_satellites(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'gps_num_satellites' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'gps_num_satellites' field must be an unsigned integer in [0, 65535]"
        self._gps_num_satellites = value

    @builtins.property
    def gnss_sig_lat(self):
        """Message field 'gnss_sig_lat'."""
        return self._gnss_sig_lat

    @gnss_sig_lat.setter
    def gnss_sig_lat(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gnss_sig_lat' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gnss_sig_lat' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gnss_sig_lat = value

    @builtins.property
    def gnss_sig_lon(self):
        """Message field 'gnss_sig_lon'."""
        return self._gnss_sig_lon

    @gnss_sig_lon.setter
    def gnss_sig_lon(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gnss_sig_lon' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gnss_sig_lon' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gnss_sig_lon = value

    @builtins.property
    def gnss_sig_alt(self):
        """Message field 'gnss_sig_alt'."""
        return self._gnss_sig_alt

    @gnss_sig_alt.setter
    def gnss_sig_alt(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gnss_sig_alt' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gnss_sig_alt' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gnss_sig_alt = value

    @builtins.property
    def alg_var_x(self):
        """Message field 'alg_var_x'."""
        return self._alg_var_x

    @alg_var_x.setter
    def alg_var_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'alg_var_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alg_var_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alg_var_x = value

    @builtins.property
    def alg_var_y(self):
        """Message field 'alg_var_y'."""
        return self._alg_var_y

    @alg_var_y.setter
    def alg_var_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'alg_var_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alg_var_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alg_var_y = value

    @builtins.property
    def alg_var_z(self):
        """Message field 'alg_var_z'."""
        return self._alg_var_z

    @alg_var_z.setter
    def alg_var_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'alg_var_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alg_var_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alg_var_z = value

    @builtins.property
    def alg_var_vx(self):
        """Message field 'alg_var_vx'."""
        return self._alg_var_vx

    @alg_var_vx.setter
    def alg_var_vx(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'alg_var_vx' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alg_var_vx' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alg_var_vx = value

    @builtins.property
    def alg_var_vy(self):
        """Message field 'alg_var_vy'."""
        return self._alg_var_vy

    @alg_var_vy.setter
    def alg_var_vy(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'alg_var_vy' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alg_var_vy' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alg_var_vy = value

    @builtins.property
    def alg_var_vz(self):
        """Message field 'alg_var_vz'."""
        return self._alg_var_vz

    @alg_var_vz.setter
    def alg_var_vz(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'alg_var_vz' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alg_var_vz' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alg_var_vz = value

    @builtins.property
    def alg_var_psi(self):
        """Message field 'alg_var_psi'."""
        return self._alg_var_psi

    @alg_var_psi.setter
    def alg_var_psi(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'alg_var_psi' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alg_var_psi' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alg_var_psi = value

    @builtins.property
    def alg_var_theta(self):
        """Message field 'alg_var_theta'."""
        return self._alg_var_theta

    @alg_var_theta.setter
    def alg_var_theta(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'alg_var_theta' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alg_var_theta' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alg_var_theta = value

    @builtins.property
    def alg_var_phi(self):
        """Message field 'alg_var_phi'."""
        return self._alg_var_phi

    @alg_var_phi.setter
    def alg_var_phi(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'alg_var_phi' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alg_var_phi' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alg_var_phi = value

    @builtins.property
    def gps_rel_heading(self):
        """Message field 'gps_rel_heading'."""
        return self._gps_rel_heading

    @gps_rel_heading.setter
    def gps_rel_heading(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gps_rel_heading' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gps_rel_heading' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gps_rel_heading = value

    @builtins.property
    def gps_rel_length(self):
        """Message field 'gps_rel_length'."""
        return self._gps_rel_length

    @gps_rel_length.setter
    def gps_rel_length(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gps_rel_length' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gps_rel_length' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gps_rel_length = value

    @builtins.property
    def heading_from_dual_antenna(self):
        """Message field 'heading_from_dual_antenna'."""
        return self._heading_from_dual_antenna

    @heading_from_dual_antenna.setter
    def heading_from_dual_antenna(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'heading_from_dual_antenna' field must be of type 'bool'"
        self._heading_from_dual_antenna = value
