// CU Boulder Robotics Club 
// Arduino Quad Copter Code
// Written by Josh Bowen
// 7-27-14

/* Notes about use
1186 Microseconds is lowest value to turn on
1100 Microseconds is fastest stop command
1700 Microseconds is highest speed

*/

#include <Servo.h>

#define DEBUG_NONE 0
#define DEBUG_STATUS 1
#define DEBUG_ALL 2

#define DEBUG DEBUG_ALL
#define UPDATE_RATE 50 //20Hz Update Rate

#define THROTTLE_MIN 0 //FIXME - need to find out what minimum throttle value is

Servo motor1; //Instance of Servo

int motor_one_out = 3;
int pwm = 0; //Initialize PWM output to 0% Duty Cycle
int n; //Variable for Serial Input
String readString;

void setup()
{ 
#if DEBUG > DEBUG_NONE
  Serial.begin(115200);
  Serial.println("Initializing...");
#endif
  
motor1.attach(motor_one_out); //Connect motor to PWM pin
pinMode(motor_one_out, OUTPUT);

//arm_esc();

}

void loop()
{
  // Take in Sensor Data
  update_sensors();
  
#if DEBUG >= DEBUG_STATUS
  keyboard_input();
#endif

  // Control motors based on sensor data
  update_motors();
  
  delay(UPDATE_RATE);
 
}

void update_sensors()
{
  // Accelerometer
  // Barometer
  // Gyro
  // Range Sensor
}

void update_motors()
{
  // Case statement to control motors based on sensor data
  // 0 is 0% duty Cycle, 64 is 25%, 127 is 50%, 191 is 75%, 255 is 100%
#if DEBUG >= DEBUG_STATUS
  Serial.print("Sending PWM to Motor: ");
  Serial.println(n);
#endif

  motor1.writeMicroseconds(n);  
}

/*
void arm_esc()
{
  motor1.writeMicroseconds(THROTTLE_MIN);
  delay(3000);
}
*/

void applyBrake()
{
  n = 1100; //Value that controls motor during update_motors()
  motor1.writeMicroseconds(1100);
}

char buf[128];
void keyboard_input()
{
  delay(10);  
  if (Serial.available() <= 0) 
    return;

  int incomingByte, num_arg = 0, arg_val;
  incomingByte = Serial.read();  //gets one byte from serial buffer
  
  switch(incomingByte)
  {
    case 'T':
    case 't':
              delay(1);
              while(Serial.available() )
              {
                buf[num_arg++] = Serial.read();
                delay(1);
              }
              buf[num_arg++] = '\0';
              arg_val = atoi(buf);
              
              Serial.print("Setting PWM = ");
              Serial.println(arg_val);
              
              if (arg_val >= 1186 && arg_val <= 1700)
                n = arg_val;
              break;
              
   case 'b':
   case 'B':
             applyBrake();
             break;
             
   default:
     break;
  }
}

