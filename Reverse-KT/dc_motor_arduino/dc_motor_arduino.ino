const int IntPin1 = 9;// interrupt1
const int IntPin2 = 10;// interrupt 2
const int enable = 11;// ena pin for speed control(PWM)

void setup(){
  pinMode(IntPin1,OUTPUT);
  pinMode(IntPin2,OUTPUT);
  pinMode(enable,OUTPUT);
  
  
}

void loop()
{
  analogWrite(enable,100);//speed is 100(pwm)
  digitalWrite(IntPin1,HIGH);
  digitalWrite(IntPin2,LOW);
  delay(2000);//motor running in clk wise

  analogWrite(enable,50);//speed 50
  digitalWrite(IntPin1,LOW);
  digitalWrite(IntPin2,HIGH);
  delay(2000);// motor running in anticlockwise direction

  analogWrite(enable,0);//stop motor
  delay(2000);
}
