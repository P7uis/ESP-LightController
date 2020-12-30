#include <LiquidCrystal_I2C.h>
#include <Tone32.h>
#include "ESPLC_Variables.h"
#include "ESPLC_Variables_menu.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);  
void setup(){ if(SerialDebug)Serial.begin(115200); pinMode(EncoderPinA, INPUT_PULLUP); pinMode(EncoderPinB, INPUT_PULLUP); pinMode(EncoderPinC, INPUT_PULLUP); lcd.init(); lcd.backlight(); ESPLC_Buzzer(0); } void loop(){ if(SerialDebug){ Serial.print("MenuPos: "); Serial.println(MainMenuPosition); Serial.print("MenuOption: "); Serial.println(MainMenuOptions[MainMenuPosition]); Serial.print("Screen refreshed: "); Serial.println(LCDRefresh); } if (millis() - LastTick >= RefreshInterval) { LastTick = millis(); LCDRefresh = true; } PinA = digitalRead(EncoderPinA); PinB = digitalRead(EncoderPinB); PinC = digitalRead(EncoderPinC); ESPLC_RotaryEncoder_Scroll(); ESPLC_RotaryEncoder_Click(); ESPLC_Display(); }
