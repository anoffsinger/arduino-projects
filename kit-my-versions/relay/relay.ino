const int relayPin = 2; // establishing transistor driving pin
const int timeDelay = 1000; //time in milliseconds for on/off phases

// it's possible to make this delay shorter - but keep in mind that driving it faster will wear it out

void setup()
{
  pinMode(relayPin, OUTPUT); // set pin as output
}

void loop()
{
  digitalWrite(relayPin, HIGH); // turn the relay on
  delay(timeDelay); // wait one second
  digitalWrite(relayPin, LOW);
  delay(timeDelay);
}
