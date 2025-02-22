#include <ESP8266WiFi.h>
#include <Wire.h>

WiFiServer server(80);
String command;
float distance;

void setup() {
  Serial.begin(9600);
  Wire.begin(D1, D2);

  WiFi.begin("VistanJio2.4G", "T@v!0@1234");
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("\nConnected. IP Address: " + WiFi.localIP().toString());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;
  while (!client.available()) delay(1);

  command = client.readStringUntil('\r');
  command.remove(0, 5);
  command.remove(command.length() - 9, 9);

  // Get Distance from Arduino
  Wire.requestFrom(8, 6);
  String distanceStr = "";
  while (Wire.available()) distanceStr += (char)Wire.read();
  distance = distanceStr.toFloat();
  Serial.print("Distance: ");
  Serial.println(distance);

// If command is forward and distance ≤ 60 cm, stop and wait for a new command
if (command == "forward" && distance <= 60) {  
    command = "stop";
    Serial.println("Obstacle detected in front! Stopping.");
}


  // Send command to Arduino
  char cmdChar = (command == "forward") ? 'a' :
                 (command == "backward") ? 'b' :
                 (command == "right") ? 'c' :
                 (command == "left") ? 'd' : 'e';

  Wire.beginTransmission(8);
  Wire.write(cmdChar);
  Wire.endTransmission();

  // Respond to Client
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("Command: " + command);
  client.println("</html>");

  Serial.println("Sent Command: " + command);
  delay(500);
}
