//Welcome to Durga prasad coding
#define USE_USBCON
#include <Wire.h>
#include <PID_v1.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
#include <ros/time.h>
#include <ArduinoHardware.h>
#include <std_msgs/Float64.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>0
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/Bool.h>
#include <Ultrasonic.h>
/***********************************************************************************
  loop time Decleration like frequency for publishing
************************************************************************************/
#define LOOPTIME 100     //Looptime in millisecond
const byte noCommLoopMax = 10;                //number of main loops the robot will execute without communication before stopping
unsigned int noCommLoops = 0;                 //main loop without communication counter
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);
/***********************************************************************************
exit sensor Declaration
************************************************************************************/
const int button_pin = 5;
   const int led_pin = 13;
   
   bool last_reading;
   long last_debounce_time=0;
   long debounce_delay=6000;
   bool published = true;
/***********************************************************************************
  motor pin numbers Decleration
************************************************************************************/
#define dir_rig 8
#define pwm_rig 6
#define dir_lef 9
#define pwm_lef 7
/******************************************************************************
  ULTRASONIC input pin numbers Decleration
************************************************************************************/
Ultrasonic ultrasonic_m(11,12); //11 trig,12 echo
long ultra_last_debounce_time=0;
long ultra_debounce_delay=6000;
int duration;
int distance;
int ultracount;
int u_m;
/***********************************************************************************
  encoder input pin numbers Decleration
************************************************************************************/
const byte interruptPin_rais_a_rig = 31;       //2, 3, 18, 19, 20, 21 interrupt pins
const byte interruptPin_fal_a_rig = 33;
const byte interruptPin_rais_b_rig = 35;
const byte interruptPin_fal_b_rig = 37;

const byte interruptPin_rais_a_lef = 22;       //2, 3, 18, 19, 20, 21 interrupt pins
const byte interruptPin_fal_a_lef = 23;
const byte interruptPin_rais_b_lef = 24;
const byte interruptPin_fal_b_lef = 25;

volatile byte state = LOW;
signed long int count_rig = 0, count_lef = 0;
int en_a_state_rig = 0, en_b_state_rig = 0, en_a_las_state_rig = 0, en_b_las_state_rig = 0;
int en_a_state_lef = 0, en_b_state_lef = 0, en_a_las_state_lef = 0, en_b_las_state_lef = 0;

long encoder_left = 0;
long encoder_right = 0;
/***********************************************************************************
  speed Decleration
*********************************************************************************/
const double speed_pwm = 0.00148 ;//0.00083--dc motors //0.00235 //0.011
const double min_speed_cmd = 0.02962;//100 rpm  0.01349; //50 rpm//0.0038--dc motors; //2.26; //0.0882;
unsigned long lastMilli = 0, lm = 0;
const double radius = 0.0625;  //0.06125;////0.055681818;                   //Wheel radius, in m
const double wheelbase = 0.32; //0.32;               //Wheelbase, in m

double c_r = 0, c_l = 0;

double speed_req = 0;                         //Desired linear speed for the robot, in m/s
double angular_speed_req = 0;                 //Desired angular speed for the robot, in rad/s

double speed_req_left = 0;                    //Desired speed for left wheel in m/s
double speed_act_left = 0;                    //Actual speed for left wheel in m/s
double speed_cmd_left = 0;                    //Command speed for left wheel in m/s

double speed_req_right = 0;                   //Desired speed for right wheel in m/s
double speed_act_right = 0;                   //Actual speed for right wheel in m/s
double speed_cmd_right = 0;                   //Command speed for right wheel in m/s

