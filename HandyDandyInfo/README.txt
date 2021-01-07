Er is nog best wat om te testen en te implementeren na het menu. De rooflights, Underglow en beacon moeten aangestuurd gaan worden met het "ESP NOW" protocol.
Aansturend board is een WEMOS LOLIN32 luisterende boarden zijn ESP8266-S1

Een aantal foto's van het project zijn toegevoegd

PLS maak het vooral makkelijk om dingen toe te voegen en aan te passen

Als je denkt dat het makkelijker is om de ESP NOW verbindingen eerst te testen voordat het menu gemaakt word dan hoor ik het wel en ga ik dat eerst nog doen. Ik dacht dat de nodige code om de die verbindingen te maken en de data te sturen ook achteraf wel makkelijk toe te voegen was but I am not sure, You tell me.

Voor nu bij alle functies serial output toevoegen om te testen.

If you need it:
This library enables the use of analogWrite on the esp32 https://github.com/ERROPiX/ESP32_AnalogWrite
This library enables the use of simple tones on the esp32  https://github.com/lbernstone/Tone32
LiquidCrystal_I2C.h is needed for the i2c 16x2 LCD


PINS

RotaryA "4"	INPUT_PULLUP
RotaryB	"2"	INPUT_PULLUP
RotaryC "15"	INPUT_PULLUP

Rooflight flipswitch "12" INPUT_PULLUP
UnderGlow flipswitch "14" INPUT_PULLUP


PIEZO buzzer "16"	OUTPUT


NEO pixels led 1,2,3 pin "13"




Een menu waar ik doorheen kan scrollen.

----Main menu----

Rooflights (De standaard die boven midden staat zodra het systeem opgestart is.
UnderGlow
Beacon
leeg2
leeg3


----Rooflights---- (Bij selecteren van een pattern moet er code gaan lopen om de lampen aan te sturen  maar allen als pin 12 LOW is(die moet ik nog testen). Zolang pin12 LOW is word de pattern verzonden. als pin 12 HIGH gezet word, word er eenmalig de uitcode verzonden en de pattern gestopt. Zodra pin 12 LOW is gaat de pattern code weer actief. de laatste selectie is dus opgeslagen in memory.)

ON (met een selectie vraag waar een nummer tussen de 5 en 1 te kiezen is
5	(Alle Lampen aan)
4	(Alle lampen aan behalve de midelste)
3	(Lamp 1, 3 en 5 aan)
2	(Lamp 1 en 5 aan)
1	(Lamp 3 aan)


Knight Rider
[10000, 01000, 00100, 00010, 00001, 00010, 00100, 01000]
As fast as kit from knight rider.


Warning
[100101, 01010]
Not to fast but not so slow either.


Inside out
[00100, 01010, 10001]


Outside In
[10001, 01010, 00100]


Right
Right 1 [10000, 01000, 00100, 00010, 00001]
Right 2 [10000, 11000, 01100, 00110, 00011, 00001]
Right 3 [00000, 10000, 11000, 11100, 11110, 11111]


Left
Left 1 [00001, 00010, 00100, 01000, 10000]
Left 2 [00001, 00011, 00110, 01100, 11000, 10000]
Left 3 [00000, 00001, 00011, 00111, 01111, 11111]


Off


Back




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




---Beacon 1--- (sends a certain on or off code once)
ON
OFF
Back

---Leeg2--- (for future use)
Back

---Leeg3--- (for future use)
Back