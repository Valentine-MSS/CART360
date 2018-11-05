////**********************ETUDE 2 CART 360 2017*******************************
//   WELCOME!
//   THE PURPOSE OF THIS EXERCISE IS TO DESIGN A VERY SIMPLE KEYBOARD (5 KEYS)
//   WHICH ALLOWS YOU TO PLAY LIVE, RECORD, AND PLAYBACK SINGLE NOTES (NO CHORDS).
//   THERE WILL BE A BUTTON WHICH WHEN PRESSED WILL TAKE THE USER TO THE NEXT MODE:
//   THERE ARE 5 POSSIBLE MODES
//   0 ==  reset    ==   led off == also resets
//   1 ==  live     ==   led BLUE
//   2 ==  record   ==   led RED
//   3 ==  play     ==   led GREEN
//   4 ==  looper   ==   led PURPLE
//
//   ADDITIONALLY - WHEN THE USER CHANGES MODE,
//   THE RGB LED WILL CHANGE COLOR (ACCORDING TO THE SPECIFICATIONS)
//
//   PLEASE FOLLOW THE INSTRUCTIONS IN THE COMMENTS:
//   DO NOT ADD ANY MORE FUNCTION DEFINITIONS
//   ONLY IMPLEMENT THE FUNCTION DEFINITIONS SUPPLIED
//   THERE IS NO NEED TO ADD ANY NEW VARIABLES OR CONSTANTS
//   PROVIDE COMMENTS FOR ANY OF THE CODE IMPLEMENTED
//   GOOD LUCK!
//*/
/**** CONSTANTS ********************************************************/

//







// ANSWER TO QUESTION 3, PART 2: Behavior of the resistor ladder
//  By implementing this resistor ladder set up, it is enabling this analog to digital
//  conversion through voltage division. Consequently, it’s allowing us to connect 5
//  buttons to a single  analog input (This is why we use analogRead (A0)). This process
//  is also called an R–2R Ladder.
//
//  The mode selector allows someone to cycle through the different modes that we have defined to (A2).
//  Essentially once someone clicks the modes button if increments the mode by 1,
//  and if it gets to mode 4 (meaning 5th mode), , it will go back to mode 0 (first mode).
//

//The tone function is producing a tone at a specified frequency which then gets sent as voltage to the piezo that then 
//generates the tone at the specified frequency. Voltage is produced in the process which then enables the piezo to play these tones. 




#define BUTTON_MODE_PIN 2 // Button to change the mode

// constants for RGB LED
#define LED_PIN_R 5 // R PIN
#define LED_PIN_G 9 // G PIN
#define LED_PIN_B 6 // B PIN

// constant for note in (button-resistor ladder on breadboard)
# define NOTE_IN_PIN A0

//constant for max number of notes in array
#define MAX_NOTES 16

// a constant for duration
const int duration = 200;

// constant for pin to output for buzzer
#define BUZZER_PIN 3 // PWM

/******** VARIABLES *****************************************************/
// counter for how many notes we have
int countNotes = 0;
int mode = 0; // start at off
// array to hold the notes played (for record/play mode)
int notes [MAX_NOTES];

/*************************************************************************/


/**********************SETUP() DO NOT CHANGE*******************************/
// Declare pin mode for the single digital input
void setup()
{
  pinMode(BUTTON_MODE_PIN, INPUT);

  Serial.begin(9600);


}

/**********************LOOP() DO NOT CHANGE *******************************
   INSTRUCTIONS:
   There is NO NEED to change the loop - it establishes the flow of the program
   We call here 3 functions repeatedly:
   1: chooseMode(): this function will determine the mode that your program is in
   based on if the button (linked to the BUTTON_MODE_PIN) was pressed
   2: setRGB(): will set the color of the RGB LED based on the value of the mode variable
   3: selectMode(): will determine which function to call based on the value of the mode variable

**************************************************************************/
void loop()
{
  Serial.begin(9600);
  chooseMode();
  setRGB();
  selectMode();
}
/******************CHOOSEMODE(): IMPLEMENT *********************************
   INSTRUCTIONS:
   Read the value from the Button (linked to the BUTTON_MODE_PIN) and
   if is being pressed then change the mode variable.
   REMEMBER:
   mode == 0 is reset
   mode == 1 is live
   mode == 2 is record
   mode == 3 is play
   mode == 4 is loopMode
   Every time the user presses the button, the program will go to the next mode,
   once it reaches 4, it should go back to mode == 0.
   (i.e. if mode ==2 and we press, then mode ==3) ...
**************************************************************************/
void chooseMode() {
  int buttonState = digitalRead(BUTTON_MODE_PIN);
  // Serial.println(digitalRead(BUTTON_MODE_PIN));
  //delay(250);
  //int buttonValue = analogRead(A0);
  // Serial.println(buttonValue);
  //delay(250);

  // Serial.begin(9600);
  //Serial.println(digitalRead(BUTTON_MODE_PIN));

  //int var;
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (digitalRead(BUTTON_MODE_PIN) == HIGH) {

    if (mode == 4) {
      mode = 0;
    }
    else mode++;
  }
  // IMPLEMENT
}


