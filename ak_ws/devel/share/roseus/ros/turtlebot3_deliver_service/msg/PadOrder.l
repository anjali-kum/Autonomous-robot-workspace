;; Auto-generated. Do not edit!


(when (boundp 'turtlebot3_deliver_service::PadOrder)
  (if (not (find-package "TURTLEBOT3_DELIVER_SERVICE"))
    (make-package "TURTLEBOT3_DELIVER_SERVICE"))
  (shadow 'PadOrder (find-package "TURTLEBOT3_DELIVER_SERVICE")))
(unless (find-package "TURTLEBOT3_DELIVER_SERVICE::PADORDER")
  (make-package "TURTLEBOT3_DELIVER_SERVICE::PADORDER"))

(in-package "ROS")
;;//! \htmlinclude PadOrder.msg.html


(defclass turtlebot3_deliver_service::PadOrder
  :super ros::object
  :slots (_pad_number _item_number ))

(defmethod turtlebot3_deliver_service::PadOrder
  (:init
   (&key
    ((:pad_number __pad_number) 0)
    ((:item_number __item_number) 0)
    )
   (send-super :init)
   (setq _pad_number (round __pad_number))
   (setq _item_number (round __item_number))
   self)
  (:pad_number
   (&optional __pad_number)
   (if __pad_number (setq _pad_number __pad_number)) _pad_number)
  (:item_number
   (&optional __item_number)
   (if __item_number (setq _item_number __item_number)) _item_number)
  (:serialization-length
   ()
   (+
    ;; uint32 _pad_number
    4
    ;; uint32 _item_number
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _pad_number
       (write-long _pad_number s)
     ;; uint32 _item_number
       (write-long _item_number s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _pad_number
     (setq _pad_number (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _item_number
     (setq _item_number (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get turtlebot3_deliver_service::PadOrder :md5sum-) "f312fcf0d154bf3751121cfb69eca080")
(setf (get turtlebot3_deliver_service::PadOrder :datatype-) "turtlebot3_deliver_service/PadOrder")
(setf (get turtlebot3_deliver_service::PadOrder :definition-)
      "uint32 pad_number
uint32 item_number

")



(provide :turtlebot3_deliver_service/PadOrder "f312fcf0d154bf3751121cfb69eca080")


