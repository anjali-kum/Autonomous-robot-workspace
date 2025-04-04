// Generated by gencpp from file mbf_msgs/GetPathAction.msg
// DO NOT EDIT!


#ifndef MBF_MSGS_MESSAGE_GETPATHACTION_H
#define MBF_MSGS_MESSAGE_GETPATHACTION_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <mbf_msgs/GetPathActionGoal.h>
#include <mbf_msgs/GetPathActionResult.h>
#include <mbf_msgs/GetPathActionFeedback.h>

namespace mbf_msgs
{
template <class ContainerAllocator>
struct GetPathAction_
{
  typedef GetPathAction_<ContainerAllocator> Type;

  GetPathAction_()
    : action_goal()
    , action_result()
    , action_feedback()  {
    }
  GetPathAction_(const ContainerAllocator& _alloc)
    : action_goal(_alloc)
    , action_result(_alloc)
    , action_feedback(_alloc)  {
  (void)_alloc;
    }



   typedef  ::mbf_msgs::GetPathActionGoal_<ContainerAllocator>  _action_goal_type;
  _action_goal_type action_goal;

   typedef  ::mbf_msgs::GetPathActionResult_<ContainerAllocator>  _action_result_type;
  _action_result_type action_result;

   typedef  ::mbf_msgs::GetPathActionFeedback_<ContainerAllocator>  _action_feedback_type;
  _action_feedback_type action_feedback;





  typedef boost::shared_ptr< ::mbf_msgs::GetPathAction_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mbf_msgs::GetPathAction_<ContainerAllocator> const> ConstPtr;

}; // struct GetPathAction_

typedef ::mbf_msgs::GetPathAction_<std::allocator<void> > GetPathAction;

typedef boost::shared_ptr< ::mbf_msgs::GetPathAction > GetPathActionPtr;
typedef boost::shared_ptr< ::mbf_msgs::GetPathAction const> GetPathActionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mbf_msgs::GetPathAction_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mbf_msgs::GetPathAction_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mbf_msgs::GetPathAction_<ContainerAllocator1> & lhs, const ::mbf_msgs::GetPathAction_<ContainerAllocator2> & rhs)
{
  return lhs.action_goal == rhs.action_goal &&
    lhs.action_result == rhs.action_result &&
    lhs.action_feedback == rhs.action_feedback;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mbf_msgs::GetPathAction_<ContainerAllocator1> & lhs, const ::mbf_msgs::GetPathAction_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mbf_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::mbf_msgs::GetPathAction_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mbf_msgs::GetPathAction_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mbf_msgs::GetPathAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mbf_msgs::GetPathAction_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mbf_msgs::GetPathAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mbf_msgs::GetPathAction_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mbf_msgs::GetPathAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f4d6567e6c5805b81da135676625d187";
  }

  static const char* value(const ::mbf_msgs::GetPathAction_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf4d6567e6c5805b8ULL;
  static const uint64_t static_value2 = 0x1da135676625d187ULL;
};

template<class ContainerAllocator>
struct DataType< ::mbf_msgs::GetPathAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mbf_msgs/GetPathAction";
  }

  static const char* value(const ::mbf_msgs::GetPathAction_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mbf_msgs::GetPathAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"GetPathActionGoal action_goal\n"
"GetPathActionResult action_result\n"
"GetPathActionFeedback action_feedback\n"
"\n"
"================================================================================\n"
"MSG: mbf_msgs/GetPathActionGoal\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalID goal_id\n"
"GetPathGoal goal\n"
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
"MSG: mbf_msgs/GetPathGoal\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# Get a path from start_pose or current position to the target pose\n"
"\n"
"# Use start_pose or current position as the beginning of the path\n"
"bool use_start_pose\n"
"\n"
"# The start pose for the path; optional, used if use_start_pose is true\n"
"geometry_msgs/PoseStamped start_pose\n"
"\n"
"# The pose to achieve with the path\n"
"geometry_msgs/PoseStamped target_pose\n"
"\n"
"# If the goal is obstructed, how many meters the planner can relax the constraint in x and y before failing\n"
"float64 tolerance\n"
"\n"
"# Planner to use; defaults to the first one specified on \"planners\" parameter\n"
"string planner\n"
"\n"
"# use different slots for concurrency\n"
"uint8 concurrency_slot\n"
"\n"
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
"MSG: mbf_msgs/GetPathActionResult\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalStatus status\n"
"GetPathResult result\n"
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
"MSG: mbf_msgs/GetPathResult\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"# Predefined success codes:\n"
"uint8 SUCCESS         = 0\n"
"# 1..9 are reserved as plugin specific non-error results\n"
"\n"
"# Possible error codes:\n"
"uint8 FAILURE         = 50  # Unspecified failure, only used for old, non-mfb_core based plugins\n"
"uint8 CANCELED        = 51  # The action has been canceled by a action client\n"
"uint8 INVALID_START   = 52  #\n"
"uint8 INVALID_GOAL    = 53\n"
"uint8 NO_PATH_FOUND   = 54\n"
"uint8 PAT_EXCEEDED    = 55\n"
"uint8 EMPTY_PATH      = 56\n"
"uint8 TF_ERROR        = 57\n"
"uint8 NOT_INITIALIZED = 58\n"
"uint8 INVALID_PLUGIN  = 59\n"
"uint8 INTERNAL_ERROR  = 60\n"
"uint8 OUT_OF_MAP      = 61\n"
"uint8 MAP_ERROR       = 62\n"
"uint8 STOPPED         = 63  # The planner execution has been stopped rigorously.\n"
"\n"
"# 71..99 are reserved as plugin specific errors\n"
"\n"
"uint32 outcome\n"
"string message\n"
"\n"
"nav_msgs/Path path\n"
"\n"
"float64 cost\n"
"\n"
"\n"
"================================================================================\n"
"MSG: nav_msgs/Path\n"
"#An array of poses that represents a Path for a robot to follow\n"
"Header header\n"
"geometry_msgs/PoseStamped[] poses\n"
"\n"
"================================================================================\n"
"MSG: mbf_msgs/GetPathActionFeedback\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalStatus status\n"
"GetPathFeedback feedback\n"
"\n"
"================================================================================\n"
"MSG: mbf_msgs/GetPathFeedback\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
;
  }

  static const char* value(const ::mbf_msgs::GetPathAction_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mbf_msgs::GetPathAction_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action_goal);
      stream.next(m.action_result);
      stream.next(m.action_feedback);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetPathAction_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mbf_msgs::GetPathAction_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mbf_msgs::GetPathAction_<ContainerAllocator>& v)
  {
    s << indent << "action_goal: ";
    s << std::endl;
    Printer< ::mbf_msgs::GetPathActionGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.action_goal);
    s << indent << "action_result: ";
    s << std::endl;
    Printer< ::mbf_msgs::GetPathActionResult_<ContainerAllocator> >::stream(s, indent + "  ", v.action_result);
    s << indent << "action_feedback: ";
    s << std::endl;
    Printer< ::mbf_msgs::GetPathActionFeedback_<ContainerAllocator> >::stream(s, indent + "  ", v.action_feedback);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MBF_MSGS_MESSAGE_GETPATHACTION_H
