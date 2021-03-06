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
  * Multiple chaplets
    * Chaplet of Divine Mercy
    * Support for a generic format and sort of programmer
  * Desktop/web connectivity and dashboard  
  * Hardware Improvements  
    * Rotary encoder, with "Amen" button when pressed and option to accept swipes as increment/decrement (for aesthetic simplicity)
    * Power switch, battery charging, automatic shut-off / sleep (should use just microcontroller if have a sleep mode)
    * State preservation, settings, and statistics (requires some form of memory, probably EEPROM's enough)
     * Settings
       * Starting prayer
       * Final prayer(s)
       * Translations
       * Scrolling prayer text   
       * Prayer counter none, (x/10, y/5) or x, y
    * Verses and meditations (requires larger LCD)
    * Recordings and recitation of recordings (requires microphone and memory)
    * USB connectivity (largely pointless unless have memory or massive library of options at start)
    * Accessories, 3d-printable cases, etc.

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

1. Assemble the components according to this breadboard diagram and picture:
<img src="./PrayerBits%20Breadboard_bb.png">
<img src="./PrayerBits.jpg">
Note that you will need to add an extra button, connected to pin 3, to use the version with Mysteries, although you could hypothetically rig up a solution to display each option for x ms instead of having a second button, if you're low on buttons.

2. Open the code in Arduino IDE
3. Upload the code

# Operation
At the start, you press the second button to skip to the next chaplet/mysteries. Once the desired option is selected, press the primary button to confirm.
Then, simply, press the primary button to advance a prayer.

# Troubleshooting
* A bizarre error can occur where gibberish is displayed, and uploading again (sometimes repeatedly) resolves the issue.
* The included Fritzing file fails to route correctly in schematic view. 

