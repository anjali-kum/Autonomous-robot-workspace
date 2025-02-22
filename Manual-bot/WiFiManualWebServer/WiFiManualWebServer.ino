#include <Wire.h>
#include <ESP8266WiFi.h>

WiFiServer server(80);
String command;
float distance;

void setup() {
  Serial.begin(9600);
  Wire.begin(D1, D2);

  WiFi.begin("Vistan1", "12345678");
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

  // Read client request
  String request = client.readStringUntil('\r');
  client.flush();
  Serial.println("HTTP Request: " + request);

  // Extract command from URL
  if (request.indexOf("GET /cmd?value=a") != -1) command = "forward";
  else if (request.indexOf("GET /cmd?value=b") != -1) command = "backward";
  else if (request.indexOf("GET /cmd?value=c") != -1) command = "right";
  else if (request.indexOf("GET /cmd?value=d") != -1) command = "left";
  else if (request.indexOf("GET /cmd?value=e") != -1) command = "stop";
  else command = "";

  // Get Distance from Arduino
  Wire.requestFrom(8, 6);
  String distanceStr = "";
  while (Wire.available()) distanceStr += (char)Wire.read();
  distance = distanceStr.toFloat();
  Serial.print("Distance: ");
  Serial.println(distance);

  // Obstacle Avoidance
  if (command == "forward" && distance <= 60) {
    command = "stop";
    Serial.println("Obstacle detected! Stopping.");
  }

  // Send Command to Arduino
  if (command != "") {
    Serial.println("Processing Command: " + command);
    char cmdChar = (command == "forward") ? 'a' :
                   (command == "backward") ? 'b' :
                   (command == "right") ? 'c' :
                   (command == "left") ? 'd' : 'e';

    Wire.beginTransmission(8);
    Wire.write(cmdChar);
    Wire.endTransmission();

    Serial.println("Sent Command: " + command);
  }

 client.println("<html><head><style>");
client.println("body { font-family: Arial, sans-serif; text-align: center; background-color: #f8f8f8; margin: 0; padding: 0; }");
client.println("h1 { font-size: 30px; color: #333; margin-top: 20px; }");

client.println("meta[name='viewport'] { content: 'width=device-width, initial-scale=1.0' }");  // Viewport for mobile responsiveness

client.println("#container { text-align: center; margin-top: 20px; }");

client.println("#company-box { background-color: #f2f2f2; border: 2px solid black; padding: 20px; width: 80%; box-sizing: border-box; margin: 20px auto; display: flex; flex-direction: column; align-items: center; justify-content: center; max-width: 600px; min-height: 30vh; height: auto; }"); 
// Added min-height of 30vh for responsiveness, ensuring the box adapts to mobile screen height

client.println("#company-box h2 { font-size: 30px; font-weight: bold; text-align: center; margin-bottom: 10px; }"); // Reduced margin-bottom
client.println("#company-box h3 { font-size: 16px; text-align: center; margin-top: 0px; font-family: 'Times New Roman', Times, serif; margin-bottom: 10px; }"); // Removed top margin and adjusted bottom margin

client.println("button { border-radius: 50%; width: 80px; height: 80px; font-weight: bold; margin: 4px; background-color: lightgreen; color: black; font-size: 14px; }");
client.println("button#stop { background: red; color: white; }");

// Mobile responsiveness - Adjust button sizes and layout
client.println("@media (max-width: 600px) {");
client.println("  button { width: 70px; height: 70px; font-size: 12px; }");
client.println("  #company-box h2 { font-size: 30px; margin-bottom: 5px; }");
client.println("  #company-box h3 { font-size: 10px; margin-bottom: 5px; }");
client.println("  #container { margin-top: 10px; }");
client.println("  #company-box { min-height: 25vh; }"); // Adjusted min-height for smaller screens
client.println("}");

client.println("</style></head><body>");

client.println("<h1>Robot Navigation</h1>");

// Company Box with Buttons
client.println("<div id='company-box'>");
client.println("<h2><span style='color:red;'>V</span><span style='color:black;'>I</span><span style='color:black;'>S</span><span style='color:red;'>T</span><span style='color:black;'>A</span><span style='color:black;'>N</span> <span style='color:blue;'>N</span><span style='color:black;'>EX</span><span style='color:green;'>T</span><span style='color:black;'>GEN</span></h2>");
client.println("<h3>#INCLUBATINGINVENTIONS</h3>");

// JavaScript for AJAX Commands
client.println("<script>");
client.println("function sendCommand(cmd) {");
client.println("  var xhr = new XMLHttpRequest();");
client.println("  xhr.open('GET', '/cmd?value=' + cmd, true);");
client.println("  xhr.send();");
client.println("}");
client.println("</script>");

// Buttons Inside Company Box
client.println("<div id='container'>");
client.println("<button onclick=\"sendCommand('a')\">FORWARD</button><br><br>");
client.println("<button onclick=\"sendCommand('d')\">LEFT</button>");
client.println("<button id='stop' onclick=\"sendCommand('e')\">STOP</button>");
client.println("<button onclick=\"sendCommand('c')\">RIGHT</button><br><br>");
client.println("<button onclick=\"sendCommand('b')\">BACKWARD</button>");
client.println("</div>");

client.println("</div>");  // Close company-box

client.println("</body></html>");


  delay(500);
}