/******************SETRGB(): IMPLEMENT *********************************
   INSTRUCTIONS:
   Depending on the value of the mode variable:
   if the mode is 0 - RGB LED IS OFF
   if the mode is 1 - RGB LED IS BLUE
   if mode is 2 - RGB LED IS RED
   if mode is 3 - RGB LED IS GREEN
   if mode is 4 - RGB LED iS PURPLE
   YOU MUST USE A SWITCH CASE CONSTRUCT (NOT A SERIES OF IF / ELSE STATEMENTS
**************************************************************************/
void setRGB() {
  // int var;

  switch (mode) {

    case 0:
      // ALL LED's ARE OFF
      //(mode == 0); {
      digitalWrite(LED_PIN_R, LOW);
      digitalWrite(LED_PIN_G, LOW);
      digitalWrite(LED_PIN_B, LOW);
      delay(duration);

      // }
      // delay(1000);
      break;


    case 1:
      //BLUE LED ON,= THIS IS RED?
      // (mode == 1); {
      analogWrite(LED_PIN_R, HIGH);// RED IS GIVING BLUE
      analogWrite(LED_PIN_G, LOW);
      analogWrite(LED_PIN_B, LOW);
      delay(duration);
      // }
      //delay(1000);
      break;

    case 2:
      //RED LED ON = THIS IS BLUE
      //  (mode == 2); {
      analogWrite(LED_PIN_R, LOW);
      analogWrite(LED_PIN_G, HIGH);
      analogWrite(LED_PIN_B, LOW);
      delay(duration);
      // }
      break;
    //        delay(1000);

    case 3:
      //GREEN LED ON
      // (mode == 3); {
      analogWrite(LED_PIN_R, LOW);
      analogWrite(LED_PIN_G, LOW);
      analogWrite(LED_PIN_B, HIGH);
      delay(duration);
      //          delay(1000);
      break;
    //}
    case 4:
      //PURPLE LED ON
      // (mode == 4); {
      analogWrite(LED_PIN_R, HIGH); //THESE ARE SWITCHED
      analogWrite(LED_PIN_G, HIGH);
      analogWrite(LED_PIN_B, LOW);
      delay(duration);
      //}
      break;
      //          delay(1000);
  }
}


/**********************SELECTMODE() DO NOT CHANGE *******************************
   INSTRUCTIONS:
   There is NO NEED to change this function - it selects WHICH function should run based on the mode variable
   There are 4 possibilities
   1: reset(): this function will reset any arrays etc, and will do nothing else
   2: live(): this function will play the corresponding notes
   to the user pressing the respective buttons.
   NOTE:: the notes played are NOT stored
   3: record(): this function will play the corresponding notes
   to the user pressing the respective buttons
   AND will STORE up to 16 consecutive notes in an array.
   4: play(): this function will playback any notes stored in the array that were recorded
   in the previous mode
   5: loopMode(): this function will playback any notes stored in the array that were recorded,
   BUT unlike the previous mode, you can choose in which sequence the notes are played.
   REQUIRED: only play notes from the array (no live stuff)

******************************************************************************/
void selectMode()
{
  if (mode == 0) {
    reset();
  }
  else if (mode == 1) {
    live();
  }
  else if (mode == 2) {
    record();
  }

  else if (mode == 3) {
    play();
  }

  else if (mode == 4) {
    looper();
  }
}
/******************RESET(): IMPLEMENT **************************************
   INSTRUCTIONS:
   this function should ensure that any notes recorded are no longer available
**************************************************************************/
void reset()

{

  // CREDIT TO JEN FOR HELPTING ME WITH THIS FUNCTION WHICH I HAD PREVIOUSLY WRITTEN AS
  //int var;
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:

  //  if (buttonState == HIGH) {
  //
  //   if (mode == 4) {
  //      mode = 0;
  //    }

  //else mode++;}
  

  noTone(BUZZER_PIN);

  for (int i = 0; i < MAX_NOTES; i++) {

    notes[i] = 0;
  }

  countNotes = 0;

}



