//MIT License
//Developed by https://gaffneylabs.com
//October 7, 2020

/*
TODO:
  Add Mysteries
    * Calendar-based
    * Menu at start, with 4 options, and each button press corresponding to a movement
  Add Settings
    * Starting prayer
    * Final prayer
  Add Translations
  Upload as a FOSS/H project
  Different beeps for different prayers
  Debounce inputs with this: https://www.arduino.cc/en/tutorial/switch
  Multiple chaplets
  
  For input, can either increment with a button, or increment/decrement with two and simultaneous press being enter
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

int buttonpin = 2;
int buzzer = 4;
int pos = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void beep() {
 unsigned char i;
   //output an frequency
   for(i=0;i<80;i++)
   {
    digitalWrite(buzzer,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(1);//wait for 1ms
    }
    //output another frequency
     for(i=0;i<100;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(2);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(2);//wait for 2ms
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

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  
  int chaplet[] = {0, 1, 2, 2, 2, 3,
                   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,
                   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,
                   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,
                   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4,                  
                   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4};
  
  String prayer;
  
  if (digitalRead(buttonpin) == LOW) {
      switch (chaplet[pos]) {
        case 0:
          beep();
          prayer = "I believe...";
          break;
        case 2:
          beep();
          prayer = "Hail Mary...";
          break;
        case 1:
          beep();
          prayer = "Our Father...";
          break;
        case 3:
          beep();
          prayer = "Glory Be...";
          break;
        case 4:
          beep();
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
