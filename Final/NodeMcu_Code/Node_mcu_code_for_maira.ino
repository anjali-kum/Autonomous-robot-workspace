#include <ESP8266WiFi.h>
#include <Wire.h>
String i;
WiFiServer server(80);
void setup()
{
  i = "";
  Serial.begin(9600);
  Wire.begin(D1, D2);
  WiFi.disconnect();
  delay(3000);
  WiFi.begin("Vistan2", "12345678");
  Serial.println("connecting to wifi");
  while ((!(WiFi.status() == WL_CONNECTED))) {
    delay(300);
    Serial.print("*");
  }
  Serial.println("i am connected");
  Serial.println((WiFi.localIP().toString()));
  server.begin();
}

void loop()
{
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while (!client.available()) {
    delay(1);
  }
  i = (client.readStringUntil('\r'));
  i.remove(0, 5);
  i.remove(i.length() - 9, 9);
 

   if(i == "forward"){ 
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write('a'); /* sends hello string */
    Wire.endTransmission(); /* stop transmitting */
    
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("LED IS ON");
    client.println("</html>");
    Serial.println("FORWARD");
    delay(1);
  }
    if(i == "backward"){ 
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write('b'); /* sends hello string */
    Wire.endTransmission(); /* stop transmitting */
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("LED IS ON");
    client.println("</html>");
    Serial.println("Backeard");

    delay(1);
  }
  
  
 if(i == "right"){ 
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write('c'); /* sends hello string */
    Wire.endTransmission(); /* stop transmitting */
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("LED IS ON");
    client.println("</html>");
    Serial.println("rigt");

    delay(1);
  }
    
  if(i == "left") {
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write('d'); /* sends hello string */
    Wire.endTransmission(); /* stop transmitting */
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("LED IS ON");
    client.println("</html>");
    Serial.println("left");

    delay(1);
  }
  
 if (i == "stop"){
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write('e'); /* sends hello string */
    Wire.endTransmission(); /* stop transmitting */
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("LED IS ON");
    client.println("</html>");
    Serial.println("sTop");

    delay(1);
      }
  Wire.requestFrom(8, 13); /* request & read data of size 13 from slave */
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
  delay(1000);
}