/******************LIVE(): IMPLEMENT **************************************
   INSTRUCTIONS:
   this function will play the corresponding notes
   to the user pressing the respective buttons
   NOTE:: the notes played are NOT stored
   SO: you need read in the input from the analog input (linked to the button-resistor ladder combo)
   THEN - output the note to the buzzer using the tone() function
**************************************************************************/
void live()
{
  int buttonValue;
  //  //  int note0 = 2960;
  //  //  int note1 = 3136;
  //  //  int note2 = 3520;
  //  //  int note3 = 3729;
  //  //  int note4 = 3951;
  //  //
  //FIGURE OUT WHICH PIEZO TONE AND WHICH BUTTON VALUES
  //  Serial.begin(9600);
  //  buttonValue = analogRead(NOTE_IN_PIN);     // read the input pin
  //  Serial.println(buttonValue);
  buttonValue = analogRead(A0); //Read analog value from A0 pin
  //
  //
  //
  //
  if (buttonValue >= 931 && buttonValue <= 1024) {
    tone(BUZZER_PIN, 523, duration); // C5
    delay(10);

  }

  else if (buttonValue >= 486 && buttonValue <= 932) {
    tone(BUZZER_PIN, 587, duration); //D5
    delay(10);


  }

  else if (buttonValue >= 82  && buttonValue <= 485) {
    tone(BUZZER_PIN, 659, duration); //E5
    delay(10);

  }

  else if (buttonValue >= 7  && buttonValue <= 81) {
    tone(BUZZER_PIN, 698, duration); //F5
    delay(10);


  }

  else if (buttonValue >= 0  && buttonValue <= 7) {
    tone(BUZZER_PIN, 784, duration);  // G5
    delay(10);

  }

  //IMPLEMENT
}
/******************RECORD(): IMPLEMENT **********************************
   INSTRUCTIONS:
   this function will play the corresponding notes
   to the user pressing the respective buttons
   AND will STORE up to 16 consecutive notes in an array.
   SO:you need read in the input from the analog input (linked to the button-resistor ladder combo)
   AND - output the note to the buzzer using the tone() function
   THEN store that note in the array  - BE CAREFUL - you can only allow for up to MAX_NOTES to be stored
**************************************************************************/
void record()
{

  //
  //     notes [MAX_NOTES] = analogRead(A0);
  //    int buttonValue;
  //    //FIGURE OUT WHICH PIEZO TONE AND WHICH BUTTON VALUES
  //    Serial.begin(9600);
  //    buttonValue = analogRead(NOTE_IN_PIN);     // read the input pin
  //    Serial.println(buttonValue);
  //    buttonValue = analogRead(A0); //Read analog value from A0 pin
  //
  //
  //    //For 1st button:
  //    if (buttonValue >= 932 && buttonValue <= 1023) {
  //      //tone(BUZZER_PIN, NOTE_IN_PIN)
  //      delay(1000);
  //      notes [0] = NOTE_IN_PIN;
  //
  //    }
  //
  //    else if (buttonValue >= 82 && buttonValue <= 931) {
  //      tone(BUZZER_PIN, NOTE_IN_PIN,duration);
  //      delay(1000);
  //      notes[1] = NOTE_IN_PIN;
  //
  //    }
  //    else if (buttonValue >=  7  && buttonValue <= 82) {
  //      // tone(BUZZER_PIN, NOTE_IN_PIN,duration);
  //      delay(1000);
  //
  //      notes[2] = NOTE_IN_PIN;
  //
  //    }
  //
  //    else if (buttonValue >= 0  && buttonValue <= 6) {
  //      // tone(BUZZER_PIN, NOTE_IN_PIN,duration);
  //      delay(1000);
  //
  //      notes[3] = NOTE_IN_PIN;
  //
  //    }
  //
  //    else if (buttonValue >= 870  && buttonValue <= 850) {
  //      int note5;
  //      tone(BUZZER_PIN, NOTE_IN_PIN, duration);
  //      delay(1000);
  //      notes[4] = NOTE_IN_PIN;
  //      // IMPLEMENT
  //    }
}
/******************PLAY(): IMPLEMENT ************************************
   INSTRUCTIONS:
   this function will playback any notes stored in the array that were recorded
   in the previous mode
   SO: you need to go through the array of values (be careful - the user may not have put in MAX_NOTES)
   READ each value IN ORDER
   AND output each note to the buzzer using the tone() function
   ALSO: as long as we are in this mode, the notes are played over and over again
   BE CAREFUL: make sure you allow for the user to get to another mode from the mode button...
**************************************************************************/
void play()
{
  //print.ln(notes[]);
}
// IMPLEMENT

/******************LOOPMODE(): IMPLEMENT *********************************
   INSTRUCTIONS:
   this function will playback any notes stored in the array that were recorded
   in the previous mode
   SO: you need to go through the array of values (be careful - the user may not have put in MAX_NOTES)
   READ values IN ANY ORDERING (You MUST use the array - but you can determine your own sequence)
   AND output each note to the buzzer using the tone() function
   ALSO: as long as we are in this mode, the notes are played over and over again
   BE CAREFUL: make sure you allow for the user to get to another mode from the mode button...
**************************************************************************/
void looper()
{
  //IMPLEMENT
}

/**************************************************************************/
