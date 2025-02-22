                                                                 //HEADER FILES//
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
#include <utility/imumaths.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/Bool.h>
#include <Ultrasonic.h>
#include <LedControl.h>
                                                              //PINS DECLERATION//
#define dir_rig 8
#define pwm_rig 6
#define dir_lef 9
#define pwm_lef 7

#define INTERRUPT_PIN_RAIS_A_RIG 31
#define INTERRUPT_PIN_RAIS_B_RIG 35
#define INTERRUPT_PIN_RAIS_A_LEF 22
#define INTERRUPT_PIN_RAIS_B_LEF 24

#define TRIG 11
#define ECHO 12

#define button_pin 5

#define led_pin 13

#define DIN 2
#define CS  3
#define CLK 4
LedControl lc = LedControl(DIN, CLK, CS, 8);
unsigned long currentTime;
unsigned long lastUpdateTime = 0;
const long eyesDelay         = 500;
const long emptyDelay        = 500;
byte eyesPatterns[8][8]      = {
  {0x00, 0x00, 0xC0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC},
  {0x00, 0x00, 0x03, 0x0F, 0x1F, 0x1F, 0x33, 0x31},
  {0x00, 0x00, 0xC0, 0xF0, 0xF8, 0xF8, 0xCC, 0x8C},
  {0x00, 0x00, 0x03, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F},
  {0x00, 0x00, 0xC0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC},
  {0x00, 0x00, 0x03, 0x0F, 0x1F, 0x1F, 0x33, 0x39},
  {0x00, 0x00, 0xC0, 0xF0, 0xF8, 0xF8, 0xCC, 0x9C},
  {0x00, 0x00, 0x03, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F}
};

byte emptyPattern[8]         = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

                                                              //VARIABLE DECLERATIONS//
#define LOOPTIME 100                                                      // Looptime in milliseconds
const byte noCommLoopMax = 10;                                           // Max loops without communication before stopping
unsigned int noCommLoops = 0;                                           // Counter for loops without communication
Adafruit_BNO055 bno      = Adafruit_BNO055(55, 0x28);


bool last_reading;
long last_debounce_time = 0;
long debounce_delay     = 6000;
bool published          = true;

Ultrasonic ultrasonic_m(TRIG, ECHO);  
long ultra_last_debounce_time = 0;
long ultra_debounce_delay     = 60000;
int duration;
int distance;
int ultracount;
int u_m;

volatile byte state = LOW;
signed long int count_rig = 0, count_lef = 0;
int en_a_state_rig = 0, en_b_state_rig = 0, en_a_las_state_rig = 0, en_b_las_state_rig = 0;
int en_a_state_lef = 0, en_b_state_lef = 0, en_a_las_state_lef = 0, en_b_las_state_lef = 0;

long encoder_left  = 0;
long encoder_right = 0;

const double speed_pwm     = 0.00148;                                                 // DC motors
const double min_speed_cmd = 0.02962;                                                // 100 RPM
unsigned long lastMilli = 0, lm = 0;
const double radius     = 0.0625;                                                  // Wheel radius in meters
const double wheelbase  = 0.32;                                                   // Wheelbase in meters

double c_r = 0, c_l = 0;

double speed_req = 0;                                                          // Desired linear speed for the robot in m/s
double angular_speed_req = 0;                                                 // Desired angular speed in rad/s

double speed_req_left = 0;                                                  // Desired speed for left wheel in m/s
double speed_act_left = 0;                                                 // Actual speed for left wheel in m/s
double speed_cmd_left = 0;                                                // Commanded speed for left wheel in m/s

double speed_req_right = 0;                                              // Desired speed for right wheel in m/s
double speed_act_right = 0;                                             // Actual speed for right wheel in m/s
double speed_cmd_right = 0;                                            // Commanded speed for right wheel in m/s

const double max_speed = 0.03599;                                    // Max speed in m/s

                                                                   //Initialize PWM values to zero
