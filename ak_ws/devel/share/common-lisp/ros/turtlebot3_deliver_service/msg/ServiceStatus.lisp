; Auto-generated. Do not edit!


(cl:in-package turtlebot3_deliver_service-msg)


;//! \htmlinclude ServiceStatus.msg.html

(cl:defclass <ServiceStatus> (roslisp-msg-protocol:ros-message)
  ((item_num_chosen_by_pad
    :reader item_num_chosen_by_pad
    :initarg :item_num_chosen_by_pad
    :type (cl:vector cl:integer)
   :initform (cl:make-array 3 :element-type 'cl:integer :initial-element 0))
   (is_item_available
    :reader is_item_available
    :initarg :is_item_available
    :type (cl:vector cl:boolean)
   :initform (cl:make-array 3 :element-type 'cl:boolean :initial-element cl:nil))
   (robot_service_sequence
    :reader robot_service_sequence
    :initarg :robot_service_sequence
    :type (cl:vector cl:integer)
   :initform (cl:make-array 3 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass ServiceStatus (<ServiceStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ServiceStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ServiceStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot3_deliver_service-msg:<ServiceStatus> is deprecated: use turtlebot3_deliver_service-msg:ServiceStatus instead.")))

(cl:ensure-generic-function 'item_num_chosen_by_pad-val :lambda-list '(m))
(cl:defmethod item_num_chosen_by_pad-val ((m <ServiceStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot3_deliver_service-msg:item_num_chosen_by_pad-val is deprecated.  Use turtlebot3_deliver_service-msg:item_num_chosen_by_pad instead.")
  (item_num_chosen_by_pad m))

(cl:ensure-generic-function 'is_item_available-val :lambda-list '(m))
(cl:defmethod is_item_available-val ((m <ServiceStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot3_deliver_service-msg:is_item_available-val is deprecated.  Use turtlebot3_deliver_service-msg:is_item_available instead.")
  (is_item_available m))

(cl:ensure-generic-function 'robot_service_sequence-val :lambda-list '(m))
(cl:defmethod robot_service_sequence-val ((m <ServiceStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot3_deliver_service-msg:robot_service_sequence-val is deprecated.  Use turtlebot3_deliver_service-msg:robot_service_sequence instead.")
  (robot_service_sequence m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ServiceStatus>) ostream)
  "Serializes a message object of type '<ServiceStatus>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'item_num_chosen_by_pad))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if ele 1 0)) ostream))
   (cl:slot-value msg 'is_item_available))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'robot_service_sequence))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ServiceStatus>) istream)
  "Deserializes a message object of type '<ServiceStatus>"
  (cl:setf (cl:slot-value msg 'item_num_chosen_by_pad) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'item_num_chosen_by_pad)))
    (cl:dotimes (i 3)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))))
  (cl:setf (cl:slot-value msg 'is_item_available) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'is_item_available)))
    (cl:dotimes (i 3)
    (cl:setf (cl:aref vals i) (cl:not (cl:zerop (cl:read-byte istream))))))
  (cl:setf (cl:slot-value msg 'robot_service_sequence) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'robot_service_sequence)))
    (cl:dotimes (i 3)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ServiceStatus>)))
  "Returns string type for a message object of type '<ServiceStatus>"
  "turtlebot3_deliver_service/ServiceStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ServiceStatus)))
  "Returns string type for a message object of type 'ServiceStatus"
  "turtlebot3_deliver_service/ServiceStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ServiceStatus>)))
  "Returns md5sum for a message object of type '<ServiceStatus>"
  "88c792271484968782eee6bf1d95c178")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ServiceStatus)))
  "Returns md5sum for a message object of type 'ServiceStatus"
  "88c792271484968782eee6bf1d95c178")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ServiceStatus>)))
  "Returns full string definition for message of type '<ServiceStatus>"
  (cl:format cl:nil "int32[3] item_num_chosen_by_pad~%bool[3] is_item_available~%int32[3] robot_service_sequence~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ServiceStatus)))
  "Returns full string definition for message of type 'ServiceStatus"
  (cl:format cl:nil "int32[3] item_num_chosen_by_pad~%bool[3] is_item_available~%int32[3] robot_service_sequence~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ServiceStatus>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'item_num_chosen_by_pad) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'is_item_available) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'robot_service_sequence) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ServiceStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'ServiceStatus
    (cl:cons ':item_num_chosen_by_pad (item_num_chosen_by_pad msg))
    (cl:cons ':is_item_available (is_item_available msg))
    (cl:cons ':robot_service_sequence (robot_service_sequence msg))
))
