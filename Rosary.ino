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
int pos = 0;

/*
Interface:
__________________
|Mystery Name     |
|Prayer (/10)[/5] |
------------------*
*/

// Mysteries
String joyful[] = {"The Annunciation", "The Visitation", "The Nativity", "The Presentation", "The Temple"};
String glorious[] = {"The Resurrection", "The Ascension", "Pentecost", "The Assumption", "The Coronation"};
String luminous[] = {"The Baptism", "Wedding at Cana", "The Kingdom", "Transfiguration", "The Eucharist"};
String sorrowful[] = {"Agony", "Scourging", "Thorns", "Carrying Cross", "Crucifixion"};

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int input(int options) {
  int selection = 1;
  for (int i=0; i<options; options++) {
    if (digitalRead(buttonpin == LOW)) {
      if ((digitalRead(secondbutton) == LOW))
        {
          //both buttons pressed, return input
          break; 
        }
        //increment 
        selection += 1;
    }
  }
}

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
  pinMode(buzzer, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Let's pray now!");
}



/*
Can determine current position using modulo, e.g., if pos=10, subtract 6, then do mod%10, and compare to table
Not necessarily most computationally efficient, though avoids rewriting. Might need to rewrite for general chaplets which aren't as well-suited to modular arithmetic.

*/
void loop() {
  
  //redundant for rosary, since can determine prayer from pos and decade
  int chaplet[] = {0, 1, 2, 2, 2, 3,
                   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,
                   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,
                   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,
                   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,                  
                   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4};
  
  
  //Determine mystery and position
  if (pos - 6 >= 0) {
    int decade = ceil((pos-6)/13);
    int bead = (pos - 6)%13; //results in Fatima prayer bead corresponding to value of 0
  }
  else {
    int decade = 0;
    int bead = pos;
  }
  
  /*write prayer when button pressed*/
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);

  String prayer;
  
  
  if (digitalRead(buttonpin) == LOW) {
      beep(1, chaplet[pos]);
      switch (chaplet[pos]) {
        case 0:
          prayer = "I believe...";
          break;
        case 2:
          prayer = "Hail Mary...";
          break;
        case 1:
          prayer = "Our Father...";
          break;
        case 3:
          prayer = "Glory Be...";
          break;
        case 4:
          prayer = "Oh my Jesus...";
          break;              
      }
      lcd.print(prayer);
      pos+=1;
      delay(50); // to prevent multiple reads
  }
  
  if (pos >= sizeof(chaplet)) {
    lcd.print("Amen!");
    lcd.setCursor(0,0);
    lcd.print("Great Job!");
  }

}