int PWM_leftMotor = 0;
int PWM_rightMotor = 0;
int d = 0;

const double PID_left_param[] = {0.24, 0, 1};                  // Kp, Ki, Kd for left motor PID
const double PID_right_param[] = {0.24, 0, 1};                // Kp, Ki, Kd for right motor PID
PID PID_leftMotor(&speed_act_left, &speed_cmd_left, &speed_req_left,
                  PID_left_param[0], PID_left_param[1], PID_left_param[2], DIRECT);
PID PID_rightMotor(&speed_act_right, &speed_cmd_right, &speed_req_right,
                   PID_right_param[0], PID_right_param[1], PID_right_param[2], DIRECT);

ros::NodeHandle nh;

                                     /**************************************************************************************
                                                                         Function to Handle cmd_vel
                                      **************************************************************************************/
void handle_cmd(const geometry_msgs::Twist& cmd_vel) {
  noCommLoops = 0;                                                                                    // Reset the counter for number of loops without communication

  speed_req = cmd_vel.linear.x;                                                                       // Extract the commanded linear speed
  angular_speed_req = cmd_vel.angular.z;                                                              // Extract the commanded angular speed

  speed_req_left = speed_req - angular_speed_req * (wheelbase / 2);                                   // Calculate left motor speed
  speed_req_right = speed_req + angular_speed_req * (wheelbase / 2);                                  // Calculate right motor speed
}
                                                                                                      //Declaration of PUB & SUB Message Types 
geometry_msgs::Pose2D pwm_output_msg;
geometry_msgs::Pose2D encoder_msg;
geometry_msgs::Vector3Stamped speed_msg;
sensor_msgs::Imu imu_msg;
sensor_msgs::Range sonar_msg_m;                                                                       // Ultrasonic
std_msgs::Bool pushed_msg;
geometry_msgs::TransformStamped t;
geometry_msgs::TransformStamped l;
tf::TransformBroadcaster broadcaster;
char base_link[] = "/base_link";
char imu_frame[] = "/imu";
char ultra_frame[] = "/ultrasonic";

ros::Publisher pub_sonar_m("rangeSonar", &sonar_msg_m);
ros::Publisher pub_button("pushed", &pushed_msg);
ros::Publisher imu_pub("imu_data", &imu_msg);
ros::Subscriber<geometry_msgs::Twist> cmd_vel("cmd_vel", handle_cmd);
ros::Publisher speed_pub("speed", &speed_msg);
ros::Publisher pwm_output_pub("pwm_output", &pwm_output_msg);
ros::Publisher encoder_pub("encoder", &encoder_msg);


                        /************************************************************************************************
                                                                  SETUP FUNCTION
                        ************************************************************************************************/
