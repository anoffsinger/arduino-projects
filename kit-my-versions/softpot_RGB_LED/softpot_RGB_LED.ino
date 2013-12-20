const int RED_LED_PIN = 9; // establishing constants for LED connections - must be PWM
const int GREEN_LED_PIN = 10;
const int BLUE_LED_PIN = 11;
const int SENSOR_PIN = 0; // analog input pin

int redValue, greenValue, blueValue; // global pwm brightness variables

void setup()
{
 // no code needed here - but portion must still exist 
}

void loop()
{
 int sensorValue; // calling sensorValue variable 
 
 sensorValue = analogRead(0); // sensorValue variable equals analogRead of pin A0 (0-1023)
 
 setRGB(sensorValue); // reference function below that translates sensorValue into writeable color
}

void setRGB(int RGBposition) // parameter says "return value of RGBposition" - see this for help: http://arduino.cc/en/Reference/FunctionDeclaration
{
 
 int mapRGB1, mapRGB2, constrained1, constrained2; // calling variables
 
 // red peak - centered at 0 - see following for understanding math: http://sfecdn.s3.amazonaws.com/education/SIK/SchematicImages/Misc/RGB_function.jpg
 
 mapRGB1 = map(RGBposition, 0, 341, 255, 0); // 0-341 is red segment 1 - mapping to 255-O
 constrained1 = constrain(mapRGB1, 0, 255); // constraining mapRGB1 to 0-255 value just in case
 
 mapRGB2 = map(RGBposition, 682, 1023, 0, 255); // 682-1023 is red segment 2 - mapping to 0-255
 constrained2 = constrain(mapRGB2, 0, 255);
 
 redValue = constrained1 + constrained2;
 
 // green peak - centered at 341
 
 greenValue = constrain(map(RGBposition, 0, 341, 0, 255), 0, 255) // nesting achieves the above affect but with less code
            - constrain(map(RGBposition, 341, 682, 0, 255), 0, 255);
 
 // blue peak - centered at 682
           
 blueValue = constrain(map(RGBposition, 341, 682, 0, 255), 0, 255)
           - constrain(map(RGBposition, 682, 1023, 0, 255), 0, 255);
           
 analogWrite(RED_LED_PIN, redValue); // writing our computed colors
 analogWrite(GREEN_LED_PIN, greenValue);
 analogWrite(BLUE_LED_PIN, blueValue); 
   
}

