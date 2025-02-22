from pathlib import Path
source_path = Path(__file__).resolve()
source_dir = source_path.parent
path=str(source_dir)+'/dependencies/'
coordinates_path=str(source_dir)+'/Coordinates/'
path_to_sounds=str(source_dir)+'/Audios/'
import json
file_name = path+'params.json'
with open(file_name) as f:
    params = json.loads(f.read())
request_time=params['Request_timeout_time']
import time
import sys
sys.path.append(path)
from ClearLogs import ClearLogs
ClearLogs(path)
import requests
from LogGenerator import logging
from Connection import connection

connect=connection(params)
IP=connect.StartConnection()
#print(IP)

WhileStatus=True
Except_Count=0
while WhileStatus:
    try:
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
        WhileStatus=False
    except Exception as e:
        Except_Count+=1
        logging.error(e)
        logging.info('Waiting for 10 seconds')
        time.sleep(params['ROS_delay_time'])
        if Except_Count>=7:
            logging.error("Breaking code because of library import failure")
            sys.exit()
            
try:
    df=pd.read_csv(coordinates_path+params['Coordinates_path'])
    df_nz=pd.read_csv(coordinates_path+params['coordinates_nz_path'])
    df_table_goal=pd.read_csv(coordinates_path+params['tables_path'])
    
    #time.sleep(10)
    requests.post('http://'+params['cloud_application_ip']+'/api/ipaddress',data={'rest_name':params['Restuarant_Name'],'bot_name':params['Bot_name'],'ip':IP},timeout=request_time)
    service=requests.get('http://'+params['cloud_application_ip']+'/api/'+params['Restuarant_Name']+'/service/latest',timeout=request_time)
    service=service.json()
    service=service['service_avi']
except Exception as e:
    logging.error(e)
def sub_callback(data):
    if(data.data==False):
        #rospy.loginfo(message)
        message='Exit button is pressed'
        logging.info(message)
        df_table=df[(df['Table']==previous_table[0]) & (df['Direction']=='Reverse')]
        for i in range(len(df_table)):
            coordinates=list(df_table.iloc[len(df_table)-1-i,:])
        #goalReached = self.moveToGoal()
            map_navigation.goalReached = map_navigation.moveToGoal(map_navigation,coordinates[0], coordinates[1],coordinates[2], coordinates[3], coordinates[4], coordinates[5])
        df_table_goal_m=df_table_goal[df_table_goal['Table']==0]
        coordinates=list(df_table_goal_m.iloc[0,:])
        map_navigation.goalReached = map_navigation.moveToGoal(map_navigation,coordinates[0], coordinates[1],coordinates[2], coordinates[3], coordinates[4], coordinates[5])
        previous_table[0]=0