void setup()
{
  for (int i = 0; i < 8; i++)
  {
    lc.shutdown(i, false);
    lc.setIntensity(i, 5);
    lc.clearDisplay(i);
  }
                                                                                                      // Initialize ROS node
  nh.initNode();

                                                                                                      // Set baud rate for ROS serial communication
  nh.getHardware()->setBaud(115200);

                                                                                                      // Subscribe to ROS topic for velocity commands
  nh.subscribe(cmd_vel);

                                                                                                      // Prepare to publish speed in ROS topics
  nh.advertise(speed_pub);
  nh.advertise(encoder_pub);
  nh.advertise(pwm_output_pub);
  nh.advertise(imu_pub);
  nh.advertise(pub_button);
  nh.advertise(pub_sonar_m);

                                                                                                      // Initialize broadcaster for ROS
  broadcaster.init(nh);
  ultrasonic_m.setTimeout(40000UL);

                                                                                                      // Configure pins for LEDs and button
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);

                                                                                                      // Enable the pull-up resistor on the button
  digitalWrite(button_pin, HIGH);
  while (!bno.begin())
  {
    nh.loginfo("No BNO055 detected");
  }
                                                                                                      // Set up motor control pins
  pinMode(pwm_rig, OUTPUT);
  pinMode(dir_rig, OUTPUT);
  pinMode(pwm_lef, OUTPUT);
  pinMode(dir_lef, OUTPUT);


                                                                                                     // Set up interrupt pins for right motor encoders
  pinMode(INTERRUPT_PIN_RAIS_A_RIG, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN_RAIS_A_RIG), rais_a_rig, CHANGE);              // Change Interrupt state to RISING to CHANGE State


  pinMode(INTERRUPT_PIN_RAIS_B_RIG, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN_RAIS_B_RIG), rais_b_rig, CHANGE);              // Change Interrupt state to RISING to CHANGE State


                                                           // Set up interrupt pins for left motor encoders
  pinMode(INTERRUPT_PIN_RAIS_A_LEF, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN_RAIS_A_LEF), rais_a_lef, CHANGE);              // Change Interrupt state to RISING to CHANGE State

  pinMode(INTERRUPT_PIN_RAIS_B_LEF, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN_RAIS_B_LEF), rais_b_lef, CHANGE);              // Change Interrupt state to RISING to CHANGE State
}

                      /************************************************************************************************
                                                              LOOP FUNCTION
                      ************************************************************************************************/
void loop()
{
  currentTime = millis();

                                                                   // Determine if we should show the eyes or empty pattern
  if (currentTime - lastUpdateTime >= eyesDelay && (currentTime - lastUpdateTime) < (eyesDelay + emptyDelay)) {
    showEyes();
  } else if (currentTime - lastUpdateTime >= (eyesDelay + emptyDelay)) {
    showEmpty();
    lastUpdateTime = currentTime;                                 // Reset lastUpdateTime after displaying empty state
  }
  nh.spinOnce();

  if ((millis() - lastMilli) >= LOOPTIME) {
    lastMilli = millis();

                                                                 // Read and calculate speeds
    c_l = count_lef;
    c_r = count_rig;

    if (abs(count_lef) < 5) {
      speed_act_left = 0;                                       // Ignore minor disturbances
    } else {
      speed_act_left = ((c_l / 2800.0) * 2 * (22 / 7.0) * radius) * (1000.0 / LOOPTIME); // Change the tick value 2786 to 2800
    }

    if (abs(count_rig) < 5) {
      speed_act_right = 0;                                      // Ignore minor disturbances
    } else {
      speed_act_right = ((c_r / 2800.0) * 2 * (22 / 7.0) * radius) * (1000.0 / LOOPTIME); // Change the tick value 2786 to 2800
    }

    encoder_left += count_lef;
    encoder_right += count_rig;

                                                                // Reset encoder counts
    count_lef = 0;
    count_rig = 0;

                                                                // Left Motor Control
    speed_cmd_left = constrain(speed_cmd_left, -max_speed, max_speed);
    PID_leftMotor.Compute();                                    // Compute PWM for left motor
    PWM_leftMotor = constrain(
                      ((speed_req_left + sgn(speed_req_left) * min_speed_cmd) / speed_pwm) +
                      (speed_cmd_left / speed_pwm),
                      -255, 255
                    );

    if (noCommLoops >= noCommLoopMax) {
      analogWrite(pwm_lef, 0);                                  // Stop motor if communication timeout
    } else if (speed_req_left == 0) {
      analogWrite(pwm_lef, 0);                                  // Stop motor if no speed request
    } else if (PWM_leftMotor > 0) {
      analogWrite(pwm_lef, PWM_leftMotor);                      // Move forward
      digitalWrite(dir_lef, HIGH);
    } else {
      analogWrite(pwm_lef, abs(PWM_leftMotor));                 // Move backward
      digitalWrite(dir_lef, LOW);
    }

                                                                // Right Motor Control
    speed_cmd_right = constrain(speed_cmd_right, -max_speed, max_speed);
    PID_rightMotor.Compute();                                   // Compute PWM for right motor
    PWM_rightMotor = constrain(
                       ((speed_req_right + sgn(speed_req_right) * min_speed_cmd) / speed_pwm) +
                       (speed_cmd_right / speed_pwm),
                       -255, 255
                     );

    if (noCommLoops >= noCommLoopMax) {
      analogWrite(pwm_rig, 0);                                  // Stop motor if communication timeout
    } else if (speed_req_right == 0) {
      analogWrite(pwm_rig, 0);                                  // Stop motor if no speed request
    } else if (PWM_rightMotor > 0) {
      analogWrite(pwm_rig, PWM_rightMotor);                     // Move forward
      digitalWrite(dir_rig, HIGH);
    } else {
      analogWrite(pwm_rig, abs(PWM_rightMotor));                // Move backward
      digitalWrite(dir_rig, LOW);
    }

                                                                // Increment communication loops counter
    noCommLoops++;
    if (noCommLoops == 65535) {
      noCommLoops = noCommLoopMax;                              // Prevent overflow
    }

                                                                // Sensor updates and data publishing
    updateimu();
    publishSpeed();
    updateexit();
    updateultra();
  }
}

                      /********************************************************************************************
                                                        Publish speed function
                      *********************************************************************************************/
