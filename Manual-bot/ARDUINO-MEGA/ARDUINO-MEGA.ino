#include <Wire.h>
#include <ArduinoJson.h>
// Motor Driver Pins
#define DIR1 5
#define PWM1 6
#define DIR2 7
#define PWM2 8

// Ultrasonic Sensor Pins
#define TRIG 9
#define ECHO 10

char g;  // I2C received command
float distance; // Measured distance

void setup() {
  pinMode(DIR1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PWM2, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
  Wire.begin(8);                        // Join I2C bus with address 8
  Wire.onReceive(receiveEvent);         // Register receive event
  Wire.onRequest(requestEvent);         // Register request event
}
void loop() {
  distance = measureDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  // Obstacle detection should only apply to forward movement
if (g == 'a' && distance <= 60) {  
    dc_stop();
    Serial.println("Obstacle detected! Stopping forward movement.");
    g = 'e'; // Stop and wait for a new command
}


  // Execute movement based on command
  if (g == 'a') forward();
  else if (g == 'b') backward(); // Backward is NOT affected by obstacle detection
  else if (g == 'c') right();
  else if (g == 'd') left();
  else if (g == 'e') dc_stop();

  delay(100);
}

// Function to measure distance using Ultrasonic Sensor
float measureDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  float duration = pulseIn(ECHO, HIGH);
  return (duration * 0.0343) / 2; // Convert to cm
}

// Motor Control Functions (NO MODIFICATIONS)
void forward() {
  analogWrite(PWM1, 100);
  analogWrite(PWM2, 100);
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, LOW);//high
}
void backward() {
  analogWrite(PWM1, 100);
  analogWrite(PWM2, 100);
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, HIGH);//low
}
void left() {
  analogWrite(PWM1, 60);
  analogWrite(PWM2, 60);
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);//low
}
void right() {
  analogWrite(PWM1, 60);
  analogWrite(PWM2, 60);
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, LOW);
}
void dc_stop() {
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);
  Serial.print("Motor Stopped");
}

// I2C Communication
void receiveEvent(int howMany) {
  while (Wire.available()) {
    g = Wire.read();
  }
}
void requestEvent() {
  Wire.write(String(distance).c_str());  // Send distance to NodeMCU
}
