# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

# Member 'packet_param_ids'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GKV2ConfigStatus(type):
    """Metaclass of message 'GKV2ConfigStatus'."""

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
                'gkv2_motor_bridge.msg.GKV2ConfigStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gkv2_config_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gkv2_config_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gkv2_config_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gkv2_config_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gkv2_config_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GKV2ConfigStatus(metaclass=Metaclass_GKV2ConfigStatus):
    """Message class 'GKV2ConfigStatus'."""

    __slots__ = [
        '_device_name',
        '_serial_number',
        '_firmware_version',
        '_algorithm_mode',
        '_connection_ok',
        '_data_ready',
        '_adc_overflow',
        '_adc_skip',
        '_gyroscope_fail',
        '_accelerometer_fail',
        '_packet_param_count',
        '_packet_param_ids',
        '_packet_structure_match',
        '_status_message',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'device_name': 'string',
        'serial_number': 'string',
        'firmware_version': 'uint16',
        'algorithm_mode': 'uint8',
        'connection_ok': 'boolean',
        'data_ready': 'boolean',
        'adc_overflow': 'boolean',
        'adc_skip': 'boolean',
        'gyroscope_fail': 'boolean',
        'accelerometer_fail': 'boolean',
        'packet_param_count': 'uint8',
        'packet_param_ids': 'sequence<int32>',
        'packet_structure_match': 'boolean',
        'status_message': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
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
        self.device_name = kwargs.get('device_name', str())
        self.serial_number = kwargs.get('serial_number', str())
        self.firmware_version = kwargs.get('firmware_version', int())
        self.algorithm_mode = kwargs.get('algorithm_mode', int())
        self.connection_ok = kwargs.get('connection_ok', bool())
        self.data_ready = kwargs.get('data_ready', bool())
        self.adc_overflow = kwargs.get('adc_overflow', bool())
        self.adc_skip = kwargs.get('adc_skip', bool())
        self.gyroscope_fail = kwargs.get('gyroscope_fail', bool())
        self.accelerometer_fail = kwargs.get('accelerometer_fail', bool())
        self.packet_param_count = kwargs.get('packet_param_count', int())
        self.packet_param_ids = array.array('i', kwargs.get('packet_param_ids', []))
        self.packet_structure_match = kwargs.get('packet_structure_match', bool())
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
        if self.device_name != other.device_name:
            return False
        if self.serial_number != other.serial_number:
            return False
        if self.firmware_version != other.firmware_version:
            return False
        if self.algorithm_mode != other.algorithm_mode:
            return False
        if self.connection_ok != other.connection_ok:
            return False
        if self.data_ready != other.data_ready:
            return False
        if self.adc_overflow != other.adc_overflow:
            return False
        if self.adc_skip != other.adc_skip:
            return False
        if self.gyroscope_fail != other.gyroscope_fail:
            return False
        if self.accelerometer_fail != other.accelerometer_fail:
            return False
        if self.packet_param_count != other.packet_param_count:
            return False
        if self.packet_param_ids != other.packet_param_ids:
            return False
        if self.packet_structure_match != other.packet_structure_match:
            return False
        if self.status_message != other.status_message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def device_name(self):
        """Message field 'device_name'."""
        return self._device_name

    @device_name.setter
    def device_name(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'device_name' field must be of type 'str'"
        self._device_name = value

    @builtins.property
    def serial_number(self):
        """Message field 'serial_number'."""
        return self._serial_number

    @serial_number.setter
    def serial_number(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'serial_number' field must be of type 'str'"
        self._serial_number = value

    @builtins.property
    def firmware_version(self):
        """Message field 'firmware_version'."""
        return self._firmware_version

    @firmware_version.setter
    def firmware_version(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'firmware_version' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'firmware_version' field must be an unsigned integer in [0, 65535]"
        self._firmware_version = value

    @builtins.property
    def algorithm_mode(self):
        """Message field 'algorithm_mode'."""
        return self._algorithm_mode

    @algorithm_mode.setter
    def algorithm_mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'algorithm_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'algorithm_mode' field must be an unsigned integer in [0, 255]"
        self._algorithm_mode = value

    @builtins.property
    def connection_ok(self):
        """Message field 'connection_ok'."""
        return self._connection_ok

    @connection_ok.setter
    def connection_ok(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'connection_ok' field must be of type 'bool'"
        self._connection_ok = value

    @builtins.property
    def data_ready(self):
        """Message field 'data_ready'."""
        return self._data_ready

    @data_ready.setter
    def data_ready(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'data_ready' field must be of type 'bool'"
        self._data_ready = value

    @builtins.property
    def adc_overflow(self):
        """Message field 'adc_overflow'."""
        return self._adc_overflow

    @adc_overflow.setter
    def adc_overflow(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'adc_overflow' field must be of type 'bool'"
        self._adc_overflow = value

    @builtins.property
    def adc_skip(self):
        """Message field 'adc_skip'."""
        return self._adc_skip

    @adc_skip.setter
    def adc_skip(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'adc_skip' field must be of type 'bool'"
        self._adc_skip = value

    @builtins.property
    def gyroscope_fail(self):
        """Message field 'gyroscope_fail'."""
        return self._gyroscope_fail

    @gyroscope_fail.setter
    def gyroscope_fail(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'gyroscope_fail' field must be of type 'bool'"
        self._gyroscope_fail = value

    @builtins.property
    def accelerometer_fail(self):
        """Message field 'accelerometer_fail'."""
        return self._accelerometer_fail

    @accelerometer_fail.setter
    def accelerometer_fail(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'accelerometer_fail' field must be of type 'bool'"
        self._accelerometer_fail = value

    @builtins.property
    def packet_param_count(self):
        """Message field 'packet_param_count'."""
        return self._packet_param_count

    @packet_param_count.setter
    def packet_param_count(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'packet_param_count' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'packet_param_count' field must be an unsigned integer in [0, 255]"
        self._packet_param_count = value

    @builtins.property
    def packet_param_ids(self):
        """Message field 'packet_param_ids'."""
        return self._packet_param_ids

    @packet_param_ids.setter
    def packet_param_ids(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'i', \
                    "The 'packet_param_ids' array.array() must have the type code of 'i'"
                self._packet_param_ids = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'packet_param_ids' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._packet_param_ids = array.array('i', value)

    @builtins.property
    def packet_structure_match(self):
        """Message field 'packet_structure_match'."""
        return self._packet_structure_match

    @packet_structure_match.setter
    def packet_structure_match(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'packet_structure_match' field must be of type 'bool'"
        self._packet_structure_match = value

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
