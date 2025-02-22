;; Auto-generated. Do not edit!


(when (boundp 'turtlebot3_deliver_service::InitTurtlebotPose)
  (if (not (find-package "TURTLEBOT3_DELIVER_SERVICE"))
    (make-package "TURTLEBOT3_DELIVER_SERVICE"))
  (shadow 'InitTurtlebotPose (find-package "TURTLEBOT3_DELIVER_SERVICE")))
(unless (find-package "TURTLEBOT3_DELIVER_SERVICE::INITTURTLEBOTPOSE")
  (make-package "TURTLEBOT3_DELIVER_SERVICE::INITTURTLEBOTPOSE"))
(unless (find-package "TURTLEBOT3_DELIVER_SERVICE::INITTURTLEBOTPOSEREQUEST")
  (make-package "TURTLEBOT3_DELIVER_SERVICE::INITTURTLEBOTPOSEREQUEST"))
(unless (find-package "TURTLEBOT3_DELIVER_SERVICE::INITTURTLEBOTPOSERESPONSE")
  (make-package "TURTLEBOT3_DELIVER_SERVICE::INITTURTLEBOTPOSERESPONSE"))

(in-package "ROS")

(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))




(defclass turtlebot3_deliver_service::InitTurtlebotPoseRequest
  :super ros::object
  :slots (_poseWithCovarianceStamped ))

(defmethod turtlebot3_deliver_service::InitTurtlebotPoseRequest
  (:init
   (&key
    ((:poseWithCovarianceStamped __poseWithCovarianceStamped) (instance geometry_msgs::PoseWithCovarianceStamped :init))
    )
   (send-super :init)
   (setq _poseWithCovarianceStamped __poseWithCovarianceStamped)
   self)
  (:poseWithCovarianceStamped
   (&rest __poseWithCovarianceStamped)
   (if (keywordp (car __poseWithCovarianceStamped))
       (send* _poseWithCovarianceStamped __poseWithCovarianceStamped)
     (progn
       (if __poseWithCovarianceStamped (setq _poseWithCovarianceStamped (car __poseWithCovarianceStamped)))
       _poseWithCovarianceStamped)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/PoseWithCovarianceStamped _poseWithCovarianceStamped
    (send _poseWithCovarianceStamped :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/PoseWithCovarianceStamped _poseWithCovarianceStamped
       (send _poseWithCovarianceStamped :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/PoseWithCovarianceStamped _poseWithCovarianceStamped
     (send _poseWithCovarianceStamped :deserialize buf ptr-) (incf ptr- (send _poseWithCovarianceStamped :serialization-length))
   ;;
   self)
  )

(defclass turtlebot3_deliver_service::InitTurtlebotPoseResponse
  :super ros::object
  :slots ())

(defmethod turtlebot3_deliver_service::InitTurtlebotPoseResponse
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass turtlebot3_deliver_service::InitTurtlebotPose
  :super ros::object
  :slots ())

(setf (get turtlebot3_deliver_service::InitTurtlebotPose :md5sum-) "dd1774f5f4457d898f2470c31d60fe55")
(setf (get turtlebot3_deliver_service::InitTurtlebotPose :datatype-) "turtlebot3_deliver_service/InitTurtlebotPose")
(setf (get turtlebot3_deliver_service::InitTurtlebotPose :request) turtlebot3_deliver_service::InitTurtlebotPoseRequest)
(setf (get turtlebot3_deliver_service::InitTurtlebotPose :response) turtlebot3_deliver_service::InitTurtlebotPoseResponse)

(defmethod turtlebot3_deliver_service::InitTurtlebotPoseRequest
  (:response () (instance turtlebot3_deliver_service::InitTurtlebotPoseResponse :init)))

(setf (get turtlebot3_deliver_service::InitTurtlebotPoseRequest :md5sum-) "dd1774f5f4457d898f2470c31d60fe55")
(setf (get turtlebot3_deliver_service::InitTurtlebotPoseRequest :datatype-) "turtlebot3_deliver_service/InitTurtlebotPoseRequest")
(setf (get turtlebot3_deliver_service::InitTurtlebotPoseRequest :definition-)
      "geometry_msgs/PoseWithCovarianceStamped poseWithCovarianceStamped


================================================================================
MSG: geometry_msgs/PoseWithCovarianceStamped
# This expresses an estimated pose with a reference coordinate frame and timestamp

Header header
PoseWithCovariance pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/PoseWithCovariance
# This represents a pose in free space with uncertainty.

Pose pose

# Row-major representation of the 6x6 covariance matrix
# The orientation parameters use a fixed-axis representation.
# In order, the parameters are:
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
float64[36] covariance

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
---
")

(setf (get turtlebot3_deliver_service::InitTurtlebotPoseResponse :md5sum-) "dd1774f5f4457d898f2470c31d60fe55")
(setf (get turtlebot3_deliver_service::InitTurtlebotPoseResponse :datatype-) "turtlebot3_deliver_service/InitTurtlebotPoseResponse")
(setf (get turtlebot3_deliver_service::InitTurtlebotPoseResponse :definition-)
      "geometry_msgs/PoseWithCovarianceStamped poseWithCovarianceStamped


================================================================================
MSG: geometry_msgs/PoseWithCovarianceStamped
# This expresses an estimated pose with a reference coordinate frame and timestamp

Header header
PoseWithCovariance pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/PoseWithCovariance
# This represents a pose in free space with uncertainty.

Pose pose

# Row-major representation of the 6x6 covariance matrix
# The orientation parameters use a fixed-axis representation.
# In order, the parameters are:
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
float64[36] covariance

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
---
")



(provide :turtlebot3_deliver_service/InitTurtlebotPose "dd1774f5f4457d898f2470c31d60fe55")


