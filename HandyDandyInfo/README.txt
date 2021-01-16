Install ESPnow libs
Install wifi8266 libs


If you need it:
This library enables the use of analogWrite on the esp32 https://github.com/ERROPiX/ESP32_AnalogWrite
This library enables the use of simple tones on the esp32  https://github.com/lbernstone/Tone32
LiquidCrystal_I2C.h is needed for the i2c 16x2 LCD


PINS

RotaryA "4"	INPUT_PULLUP
RotaryB	"2"	INPUT_PULLUP
RotaryC "15"	INPUT_PULLUP

Rooflight flipswitch "14" INPUT_PULLUP
Beacon/Extra flipswitch "12" INPUT_PULLUP
Underglow flipswitch "27" INPUT_PULLUP

PIEZO buzzer "16"	OUTPUT

NEO pixel led 1 pin "13"


NEO pixels leds 2,3 pin "13" on UG ESP32




Menu layout

----Main menu----


Rooflights
UnderGlow
Extra
Beacon



----Rooflights----

Static
Knightrider	[10000,01000,00100,00010,00001,00010,00100,01000] 100
Slowrider	[10000,01000,00100,00010,00001,00010,00100,01000] 300
Warning		[100101,01010] 200
Slow warning	[100101,01010] 500
Inside out	
Outise in
Left
Right
Off
Back



Static (switch selected amount of lights static on)
1		[00100]
2		[10001]
3		[10101]
4		[11011]
5		[11111]



Inside out
IO single 	[00100,01010,10001,00000] 200
IO fill		[00100,01110,11111,00000] 200



Outside in

OI single	[10001,01010,00100,00000] 200
OI fill		[10001,11011,11111,00000] 200



Right

Right 1		[10000,01000,00100,00010,00001]
Right 2		[10000,11000,01100,00110,00011,00001]
Right fill	[00000,10000,11000,11100,11110,11111]



Left

Left 1		[00001,00010,00100,01000,10000]
Left 2		[00001,00011,00110,01100,11000, 10000]
Left fill	[00000,00001,00011,00111,01111, 11111]




----UnderGlow---- (Bij selecteren van onderstaande opties functie uitvoeren) Store selectie in memory en die eenmalig verstuurd word als flipswitchpin14 LOW gezet word, als pin 14Low gezet word of uit is word eenmalig uitcode verzonden maar niet de selectie in memory wijzigen. Dit aan en uit zetten zou ik graag willen doen op elk gewenst moment.
Sync with internal Leds if possible)

Smooth cycle
Just cycle through all the colours smooth

Harsh cycle
Just cycle through all coulors but not smooth

Police (blinking randomly blue om both sides)

American police (blinking like the american police lights)

Red

Apple green

Blue

Panda yellow

Purple

White

CUSTOM (to put in rgb values that will be sent once)

OFF

Back




---Extra--- (sends a certain on or off code once)
ON/OFF on click

---Beacon--- (for future use)
ON/OFF on click





