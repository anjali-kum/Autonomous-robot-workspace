; Auto-generated. Do not edit!


(cl:in-package turtlebot3_deliver_service-msg)


;//! \htmlinclude PadOrder.msg.html

(cl:defclass <PadOrder> (roslisp-msg-protocol:ros-message)
  ((pad_number
    :reader pad_number
    :initarg :pad_number
    :type cl:integer
    :initform 0)
   (item_number
    :reader item_number
    :initarg :item_number
    :type cl:integer
    :initform 0))
)

(cl:defclass PadOrder (<PadOrder>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PadOrder>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PadOrder)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot3_deliver_service-msg:<PadOrder> is deprecated: use turtlebot3_deliver_service-msg:PadOrder instead.")))

(cl:ensure-generic-function 'pad_number-val :lambda-list '(m))
(cl:defmethod pad_number-val ((m <PadOrder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot3_deliver_service-msg:pad_number-val is deprecated.  Use turtlebot3_deliver_service-msg:pad_number instead.")
  (pad_number m))

(cl:ensure-generic-function 'item_number-val :lambda-list '(m))
(cl:defmethod item_number-val ((m <PadOrder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot3_deliver_service-msg:item_number-val is deprecated.  Use turtlebot3_deliver_service-msg:item_number instead.")
  (item_number m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PadOrder>) ostream)
  "Serializes a message object of type '<PadOrder>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pad_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pad_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'pad_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'pad_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'item_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'item_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'item_number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'item_number)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PadOrder>) istream)
  "Deserializes a message object of type '<PadOrder>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pad_number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pad_number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'pad_number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'pad_number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'item_number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'item_number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'item_number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'item_number)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PadOrder>)))
  "Returns string type for a message object of type '<PadOrder>"
  "turtlebot3_deliver_service/PadOrder")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PadOrder)))
  "Returns string type for a message object of type 'PadOrder"
  "turtlebot3_deliver_service/PadOrder")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PadOrder>)))
  "Returns md5sum for a message object of type '<PadOrder>"
  "f312fcf0d154bf3751121cfb69eca080")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PadOrder)))
  "Returns md5sum for a message object of type 'PadOrder"
  "f312fcf0d154bf3751121cfb69eca080")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PadOrder>)))
  "Returns full string definition for message of type '<PadOrder>"
  (cl:format cl:nil "uint32 pad_number~%uint32 item_number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PadOrder)))
  "Returns full string definition for message of type 'PadOrder"
  (cl:format cl:nil "uint32 pad_number~%uint32 item_number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PadOrder>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PadOrder>))
  "Converts a ROS message object to a list"
  (cl:list 'PadOrder
    (cl:cons ':pad_number (pad_number msg))
    (cl:cons ':item_number (item_number msg))
))
