#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver srituhobby = Adafruit_PWMServoDriver();

// #define servoMIN 150
// #define servoMAX 600

void setup()
{
    
    srituhobby.setPWM(0, 0, 400);
    srituhobby.setPWM(1, 0, 400);
    srituhobby.setPWM(2, 0, 200);
    srituhobby.setPWM(4, 0, 5);
    Serial.begin(9600);
    srituhobby.begin();
    srituhobby.setPWMFreq(60);
}
int mov(int servo, int start, int stop1)
{
    servo = servo;
    start = start;
    stop1 = stop1;
    
  srituhobby.setPWM(servo, 0, start);
  Serial.println(servo);
  delay(50);
  for(int i=start;i<stop1;i+=5){
      srituhobby.setPWM(servo, 0, i);
      Serial.println(servo);
      delay(50);
      
   
}
}
void loop(){
  mov (1, 300, 600);
  mov (2, 150, 200);
  mov (4, 90, 500);
}
