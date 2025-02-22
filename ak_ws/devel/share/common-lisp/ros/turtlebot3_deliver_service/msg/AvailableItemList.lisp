; Auto-generated. Do not edit!


(cl:in-package turtlebot3_deliver_service-msg)


;//! \htmlinclude AvailableItemList.msg.html

(cl:defclass <AvailableItemList> (roslisp-msg-protocol:ros-message)
  ((item_number
    :reader item_number
    :initarg :item_number
    :type cl:integer
    :initform 0)
   (is_item_available
    :reader is_item_available
    :initarg :is_item_available
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass AvailableItemList (<AvailableItemList>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AvailableItemList>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AvailableItemList)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot3_deliver_service-msg:<AvailableItemList> is deprecated: use turtlebot3_deliver_service-msg:AvailableItemList instead.")))

(cl:ensure-generic-function 'item_number-val :lambda-list '(m))
(cl:defmethod item_number-val ((m <AvailableItemList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot3_deliver_service-msg:item_number-val is deprecated.  Use turtlebot3_deliver_service-msg:item_number instead.")
  (item_number m))

(cl:ensure-generic-function 'is_item_available-val :lambda-list '(m))
(cl:defmethod is_item_available-val ((m <AvailableItemList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot3_deliver_service-msg:is_item_available-val is deprecated.  Use turtlebot3_deliver_service-msg:is_item_available instead.")
  (is_item_available m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AvailableItemList>) ostream)
  "Serializes a message object of type '<AvailableItemList>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'item_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'item_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'item_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'item_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_item_available) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AvailableItemList>) istream)
  "Deserializes a message object of type '<AvailableItemList>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'item_number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'item_number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'item_number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'item_number)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'is_item_available) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AvailableItemList>)))
  "Returns string type for a message object of type '<AvailableItemList>"
  "turtlebot3_deliver_service/AvailableItemList")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AvailableItemList)))
  "Returns string type for a message object of type 'AvailableItemList"
  "turtlebot3_deliver_service/AvailableItemList")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AvailableItemList>)))
  "Returns md5sum for a message object of type '<AvailableItemList>"
  "4c8abaae09f0bffda0bd8946d2c8b728")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AvailableItemList)))
  "Returns md5sum for a message object of type 'AvailableItemList"
  "4c8abaae09f0bffda0bd8946d2c8b728")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AvailableItemList>)))
  "Returns full string definition for message of type '<AvailableItemList>"
  (cl:format cl:nil "uint32 item_number ~%bool is_item_available~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AvailableItemList)))
  "Returns full string definition for message of type 'AvailableItemList"
  (cl:format cl:nil "uint32 item_number ~%bool is_item_available~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AvailableItemList>))
  (cl:+ 0
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AvailableItemList>))
  "Converts a ROS message object to a list"
  (cl:list 'AvailableItemList
    (cl:cons ':item_number (item_number msg))
    (cl:cons ':is_item_available (is_item_available msg))
))
