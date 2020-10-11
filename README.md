# prayerbits
A simple Arduino device to pray chaplets digitally

# Features
Those in bold have already been implemented:
  * **Rosary prayers**
  * Rosary Mysteries
    * Calendar-based
    * Menu at start, with 4 options, and each button press corresponding to a movement
  * Settings
    * Starting prayer
    * Final prayer
  * Translations
  * Accessibility
    * Vibration and LED for the deaf orants
    * Different beeps for different prayers, for the blind
    * Input for quadraplegics
  * **FOSS/H project**
  * Debounce inputs with this: https://www.arduino.cc/en/tutorial/switch
  * Multiple chaplets, with support for generic format
  * Rotary encoder, with "Amen" button
  * Scrolling prayer text
  * Prayer counter (x/10, y/5) or x, y
    * Due to space limitations, requires implementing scrolling text first
  * Ending prayers
  * Power switch
  * Verses

# Components
The project can be built with parts included in most Arduino starter kits.
* Breadboard
* 2x16 LCD
* 10k pot
* Button
* Jumper wires
* LED
* Arduino UNO R3

# Instructions
You will need the LiquidCrystal Library.

1. Assemble the components according to the attached schematic/photograph
2. Open the code in Arduino IDE
3. Upload the code

# Operation
Simply, press the button to advance a prayer.

# Troubleshooting
A bizarre error can occur where gibberish is displayed, and uploading again resolves the issue.