const double max_speed = 0.03599; /// above 100 rpm// //0.16--dc motors;                 //Max speed in m/s
/******initialize Pwm values to zero**********/
int PWM_leftMotor = 0;
int PWM_rightMotor = 0;
int d = 0;
/***********************************************************************************
  PID Decleration
************************************************************************************/
const double PID_left_param[] = { 0.24, 0, 1 }; //Respectively Kp//0.29, Ki and Kd for left motor PID
const double PID_right_param[] = { 0.24, 0, 1 }; //Respectively Kp//0.262, Ki and Kd for right motor PID
PID PID_leftMotor(&speed_act_left, &speed_cmd_left, &speed_req_left, PID_left_param[0], PID_left_param[1], PID_left_param[2], DIRECT);          //Setting up the PID for left motor
PID PID_rightMotor(&speed_act_right, &speed_cmd_right, &speed_req_right, PID_right_param[0], PID_right_param[1], PID_right_param[2], DIRECT);   //Setting up the PID for right motor

ros::NodeHandle nh;
/***********************************************************************************
  Function to handle cmd_vel
************************************************************************************/
void handle_cmd (const geometry_msgs::Twist& cmd_vel)
{
  noCommLoops = 0;                                                  //Reset the counter for number of main loops without communication
  // if(ultracount==1)
 // {
    speed_req = cmd_vel.linear.x;                                     //Extract the commanded linear speed from the message

    angular_speed_req = cmd_vel.angular.z;                            //Extract the commanded angular speed from the message

    speed_req_left  = speed_req - angular_speed_req * (wheelbase / 2); //Calculate the required speed for the left motor to comply with commanded linear and angular speeds
    speed_req_right = speed_req + angular_speed_req * (wheelbase / 2); //Calculate the required speed for the right motor to comply with commanded linear and angular speeds
  //}
  //    else if(ultracount==0)
  //    {
  //      speed_req_left=0;
  //      speed_req_right=0;
  //      }
}
/***********************************************************************************
  Decelartion & Intialization of PUB & SUB message types and functiolns
************************************************************************************/

geometry_msgs::Pose2D pwm_output_msg;
geometry_msgs::Pose2D encoder_msg;
geometry_msgs::Vector3Stamped speed_msg;                                //create a "speed_msg" ROS message
sensor_msgs::Imu imu_msg;
sensor_msgs::Range sonar_msg_m;//ultrasonic
std_msgs::Bool pushed_msg;

geometry_msgs::TransformStamped t;
geometry_msgs::TransformStamped l;
tf::TransformBroadcaster broadcaster;
char base_link[] = "/base_link";
char imu_frame[] = "/imu";
char ultra_frame[]="/ultrasonic";
ros::Publisher pub_sonar_m("rangeSonar_m", &sonar_msg_m);
ros::Publisher pub_button("pushed", &pushed_msg);
ros::Publisher imu_pub("imu_data", &imu_msg);
//ros::Publisher range_pub("sonar",&range_msg);
ros::Subscriber<geometry_msgs::Twist> cmd_vel("cmd_vel", handle_cmd);   //create a subscriber to ROS topic for velocity commands (will execute "handle_cmd" function when receiving data)
ros::Publisher speed_pub("speed", &speed_msg);                          //create a publisher to ROS topic "speed" using the "speed_msg" type
ros::Publisher pwm_output_pub("pwm_output", &pwm_output_msg);
ros::Publisher encoder_pub("encoder", &encoder_msg);

