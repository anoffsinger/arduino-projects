//10k pullup resistors ensure that input pin will be either 5V (unpushed) or ground (pushed) 
//and not somewhere in between

//establishing constants for every pin:

const int button1Pin = 2;
const int button2Pin = 3;
const int ledPin = 13;

void setup()
{
//setting pushbutton pins to input mode

pinMode(button1Pin, INPUT);
pinMode(button2Pin, INPUT);

//led pin to be output

pinMode(ledPin, OUTPUT);
}
void loop()
{
  int button1State, button2State; //establishing variables to read pushbutton states
  
  button1State = digitalRead(button1Pin); //defining variables
  button2State = digitalRead(button2Pin); //digitalRead takes one parameter, the pin number, and returns either HIGH (5V) or LOW (GND)
  
  if (((button1State == LOW) || (button2State == LOW)) // if we're pushing button 1 OR button 2
  && !                                                 // AND we're NOT
  ((button1State == LOW) && (button2State == LOW)))    // pushing button 1 AND button 2
  
  {
    digitalWrite(ledPin, HIGH); //turn on LED
  }
  else
  {
    digitalWrite(ledPin, LOW); //turn off LED
  }
}
