
(cl:in-package :asdf)

(defsystem "turtlebot3_deliver_service-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "InitTurtlebotPose" :depends-on ("_package_InitTurtlebotPose"))
    (:file "_package_InitTurtlebotPose" :depends-on ("_package"))
  ))