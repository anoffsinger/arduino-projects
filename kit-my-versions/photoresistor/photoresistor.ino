const int sensorPin = 0; //establishing constants for pins
const int ledPin = 9;
int lightLevel, high = 0, low = 1023; //establishing global varaibles for light level - 1023 equals "low" or 5 volts

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  lightLevel = analogRead(sensorPin); //anaolgRead returns values between 0 and 1023 only
  
  //lightlevel = map(lightLevel, 0, 1023, 0, 255); //map function takes one range and maps it to fit within another (i.e. from 0/1023-0/255)
  //lightLevel = constrain(lightLevel, 0, 255); //constrain function ensures that if any numbers come in outside of the from value range, number is clipped to either highest or lowest to value respectively
  
  //manualTune(); //calling function to manually change range from light to dark
  autoTune(); //arduino changes range from light to dark
  
  analogWrite(ledPin, lightLevel); //brighten led along with light level
}

void manualTune() //defining function that manually changes range from light to dark
{
  lightLevel = map(lightLevel, 500, 800, 0, 255); //by tightening the 0-1023 range here the sensor becomes more sensitive to light
  lightLevel = constrain(lightLevel, 0, 255);
}

void autoTune()
{
  if (lightLevel < low) // if lightlevel is less than 1023... 
  { 
    low = lightLevel;  // ...than lightlevel = 1023
  }
  
  if (lightLevel > high)
  {
    high = lightLevel;
  }
  
  lightLevel = map(lightLevel, low+30, high-30, 0, 255); //putting in slight offset of -/+ 30 to make sure light is either fully on or off
  lightLevel = constrain(lightLevel, 0, 255);
}
