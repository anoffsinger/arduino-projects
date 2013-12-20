const int buttonPin = 2;
  const int ledPin =  13;    // LED pin
const int buzzerPin = 9;

const int songLength = 29;

char notes[] = "eeeeeeegcdefffffeeeeddedg"; // a space represents a rest

int beats[] = { 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4,  
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1 };

int tempo = 300;

void setup() 
{
  pinMode(buttonPin,INPUT);
  pinMode(buzzerPin, OUTPUT);
}

  int frequency(char note) 
  {

    int i;
    const int numNotes = 8;  // number of notes we're storing
 
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
    
    // Now we'll search through the letters in the array, and if
    // we find it, we'll return the frequency for that note.
    
    for (i = 0; i < numNotes; i++)  // Step through the notes
    {
      if (names[i] == note)         // Is this the one?
      {
        return(frequencies[i]);     // Yes! Return the frequency
      }
    }
    return(0);  // We looked through everything and didn't find it,
                // but we still need to return a value, so return 0.
   }

void loop() 
{
  int i, duration, buttonState;
  
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW)
  {
    digitalWrite(ledPin, HIGH);
    for (i = 0; i < songLength; i++) // step through the song arrays
    {
      duration = beats[i] * tempo;  // length of note/rest in ms
      
      if (notes[i] == ' ')          // is this a rest? 
      {
        delay(duration);            // then pause for a moment
      }
      else                          // otherwise, play the note
      {
        tone(buzzerPin, frequency(notes[i]), duration);
        delay(duration);            // wait for tone to finish
      }
      delay(tempo/10);              // brief pause between notes
    }
    
    // We only want to play the song once, so we'll pause forever:
    while(true){}
    // If you'd like your song to play over and over,
    // remove the above statement  
  }
  else{
   digitalWrite(ledPin, LOW); 
  }
}

