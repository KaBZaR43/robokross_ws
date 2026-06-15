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
        '_gps_num_satellites',
        '_alg_state_status',
        '_rtk_fixed',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'gps_state_status': 'uint32',
        'gps_num_satellites': 'uint16',
        'alg_state_status': 'float',
        'rtk_fixed': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
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
        self.gps_num_satellites = kwargs.get('gps_num_satellites', int())
        self.alg_state_status = kwargs.get('alg_state_status', float())
        self.rtk_fixed = kwargs.get('rtk_fixed', bool())

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
        if self.gps_num_satellites != other.gps_num_satellites:
            return False
        if self.alg_state_status != other.alg_state_status:
            return False
        if self.rtk_fixed != other.rtk_fixed:
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
    def alg_state_status(self):
        """Message field 'alg_state_status'."""
        return self._alg_state_status

    @alg_state_status.setter
    def alg_state_status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'alg_state_status' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alg_state_status' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alg_state_status = value

    @builtins.property
    def rtk_fixed(self):
        """Message field 'rtk_fixed'."""
        return self._rtk_fixed

    @rtk_fixed.setter
    def rtk_fixed(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'rtk_fixed' field must be of type 'bool'"
        self._rtk_fixed = value
