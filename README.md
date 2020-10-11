# prayerbits
A simple Arduino device to pray chaplets digitally, which can be built easily from components included in most starter kits.
The design is released under the MIT License in the hopes of spurring development of Catholic software and hardware projects, and other edifying endeavors. Also serves as a nice introduction to the basics of the Arduino system.

# Features
Those in bold have already been implemented:
  * **Rosary prayers**
  * **FOSS/H project**
  * **Accessibility**
    * **Different beeps for different prayers, for the blind (improve differentiation)**
    * Vibration and **LED for the deaf orants** (use RGB LED)
    * Input for quadraplegics
  * Scrolling prayer text
  * Prayer counter (x/10, y/5) or x, y
    * Due to space limitations, requires implementing scrolling text first  
  * Rosary Mysteries
    * Calendar-based
    * Menu at start, with 4 options, and each button press corresponding to a movement
  * Settings
    * Starting prayer
    * Final prayer
  * Translations
  * Multiple chaplets
    * Chaplet of Divine Mercy
    * Support for a generic format
  * Rotary encoder, with "Amen" button
  * Ending prayers
  * Power switch, automatic shut-off, and state preservation
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

