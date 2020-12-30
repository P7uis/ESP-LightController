// Library - LCD with I2C module
#include <LiquidCrystal_I2C.h>

// Library - Piezo buzzer
#include <Tone32.h>

// Variables
#include "ESPLC_Variables.h"
#include "ESPLC_Variables_menu.h"

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup(){

    // Initialize encode pins
    pinMode(EncoderPinA, INPUT_PULLUP);
    pinMode(EncoderPinB, INPUT_PULLUP);
    pinMode(EncoderPinC, INPUT_PULLUP);

    // Initialize the LCD
    lcd.init();

    // Turn on the LCD backlight                      
    lcd.backlight();

    // Play startup tune (if you haven't disabled the jingle and decided to add code more code in the setup make sure to keep this last as an indicator of complete startup)
    ESPLC_Buzzer(0);
}

void loop(){

    // Read rotary encoder input
    PinA = digitalRead(EncoderPinA);
    PinB = digitalRead(EncoderPinB);
    PinC = digitalRead(EncoderPinC);

     // Scroll actions
    ESPLC_RotaryEncoder_Scroll();

    // Click actions
    ESPLC_RotaryEncoder_Click();

    // Show menu on display
    ESPLC_Display();
}