void publishSpeed() {
                                                               // Update speed message
  speed_msg.header.stamp = nh.now();                           // Timestamp for odometry data
  speed_msg.vector.x = speed_act_left;                         // Left wheel speed (m/s)
  speed_msg.vector.y = speed_act_right;                        // Right wheel speed (m/s)
  speed_msg.vector.z = 0.1;                                    // Loop time (should match LOOPTIME in seconds)
  speed_pub.publish(&speed_msg);

                                                               // Update encoder message
  encoder_msg.x = millis();                                    // Current timestamp in milliseconds
  encoder_msg.y = encoder_right;                               // Right wheel encoder count
  encoder_pub.publish(&encoder_msg);

                                                               // Update PWM output message
  pwm_output_msg.x = PWM_leftMotor;                            // PWM value for left motor
  pwm_output_msg.y = PWM_rightMotor;                           // PWM value for right motor
  pwm_output_pub.publish(&pwm_output_msg);

                                                               // Publish IMU data
  imu_pub.publish(&imu_msg);

                                                               // Trigger ROS communication
  nh.spinOnce();

                                                               // Optional log for debugging (can be disabled in production)
  nh.loginfo("Odometry data published");
}


                          /**************************************************************************************
                                                                update imu
                          **************************************************************************************/
void updateimu() {
  nh.spinOnce();
  imu::Quaternion quat = bno.getQuat();
  sensors_event_t orientationData , angVelocityData , linearAccelData, magnetometerData, accelerometerData, gravityData;
  bno.getEvent(&angVelocityData, Adafruit_BNO055::VECTOR_GYROSCOPE);
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
  l.transform.rotation.x = 0;
  l.transform.rotation.y = 0;
  l.transform.rotation.z = 0;
  l.transform.rotation.w = 1.0;
  l.header.stamp = nh.now();
  { lm = millis();
    broadcaster.sendTransform(l);
  }

}
                          /**************************************************************************************
                                                              Button Update
                          **************************************************************************************/
void updateexit()
{
  bool reading = digitalRead(button_pin);
  if (reading == 0 && (millis() - last_debounce_time) > debounce_delay) {                        // Using logical operator to optimize if condition
    last_debounce_time = millis();
    pushed_msg.data = reading;
    pub_button.publish(&pushed_msg);
    nh.loginfo("0");
  }
}

                          /**************************************************************************************
                                                        Ultrasonic Sensor Update
                          **************************************************************************************/
