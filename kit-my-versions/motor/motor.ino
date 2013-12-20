// with PWM values below 50, motor will not begin spinning

const int motorPin = 9; // setting pwm pin to control motor

void setup()
{
  pinMode(motorPin, OUTPUT); // pwm pin to output
  
  Serial.begin(9600); // initialize serial port
}

void loop()
{
  //motorOnThenOff();
  //motorOnThenOffWithSpeed();
  //motorAcceleration();
  serialSpeed();
}

// on and off like blinking light 

void motorOnThenOff()
{
  int onTime = 3000; // establishing and setting variable for milliseconds to turn motor on
  int offTime = 3000;
  
  digitalWrite(motorPin, HIGH); //turn motor speed on full speed
  delay(onTime);
  digitalWrite(motorPin, LOW);
  delay(offTime);
}

// alternates between 2 speeds
  
void motorOnThenOffWithSpeed()
{
  int Speed1 = 255; // 0 = stopped 255 = full speed
  int Time1 = 3000; // milliseconds for speed 1
  
  int Speed2 = 50; //turns motor off
  int Time2 = 3000;
  
  analogWrite(motorPin, Speed1); // writing motor pin with speed 1
  delay(Time1);
  analogWrite(motorPin, Speed2);
  delay(Time2);
}

// slowly accelerate to full speed, then back to zero

void motorAcceleration()
{
  int speed;
  int delayTime = 20; // to be used as milliseconds between each speed step
  
  // accelerate the motor
  
  for(speed = 0; speed <= 255; speed++)
  {
    analogWrite(motorPin, speed); //write the motor pin with the "speed" value as it cycles
    delay(delayTime);
  }
  
  // decelerate the motor
  
  for(speed = 255; speed >= 0; speed--)
  {
    analogWrite(motorPin, speed);
    delay(delayTime);
  }
}

void serialSpeed()
{
  int speed;
  
  Serial.println("Type a speed (0-255) into the box above,");
  Serial.println("then click [send] or press [return]");
  Serial.println(); // print blank line
  
  // in order to type out the above message in the serial port only once, rest of function will run infinitely
  
  while(true) // true is always true, so will loop forever
  {
    while (Serial.available() > 0) // check to see if incoming data is available
    {
      speed = Serial.parseInt(); // pull out number (parseInt) if it is available
      speed = constrain(speed, 0, 255); // analogWrite only works with 0-255, so we will constrain to that range
      
      Serial.print("Setting speed to "); // write the speed we are sending
      Serial.println(speed);
     
      analogWrite(motorPin, speed); // write to motor
    }
  }
}  
