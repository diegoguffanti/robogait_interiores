# generated from rosidl_generator_py/resource/_idl.py.em
# with input from body_tracking:msg/Skeleton.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Skeleton(type):
    """Metaclass of message 'Skeleton'."""

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
            module = import_type_support('body_tracking')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'body_tracking.msg.Skeleton')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__skeleton
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__skeleton
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__skeleton
            cls._TYPE_SUPPORT = module.type_support_msg__msg__skeleton
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__skeleton

            from geometry_msgs.msg import Point32
            if Point32.__class__._TYPE_SUPPORT is None:
                Point32.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Skeleton(metaclass=Metaclass_Skeleton):
    """Message class 'Skeleton'."""

    __slots__ = [
        '_body_id',
        '_tiempo',
        '_joint_position_head',
        '_joint_position_neck',
        '_joint_position_shoulder',
        '_joint_position_spine_top',
        '_joint_position_spine_mid',
        '_joint_position_spine_bottom',
        '_joint_position_left_shoulder',
        '_joint_position_left_elbow',
        '_joint_position_left_hand',
        '_joint_position_right_shoulder',
        '_joint_position_right_elbow',
        '_joint_position_right_hand',
        '_joint_position_right_hip',
        '_joint_position_right_knee',
        '_joint_position_right_ankle',
        '_joint_position_left_hip',
        '_joint_position_left_knee',
        '_joint_position_left_ankle',
    ]

    _fields_and_field_types = {
        'body_id': 'int32',
        'tiempo': 'double',
        'joint_position_head': 'geometry_msgs/Point32',
        'joint_position_neck': 'geometry_msgs/Point32',
        'joint_position_shoulder': 'geometry_msgs/Point32',
        'joint_position_spine_top': 'geometry_msgs/Point32',
        'joint_position_spine_mid': 'geometry_msgs/Point32',
        'joint_position_spine_bottom': 'geometry_msgs/Point32',
        'joint_position_left_shoulder': 'geometry_msgs/Point32',
        'joint_position_left_elbow': 'geometry_msgs/Point32',
        'joint_position_left_hand': 'geometry_msgs/Point32',
        'joint_position_right_shoulder': 'geometry_msgs/Point32',
        'joint_position_right_elbow': 'geometry_msgs/Point32',
        'joint_position_right_hand': 'geometry_msgs/Point32',
        'joint_position_right_hip': 'geometry_msgs/Point32',
        'joint_position_right_knee': 'geometry_msgs/Point32',
        'joint_position_right_ankle': 'geometry_msgs/Point32',
        'joint_position_left_hip': 'geometry_msgs/Point32',
        'joint_position_left_knee': 'geometry_msgs/Point32',
        'joint_position_left_ankle': 'geometry_msgs/Point32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.body_id = kwargs.get('body_id', int())
        self.tiempo = kwargs.get('tiempo', float())
        from geometry_msgs.msg import Point32
        self.joint_position_head = kwargs.get('joint_position_head', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_neck = kwargs.get('joint_position_neck', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_shoulder = kwargs.get('joint_position_shoulder', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_spine_top = kwargs.get('joint_position_spine_top', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_spine_mid = kwargs.get('joint_position_spine_mid', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_spine_bottom = kwargs.get('joint_position_spine_bottom', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_left_shoulder = kwargs.get('joint_position_left_shoulder', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_left_elbow = kwargs.get('joint_position_left_elbow', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_left_hand = kwargs.get('joint_position_left_hand', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_right_shoulder = kwargs.get('joint_position_right_shoulder', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_right_elbow = kwargs.get('joint_position_right_elbow', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_right_hand = kwargs.get('joint_position_right_hand', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_right_hip = kwargs.get('joint_position_right_hip', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_right_knee = kwargs.get('joint_position_right_knee', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_right_ankle = kwargs.get('joint_position_right_ankle', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_left_hip = kwargs.get('joint_position_left_hip', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_left_knee = kwargs.get('joint_position_left_knee', Point32())
        from geometry_msgs.msg import Point32
        self.joint_position_left_ankle = kwargs.get('joint_position_left_ankle', Point32())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.body_id != other.body_id:
            return False
        if self.tiempo != other.tiempo:
            return False
        if self.joint_position_head != other.joint_position_head:
            return False
        if self.joint_position_neck != other.joint_position_neck:
            return False
        if self.joint_position_shoulder != other.joint_position_shoulder:
            return False
        if self.joint_position_spine_top != other.joint_position_spine_top:
            return False
        if self.joint_position_spine_mid != other.joint_position_spine_mid:
            return False
        if self.joint_position_spine_bottom != other.joint_position_spine_bottom:
            return False
        if self.joint_position_left_shoulder != other.joint_position_left_shoulder:
            return False
        if self.joint_position_left_elbow != other.joint_position_left_elbow:
            return False
        if self.joint_position_left_hand != other.joint_position_left_hand:
            return False
        if self.joint_position_right_shoulder != other.joint_position_right_shoulder:
            return False
        if self.joint_position_right_elbow != other.joint_position_right_elbow:
            return False
        if self.joint_position_right_hand != other.joint_position_right_hand:
            return False
        if self.joint_position_right_hip != other.joint_position_right_hip:
            return False
        if self.joint_position_right_knee != other.joint_position_right_knee:
            return False
        if self.joint_position_right_ankle != other.joint_position_right_ankle:
            return False
        if self.joint_position_left_hip != other.joint_position_left_hip:
            return False
        if self.joint_position_left_knee != other.joint_position_left_knee:
            return False
        if self.joint_position_left_ankle != other.joint_position_left_ankle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def body_id(self):
        """Message field 'body_id'."""
        return self._body_id

    @body_id.setter
    def body_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'body_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'body_id' field must be an integer in [-2147483648, 2147483647]"
        self._body_id = value

    @property
    def tiempo(self):
        """Message field 'tiempo'."""
        return self._tiempo

    @tiempo.setter
    def tiempo(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tiempo' field must be of type 'float'"
        self._tiempo = value

    @property
    def joint_position_head(self):
        """Message field 'joint_position_head'."""
        return self._joint_position_head

    @joint_position_head.setter
    def joint_position_head(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_head' field must be a sub message of type 'Point32'"
        self._joint_position_head = value

    @property
    def joint_position_neck(self):
        """Message field 'joint_position_neck'."""
        return self._joint_position_neck

    @joint_position_neck.setter
    def joint_position_neck(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_neck' field must be a sub message of type 'Point32'"
        self._joint_position_neck = value

    @property
    def joint_position_shoulder(self):
        """Message field 'joint_position_shoulder'."""
        return self._joint_position_shoulder

    @joint_position_shoulder.setter
    def joint_position_shoulder(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_shoulder' field must be a sub message of type 'Point32'"
        self._joint_position_shoulder = value

    @property
    def joint_position_spine_top(self):
        """Message field 'joint_position_spine_top'."""
        return self._joint_position_spine_top

    @joint_position_spine_top.setter
    def joint_position_spine_top(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_spine_top' field must be a sub message of type 'Point32'"
        self._joint_position_spine_top = value

    @property
    def joint_position_spine_mid(self):
        """Message field 'joint_position_spine_mid'."""
        return self._joint_position_spine_mid

    @joint_position_spine_mid.setter
    def joint_position_spine_mid(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_spine_mid' field must be a sub message of type 'Point32'"
        self._joint_position_spine_mid = value

    @property
    def joint_position_spine_bottom(self):
        """Message field 'joint_position_spine_bottom'."""
        return self._joint_position_spine_bottom

    @joint_position_spine_bottom.setter
    def joint_position_spine_bottom(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_spine_bottom' field must be a sub message of type 'Point32'"
        self._joint_position_spine_bottom = value

    @property
    def joint_position_left_shoulder(self):
        """Message field 'joint_position_left_shoulder'."""
        return self._joint_position_left_shoulder

    @joint_position_left_shoulder.setter
    def joint_position_left_shoulder(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_left_shoulder' field must be a sub message of type 'Point32'"
        self._joint_position_left_shoulder = value

    @property
    def joint_position_left_elbow(self):
        """Message field 'joint_position_left_elbow'."""
        return self._joint_position_left_elbow

    @joint_position_left_elbow.setter
    def joint_position_left_elbow(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_left_elbow' field must be a sub message of type 'Point32'"
        self._joint_position_left_elbow = value

    @property
    def joint_position_left_hand(self):
        """Message field 'joint_position_left_hand'."""
        return self._joint_position_left_hand

    @joint_position_left_hand.setter
    def joint_position_left_hand(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_left_hand' field must be a sub message of type 'Point32'"
        self._joint_position_left_hand = value

    @property
    def joint_position_right_shoulder(self):
        """Message field 'joint_position_right_shoulder'."""
        return self._joint_position_right_shoulder

    @joint_position_right_shoulder.setter
    def joint_position_right_shoulder(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_right_shoulder' field must be a sub message of type 'Point32'"
        self._joint_position_right_shoulder = value

    @property
    def joint_position_right_elbow(self):
        """Message field 'joint_position_right_elbow'."""
        return self._joint_position_right_elbow

    @joint_position_right_elbow.setter
    def joint_position_right_elbow(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_right_elbow' field must be a sub message of type 'Point32'"
        self._joint_position_right_elbow = value

    @property
    def joint_position_right_hand(self):
        """Message field 'joint_position_right_hand'."""
        return self._joint_position_right_hand

    @joint_position_right_hand.setter
    def joint_position_right_hand(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_right_hand' field must be a sub message of type 'Point32'"
        self._joint_position_right_hand = value

    @property
    def joint_position_right_hip(self):
        """Message field 'joint_position_right_hip'."""
        return self._joint_position_right_hip

    @joint_position_right_hip.setter
    def joint_position_right_hip(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_right_hip' field must be a sub message of type 'Point32'"
        self._joint_position_right_hip = value

    @property
    def joint_position_right_knee(self):
        """Message field 'joint_position_right_knee'."""
        return self._joint_position_right_knee

    @joint_position_right_knee.setter
    def joint_position_right_knee(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_right_knee' field must be a sub message of type 'Point32'"
        self._joint_position_right_knee = value

    @property
    def joint_position_right_ankle(self):
        """Message field 'joint_position_right_ankle'."""
        return self._joint_position_right_ankle

    @joint_position_right_ankle.setter
    def joint_position_right_ankle(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_right_ankle' field must be a sub message of type 'Point32'"
        self._joint_position_right_ankle = value

    @property
    def joint_position_left_hip(self):
        """Message field 'joint_position_left_hip'."""
        return self._joint_position_left_hip

    @joint_position_left_hip.setter
    def joint_position_left_hip(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_left_hip' field must be a sub message of type 'Point32'"
        self._joint_position_left_hip = value

    @property
    def joint_position_left_knee(self):
        """Message field 'joint_position_left_knee'."""
        return self._joint_position_left_knee

    @joint_position_left_knee.setter
    def joint_position_left_knee(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_left_knee' field must be a sub message of type 'Point32'"
        self._joint_position_left_knee = value

    @property
    def joint_position_left_ankle(self):
        """Message field 'joint_position_left_ankle'."""
        return self._joint_position_left_ankle

    @joint_position_left_ankle.setter
    def joint_position_left_ankle(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'joint_position_left_ankle' field must be a sub message of type 'Point32'"
        self._joint_position_left_ankle = value
