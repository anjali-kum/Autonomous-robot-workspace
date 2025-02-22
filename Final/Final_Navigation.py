#!/usr/bin/env python3
import time
#time.sleep(60)
import rospy
import pandas as pd
import datetime
import os
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
from sensor_msgs.msg import LaserScan
from threading import Thread
from actionlib_msgs.msg import GoalID
import requests
import time
import rospy

print("libraries imported")

df = pd.read_csv('/home/ubuntu/ak_ws/src/Nox_robot/nox/Coordinates/coordinates.csv')
df_nz = pd.read_csv('/home/ubuntu/ak_ws/src/Nox_robot/nox/Coordinates/coordinates_nz.csv')
df_table_goal = pd.read_csv('/home/ubuntu/ak_ws/src/Nox_robot/nox/Coordinates/Table.csv')


def sub_callback(data):
    #global obstacle_detected #add this line for ultrasonic sensor
    print('exit')
    print(data.data)
    if(data.data == False):
        df_table = df[(df['Table'] == previous_table[0]) & (df['Direction'] == 'Reverse')]
        for i in range(len(df_table)):
            coordinates = list(df_table.iloc[len(df_table)-1-i,:])
        #goalReached = self.moveToGoal()
            map_navigation.goalReached = map_navigation.moveToGoal(map_navigation, coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5])
        df_table_goal_m = df_table_goal[df_table_goal['Table'] == 0]
        coordinates = list(df_table_goal_m.iloc[0,:])
        map_navigation.goalReached = map_navigation.moveToGoal(map_navigation, coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5])
        previous_table[0] = 0

sub = rospy.Subscriber("pushed", Bool, sub_callback)


