// the 74HC95 IC uses SPI - which requires 3 specific pins:

int datapin = 2;
int clockpin = 3;
int latchpin = 4;

byte data = 0; // declaring global byte variable called "data" we will send to the shift register

// if bit in byte = 0, LOW, if bit in byte = 1, HIGH

void setup()
{
  // setting 3 SPI pins to output
  
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(latchpin, OUTPUT);
}

void loop()
{
  // instead of digitalWrite, we will now use shiftWrite
  
  oneAfterAnother(); // all on, all off
  //oneOnAtATime(); // scroll down the line
  //pingPong(); // like above but back and forth
  //randomLED(); // blink random LEDs
  //marquee();
  //binaryCount(); // bit patterns from 0-255
}

void shiftWrite(int desiredPin, boolean desiredState) 

// desiredPin is the output pin you want to affect
// desiredState is whether you want that output to be high or low

{
 bitWrite(data, desiredPin, desiredState); // altering global variable data changing desired bit to 1 or 0
 
 shiftOut(datapin, clockpin, MSBFIRST, data); // moving data onto shift register
 
 digitalWrite(latchpin, HIGH); // latching the data to the actual outputs
 digitalWrite(latchpin, LOW); 
}

void oneAfterAnother()
{
  int index;
  int delayTime = 100;
  
  for(index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);
    delay(delayTime);
  }
  
  for(index = 7; index>=0; index--)
  {
    shiftWrite(index, LOW);
    delay(delayTime);
  }
}

void oneOnAtATime()
{
  int index;
  int delayTime = 100; 

  for(index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH); // turn LED on
    delay(delayTime); // pause to slow down the sequence
    shiftWrite(index, LOW); // turn LED off
  }
}

void pingPong()
{
  int index;
  int delayTime = 100; 
  
  for(index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);
    delay(delayTime);
    shiftWrite(index, LOW);
  }

  for(index = 7; index >= 0; index--)
  {
    shiftWrite(index, HIGH);
    delay(delayTime);
    shiftWrite(index, LOW);
  }
}

void randomLED()
{
  int index;
  int delayTime = 100; 
  
  // The random() function will return a semi-random number each time it is called. See http://arduino.cc/en/Reference/Randomfor for more
  
  index = random(8); // pick a random number between 0 and 7
  
  shiftWrite(index, HIGH);
  delay(delayTime);
  shiftWrite(index, LOW);
}

void marquee()
{
  int index;
  int delayTime = 200; 
  
  // Step through the first four LEDs - we'll light up one in the lower 4 and one in the upper 4
  
  for(index = 0; index <= 3; index++)
  {
    shiftWrite(index, HIGH); // Turn a LED on
    shiftWrite(index+4, HIGH); // Skip four, and turn that LED on
    delay(delayTime); // Pause to slow down the sequence
    shiftWrite(index, LOW); // Turn both LEDs off
    shiftWrite(index+4, LOW);
  }
}


/*

Bit position   Contribution
0              1
1              2
2              4
3              8
4              16
5              32
6              64
7              128

To build any number from 0 to 255 from the above 8 bits, just
select the contributions you need to make. The bits will then be
1 if you use that contribution, and 0 if you don't.

This function will increment the "data" variable from 0 to 255
and repeat. When we send this value to the shift register and LEDs,
you can see the on-off pattern of the eight bits that make up the
byte. 
*/

void binaryCount()
{
  int delayTime = 1000;
  
  shiftOut(datapin, clockpin, MSBFIRST, data);

  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);

  data++; // Add one to data, and repeat

  delay(delayTime);
}