/*************************************************************************************
  setup
**************************************************************************************/
void setup()
{
  nh.initNode();                            //init ROS node
  nh.getHardware()->setBaud(115200);         //set baud for ROS serial communication
  nh.subscribe(cmd_vel);                    //suscribe to ROS topic for velocity commands
  nh.advertise(speed_pub);                  //prepare to publish speed in ROS topic
  nh.advertise(encoder_pub);
  nh.advertise(pwm_output_pub);
  nh.advertise(imu_pub);
  
     nh.advertise(pub_button);
     nh.advertise(pub_sonar_m);
  //nh.advertise(range_pub);
  broadcaster.init(nh);
  /**************************************************************
    Exit & ultra
    *******************************************************************/
    ultrasonic_m.setTimeout(40000UL);

        
     pinMode(led_pin, OUTPUT);
     pinMode(button_pin, INPUT);
     
     //Enable the pullup resistor on the button
     digitalWrite(button_pin, HIGH);
     
     //The button is a normally button
    // last_reading = ! digitalRead(button_pin);
   
  /**************************************************************************************
    BNo055 testing
  ***************************************************************************************/
 while (!bno.begin())
  {
    nh.loginfo("No BNO055 detected");
  }
  /**************************************************************************************
    encoders and motors initilization
  **************************************************************************************/
  pinMode (pwm_rig, OUTPUT);
  pinMode (dir_rig, OUTPUT);
  pinMode (pwm_lef, OUTPUT);
  pinMode (dir_lef, OUTPUT);

  //pinMode(trigPin, OUTPUT);
 // pinMode(echoPin, INPUT);

  pinMode(interruptPin_rais_a_rig, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_rais_a_rig), rais_a_rig, RISING);
  pinMode(interruptPin_fal_a_rig, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_fal_a_rig), fall_a_rig, FALLING);
  pinMode(interruptPin_rais_b_rig, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_rais_b_rig), rais_b_rig, RISING);
  pinMode(interruptPin_fal_b_rig, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_fal_b_rig), fall_b_rig, FALLING);

  pinMode(interruptPin_rais_a_lef, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_rais_a_lef), rais_a_lef, RISING);
  pinMode(interruptPin_fal_a_lef, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_fal_a_lef), fall_a_lef, FALLING);
  pinMode(interruptPin_rais_b_lef, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_rais_b_lef), rais_b_lef, RISING);
  pinMode(interruptPin_fal_b_lef, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_fal_b_lef), fall_b_lef, FALLING);
}
/**************************************************************************************
  Loop starts here
**************************************************************************************/
void loop()
{
  nh.spinOnce();
  if ((millis() - lastMilli) >= LOOPTIME)
  {
    lastMilli = millis();
    c_l = count_lef;
    c_r = count_rig;
    if (abs(count_lef) < 5) {                                                //Avoid taking in account small disturbances
      speed_act_left = 0;
    }
    else
    {
      speed_act_left = ((c_l / 2786) * 2 * (22 / 7) * radius) * (1000 / LOOPTIME); // calculate speed of left wheel             !!!! 990 encoder total pulse coun //384 //15260--dc motors
    }

    if (abs(count_rig) < 5) {                                               //Avoid taking in account small disturbances
      speed_act_right = 0;
    }
    else {
      speed_act_right = ((c_r / 2786) * 2 * (22 / 7) * radius) * (1000 / LOOPTIME); // calculate speed of right wheel          !!!! 990 encoder total pulse coun
    }

    encoder_left = encoder_left + count_lef;
    encoder_right = encoder_right + count_rig;

    //        if(encoder_left>32000) encoder_left = 0;
    //       if(encoder_right>32000) encoder_right = 0;

    count_lef = 0;
    count_rig = 0;

    speed_cmd_left = constrain(speed_cmd_left, -max_speed, max_speed);
    PID_leftMotor.Compute();                                                 // compute PWM value for left motor
    PWM_leftMotor = constrain(((speed_req_left + sgn(speed_req_left) * min_speed_cmd) / speed_pwm) + (speed_cmd_left / speed_pwm), -255, 255);

    if (noCommLoops >= noCommLoopMax)
    { //Stopping if too much time without command
      analogWrite(pwm_lef, 0);
    }
    else if (speed_req_left == 0) {                      //Stopping
      analogWrite(pwm_lef, 0);
    }
    else if (PWM_leftMotor > 0) {                         //Going forward
      analogWrite(pwm_lef, PWM_leftMotor);
      digitalWrite(dir_lef, HIGH);
    }
    else {                                               //Going backward
      analogWrite(pwm_lef, abs(PWM_leftMotor));
      digitalWrite(dir_lef, LOW);
    }

    speed_cmd_right = constrain(speed_cmd_right, -max_speed, max_speed);
    PID_rightMotor.Compute();                                                 // compute PWM value for right motor
    PWM_rightMotor = constrain(((speed_req_right + sgn(speed_req_right) * min_speed_cmd) / speed_pwm) + (speed_cmd_right / speed_pwm) , -255, 255);

    if (noCommLoops >= noCommLoopMax) {                   //Stopping if too much time without command
      analogWrite(pwm_rig, 0);
    }
    else if (speed_req_right == 0) {                      //Stopping
      analogWrite(pwm_rig, 0);
    }
    else if (PWM_rightMotor > 0) {                        //Going forward
      analogWrite(pwm_rig, PWM_rightMotor);
      digitalWrite(dir_rig, HIGH);
    }
    else {                                                //Going backward
      analogWrite(pwm_rig, abs(PWM_rightMotor));
      digitalWrite(dir_rig, LOW);
    }

    noCommLoops++;
    if (noCommLoops == 65535) {
      noCommLoops = noCommLoopMax;
    }
    updateimu();
    //updateultra();
    publishSpeed(); 
       updateexit();
   updateultra();
  }
}
/**************************************************************************************
  publish Odometry
**************************************************************************************/
void publishSpeed()
{
  speed_msg.header.stamp = nh.now();      //timestamp for odometry data
  speed_msg.vector.x = speed_act_left;    //left wheel speed (in m/s)
  speed_msg.vector.y = speed_act_right;   //right wheel speed (in m/s)
  speed_msg.vector.z = 0.1;//0.2;   //looptime, should be the same as specified in LOOPTIME (in s)
  speed_pub.publish(&speed_msg);


  encoder_msg.x = millis();
  encoder_msg.y = encoder_right;
  encoder_pub.publish( &encoder_msg);

  pwm_output_msg.x = PWM_leftMotor;
  pwm_output_msg.y = PWM_rightMotor;
  pwm_output_pub.publish(&pwm_output_msg);

  imu_pub.publish(&imu_msg);
  //  range_pub.publish(&range_msg);


  //t.header.stamp = nh.now();
  // broadcaster.sendTransform(t);

  nh.spinOnce();
  nh.loginfo("Publishing odometry");
}
/**************************************************************************************
  update imu
**************************************************************************************/
void updateimu()
{
  nh.spinOnce();
  imu::Quaternion quat = bno.getQuat();
  sensors_event_t orientationData , angVelocityData , linearAccelData, magnetometerData, accelerometerData, gravityData;
  bno.getEvent(&angVelocityData, Adafruit_BNO055::VECTOR_GYROSCOPE);
  //bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);
  bno.getEvent(&accelerometerData, Adafruit_BNO055::VECTOR_ACCELEROMETER);
  imu_msg.header.stamp = nh.now();
  imu_msg.header.frame_id = "imu";
  imu_msg.orientation.x = quat.x();
  imu_msg.orientation.y = quat.y();
  imu_msg.orientation.z = quat.z();
  imu_msg.orientation.w = quat.w();
  imu_msg.angular_velocity.x = angVelocityData.gyro.x;
  imu_msg.angular_velocity.y = angVelocityData.gyro.y;
  imu_msg.angular_velocity.z = angVelocityData.gyro.z;
  imu_msg.linear_acceleration.x = accelerometerData.acceleration.x;
  imu_msg.linear_acceleration.y = accelerometerData.acceleration.y;
  imu_msg.linear_acceleration.z = accelerometerData.acceleration.z;

  l.header.frame_id = base_link;
  l.child_frame_id = imu_frame;
  // l.header.frame_id = imu_frame;
  l.transform.rotation.x = 0;
  l.transform.rotation.y = 0;
  l.transform.rotation.z = 0;
  l.transform.rotation.w = 1.0;
  l.header.stamp = nh.now();
  // if ((millis() - lm) >= 1000)
  { lm = millis();
    broadcaster.sendTransform(l);
  }

}
void updateexit()
{
   bool reading = digitalRead(button_pin);
   if(reading ==0){
          
     if ( (millis() - last_debounce_time)  > debounce_delay) {
  
      nh.loginfo("0");
            last_debounce_time=millis();
            pushed_msg.data = reading;
            pub_button.publish(&pushed_msg);
     }
     }
     
//     if(reading ==1)
//     {
//       // nh.loginfo("1");
//     }    
     
}
/**************************************************************************************
ULTRASONIC
**************************************************************************************/
void updateultra()
{
  //nh.spinOnce();
  

if(ultrasonic_m.read()<40)
{
  u_m=ultrasonic_m.read();
   ultracount=0;
  if ((millis() - ultra_last_debounce_time)  > ultra_debounce_delay) {
      ultra_last_debounce_time = millis();

       sonar_msg_m.range = u_m;     
    pub_sonar_m.publish(&sonar_msg_m);
     nh.loginfo("ultrasonic");
  }  
}
 else
 {
  ultracount=1;
 }
// t.header.frame_id =base_link;
// t.child_frame_id = ultra_frame;
// t.transform.translation.x=0.2;
// t.transform.translation.y=0;
// t.transform.translation.z=0.055;
// t.transform.rotation.x =0;
// t.transform.rotation.y =0;
// t.transform.rotation.z =0;
// t.transform.rotation.w = 1.0;
// t.header.stamp = nh.now();
// broadcaster.sendTransform(t);
}
/**************************************************************************************************************
  ENCODER CALCULATIONS
**************************************************************************************/
void rais_a_rig() {                                                                                                                         //interrupt right functions
  en_a_state_rig = HIGH;
  calculataion_rig();
}
void fall_a_rig() {
  en_a_state_rig = LOW;
  calculataion_rig();
}
void rais_b_rig() {
  en_b_state_rig = HIGH;
  calculataion_rig();
}
void fall_b_rig() {

  en_b_state_rig = LOW;
  calculataion_rig();
}
void calculataion_rig()                                                                                                                   //interrupt right calculations
{
  if (en_a_state_rig != en_a_las_state_rig)
  {
    if (en_b_state_rig == en_a_state_rig)
    {
      count_rig --;
    }
    else
    {
      count_rig ++;
    }
  }
  else if (en_a_state_rig == en_a_las_state_rig)
  {

    if (en_b_state_rig != en_b_las_state_rig)
    {
      if (en_b_state_rig != en_a_state_rig)
      {
        count_rig --;
      }
      else
      {
        count_rig ++;
      }
    }
  }
  en_a_las_state_rig = en_a_state_rig;
  en_b_las_state_rig = en_b_state_rig;
}

