#include <ArduinoJson.h>
#include <Wire.h>
void receiveEvent(int );

// GPIO mappings for Arduino Mega 2560

/*******************MDD10A Pins***********************/
#define DIR1 5
#define PWM1 6
#define DIR2 7
#define PWM2 8

/////Defining the speeds of motors   
int speed1= 150;   ////Speed for motor1

int speed2= 150;   ////Speed for motor2

  /***************************  I2C charecter ***************************/
char g;      ////I2c charecter variable

float a, b;   // Variables for speed


/*************************/
void setup() {


  /**********MDD10A parameters************/
  pinMode(DIR1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PWM2, OUTPUT);


 Serial.begin(9600);
}

 /*************************** loop declearing ***************************/

  void loop()
  {
    
    Wire.begin(8);                /* join i2c bus with address 8 */
    Wire.onReceive(receiveEvent); /* register receive event */
    Wire.onRequest(requestEvent); /* register request event */
    dc_stop();////Initial state


    /****************************For forward in node mcu*************************/
    while  (g == 'a')
    {         
      ////Forward moment
      forward();
      Serial.println("Forward");
        }

    /****************************For forward in node mcu*************************/
    while (g == 'b')
    {
        ////Backward moment
        backward();
        Serial.println("Backward");
      }

    /****************************For forward in node mcu*************************/
    while (g == 'c')
    {

        ////right moment
        right();
        Serial.println("right");
      }


      //************************left  *******************************************//
          while (g == 'd')
    {
        //left moment
        left();
        Serial.println("left");
      }


     
      //************************stop  *******************************************/

   while (g == 'e')
    {
        ////stop moment
        dc_stop();
        Serial.println("stop");
      }
      //************************stop  *******************************************/

  }
 /***************************  for motors forward direction ***************************/



 void forward()   //
  {
   analogWrite(PWM1, 150);
    analogWrite(PWM2, 150);
 
    digitalWrite(DIR1, LOW);
    digitalWrite(DIR2, HIGH);
  }

  /***************************  for motor backward direction ***************************/

  void backward()

{
   analogWrite(PWM1, 80);
    analogWrite(PWM2, 80);
 
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, LOW );
           
}

  /**********************Function to make the bot turn left************/
  void left()
  {
 analogWrite(PWM1, 60);
 analogWrite(PWM2, 60);
 digitalWrite(DIR1, HIGH);  //low
 digitalWrite(DIR2, HIGH); //high
  }


  /************* Function to make the bot Turn Right***************/
  void right()
  {
 analogWrite(PWM1, 60);
 analogWrite(PWM2, 60);
 digitalWrite(DIR1, LOW);  //low
 digitalWrite(DIR2, LOW); //high
  }

  
  /**************Function to Stop Suddenly****************/
  void dc_stop()
  {
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);
  }

  /*************************I2C Functions******************/
  // function that executes whenever data is received from master
  void receiveEvent(int howMany)
  {
    while (0 < Wire.available())
    {
      char c = Wire.read();
      g = c; /* receive byte as a character */
    }
  }

  // function that executes whenever data is requested from master
  void requestEvent() 
  {
    Wire.write("Hello NodeMCU");  /*send string on request */
  }
  
