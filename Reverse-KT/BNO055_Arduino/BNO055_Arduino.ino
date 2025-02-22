#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

// Create an instance of the BNO055 sensor
Adafruit_BNO055 bno = Adafruit_BNO055();

void setup() {
  Serial.begin(9600);  
  Wire.begin();        

  if (!bno.begin()) {  
    Serial.println("Couldn't find the sensor!");
    while (1);
  }
  Serial.println("BNO055 sensor initialized.");
  delay(1000);  
}

void loop() {
  sensors_event_t event;
  
  bno.getEvent(&event);

  Serial.print("Roll: ");
  Serial.print(event.orientation.x);
  Serial.print("  Pitch: ");
  Serial.print(event.orientation.y);
  Serial.print("  Yaw: ");
  Serial.println(event.orientation.z);

  delay(500);  
}
