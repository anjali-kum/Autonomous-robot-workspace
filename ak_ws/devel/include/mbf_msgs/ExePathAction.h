// Generated by gencpp from file mbf_msgs/ExePathAction.msg
// DO NOT EDIT!


#ifndef MBF_MSGS_MESSAGE_EXEPATHACTION_H
#define MBF_MSGS_MESSAGE_EXEPATHACTION_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <mbf_msgs/ExePathActionGoal.h>
#include <mbf_msgs/ExePathActionResult.h>
#include <mbf_msgs/ExePathActionFeedback.h>

namespace mbf_msgs
{
template <class ContainerAllocator>
struct ExePathAction_
{
  typedef ExePathAction_<ContainerAllocator> Type;

  ExePathAction_()
    : action_goal()
    , action_result()
    , action_feedback()  {
    }
  ExePathAction_(const ContainerAllocator& _alloc)
    : action_goal(_alloc)
    , action_result(_alloc)
    , action_feedback(_alloc)  {
  (void)_alloc;
    }



   typedef  ::mbf_msgs::ExePathActionGoal_<ContainerAllocator>  _action_goal_type;
  _action_goal_type action_goal;

   typedef  ::mbf_msgs::ExePathActionResult_<ContainerAllocator>  _action_result_type;
  _action_result_type action_result;

   typedef  ::mbf_msgs::ExePathActionFeedback_<ContainerAllocator>  _action_feedback_type;
  _action_feedback_type action_feedback;





  typedef boost::shared_ptr< ::mbf_msgs::ExePathAction_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mbf_msgs::ExePathAction_<ContainerAllocator> const> ConstPtr;

}; // struct ExePathAction_

typedef ::mbf_msgs::ExePathAction_<std::allocator<void> > ExePathAction;

typedef boost::shared_ptr< ::mbf_msgs::ExePathAction > ExePathActionPtr;
typedef boost::shared_ptr< ::mbf_msgs::ExePathAction const> ExePathActionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mbf_msgs::ExePathAction_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mbf_msgs::ExePathAction_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mbf_msgs::ExePathAction_<ContainerAllocator1> & lhs, const ::mbf_msgs::ExePathAction_<ContainerAllocator2> & rhs)
{
  return lhs.action_goal == rhs.action_goal &&
    lhs.action_result == rhs.action_result &&
    lhs.action_feedback == rhs.action_feedback;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mbf_msgs::ExePathAction_<ContainerAllocator1> & lhs, const ::mbf_msgs::ExePathAction_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mbf_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::mbf_msgs::ExePathAction_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mbf_msgs::ExePathAction_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mbf_msgs::ExePathAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mbf_msgs::ExePathAction_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mbf_msgs::ExePathAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mbf_msgs::ExePathAction_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mbf_msgs::ExePathAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1eb3204035d1ceb85b999c9c0a477f7b";
  }

  static const char* value(const ::mbf_msgs::ExePathAction_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1eb3204035d1ceb8ULL;
  static const uint64_t static_value2 = 0x5b999c9c0a477f7bULL;
};

