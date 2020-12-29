// Library - LCD with I2C module
#include <LiquidCrystal_I2C.h>

// Library - Piezo buzzer
#include <Tone32.h>

// Other tabs
#include "ESP_LightController_Variables.h"
#include "ESP_LightController_Buzzer.h"
#include "ESP_LightController_RotaryEncoder_Click.h"
#include "ESP_LightController_RotaryEncoder_Scroll.h"
#include "ESP_LightController_Menu_Variables.h"
#include "ESP_LightController_Menu_Walkthrough.h"

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup(){

    //Enable serial if debugging is on
    if(SerialDebug)Serial.begin (9600);

    // Initialize encode pins
    pinMode(EncoderPinA, INPUT_PULLUP);
    pinMode(EncoderPinB, INPUT_PULLUP);
    pinMode(EncoderPinC, INPUT_PULLUP);

    // Initialize the LCD
    lcd.init();

    // Turn on the LCD backlight                      
    lcd.backlight();

    // Play startup tune (if you haven't disabled the jingle and decided to add code more code in the setup make sure to keep this last as an indicator of complete startup)
    ESP_LightController_Buzzer(0);
}

void loop(){

    // This is a timer that refreshes the screen every x miliseconds
    if (millis() - LastTick >= RefreshInterval) {
        // Update last tick moment
        LastTick = millis();

        // Clear screen
        lcd.clear();
        // Tell other functions that screen has cleared
        LCDRefresh = true;
    }

    // Read rotary encoder input
    PinA = digitalRead(A0);
    PinB = digitalRead(A1);
    PinC = digitalRead(A2);

    // Scroll Actions
    FilamentCalculator_RotaryEncoderScroll();

    // Click Actions
    FilamentCalculator_RotaryEncoderClick();
  
    // Screen Output
    FilamentCalculator_MenuWalkthrough();
}