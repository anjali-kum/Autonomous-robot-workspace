import rospy
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from math import radians, degrees
from actionlib_msgs.msg import *
from geometry_msgs.msg import Point
#from playsound import playsound
from sensor_msgs.msg import Range
from std_msgs.msg import Bool


class map_navigation():
  def choose(self):
    choice='q'
    rospy.loginfo("|-------------------------------|")
    rospy.loginfo("|PRESSE A KEY:")
    rospy.loginfo("|'0': Cafe ")
    rospy.loginfo("|'1': Office 1 ")
    rospy.loginfo("|'2': Office 2 ")
    rospy.loginfo("|'3': Office 3 ")
    rospy.loginfo("|'4': Office 4 ")
    rospy.loginfo("|'5': Office 5 ")
    rospy.loginfo("|'6': Office 6 ")
    rospy.loginfo("|'7': Office 7 ")
    rospy.loginfo("|'8': Office 8 ")
    rospy.loginfo("|'9': Office 9 ")
    rospy.loginfo("|'10': Office 10 ")
    rospy.loginfo("|'11': Office 11 ")
    rospy.loginfo("|'12': Office 12 ")
    rospy.loginfo("|'13': Office 13 ")
    rospy.loginfo("|'14': Office 14 ")
    rospy.loginfo("|'15': Office 15 ")
    rospy.loginfo("|'16': Office 16 ")
    rospy.loginfo("|'17': Office 17 ")
    rospy.loginfo("|'18': Office 18 ")
    rospy.loginfo("|'19': Office 19 ")
    rospy.loginfo("|'20': Office 20 ")

    rospy.loginfo("|'q': Quit ")
    rospy.loginfo("|-------------------------------|")
    rospy.loginfo("|WHERE TO GO?")
    choice = input()
    return choice
  def __init__(self):
    self.sub=rospy.Subscriber("pushed",Bool,self.sub_callback)
    self.sub1=rospy.Subscriber("rangeSonar_m",Range,self.ultra_m_callback)
 #   path_to_sounds = "/home/ubuntu/catkin_ws/src/turtlebot/sounds/"
    # declare the coordinates of interest
    self.xCafe = 5.332
    self.yCafe = -2.618
    self.x = 0.0
    self.y = 0.0
    self.z = 0.723
    self.w = 0.691
    self.xOffice1 = 4.987
    self.yOffice1 = 0.593
    self.x1 = 0.0
    self.y1 = 0.0
    self.z1 = 1.000
    self.w1 = 0.035
    self.xOffice2= 4.963
    self.yOffice2 = 1.879
    self.x2 = 0.0
    self.y2 = 0.0
    self.z2 = 1.000
    self.w2 = 0.008
    self.xOffice3 = 5.043
    self.yOffice3 = 3.915
    self.x3 = 0.0
    self.y3 = 0.0
    self.z3 = 1.000
    self.w3 = 0.026
    self.xOffice4 = 4.966
    self.yOffice4 = 5.852
    self.x4 = 0.0
    self.y4 = 0.0
    self.z4 = 1.000
    self.w4 = 0.017
    self.xOffice5 = 5.028
    self.yOffice5 = 8.027
    self.x5 = 0.0
    self.y5 = 0.0
    self.z5 = 1.000
    self.w5 = 0.005
    self.xOffice6= 5.148
    self.yOffice6 = 8.051
    self.x6 = 0.0
    self.y6 = 0.0
    self.z6 = -0.025
    self.w6 = 1.000
    self.xOffice7 = 5.210
    self.yOffice7 = 6.424
    self.x7 = 0.0
    self.y7 = 0.0
    self.z7 = 0.005
    self.w7 = 1.000
    self.xOffice8 = 5.267
    self.yOffice8 = 4.056
    self.x8 = 0.0
    self.y8 = 0.0
    self.z8 = 0.022
    self.w8 = 1.000
    self.xOffice9 = 5.214
    self.yOffice9 = 1.465
    self.x9 = 0.0
    self.y9 = 0.0
    self.z9 = -0.020
    self.w9 = 1.000
    self.xOffice10 = 5.292
    self.yOffice10 = -0.435
    self.x10 = 0.0
    self.y10 = 0.0
    self.z10 = 0.010
    self.w10 = 1.000 #20a
    self.xOffice11 = 5.244
    self.yOffice11 = 9.944
    self.x11 = 0.0
    self.y11 = 0.0
    self.z11 = 0.719
    self.w11 = 0.695  #straight 3
    self.xOffice12 = 3.272
    self.yOffice12 = 9.692
    self.x12 = 0.0
    self.y12 = 0.0
    self.z12 = 0.722
    self.w12 = 0.692  #straight 2


    self.goalReached = False
    # initiliaze
    rospy.init_node('map_navigation', anonymous=False)
    choice = self.choose()
    if (choice == 0):
    #  playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xCafe, self.yCafe, self.x, self.y, self.z, self.w)
    elif (choice == 1):
    #  playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice1, self.yOffice1, self.x1, self.y1, self.z1, self.w1)
    elif (choice == 2):
    #  playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice2, self.yOffice2, self.x2, self.y2, self.z2, self.w2)
    elif (choice == 3):
    #  playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice3, self.yOffice3, self.x3, self.y3, self.z3, self.w3)
    elif (choice == 4):
    #  playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice4, self.yOffice4, self.x4, self.y4, self.z4, self.w4)
    elif (choice == 5):
   #   playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice5, self.yOffice5, self.x5, self.y5, self.z5, self.w5)
    elif (choice == 6):
      #playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice6, self.yOffice6, self.x6, self.y6, self.z6, self.w6)
    elif (choice == 7):
     # playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice7, self.yOffice7, self.x7, self.y7, self.z7, self.w7)
    elif (choice == 8):
    #  playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice8, self.yOffice8, self.x8, self.y8, self.z8, self.w8)
    elif (choice == 9):
    #  playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice9, self.yOffice9, self.x9, self.y9, self.z9, self.w9)
    elif (choice == 10):
    #  playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice10, self.yOffice10, self.x10, self.y10, self.z10, self.w10)
    elif (choice == 11):
    #  playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice11, self.yOffice11, self.x11, self.y11, self.z11, self.w11)
    elif (choice == 12):
    #  playsound(path_to_sounds+"shubhadinam.wav")
      self.goalReached = self.moveToGoal(self.xOffice12, self.yOffice12, self.x12, self.y12, self.z12, self.w12)

    if (choice!='q'):
      if (self.goalReached):
        rospy.loginfo("Congratulations!")
        #rospy.spin()