class map_navigation():

    def __init__(self):
        self.playing = False
        self.remaining_coordinates = []
        self.obstacle = 0
        self.sub1 = rospy.Subscriber('rangeSonar', Range, self.ultra_m_callback)
        #self.sub1 = rospy.Subscriber('scan', LaserScan, self.laser_scan_callback)
        path_to_sounds = "/home/ubuntu/ak_ws/src/turtlebot/sounds/"
        # declare the coordinates of interest
        self.goalReached = False
        self.remaining_coordinates_array()
        print(f"destinations {self.remaining_coordinates}")
        rospy.init_node('map_navigation', anonymous=False)
        print(num[0])
        self.no_obs_threshold = 0
        self.recursive_move()
        if (self.goalReached):
            rospy.loginfo("Congratulations!")
            #rospy.spin()
            playsound(path_to_sounds + "namaskaram.wav")
            playsound(path_to_sounds + "tisukondi.wav")
            playsound(path_to_sounds + "exit_button.wav")
        else:
            rospy.loginfo("Hard Luck!")
            #playsound(path_to_sounds+"sorry.mp3")


    def recursive_move(self):
        print("Starting movement through coordinates")

        while self.remaining_coordinates:
            print("here inside loop")

            # Process the first set of coordinates
            coordinates = self.remaining_coordinates[0]
            print("4444")

            if self.obstacle == 0:
                print("5555")
                self.goalReached = self.moveToGoal(coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5])
                print("testing statement", self.goalReached)

                if self.goalReached:
                    self.remaining_coordinates.pop(0)
                #else:
                    #pass
            else:
                 current_time = time.time()
                 if self.obstacle_start_time and (current_time - self.obstacle_start_time)>60:
                
                     print("Audio is playing")
                     self.obstacle = 0
                     self.obstacle_start_time = None
                     self.no_obs_threshold = 0

        if len(self.remaining_coordinates) == 0:
            return 1
        else:
            return 0


    def remaining_coordinates_array(self):

        if (num[0] == 0):
            df_table = df[(df['Table'] == previous_table[0]) & (df['Direction'] == 'Reverse')]
            print(df_table)
            for i in range(len(df_table)):
                self.remaining_coordinates.append(list(df_table.iloc[i,:]))
            #playsound(path_to_sounds+"shubhadinam.wav")
            df_table_goal_m = df_table_goal[df_table_goal['Table'] == num[0]]
            self.remaining_coordinates.append(list(df_table_goal_m.iloc[0,:]))
            #self.goalReached = self.moveToGoal(coordinates[0], coordinates[1],coo>
            #self.goalReached = self.moveToGoal(-8.039,6.348,0,0,-0.064,0.998)
        else:
            #print('entered else condition',num[0])
            if previous_table[0] == 0:
                print('entered 2 nd condition', num[0])
                df_table = df[(df['Table'] == num[0]) & (df['Direction'] == 'Forward')]
                print(df_table)
                for i in range(len(df_table)):
                    self.remaining_coordinates.append(list(df_table.iloc[i,:]))
            else:
                df_table = df_nz[(df_nz['Previous'] == previous_table[0]) & (df_nz['Current'] == num[0])]
                for i in range(len(df_table)):
                    self.remaining_coordinates.append(list(df_table.iloc[i,:]))
            #playsound(path_to_sounds+"shubhadinam.wav")
            df_table_goal_m = df_table_goal[df_table_goal['Table'] == num[0]]
            self.remaining_coordinates.append(list(df_table_goal_m.iloc[0,:]))

    def multiple_goals(self):
        print('entered multiple goals ffunction', df)
        df_table = df[(df['Table'] == num[0]) & (df['Direction'] == 'Forward')]
        print(df_table)
        for i in range(len(df_table)):
            coordinates = list(df_table.iloc[i,:])
            print(coordinates)
            self.goalReached = self.moveToGoal(coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5])
        print('end of multiple goals ffunction')

    def multiple_goals_not_zero(self):
        print('entered multiple goals ffunction')
        df_table = df_nz[(df_nz['Previous'] == previous_table[0]) & (df_nz['Current'] == num[0])]
        for i in range(len(df_table)):
            coordinates = list(df_table.iloc[i,:])
            print(coordinates)
            self.goalReached = self.moveToGoal(coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5])
        print('end of multiple goals ffunction')

    def multiple_goals_return(self):
        print('entered multiple goals return ffunction')
        df_table = df[(df['table_no'] == previous_table[0]) & (df['Direction'] == 'Reverse')]
        print(df_table)
        print('table number is', previous_table[0], num[0])
        for i in range(len(df_table)):
            coordinates = list(df_table.iloc[len(df_table)-1-i,:])
            print(coordinates)
            self.goalReached = self.moveToGoal(coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5])
        print('end of multiple goals ffunction')

    
    def ultra_m_callback(self, msg):
        print("================ultrasonic readings=================")
        print( "Range values:", msg.range) # Print the range values (ultrasonic readings)
        #print(len(msg.ranges))
        #obstacles=msg.ranges[146:]
        #split_obs=len(obstacles)/3
        #r1,r2,r3=obstacles[:int(split_obs)],obstacles[int(split_obs):2*int(split_obs)],obstacles[2*int(split_obs):]
        #obs=[x for x in obstacles if x>0.2]
        #obs1=[x for x in r1 if x>0.2]
        #obs2=[x for x in r2 if x>0.2]
        #obs3=[x for x in r3 if x>0.2]
        try: 
            print("range:", msg.range)
            #print(min(obs),min(obs1),min(obs2),min(obs3))
            #if (min(obs1) <=0.5 and min(obs1)>=0.25) or (min(obs2) <=1.2 and min(obs2)>=0.2) or (min(obs3) <=0.5 and min(obs3)>=0.25):
            if (msg.range<200):
                path_to_sounds = "/home/ubuntu/ak_ws/src/turtlebot/sounds/" 
                print("obstacle is detected")
                print("Inside playing song")
                if self.playing==False:
                    print("playing")
                    self.playing=True
                    Thread(target=self.playaudio).start()
           # if (min(obs1) <=0.3 and min(obs1)>=0.2) or (min(obs2) <=0.7 and min(obs2)>=0.2) or (min(obs3) <=0.3 and min(obs3)>=0.2):
            if (msg.range <200):
                start=time.time()
                if self.obstacle==0:
                    self.obstacle=1
                    self.no_obs_threshold=0
                    self.obstacle_start_time = time.time()
                    self.cancel_goal()
            else:
                print("enetered here",self.no_obs_threshold)
                self.no_obs_threshold+=1
                print("enetered here",self.no_obs_threshold)
                print(self.no_obs_threshold)
                if self.no_obs_threshold>=20:
                    print("no obstacle bot moving")
                    self.obstacle=0
                    self.no_obs_threshold=0
        except Exception as e:
            print(e)
    def cancel_goal(self):
        start_cancel = time.time()
        print("Enter into Cancel Goal Function")
        try:
            cancel_pub = rospy.Publisher('/move_base/cancel', GoalID, queue_size=10)
            cancel_msg = GoalID()
            cancel_pub.publish(cancel_msg)
            print("Running in try block")
	    

        except Exception as e:
            print(e)


    def playaudio(self):
        #path_to_sounds = "/home/ubuntu/robot5_ws/src/turtlebot/sounds/"
        #playsound(path_to_sounds + "move.wav")       
        self.playing = False


    def shutdown(self):
        # stop turtlebot
        rospy.loginfo("Quit program")
        rospy.sleep()

    def moveToGoal(self, xGoal, yGoal, x, y, z, w):
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
        goal.target_pose.pose.position = Point(xGoal, yGoal, 0)
        goal.target_pose.pose.orientation.x = x
        goal.target_pose.pose.orientation.y = y
        goal.target_pose.pose.orientation.z = z
        goal.target_pose.pose.orientation.w = w
        rospy.loginfo("Sending goal location ...")
        ac.send_goal(goal)
        ac.wait_for_result(rospy.Duration(240))
        if(ac.get_state() == GoalStatus.SUCCEEDED):
            rospy.loginfo("You have reached the destination")
            previous_table[0] = num[0]
            return True
        else:
            rospy.loginfo("The robot failed to reach the destination")
            return False


bot_name = 'SKIVVY'  #bot ip address
t = [0]
l = [0]
l1 = [0]
previous_table = [0]
links = ['http://10.147.17.141/api/Office/latest']
num=[0]
list_tables=[1,2,0]
aa=input("enter the table numbers :")
while len(list_tables):
    num[0]=int(list_tables[0])
    print("the bot moving the table number ",num[0])
    map_navigation()
    list_tables.pop(0)
    time.sleep(2)
    

