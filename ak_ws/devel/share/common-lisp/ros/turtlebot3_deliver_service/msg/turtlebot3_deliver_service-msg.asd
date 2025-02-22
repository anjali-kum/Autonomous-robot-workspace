
(cl:in-package :asdf)

(defsystem "turtlebot3_deliver_service-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "AvailableItemList" :depends-on ("_package_AvailableItemList"))
    (:file "_package_AvailableItemList" :depends-on ("_package"))
    (:file "PadOrder" :depends-on ("_package_PadOrder"))
    (:file "_package_PadOrder" :depends-on ("_package"))
    (:file "ServiceStatus" :depends-on ("_package_ServiceStatus"))
    (:file "_package_ServiceStatus" :depends-on ("_package"))
  ))