template<class ContainerAllocator>
struct DataType< ::mbf_msgs::ExePathAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mbf_msgs/ExePathAction";
  }

  static const char* value(const ::mbf_msgs::ExePathAction_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mbf_msgs::ExePathAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"ExePathActionGoal action_goal\n"
"ExePathActionResult action_result\n"
"ExePathActionFeedback action_feedback\n"
"\n"
"================================================================================\n"
"MSG: mbf_msgs/ExePathActionGoal\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalID goal_id\n"
"ExePathGoal goal\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: actionlib_msgs/GoalID\n"
"# The stamp should store the time at which this goal was requested.\n"
"# It is used by an action server when it tries to preempt all\n"
"# goals that were requested before a certain time\n"
"time stamp\n"
"\n"
"# The id provides a way to associate feedback and\n"
"# result message with specific goal requests. The id\n"
"# specified must be unique.\n"
"string id\n"
"\n"
"\n"
"================================================================================\n"
"MSG: mbf_msgs/ExePathGoal\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# Follow the given path until completion or failure\n"
"\n"
"nav_msgs/Path path\n"
"\n"
"# Controller to use; defaults to the first one specified on \"controllers\" parameter\n"
"string controller\n"
"\n"
"# use different slots for concurrency\n"
"uint8 concurrency_slot\n"
"\n"
"# define goal tolerance for the action\n"
"bool tolerance_from_action\n"
"float32 dist_tolerance\n"
"float32 angle_tolerance\n"
"\n"
"================================================================================\n"
"MSG: nav_msgs/Path\n"
"#An array of poses that represents a Path for a robot to follow\n"
"Header header\n"
"geometry_msgs/PoseStamped[] poses\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseStamped\n"
"# A Pose with reference coordinate frame and timestamp\n"
"Header header\n"
"Pose pose\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: mbf_msgs/ExePathActionResult\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalStatus status\n"
"ExePathResult result\n"
"\n"
"================================================================================\n"
"MSG: actionlib_msgs/GoalStatus\n"
"GoalID goal_id\n"
"uint8 status\n"
"uint8 PENDING         = 0   # The goal has yet to be processed by the action server\n"
"uint8 ACTIVE          = 1   # The goal is currently being processed by the action server\n"
"uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing\n"
"                            #   and has since completed its execution (Terminal State)\n"
"uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)\n"
"uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due\n"
"                            #    to some failure (Terminal State)\n"
"uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,\n"
"                            #    because the goal was unattainable or invalid (Terminal State)\n"
"uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing\n"
"                            #    and has not yet completed execution\n"
"uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,\n"
"                            #    but the action server has not yet confirmed that the goal is canceled\n"
"uint8 RECALLED        = 8   # The goal received a cancel request before it started executing\n"
"                            #    and was successfully cancelled (Terminal State)\n"
"uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be\n"
"                            #    sent over the wire by an action server\n"
"\n"
"#Allow for the user to associate a string with GoalStatus for debugging\n"
"string text\n"
"\n"
"\n"
"================================================================================\n"
"MSG: mbf_msgs/ExePathResult\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"# Predefined success codes:\n"
"uint8 SUCCESS         = 0\n"
"# 1..9 are reserved as plugin specific non-error results\n"
"\n"
"# Predefined error codes:\n"
"uint8 FAILURE         = 100  # Unspecified failure, only used for old, non-mfb_core based plugins\n"
"uint8 CANCELED        = 101\n"
"uint8 NO_VALID_CMD    = 102\n"
"uint8 PAT_EXCEEDED    = 103\n"
"uint8 COLLISION       = 104\n"
"uint8 OSCILLATION     = 105\n"
"uint8 ROBOT_STUCK     = 106\n"
"uint8 MISSED_GOAL     = 107\n"
"uint8 MISSED_PATH     = 108\n"
"uint8 BLOCKED_PATH    = 109\n"
"uint8 INVALID_PATH    = 110\n"
"uint8 TF_ERROR        = 111\n"
"uint8 NOT_INITIALIZED = 112\n"
"uint8 INVALID_PLUGIN  = 113\n"
"uint8 INTERNAL_ERROR  = 114\n"
"uint8 OUT_OF_MAP      = 115  # The start and / or the goal are outside the map\n"
"uint8 MAP_ERROR       = 116  # The map is not running properly\n"
"uint8 STOPPED         = 117  # The controller execution has been stopped rigorously.\n"
"\n"
"# 121..149 are reserved as plugin specific errors\n"
"\n"
"uint32 outcome\n"
"string message\n"
"\n"
"geometry_msgs/PoseStamped  final_pose\n"
"float32 dist_to_goal\n"
"float32 angle_to_goal\n"
"\n"
"\n"
"================================================================================\n"
"MSG: mbf_msgs/ExePathActionFeedback\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalStatus status\n"
"ExePathFeedback feedback\n"
"\n"
"================================================================================\n"
"MSG: mbf_msgs/ExePathFeedback\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"# Outcome of most recent controller cycle. Same values as in result\n"
"uint32 outcome\n"
"string message\n"
"\n"
"float32 dist_to_goal\n"
"float32 angle_to_goal\n"
"geometry_msgs/PoseStamped  current_pose\n"
"geometry_msgs/TwistStamped last_cmd_vel  # last command calculated by the controller\n"
"\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/TwistStamped\n"
"# A twist with reference coordinate frame and timestamp\n"
"Header header\n"
"Twist twist\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Twist\n"
"# This expresses velocity in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::mbf_msgs::ExePathAction_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mbf_msgs::ExePathAction_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action_goal);
      stream.next(m.action_result);
      stream.next(m.action_feedback);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ExePathAction_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mbf_msgs::ExePathAction_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mbf_msgs::ExePathAction_<ContainerAllocator>& v)
  {
    s << indent << "action_goal: ";
    s << std::endl;
    Printer< ::mbf_msgs::ExePathActionGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.action_goal);
    s << indent << "action_result: ";
    s << std::endl;
    Printer< ::mbf_msgs::ExePathActionResult_<ContainerAllocator> >::stream(s, indent + "  ", v.action_result);
    s << indent << "action_feedback: ";
    s << std::endl;
    Printer< ::mbf_msgs::ExePathActionFeedback_<ContainerAllocator> >::stream(s, indent + "  ", v.action_feedback);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MBF_MSGS_MESSAGE_EXEPATHACTION_H
