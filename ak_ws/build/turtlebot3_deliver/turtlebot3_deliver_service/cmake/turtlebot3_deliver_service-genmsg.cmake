# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "turtlebot3_deliver_service: 3 messages, 1 services")

set(MSG_I_FLAGS "-Iturtlebot3_deliver_service:/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(turtlebot3_deliver_service_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg" NAME_WE)
add_custom_target(_turtlebot3_deliver_service_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlebot3_deliver_service" "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg" ""
)

get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg" NAME_WE)
add_custom_target(_turtlebot3_deliver_service_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlebot3_deliver_service" "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg" ""
)

get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg" NAME_WE)
add_custom_target(_turtlebot3_deliver_service_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlebot3_deliver_service" "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg" ""
)

get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv" NAME_WE)
add_custom_target(_turtlebot3_deliver_service_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlebot3_deliver_service" "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv" "geometry_msgs/Point:geometry_msgs/PoseWithCovariance:geometry_msgs/PoseWithCovarianceStamped:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Pose"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot3_deliver_service
)
_generate_msg_cpp(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot3_deliver_service
)
_generate_msg_cpp(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot3_deliver_service
)

### Generating Services
_generate_srv_cpp(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot3_deliver_service
)

### Generating Module File
_generate_module_cpp(turtlebot3_deliver_service
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot3_deliver_service
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(turtlebot3_deliver_service_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(turtlebot3_deliver_service_generate_messages turtlebot3_deliver_service_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_cpp _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_cpp _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_cpp _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_cpp _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlebot3_deliver_service_gencpp)
add_dependencies(turtlebot3_deliver_service_gencpp turtlebot3_deliver_service_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlebot3_deliver_service_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot3_deliver_service
)
_generate_msg_eus(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot3_deliver_service
)
_generate_msg_eus(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot3_deliver_service
)

### Generating Services
_generate_srv_eus(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot3_deliver_service
)

### Generating Module File
_generate_module_eus(turtlebot3_deliver_service
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot3_deliver_service
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(turtlebot3_deliver_service_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(turtlebot3_deliver_service_generate_messages turtlebot3_deliver_service_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_eus _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_eus _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_eus _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_eus _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlebot3_deliver_service_geneus)
add_dependencies(turtlebot3_deliver_service_geneus turtlebot3_deliver_service_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlebot3_deliver_service_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot3_deliver_service
)
_generate_msg_lisp(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot3_deliver_service
)
_generate_msg_lisp(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot3_deliver_service
)

### Generating Services
_generate_srv_lisp(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot3_deliver_service
)

### Generating Module File
_generate_module_lisp(turtlebot3_deliver_service
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot3_deliver_service
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(turtlebot3_deliver_service_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(turtlebot3_deliver_service_generate_messages turtlebot3_deliver_service_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_lisp _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_lisp _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_lisp _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_lisp _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlebot3_deliver_service_genlisp)
add_dependencies(turtlebot3_deliver_service_genlisp turtlebot3_deliver_service_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlebot3_deliver_service_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot3_deliver_service
)
_generate_msg_nodejs(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot3_deliver_service
)
_generate_msg_nodejs(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot3_deliver_service
)

### Generating Services
_generate_srv_nodejs(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot3_deliver_service
)

### Generating Module File
_generate_module_nodejs(turtlebot3_deliver_service
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot3_deliver_service
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(turtlebot3_deliver_service_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(turtlebot3_deliver_service_generate_messages turtlebot3_deliver_service_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_nodejs _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_nodejs _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_nodejs _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_nodejs _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlebot3_deliver_service_gennodejs)
add_dependencies(turtlebot3_deliver_service_gennodejs turtlebot3_deliver_service_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlebot3_deliver_service_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot3_deliver_service
)
_generate_msg_py(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot3_deliver_service
)
_generate_msg_py(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot3_deliver_service
)

### Generating Services
_generate_srv_py(turtlebot3_deliver_service
  "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot3_deliver_service
)

### Generating Module File
_generate_module_py(turtlebot3_deliver_service
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot3_deliver_service
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(turtlebot3_deliver_service_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(turtlebot3_deliver_service_generate_messages turtlebot3_deliver_service_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/PadOrder.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_py _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/AvailableItemList.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_py _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/msg/ServiceStatus.msg" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_py _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubuntu/ak_ws/src/turtlebot3_deliver/turtlebot3_deliver_service/srv/InitTurtlebotPose.srv" NAME_WE)
add_dependencies(turtlebot3_deliver_service_generate_messages_py _turtlebot3_deliver_service_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlebot3_deliver_service_genpy)
add_dependencies(turtlebot3_deliver_service_genpy turtlebot3_deliver_service_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlebot3_deliver_service_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot3_deliver_service)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot3_deliver_service
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(turtlebot3_deliver_service_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot3_deliver_service)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot3_deliver_service
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(turtlebot3_deliver_service_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot3_deliver_service)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot3_deliver_service
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(turtlebot3_deliver_service_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot3_deliver_service)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot3_deliver_service
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(turtlebot3_deliver_service_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot3_deliver_service)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot3_deliver_service\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot3_deliver_service
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(turtlebot3_deliver_service_generate_messages_py geometry_msgs_generate_messages_py)
endif()
