// Generated by gencpp from file mbf_msgs/CheckPathRequest.msg
// DO NOT EDIT!


#ifndef MBF_MSGS_MESSAGE_CHECKPATHREQUEST_H
#define MBF_MSGS_MESSAGE_CHECKPATHREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <nav_msgs/Path.h>

namespace mbf_msgs
{
template <class ContainerAllocator>
struct CheckPathRequest_
{
  typedef CheckPathRequest_<ContainerAllocator> Type;

  CheckPathRequest_()
    : path()
    , safety_dist(0.0)
    , lethal_cost_mult(0.0)
    , inscrib_cost_mult(0.0)
    , unknown_cost_mult(0.0)
    , costmap(0)
    , return_on(0)
    , skip_poses(0)
    , path_cells_only(false)  {
    }
  CheckPathRequest_(const ContainerAllocator& _alloc)
    : path(_alloc)
    , safety_dist(0.0)
    , lethal_cost_mult(0.0)
    , inscrib_cost_mult(0.0)
    , unknown_cost_mult(0.0)
    , costmap(0)
    , return_on(0)
    , skip_poses(0)
    , path_cells_only(false)  {
  (void)_alloc;
    }



   typedef  ::nav_msgs::Path_<ContainerAllocator>  _path_type;
  _path_type path;

   typedef float _safety_dist_type;
  _safety_dist_type safety_dist;

   typedef float _lethal_cost_mult_type;
  _lethal_cost_mult_type lethal_cost_mult;

   typedef float _inscrib_cost_mult_type;
  _inscrib_cost_mult_type inscrib_cost_mult;

   typedef float _unknown_cost_mult_type;
  _unknown_cost_mult_type unknown_cost_mult;

   typedef uint8_t _costmap_type;
  _costmap_type costmap;

   typedef uint8_t _return_on_type;
  _return_on_type return_on;

   typedef uint8_t _skip_poses_type;
  _skip_poses_type skip_poses;

   typedef uint8_t _path_cells_only_type;
  _path_cells_only_type path_cells_only;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(LOCAL_COSTMAP)
  #undef LOCAL_COSTMAP
#endif
#if defined(_WIN32) && defined(GLOBAL_COSTMAP)
  #undef GLOBAL_COSTMAP
#endif

  enum {
    LOCAL_COSTMAP = 1u,
    GLOBAL_COSTMAP = 2u,
  };


  typedef boost::shared_ptr< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> const> ConstPtr;

}; // struct CheckPathRequest_

typedef ::mbf_msgs::CheckPathRequest_<std::allocator<void> > CheckPathRequest;

typedef boost::shared_ptr< ::mbf_msgs::CheckPathRequest > CheckPathRequestPtr;
typedef boost::shared_ptr< ::mbf_msgs::CheckPathRequest const> CheckPathRequestConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mbf_msgs::CheckPathRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mbf_msgs::CheckPathRequest_<ContainerAllocator1> & lhs, const ::mbf_msgs::CheckPathRequest_<ContainerAllocator2> & rhs)
{
  return lhs.path == rhs.path &&
    lhs.safety_dist == rhs.safety_dist &&
    lhs.lethal_cost_mult == rhs.lethal_cost_mult &&
    lhs.inscrib_cost_mult == rhs.inscrib_cost_mult &&
    lhs.unknown_cost_mult == rhs.unknown_cost_mult &&
    lhs.costmap == rhs.costmap &&
    lhs.return_on == rhs.return_on &&
    lhs.skip_poses == rhs.skip_poses &&
    lhs.path_cells_only == rhs.path_cells_only;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mbf_msgs::CheckPathRequest_<ContainerAllocator1> & lhs, const ::mbf_msgs::CheckPathRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mbf_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "16f70020b17f5c034724ed8fb518b9f5";
  }

  static const char* value(const ::mbf_msgs::CheckPathRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x16f70020b17f5c03ULL;
  static const uint64_t static_value2 = 0x4724ed8fb518b9f5ULL;
};

template<class ContainerAllocator>
struct DataType< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mbf_msgs/CheckPathRequest";
  }

  static const char* value(const ::mbf_msgs::CheckPathRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8                      LOCAL_COSTMAP  = 1\n"
"uint8                      GLOBAL_COSTMAP = 2\n"
"\n"
"nav_msgs/Path              path              # the path to be checked after transforming to costmap frame\n"
"float32                    safety_dist       # minimum distance allowed to the closest obstacle (footprint padding)\n"
"float32                    lethal_cost_mult  # cost multiplier for cells marked as lethal obstacle (zero is ignored)\n"
"float32                    inscrib_cost_mult # cost multiplier for cells marked as inscribed obstacle (zero is ignored)\n"
"float32                    unknown_cost_mult # cost multiplier for cells marked as unknown space (zero is ignored)\n"
"uint8                      costmap           # costmap in which to check the pose\n"
"uint8                      return_on         # abort check on finding a pose with this state or worse (zero is ignored)\n"
"uint8                      skip_poses        # skip this number of poses between checks, to speedup processing\n"
"bool                       path_cells_only   # check only cells directly traversed by the path, ignoring robot footprint\n"
"                                             # (if true, safety_dist is ignored)\n"
"\n"
"================================================================================\n"
"MSG: nav_msgs/Path\n"
"#An array of poses that represents a Path for a robot to follow\n"
"Header header\n"
"geometry_msgs/PoseStamped[] poses\n"
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
;
  }

  static const char* value(const ::mbf_msgs::CheckPathRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.path);
      stream.next(m.safety_dist);
      stream.next(m.lethal_cost_mult);
      stream.next(m.inscrib_cost_mult);
      stream.next(m.unknown_cost_mult);
      stream.next(m.costmap);
      stream.next(m.return_on);
      stream.next(m.skip_poses);
      stream.next(m.path_cells_only);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CheckPathRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mbf_msgs::CheckPathRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mbf_msgs::CheckPathRequest_<ContainerAllocator>& v)
  {
    s << indent << "path: ";
    s << std::endl;
    Printer< ::nav_msgs::Path_<ContainerAllocator> >::stream(s, indent + "  ", v.path);
    s << indent << "safety_dist: ";
    Printer<float>::stream(s, indent + "  ", v.safety_dist);
    s << indent << "lethal_cost_mult: ";
    Printer<float>::stream(s, indent + "  ", v.lethal_cost_mult);
    s << indent << "inscrib_cost_mult: ";
    Printer<float>::stream(s, indent + "  ", v.inscrib_cost_mult);
    s << indent << "unknown_cost_mult: ";
    Printer<float>::stream(s, indent + "  ", v.unknown_cost_mult);
    s << indent << "costmap: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.costmap);
    s << indent << "return_on: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.return_on);
    s << indent << "skip_poses: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.skip_poses);
    s << indent << "path_cells_only: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.path_cells_only);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MBF_MSGS_MESSAGE_CHECKPATHREQUEST_H
