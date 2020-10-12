# prayerbits
A simple Arduino device to pray chaplets digitally, which can be built easily from components included in most starter kits.
The design is released under the MIT License in the hopes of spurring development of Catholic software and hardware projects, and other edifying endeavors (basically anything involving counting can be derived from the techniques here). Also serves as a nice introduction to the basics of the Arduino system.

# Features
Those in bold have already been implemented:
  * **Rosary prayers**
  * **Rosary Mysteries**
    * **Menu at start, with 4 options, and each button press corresponding to a movement**
    * Calendar-based (will require a Real-Time Clock, or Ethernet connection)
  * **FOSS/H project**
  * **Accessibility**
    * **Different beeps for different prayers, for the blind (improve differentiation)**
    * Vibration and **LED for the deaf orants** (use RGB LED)
    * Input for quadraplegics
  * Scrolling prayer text
  * Prayer counter (x/10, y/5) or x, y
    * Due to space limitations, requires implementing scrolling text first  
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
  * Accessories, 3d-printable case, etc.

# Components
The project can be built with parts included in most Arduino starter kits.
* Breadboard
* 2x16 LCD
* 10k pot
* 2x Buttons
* Jumper wires
* LED
* Arduino UNO R3

# Instructions
You will need the LiquidCrystal Library.

1. Assemble the components according to this breadboard diagram:
<img src="./PrayerBits%20Breadboard_bb.png">
Note that you will need to add an extra button, connected to pin 3, to use the version with Mysteries, although you could hypothetically rig up a solution to display each option for x ms instead of having a second button, if you're low on buttons.

2. Open the code in Arduino IDE
3. Upload the code

# Operation
At the start, you press the second button to skip to the next chaplet/mysteries. Once the desired option is selected, press the primary button to confirm.
Then, simply, press the primary button to advance a prayer.

# Troubleshooting
* A bizarre error can occur where gibberish is displayed, and uploading again (sometimes repeatedly) resolves the issue.
* The included Fritzing file fails to route correctly in schematic view. 

