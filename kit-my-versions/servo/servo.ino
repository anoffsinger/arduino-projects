#include <Servo.h> //including the servo library

Servo servo1; //creating a servo object called servo1

void setup()
{
  servo1.attach(9); //attach tells arduino to begin sending control signals to the servo, which are constant
}

void loop()
{
  int position;
  
  servo1.write(90); //move to 90 degrees at full speed
  delay(1000); //pausing so servo has time to move
  servo1.write(180);
  delay(1000);
  servo1.write(0);
  delay(1000);
  
  for(position = 0; position < 180; position += 2) //stepping by 2 degrees
  {
    servo1.write(position); // move to next position
    delay(20); //short pause to allow to move, which also slows down overall servo rotation speed
  }
  
  for(position = 180; position > 0; position -= 1) //stepping by 1 degree
  {
    servo1.write(position);
    delay(20);
  }
}
