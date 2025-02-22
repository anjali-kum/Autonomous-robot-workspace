; Auto-generated. Do not edit!


(cl:in-package turtlebot3_deliver_service-srv)


;//! \htmlinclude InitTurtlebotPose-request.msg.html

(cl:defclass <InitTurtlebotPose-request> (roslisp-msg-protocol:ros-message)
  ((poseWithCovarianceStamped
    :reader poseWithCovarianceStamped
    :initarg :poseWithCovarianceStamped
    :type geometry_msgs-msg:PoseWithCovarianceStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PoseWithCovarianceStamped)))
)

(cl:defclass InitTurtlebotPose-request (<InitTurtlebotPose-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <InitTurtlebotPose-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'InitTurtlebotPose-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot3_deliver_service-srv:<InitTurtlebotPose-request> is deprecated: use turtlebot3_deliver_service-srv:InitTurtlebotPose-request instead.")))

(cl:ensure-generic-function 'poseWithCovarianceStamped-val :lambda-list '(m))
(cl:defmethod poseWithCovarianceStamped-val ((m <InitTurtlebotPose-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot3_deliver_service-srv:poseWithCovarianceStamped-val is deprecated.  Use turtlebot3_deliver_service-srv:poseWithCovarianceStamped instead.")
  (poseWithCovarianceStamped m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <InitTurtlebotPose-request>) ostream)
  "Serializes a message object of type '<InitTurtlebotPose-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'poseWithCovarianceStamped) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <InitTurtlebotPose-request>) istream)
  "Deserializes a message object of type '<InitTurtlebotPose-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'poseWithCovarianceStamped) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<InitTurtlebotPose-request>)))
  "Returns string type for a service object of type '<InitTurtlebotPose-request>"
  "turtlebot3_deliver_service/InitTurtlebotPoseRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'InitTurtlebotPose-request)))
  "Returns string type for a service object of type 'InitTurtlebotPose-request"
  "turtlebot3_deliver_service/InitTurtlebotPoseRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<InitTurtlebotPose-request>)))
  "Returns md5sum for a message object of type '<InitTurtlebotPose-request>"
  "dd1774f5f4457d898f2470c31d60fe55")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'InitTurtlebotPose-request)))
  "Returns md5sum for a message object of type 'InitTurtlebotPose-request"
  "dd1774f5f4457d898f2470c31d60fe55")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<InitTurtlebotPose-request>)))
  "Returns full string definition for message of type '<InitTurtlebotPose-request>"
  (cl:format cl:nil "geometry_msgs/PoseWithCovarianceStamped poseWithCovarianceStamped~%~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovarianceStamped~%# This expresses an estimated pose with a reference coordinate frame and timestamp~%~%Header header~%PoseWithCovariance pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'InitTurtlebotPose-request)))
  "Returns full string definition for message of type 'InitTurtlebotPose-request"
  (cl:format cl:nil "geometry_msgs/PoseWithCovarianceStamped poseWithCovarianceStamped~%~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovarianceStamped~%# This expresses an estimated pose with a reference coordinate frame and timestamp~%~%Header header~%PoseWithCovariance pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <InitTurtlebotPose-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'poseWithCovarianceStamped))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <InitTurtlebotPose-request>))
  "Converts a ROS message object to a list"
  (cl:list 'InitTurtlebotPose-request
    (cl:cons ':poseWithCovarianceStamped (poseWithCovarianceStamped msg))
))
;//! \htmlinclude InitTurtlebotPose-response.msg.html

(cl:defclass <InitTurtlebotPose-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass InitTurtlebotPose-response (<InitTurtlebotPose-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <InitTurtlebotPose-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'InitTurtlebotPose-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot3_deliver_service-srv:<InitTurtlebotPose-response> is deprecated: use turtlebot3_deliver_service-srv:InitTurtlebotPose-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <InitTurtlebotPose-response>) ostream)
  "Serializes a message object of type '<InitTurtlebotPose-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <InitTurtlebotPose-response>) istream)
  "Deserializes a message object of type '<InitTurtlebotPose-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<InitTurtlebotPose-response>)))
  "Returns string type for a service object of type '<InitTurtlebotPose-response>"
  "turtlebot3_deliver_service/InitTurtlebotPoseResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'InitTurtlebotPose-response)))
  "Returns string type for a service object of type 'InitTurtlebotPose-response"
  "turtlebot3_deliver_service/InitTurtlebotPoseResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<InitTurtlebotPose-response>)))
  "Returns md5sum for a message object of type '<InitTurtlebotPose-response>"
  "dd1774f5f4457d898f2470c31d60fe55")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'InitTurtlebotPose-response)))
  "Returns md5sum for a message object of type 'InitTurtlebotPose-response"
  "dd1774f5f4457d898f2470c31d60fe55")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<InitTurtlebotPose-response>)))
  "Returns full string definition for message of type '<InitTurtlebotPose-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'InitTurtlebotPose-response)))
  "Returns full string definition for message of type 'InitTurtlebotPose-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <InitTurtlebotPose-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <InitTurtlebotPose-response>))
  "Converts a ROS message object to a list"
  (cl:list 'InitTurtlebotPose-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'InitTurtlebotPose)))
  'InitTurtlebotPose-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'InitTurtlebotPose)))
  'InitTurtlebotPose-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'InitTurtlebotPose)))
  "Returns string type for a service object of type '<InitTurtlebotPose>"
  "turtlebot3_deliver_service/InitTurtlebotPose")