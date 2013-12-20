//  note frequency
//  c     262 Hz
//  d     294 Hz
//  e     330 Hz
//  f     349 Hz
//  g     392 Hz
//  a     440 Hz
//  b     494 Hz
//  C     523 Hz

const int buzzerPin = 9; //setting buzzer pin location
const int songLength = 18; //length must equal the total number of notes and spaces
char notes[] = ""; //notes is an array of text characters corresponding to notes - a space represents a rest - 18 characters total (counting spaces)
int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2}; //beats is an array of values for each notes and rest, 1 quarter, 2 half, etc (18 characters)
int tempo = 150;

void setup()
{
  pinMode (buzzerPin, OUTPUT);
}

void loop()
{
  int i, duration; //calling variables
  
  for (i = 0; i < songLength; i++) //step through the song arrays
  {
    duration = beats[i] * tempo;
    
    if (notes[i] == ' ') //is this a rest?
    {
      delay(duration); //then pause for a moment
    }
    else //otherwise
    {
      tone(buzzerPin, frequency(notes[i]), duration); //play the note
      delay(duration); //wait for tone to finish
    }
    delay(tempo/10); //brief pause between notes
  }
  while(true){} //we only want to play song once, remove this to have it loop forever
}

int frequency(char note) //this function returns corresponding hz frequency for note characters for tone() functions
{
  int i; //calling variable
  const int numNotes = 8; //number of notes we storing 
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' }; //each char must be unique
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  
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
      
    
