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


LED1 "RGB, 32, 33, 34"

LED2 "RGB, 25, 26, 27"

LED3 "RGB, 17, 18, 19"



Een menu waar ik doorheen kan scrollen.

----Main menu----

Rooflights (De standaard die boven midden staat zodra het systeem opgestart is.
UnderGlow
Beacon
leeg2
leeg3


----Rooflights---- (Bij selecteren van een pattern moet er code gaan lopen om de lampen aan te sturen  maar allen als pin 12 LOW is(die moet ik nog testen). Zolang pin12 LOW is word de pattern verzonden. als pin 12 HIGH gezet word, word er eenmalig de uitcode verzonden en de pattern gestopt. Zodra pin 12 LOW is gaat de pattern code weer actief. de laatste selectie is dus opgeslagen in memory.)

ON 		(dit stuurt eenmalig de aan code naar alle lampen)
Pattern 1 	(patterns worden net als de ON funtie nog geprogrammeerd)
Pattern 2
Pattern 3
Pattern 4
Pattern 5
Pattern 6
Pattern 7
OFF
Back


----UnderGlow---- (Bij selecteren van onderstaande opties eenmalig code uitvoeren en terug keren naar menu. store selectie in memory en die eenmalig verstuurd word als flipswitchpin14 LOW gezet word, als pin 14Low gezet word of uit is word eenmalig uitcode verzonden maar niet de selectie in memory wijzigen. Dit aan en uit zetten zou ik graag willen doen op elk gewenst moment.)
Preset1
Preset2
Preset3
Preset4
Preset5
Preset6
CUSTOM
OFF
Back

---Beacon--- (sends a certain on or off code once)
ON
OFF
Back

---Leeg2--- (for future use)
Back

---Leeg3--- (for future use)
Back