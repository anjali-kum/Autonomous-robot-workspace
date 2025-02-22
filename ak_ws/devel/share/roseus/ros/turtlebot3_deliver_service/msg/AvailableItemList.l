;; Auto-generated. Do not edit!


(when (boundp 'turtlebot3_deliver_service::AvailableItemList)
  (if (not (find-package "TURTLEBOT3_DELIVER_SERVICE"))
    (make-package "TURTLEBOT3_DELIVER_SERVICE"))
  (shadow 'AvailableItemList (find-package "TURTLEBOT3_DELIVER_SERVICE")))
(unless (find-package "TURTLEBOT3_DELIVER_SERVICE::AVAILABLEITEMLIST")
  (make-package "TURTLEBOT3_DELIVER_SERVICE::AVAILABLEITEMLIST"))

(in-package "ROS")
;;//! \htmlinclude AvailableItemList.msg.html


(defclass turtlebot3_deliver_service::AvailableItemList
  :super ros::object
  :slots (_item_number _is_item_available ))

(defmethod turtlebot3_deliver_service::AvailableItemList
  (:init
   (&key
    ((:item_number __item_number) 0)
    ((:is_item_available __is_item_available) nil)
    )
   (send-super :init)
   (setq _item_number (round __item_number))
   (setq _is_item_available __is_item_available)
   self)
  (:item_number
   (&optional __item_number)
   (if __item_number (setq _item_number __item_number)) _item_number)
  (:is_item_available
   (&optional (__is_item_available :null))
   (if (not (eq __is_item_available :null)) (setq _is_item_available __is_item_available)) _is_item_available)
  (:serialization-length
   ()
   (+
    ;; uint32 _item_number
    4
    ;; bool _is_item_available
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _item_number
       (write-long _item_number s)
     ;; bool _is_item_available
       (if _is_item_available (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _item_number
     (setq _item_number (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _is_item_available
     (setq _is_item_available (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get turtlebot3_deliver_service::AvailableItemList :md5sum-) "4c8abaae09f0bffda0bd8946d2c8b728")
(setf (get turtlebot3_deliver_service::AvailableItemList :datatype-) "turtlebot3_deliver_service/AvailableItemList")
(setf (get turtlebot3_deliver_service::AvailableItemList :definition-)
      "uint32 item_number 
bool is_item_available

")



(provide :turtlebot3_deliver_service/AvailableItemList "4c8abaae09f0bffda0bd8946d2c8b728")