void updateultra()
{
                                                                                                 // Read ultrasonic distance
  u_m = ultrasonic_m.read();                                                                     // optimize u_m data from multiple initializtion and update in if condition

                                                                                                 // Check if the distance is less than 200
  if (u_m < 200) {
    ultracount = 0;
    if ((millis() - ultra_last_debounce_time) > ultra_debounce_delay) {
      ultra_last_debounce_time = millis();
      sonar_msg_m.range = u_m;
      pub_sonar_m.publish(&sonar_msg_m);
      nh.loginfo("ultrasonic");
    }
  } else {
    ultracount = 1;
  }
}

                                 /**************************************************************************************
                                                        Encoder Calculations for Right Motor
                                 **************************************************************************************/
void rais_a_rig(){
  en_a_state_rig = digitalRead(INTERRUPT_PIN_RAIS_A_RIG);                                           // use digitalRead to read sensor value
  calculataion_rig();
}

void rais_b_rig() {
  en_b_state_rig = digitalRead(INTERRUPT_PIN_RAIS_B_RIG);                                           // use digitalRead to read sensor value
  calculataion_rig();
}

void calculataion_rig() {                                                                           // create a function using comparision operator
  if (en_a_state_rig != en_a_las_state_rig) {
    count_rig += (en_b_state_rig == en_a_state_rig) ? -1 : 1;
  } else if (en_a_state_rig == en_a_las_state_rig) {
    if (en_b_state_rig != en_b_las_state_rig) {
      count_rig += (en_b_state_rig != en_a_state_rig) ? -1 : 1;                                     // implace of using unary opertor use binary operator
    }
  }
  en_a_las_state_rig = en_a_state_rig;
  en_b_las_state_rig = en_b_state_rig;
}

                                 /**************************************************************************************
                                                    Encoder Calculations for Left Motor
                                  **************************************************************************************/
void rais_a_lef() {
  en_a_state_lef = digitalRead(INTERRUPT_PIN_RAIS_A_LEF);                                         // use digitRead to reading encoder value to high
  calculataion_lef();
}

void rais_b_lef() {
  en_b_state_lef = digitalRead(INTERRUPT_PIN_RAIS_B_LEF);                                         // use digitRead to reading encoder value to high
  calculataion_lef();
}

void calculataion_lef() {                                                                          // create a function using comparision operator
  if (en_a_state_lef != en_a_las_state_lef) {
    count_lef += (en_b_state_lef == en_a_state_lef) ? 1 : -1;
  } else if (en_a_state_lef == en_a_las_state_lef) {
    if (en_b_state_lef != en_b_las_state_lef) {
      count_lef += (en_b_state_lef != en_a_state_lef) ? 1 : -1;                                    // implace of using unary opertor use binary operator
    }
  }
  en_a_las_state_lef = en_a_state_lef;
  en_b_las_state_lef = en_b_state_lef;
}

                                      /**************************************************************************************
                                                                             Stop Motors
                                      **************************************************************************************/
void dc_stop() {
  Serial.println("stopped");
  analogWrite(pwm_rig, 0);
  analogWrite(pwm_lef, 0);
  digitalWrite(dir_rig, LOW);
  digitalWrite(dir_lef, HIGH);
}

                                     /**************************************************************************************
                                                                              Sign Function
                                      **************************************************************************************/
template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

                                     /**************************************************************************************
                                                                              Eyes Pattern Function
                                      **************************************************************************************/
void showEyes()
{
  for (int i = 0; i < 8; i++)
  {
    for (int row = 0; row < 8; row++)
    {
      lc.setRow(i, row, eyesPatterns[i][row]);
    }
  }
}

                                     /**************************************************************************************
                                                                              Eyes Blink Display Function
                                      **************************************************************************************/
void showEmpty()
{
  for (int i = 0; i < 8; i++)
  {
    for (int row = 0; row < 8; row++)
    {
      lc.setRow(i, row, emptyPattern[row]);
    }
  }
}
