//www.elegoo.com
//2016.12.9

/*
TODO:
  Add Mysteries
    * Calendar-based
    * Menu at start, with 4 options, and each button press corresponding to a movement
  Add Settings
    * Starting prayer
    * Final prayer
  Add Translations
  Vibrate and LED for the deaf orants
  Upload as a FOSS/H project
  Different beeps for different prayers
  Debounce inputs with this: https://www.arduino.cc/en/tutorial/switch
  Multiple chaplets
  Implement rotary encoder, with "Amen" button
  Scrolling prayer text
  Prayer counter (x/10, y/5) or x, y
    Due to space limitations, requires implementing scrolling text first
  Add ending prayers
  Add power switch
  Add verses
 
 DEBUG:
  Random restarts
  Random erroneous flashing
  Restarting at end with repeated Creeds; add a starting menu ASAP
  
  For input, can either increment with a button, or increment/decrement with two and simultaneous press being enter
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

int buttonpin = 2;
int secondbutton = 3;
int buzzer = 4;
int LED = 13;
int pos = 0; //keep in mind when counting beads
int sel = 0;

int state = HIGH;      // the current state of the output
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
int mystery = -1;       // the selected mystery; -1 is signal value indicating need to select

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers


/*
Interface:
__________________
|Mystery Name     |
|Prayer (/10)[/5] |
------------------*
*/

//redundant for rosary, since can determine prayer from pos and decade
int chaplet[] = {0, 1, 2, 2, 2, 3,
                 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, //last bead corresponds to pos=18
                 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,
                 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,
                 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,                  
                 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4};
  
// Mysteries
String mysteries[] = {"Glorious ", "Joyful    ", "Sorrowful", "Luminous "}; //Put random spaces at end to avoid having to clean up LCD to get rid of 'l' from sorrowful, lol, obv could improve
String joyful[] = {"The Annunciation", "The Visitation", "The Nativity", "The Presentation", "The Temple"};
String glorious[] = {"The Resurrection", "The Ascension", "Pentecost", "The Assumption", "The Coronation"};
String luminous[] = {"The Baptism", "Wedding at Cana", "The Kingdom", "Transfiguration", "The Eucharist"};
String sorrowful[] = {"Agony", "Scourging", "Thorns", "Carrying Cross", "Crucifixion"};

// Prayers
String prayers[] = {"I believe...", "Our Father...", "Hail Mary...", "Glory Be...", "Oh my Jesus..."};

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//int input(int options) {
//  int selection = 1;
//  for (int i=0; i<options; options++) {
//    if (digitalRead(buttonpin == LOW)) {
//      if ((digitalRead(secondbutton) == LOW))
//        {
//          //both buttons pressed, return input
//          break; 
//        }
//        //increment 
//        selection += 1;
//    }
//  }
//}

/* Can take as either input a random small integer and any one of the standard prayer encodings, e.g., 0 for the Creed, and then beep a different tune for each */
void beep(int firstdelay, int seconddelay) {
 unsigned char i;
   //output an frequency
   for(i=0;i<80;i++)
   {
    digitalWrite(buzzer,HIGH);
    delay(firstdelay);//wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(firstdelay);//wait for 1ms
    }
    //output another frequency
     for(i=0;i<100;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(seconddelay);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(seconddelay);//wait for 2ms
      }
}

void setup() {
  pinMode(buttonpin, INPUT_PULLUP);
  pinMode(secondbutton, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("Let's pray now!");
  lcd.print("Choose Mystery:");
  Serial.begin(9600);
}



/*
Can determine current position using modulo, e.g., if pos=10, subtract 6, then do mod%10, and compare to table
Not necessarily most computationally efficient, though avoids rewriting. Might need to rewrite for general chaplets which aren't as well-suited to modular arithmetic.

*/
void loop() {
  /* 
  If at the very start, read for input of a mystery
  Assumes a mystery is required, so select chaplet first, and skip if inapplicable
  Simulates a rotary encoder basically
  */
  Serial.print(sel);
  if (pos == 0 && mystery == -1) {
    if (sel >= 4) { 
      sel = 0; //reached end of menu; reset
    }
    else {
      lcd.setCursor(0,1);
      lcd.print(mysteries[sel]);
      if (digitalRead(buttonpin) == LOW) {
        mystery = sel;
        delay(500); //debounce
      }
      if (digitalRead(secondbutton) == LOW) {
        sel += 1;
        delay(150); //debounce
      }
    }
  }

  else {
    String prayer;
    
    reading = digitalRead(buttonpin);
  
    // if the input just went from LOW and HIGH and we've waited long enough
    // to ignore any noise on the circuit, toggle the output pin and remember
    // the time
    if (reading == HIGH && previous == LOW && millis() - time > debounce) {
      if (state == HIGH)
        state = LOW;
      else
        state = HIGH;
  
      time = millis();    
    }
  
    previous = reading;
    
    if (state == LOW) {
        lcd.clear(); //Annoyingly clears screen; modify to only clear on transitions of mystery
        /*write prayer when button pressed*/
        
        // set the cursor to column 0, line 1
        // (note: line 1 is the second row, since counting begins with 0):
        lcd.setCursor(0, 1);  
        
        digitalWrite(LED, HIGH);
        beep(1, chaplet[pos]);
        lcd.print(prayers[chaplet[pos]]);
        pos+=1;
        //delay(100); // to prevent multiple reads, replaced by debouncing
        digitalWrite(LED, LOW);
        state = HIGH;
        
                //Determine mystery and position
        if (pos - 6 > 0) {
          int decade = ceil((pos-7)/13);
          int bead = (pos - 6)%13; //results in Fatima prayer bead corresponding to value of 0
          lcd.setCursor(0,0);
          switch (mystery) {
            case 0:
              lcd.print(glorious[decade]);
              break;
            case 1:
              lcd.print(joyful[decade]);
              break;
            case 2:
              lcd.print(sorrowful[decade]);
              break;
            case 3:
              lcd.print(luminous[decade]);
              break;
          }
        }
        else {
          int decade = 0;
          int bead = pos;
          lcd.setCursor(0,0);
          lcd.print("Intro. Prayers");
        }
    }
    
    if (pos >= sizeof(chaplet)) {
      lcd.print("Amen!");
      lcd.setCursor(0,0);
      lcd.print("Great Job!");
    }
  }

}
