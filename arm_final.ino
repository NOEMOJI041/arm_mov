


/* Include the HCPCA9685 library */
#include "HCPCA9685.h"

/* I2C slave address for the device/module. For the HCMODU0097 the default I2C address
   is 0x40 */
#define  I2CAdd 0x40

#define shoulder 0
#define elbow 1
#define gripper 2
#define seeder 3
#define closed 100
#define opened 270
#define acopen 430


/* Create an instance of the library */
HCPCA9685 HCPCA9685(I2CAdd);


void setup() 
{
  /* Initialise the library and set it to 'servo mode' */ 
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);
  
  HCPCA9685.Servo(shoulder, 200);
  HCPCA9685.Servo(elbow, 250);
  HCPCA9685.Servo(gripper, closed);
}

int mov(int servo,int start, int angle, float step_size){    
  for(int i=start; i < angle; i+= step_size){
    HCPCA9685.Servo(servo, i);
    delay(100);
  }
}

int back(int servo, int start, int angle, float step_size){
  for(int i=start; i > angle; i-= step_size){
    HCPCA9685.Servo(servo,i);
    delay(100);
  }
  
}
void loop() 
{
  
  HCPCA9685.Servo(3, acopen);
  delay(2000);
  HCPCA9685.Servo(3, 0);
  delay(3000);
  mov (0,200, 400, 5);
  back (1, 230, 50, 5);
  HCPCA9685.Servo(gripper, opened);
  back (0, 400, 150 ,5);
  HCPCA9685.Servo(gripper, closed);
  mov (0, 150, 400, 5);
  mov (1, 50, 230,5);  
  HCPCA9685.Servo(gripper, opened);
  delay(500);
  HCPCA9685.Servo(gripper, closed);
  delay(5000);
 

  

  
  

}