#sub=rospy.Subscriber("pushed",Bool,sub_callback)
class map_navigation():
    
    def __init__(self):
        self.sub1=rospy.Subscriber("rangeSonar_m",Range,self.ultra_m_callback)
        # declare the coordinates of interest
        self.goalReached = False
        rospy.init_node('map_navigation', anonymous=False)
        if (num[0] == 0):
          self.multiple_goals_return()
          #playsound(path_to_sounds+"shubhadinam.wav")
          df_table_goal_m=df_table_goal[df_table_goal['Table']==num[0]]
          coordinates=list(df_table_goal_m.iloc[0,:])
          self.goalReached = self.moveToGoal(coordinates[0], coordinates[1],coordinates[2], coordinates[3], coordinates[4], coordinates[5])
          #self.goalReached = self.moveToGoal(-8.039,6.348,0,0,-0.064,0.998)
        else:
          #print('entered else condition',num[0])
          if previous_table[0]==0:
              self.multiple_goals()
          else:
              self.multiple_goals_not_zero()
          #playsound(path_to_sounds+"shubhadinam.wav")
          df_table_goal_m=df_table_goal[df_table_goal['Table']==num[0]]
          coordinates=list(df_table_goal_m.iloc[0,:])
          self.goalReached = self.moveToGoal(coordinates[0], coordinates[1],coordinates[2], coordinates[3], coordinates[4], coordinates[5])
      #if (choice !='q'):
        if (self.goalReached):
          message="Congratulations!"
          rospy.loginfo(message)
          logging.info(message)
          #rospy.spin()
          playsound(path_to_sounds+params['Namaskaram_audio_filename'])
          playsound(path_to_sounds+params['tesukondi_audio_file'])
          playsound(path_to_sounds+params['exit_audio_file'])
        else:
          rospy.loginfo("Hard Luck!")
          #playsound(path_to_sounds+"sorry.mp3")
    def multiple_goals(self):
        df_table=df[(df['Table']==num[0]) & (df['Direction']=='Forward')]
        #print(df_table)
        for i in range(len(df_table)):
            coordinates=list(df_table.iloc[i,:])
            #print(coordinates)
            self.goalReached = self.moveToGoal(coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5])
    def multiple_goals_not_zero(self):
        df_table=df_nz[(df_nz['Previous']==previous_table[0]) & (df_nz['Current']==num[0])]
        for i in range(len(df_table)):
            coordinates=list(df_table.iloc[i,:])
            #print(coordinates)
            self.goalReached = self.moveToGoal(coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5])
    def multiple_goals_return(self):
        df_table=df[(df['Table']==previous_table[0]) & (df['Direction']=='Reverse')]
        #print(df_table)
        #print('table number is',previous_table[0],num[0])
        for i in range(len(df_table)):
            coordinates=list(df_table.iloc[len(df_table)-1-i,:])
            #print(coordinates)
            self.goalReached = self.moveToGoal(coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5])
    def ultra_m_callback(self,data):
        #print('aa')
        playsound(path_to_sounds+params['move_audio'])
   
    def shutdown(self):
        # stop turtlebot
        rospy.loginfo("Quit program")
        rospy.sleep()
    def moveToGoal(self,xGoal,yGoal,x,y,z,w):
      #define a client for to send goal requests to the move_base server through a SimpleActionClient
      ac = actionlib.SimpleActionClient("move_base", MoveBaseAction)
      #wait for the action server to come up
      while(not ac.wait_for_server(rospy.Duration.from_sec(5.0))):
              message="Waiting for the move_base action server to come up"
              rospy.loginfo(message)
              logging.info(message)
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
      message="Sending goal location ..."
      rospy.loginfo(message)
      logging.info(message)
      ac.send_goal(goal)
      ac.wait_for_result(rospy.Duration(240))
      if(ac.get_state() ==  GoalStatus.SUCCEEDED):
              message="You have reached the destination"
              rospy.loginfo(message)
              logging.info(message)
              requests.post('http://'+params['cloud_application_ip']+'/api/service/post',data={'rest_name':params['Restuarant_Name'],'rest_location':params['Restuarant_location'],'bot_name':params['Bot_name'],'table_no':num[0],'bot_color':params['Bot_colours']})
              previous_table[0]=num[0]
              return True
      else:
              message="The robot failed to reach the destination"
              rospy.loginfo(message)
              logging.info(message)
              return False
bot_name=params['Bot_name'] #bot ip address
t=[0]
l=[0]
l1=[0]
previous_table=[0]
link_ip='http://'+params['cloud_application_ip']+':8000/api/'+params['Restuarant_Name']+'/latest'
links=[link_ip]
num=[0]
def Instruction(links,C):
    for link in links:
        try:
            a=requests.get(link).json()
            num[0]=a['table_no']
            t[0]=a['time']
            if t[0] not in l:
                logging.info(f'Instruction Given is table no {num[0]} at {t[0]}')
                l.append(t[0])
                if C==1:
                    map_navigation()
        except Exception as e:
            logging.error(e)
if __name__ == '__main__':
    C=0
    logging.info('About to enter while loop and service status is {service}')
    while service:
        if C==0:
            #print('while success')
            try:
                Instruction(links,C)
                C=1
            except:
                pass
