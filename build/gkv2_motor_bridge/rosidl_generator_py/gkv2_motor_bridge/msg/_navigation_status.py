# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gkv2_motor_bridge:msg/NavigationStatus.idl
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


class Metaclass_NavigationStatus(type):
    """Metaclass of message 'NavigationStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'MODE_GNSS': 0,
        'MODE_ODOMETRY': 1,
        'MODE_FUSION': 2,
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
                'gkv2_motor_bridge.msg.NavigationStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__navigation_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__navigation_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__navigation_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__navigation_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__navigation_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'MODE_GNSS': cls.__constants['MODE_GNSS'],
            'MODE_ODOMETRY': cls.__constants['MODE_ODOMETRY'],
            'MODE_FUSION': cls.__constants['MODE_FUSION'],
        }

    @property
    def MODE_GNSS(self):
        """Message constant 'MODE_GNSS'."""
        return Metaclass_NavigationStatus.__constants['MODE_GNSS']

    @property
    def MODE_ODOMETRY(self):
        """Message constant 'MODE_ODOMETRY'."""
        return Metaclass_NavigationStatus.__constants['MODE_ODOMETRY']

    @property
    def MODE_FUSION(self):
        """Message constant 'MODE_FUSION'."""
        return Metaclass_NavigationStatus.__constants['MODE_FUSION']


class NavigationStatus(metaclass=Metaclass_NavigationStatus):
    """
    Message class 'NavigationStatus'.

    Constants:
      MODE_GNSS
      MODE_ODOMETRY
      MODE_FUSION
    """

    __slots__ = [
        '_current_mode',
        '_gnss_available',
        '_rtk_fixed',
        '_gnss_satellites',
        '_gnss_quality',
        '_odometry_drift',
        '_time_since_gnss',
        '_status_message',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'current_mode': 'uint8',
        'gnss_available': 'boolean',
        'rtk_fixed': 'boolean',
        'gnss_satellites': 'uint16',
        'gnss_quality': 'float',
        'odometry_drift': 'float',
        'time_since_gnss': 'float',
        'status_message': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        self.current_mode = kwargs.get('current_mode', int())
        self.gnss_available = kwargs.get('gnss_available', bool())
        self.rtk_fixed = kwargs.get('rtk_fixed', bool())
        self.gnss_satellites = kwargs.get('gnss_satellites', int())
        self.gnss_quality = kwargs.get('gnss_quality', float())
        self.odometry_drift = kwargs.get('odometry_drift', float())
        self.time_since_gnss = kwargs.get('time_since_gnss', float())
        self.status_message = kwargs.get('status_message', str())

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
        if self.current_mode != other.current_mode:
            return False
        if self.gnss_available != other.gnss_available:
            return False
        if self.rtk_fixed != other.rtk_fixed:
            return False
        if self.gnss_satellites != other.gnss_satellites:
            return False
        if self.gnss_quality != other.gnss_quality:
            return False
        if self.odometry_drift != other.odometry_drift:
            return False
        if self.time_since_gnss != other.time_since_gnss:
            return False
        if self.status_message != other.status_message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def current_mode(self):
        """Message field 'current_mode'."""
        return self._current_mode

    @current_mode.setter
    def current_mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'current_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'current_mode' field must be an unsigned integer in [0, 255]"
        self._current_mode = value

    @builtins.property
    def gnss_available(self):
        """Message field 'gnss_available'."""
        return self._gnss_available

    @gnss_available.setter
    def gnss_available(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'gnss_available' field must be of type 'bool'"
        self._gnss_available = value

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

    @builtins.property
    def gnss_satellites(self):
        """Message field 'gnss_satellites'."""
        return self._gnss_satellites

    @gnss_satellites.setter
    def gnss_satellites(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'gnss_satellites' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'gnss_satellites' field must be an unsigned integer in [0, 65535]"
        self._gnss_satellites = value

    @builtins.property
    def gnss_quality(self):
        """Message field 'gnss_quality'."""
        return self._gnss_quality

    @gnss_quality.setter
    def gnss_quality(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gnss_quality' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gnss_quality' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gnss_quality = value

    @builtins.property
    def odometry_drift(self):
        """Message field 'odometry_drift'."""
        return self._odometry_drift

    @odometry_drift.setter
    def odometry_drift(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'odometry_drift' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'odometry_drift' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._odometry_drift = value

    @builtins.property
    def time_since_gnss(self):
        """Message field 'time_since_gnss'."""
        return self._time_since_gnss

    @time_since_gnss.setter
    def time_since_gnss(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'time_since_gnss' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'time_since_gnss' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._time_since_gnss = value

    @builtins.property
    def status_message(self):
        """Message field 'status_message'."""
        return self._status_message

    @status_message.setter
    def status_message(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'status_message' field must be of type 'str'"
        self._status_message = value