#        playsound(path_to_sounds+"namaskaram.wav")
 #       playsound(path_to_sounds+"tisukondi.wav")
  #      playsound(path_to_sounds+"exit.wav")

      else:
        rospy.loginfo("Hard Luck!")
   #     playsound(path_to_sounds+"exit_button.wav")
    while choice != 'q':
      choice = self.choose()
      if (choice == 0):
      #  playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xCafe, self.yCafe, self.x, self.y, self.z, self.w)
      elif (choice == 1):
      #  playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice1, self.yOffice1, self.x1, self.y1, self.z1, self.w1)
      elif (choice == 2):
       # playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice2, self.yOffice2, self.x2, self.y2, self.z2, self.w2)
      elif (choice == 3):
       # playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice3, self.yOffice3, self.x3, self.y3, self.z3, self.w3)
      elif (choice == 4):
      #  playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice4, self.yOffice4, self.x4, self.y4, self.z4, self.w4)
      elif (choice == 5):
      #  playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice5, self.yOffice5, self.x5, self.y5, self.z5, self.w5)
      elif (choice == 6):
       # playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice6, self.yOffice6, self.x6, self.y6, self.z6, self.w6)
      elif (choice == 7):
       # playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice7, self.yOffice7, self.x7, self.y7, self.z7, self.w7)
      elif (choice == 8):
       # playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice8, self.yOffice8, self.x8, self.y8, self.z8, self.w8)
      elif (choice == 9):
       # playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice9, self.yOffice9, self.x9, self.y9, self.z9, self.w9)
      elif (choice == 10):
       # playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice10, self.yOffice10, self.x10, self.y10, self.z10, self.w10)
      elif (choice == 11):
    #  playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice11, self.yOffice11, self.x11, self.y11, self.z11, self.w11)
      elif (choice == 12):
    #  playsound(path_to_sounds+"shubhadinam.wav")
        self.goalReached = self.moveToGoal(self.xOffice12, self.yOffice12, self.x12, self.y12, self.z12, self.w12)
    
      if (choice!='q'):
        if (self.goalReached):
          rospy.loginfo("Congratulations!")
          #rospy.spin()
    #      playsound(path_to_sounds+"namaskaram.wav")
     #     playsound(path_to_sounds+"tisukondi.wav")
      #    playsound(path_to_sounds+"exit.wav")
          
        else:
          rospy.loginfo("Hard Luck!")
       #   playsound(path_to_sounds+"exit_button.wav")
  def sub_callback(self,data):
      print('exit')
     # path_to_sounds = "/home/ubuntu/vstn_ws/src/turtlebot/sounds/"
     # playsound(path_to_sounds+"Dhanyavadamulu.wav")
      self.goalReached = self.moveToGoal(self.xCafe, self.yCafe, self.x, self.y, self.z, self.w)
  def ultra_m_callback(self,data):
      print('aa')
      path_to_sounds = "/home/ubuntu/vstn_ws/src/turtlebot/sounds/"
     # playsound(path_to_sounds+"move.wav")
  def shutdown(self):
        # stop turtlebotr
      rospy.loginfo("Quit program")
      rospy.sleep()
  def moveToGoal(self,xGoal,yGoal,x,y,z,w):
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
              return True
      else:
              rospy.loginfo("The robot failed to reach the destination")
              return False
if __name__ == '__main__':
    try:
        rospy.loginfo("You have reached the destination")
        map_navigation()
        rospy.spin()
    except rospy.ROSInterruptException:
        rospy.loginfo("map_navigation node terminated.")


