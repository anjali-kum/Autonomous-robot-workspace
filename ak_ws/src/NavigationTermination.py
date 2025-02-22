#!/usr/bin/env python3
import time
#time.sleep(60)
import rospy
import pandas as pd
from std_msgs.msg import String
pub = rospy.Publisher('chatter', String, queue_size=10)
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from math import radians, degrees
from actionlib_msgs.msg import *
from geometry_msgs.msg import Point
from playsound import playsound
from std_msgs.msg import String
from std_msgs.msg import Bool
from sensor_msgs.msg import Range
def moveToGoal(xGoal,yGoal,x,y,z,w):
  #define a client for to send goal requests to the move_base server through a SimpleActionClient
  ac = actionlib.SimpleActionClient("move_base", MoveBaseAction)
  #wait for the action server to come up
  while(not ac.wait_for_server(rospy.Duration.from_sec(5.0))):
          rospy.loginfo("Waiting for the move_base action server to come up")

  goal = MoveBaseGoal()
  #set up the frame parameters
  goal.target_pose.header.frame_id = "map"
  goal.target_pose.header.stamp = rospy.Time.now()
  # moving towards the goal*/
  goal.target_pose.pose.position =  Point(xGoal,yGoal,0)
  goal.target_pose.pose.orientation.x = x
  goal.target_pose.pose.orientation.y = y
  goal.target_pose.pose.orientation.z = z
  goal.target_pose.pose.orientation.w = w
  rospy.loginfo("Sending goal location ...")
  ac.send_goal(goal)
  ac.wait_for_result(rospy.Duration(240))
  if(ac.get_state() ==  GoalStatus.SUCCEEDED):
          rospy.loginfo("You have reached the destination")
          if num[0]=='0':              
              previous_table[0]='T0'
          else: 
              previous_table[0]=num[0]
          return True
  else:
          rospy.loginfo("The robot failed to reach the destination")
          return False
goalReached = False
goalReached = moveToGoal(map_navigation,coordinates[0], coordinates[1],coordinates[2], coordinates[3], coordinates[4], coordinates[5])
