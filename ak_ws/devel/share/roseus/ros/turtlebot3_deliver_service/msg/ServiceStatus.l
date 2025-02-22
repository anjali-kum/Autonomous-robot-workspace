;; Auto-generated. Do not edit!


(when (boundp 'turtlebot3_deliver_service::ServiceStatus)
  (if (not (find-package "TURTLEBOT3_DELIVER_SERVICE"))
    (make-package "TURTLEBOT3_DELIVER_SERVICE"))
  (shadow 'ServiceStatus (find-package "TURTLEBOT3_DELIVER_SERVICE")))
(unless (find-package "TURTLEBOT3_DELIVER_SERVICE::SERVICESTATUS")
  (make-package "TURTLEBOT3_DELIVER_SERVICE::SERVICESTATUS"))

(in-package "ROS")
;;//! \htmlinclude ServiceStatus.msg.html


(defclass turtlebot3_deliver_service::ServiceStatus
  :super ros::object
  :slots (_item_num_chosen_by_pad _is_item_available _robot_service_sequence ))

(defmethod turtlebot3_deliver_service::ServiceStatus
  (:init
   (&key
    ((:item_num_chosen_by_pad __item_num_chosen_by_pad) (make-array 3 :initial-element 0 :element-type :integer))
    ((:is_item_available __is_item_available) (let (r) (dotimes (i 3) (push nil r)) r))
    ((:robot_service_sequence __robot_service_sequence) (make-array 3 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _item_num_chosen_by_pad __item_num_chosen_by_pad)
   (setq _is_item_available __is_item_available)
   (setq _robot_service_sequence __robot_service_sequence)
   self)
  (:item_num_chosen_by_pad
   (&optional __item_num_chosen_by_pad)
   (if __item_num_chosen_by_pad (setq _item_num_chosen_by_pad __item_num_chosen_by_pad)) _item_num_chosen_by_pad)
  (:is_item_available
   (&optional __is_item_available)
   (if __is_item_available (setq _is_item_available __is_item_available)) _is_item_available)
  (:robot_service_sequence
   (&optional __robot_service_sequence)
   (if __robot_service_sequence (setq _robot_service_sequence __robot_service_sequence)) _robot_service_sequence)
  (:serialization-length
   ()
   (+
    ;; int32[3] _item_num_chosen_by_pad
    (* 4    3)
    ;; bool[3] _is_item_available
    (* 1    3)
    ;; int32[3] _robot_service_sequence
    (* 4    3)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32[3] _item_num_chosen_by_pad
     (dotimes (i 3)
       (write-long (elt _item_num_chosen_by_pad i) s)
       )
     ;; bool[3] _is_item_available
     (dotimes (i 3)
       (if (elt _is_item_available i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; int32[3] _robot_service_sequence
     (dotimes (i 3)
       (write-long (elt _robot_service_sequence i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32[3] _item_num_chosen_by_pad
   (dotimes (i (length _item_num_chosen_by_pad))
     (setf (elt _item_num_chosen_by_pad i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     )
   ;; bool[3] _is_item_available
   (dotimes (i (length _is_item_available))
     (setf (elt _is_item_available i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     )
   ;; int32[3] _robot_service_sequence
   (dotimes (i (length _robot_service_sequence))
     (setf (elt _robot_service_sequence i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get turtlebot3_deliver_service::ServiceStatus :md5sum-) "88c792271484968782eee6bf1d95c178")
(setf (get turtlebot3_deliver_service::ServiceStatus :datatype-) "turtlebot3_deliver_service/ServiceStatus")
(setf (get turtlebot3_deliver_service::ServiceStatus :definition-)
      "int32[3] item_num_chosen_by_pad
bool[3] is_item_available
int32[3] robot_service_sequence

")



(provide :turtlebot3_deliver_service/ServiceStatus "88c792271484968782eee6bf1d95c178")


