#include <Servo.h> // include library

Servo servo1; // create object
const int flexpin = 0; // define flex pin analog pin

void setup()
{
  Serial.begin(9600);
  servo1.attach(9); // enable control of servo on pin 9
}

void loop()
{
  int flexposition; // input value from the analog pin
  int servoposition; // output value from the servo
  
  flexposition = analogRead(flexpin); // read position of the flex sensor (0-1023 for anaolgRead always)
  servoposition = map(flexposition, 700, 850, 0, 180); // flex sensor generally only returns 600-900 value from analogRead - we are mapping that to 0-180 range of servo
  servoposition = constrain(servoposition, 0, 180); //ensures that if any values come in outside 0-180 they are clipped
  
  servo1.write(servoposition); // command servo to move to position
  
  Serial.print("sensor: ");
  Serial.print(flexposition);
  Serial.print("  servo: ");
  Serial.println(servoposition); // ln puts everything on the same line and then creates new line
  
  delay(20);
}
  
  

