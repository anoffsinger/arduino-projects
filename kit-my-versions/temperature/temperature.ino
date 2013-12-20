const int temperaturePin = 0;

void setup()
{
  Serial.begin(9600); //initializes comunications with cpu and sets data bits per second speed (baud rate) at 9600
}

void loop()
{
  float voltage, degreesC, degreesF; //floating point values are like variables, but can be fractional/decimals
  
  voltage = getVoltage(temperaturePin); //instead of doing analogRead we have written a new reading function below, getVoltage
  
  degreesC = (voltage - 0.5) * 100.0; //converts voltage reading to degrees celsius - equation from temperature sensor datasheet
  
  degreesF = degreesC * (9.0/5.0) + 32.0;
  
  Serial.print("voltage: "); //prints to serial monitor window
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF); //ln denotes move to next line
  
  delay(1000); //repeat once per second - can change this if you want
}

float getVoltage(int pin) //no void at front of function because float returns the value of true voltage on that pin... 0-5v. Void is used when no return value is needed.
{
  return (analogRead(pin) * 0.004882814); //giving value of voltage b/w 0-5v. Return statement is used in conjunction with value to return data.
}