void rais_a_lef() {                                                                                                             //interrupt left functions
  en_a_state_lef = HIGH;
  calculataion_lef();
}
void fall_a_lef() {

  en_a_state_lef = LOW;
  calculataion_lef();
}
void rais_b_lef() {
  en_b_state_lef = HIGH;
  calculataion_lef();
}
void fall_b_lef() {

  en_b_state_lef = LOW;
  calculataion_lef();
}
void calculataion_lef()                                                                                                                                //interrupt right claculations
{
  if (en_a_state_lef != en_a_las_state_lef)
  {
    if (en_b_state_lef == en_a_state_lef)
    {
      if (en_b_state_lef == en_a_state_lef)
        count_lef ++;
    }
    else
    {
      count_lef --;
    }

  }
  else if (en_a_state_lef == en_a_las_state_lef)
  {

    if (en_b_state_lef != en_b_las_state_lef)
    {
      if (en_b_state_lef != en_a_state_lef)
      {
        count_lef ++;
      }
      else
      {
        count_lef --;
      }
    }
  }
  en_a_las_state_lef = en_a_state_lef;
  en_b_las_state_lef = en_b_state_lef;
}

/***stop****/
void dc_stop()
{ Serial.println("stoped");
  analogWrite(pwm_rig, 0); //70
  analogWrite(pwm_lef, 0);
  digitalWrite(dir_rig, LOW); ///right wheel low for straight
  digitalWrite(dir_lef, HIGH);
}

template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
