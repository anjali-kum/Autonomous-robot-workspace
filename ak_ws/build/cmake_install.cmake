# Install script for directory: /home/ubuntu/ak_ws/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ubuntu/ak_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/ak_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/ak_ws/install" TYPE PROGRAM FILES "/home/ubuntu/ak_ws/build/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/ak_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/ak_ws/install" TYPE PROGRAM FILES "/home/ubuntu/ak_ws/build/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/ak_ws/install/setup.bash;/home/ubuntu/ak_ws/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/ak_ws/install" TYPE FILE FILES
    "/home/ubuntu/ak_ws/build/catkin_generated/installspace/setup.bash"
    "/home/ubuntu/ak_ws/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/ak_ws/install/setup.sh;/home/ubuntu/ak_ws/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/ak_ws/install" TYPE FILE FILES
    "/home/ubuntu/ak_ws/build/catkin_generated/installspace/setup.sh"
    "/home/ubuntu/ak_ws/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/ak_ws/install/setup.zsh;/home/ubuntu/ak_ws/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/ak_ws/install" TYPE FILE FILES
    "/home/ubuntu/ak_ws/build/catkin_generated/installspace/setup.zsh"
    "/home/ubuntu/ak_ws/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ubuntu/ak_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ubuntu/ak_ws/install" TYPE FILE FILES "/home/ubuntu/ak_ws/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ubuntu/ak_ws/build/gtest/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/move_base_flex/move_base_flex/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/navigation_layers/navigation_layers/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/openslam_gmapping/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_arduino/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_chibios/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_mbed/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_msgs/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_python/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_tivac/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_vex_cortex/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_vex_v5/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_xbee/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_client/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/slam_gmapping/slam_gmapping/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/move_base_flex/mbf_abstract_core/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/move_base_flex/mbf_msgs/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3/turtlebot3/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3_deliver/turtlebot3_deliver/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3_msgs/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3/turtlebot3_navigation/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3_simulations/turtlebot3_simulations/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/auto_clear_costmap/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/speed_odom/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/follow_waypoints/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_server/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/hls_lfcd_lds_driver/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/audio_common/sound_play/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/slam_gmapping/gmapping/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/robot_pose_ekf/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_embeddedlinux/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_test/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/rosserial/rosserial_windows/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/laser_filters-noetic-devel/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/move_base_flex/mbf_utility/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/move_base_flex/mbf_abstract_nav/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/move_base_flex/mbf_simple_nav/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3/turtlebot3_bringup/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3_deliver/turtlebot3_deliver_service/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3/turtlebot3_example/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3_simulations/turtlebot3_fake/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3_simulations/turtlebot3_gazebo/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3/turtlebot3_slam/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3/turtlebot3_teleop/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/Nox_robot/nox_description/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/costmap_converter/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/move_base_flex/mbf_costmap_core/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/move_base_flex/mbf_costmap_nav/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/navigation_layers/range_sensor_layer/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/relaxed_astar/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/navigation_layers/social_navigation_layers/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/teb_local_planner/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/Nox_robot/nox/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/turtlebot3/turtlebot3_description/cmake_install.cmake")
  include("/home/ubuntu/ak_ws/build/ydlidar_ros_driver/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ubuntu/ak_ws/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
