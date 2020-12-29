// Library - LCD with I2C module
#include <LiquidCrystal_I2C.h>

// Library - Piezo buzzer
#include <Tone32.h>

// Other tabs
#include "ESP_LightController_Variables.h"
#include "ESP_LightController_Menu_Variables.h"

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup(){

    //Enable serial if debugging is on
    if(SerialDebug)Serial.begin(115200);

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
    PinA = digitalRead(EncoderPinA);
    PinB = digitalRead(EncoderPinB);
    PinC = digitalRead(EncoderPinC);

     // Scroll Actions
    ESP_LightController_RotaryEncoder_Scroll();

    // Click Actions
    ESP_LightController_RotaryEncoder_Click();
  
    // Screen Output
    ESP_LightController_Menu_Walkthrough();

    if(SerialDebug){
        Serial.print("[");
        Serial.print(MainMenuPosition);
        Serial.print("]Selection: ");
        Serial.println(MainMenuOption);
        Serial.print("Pin A: ");
        Serial.println(PinA);
        Serial.print("Pin A Last: ");
        Serial.println(PinALast);
        Serial.print("Pin B: ");
        Serial.println(PinB);
        Serial.print("Pin C: ");
        Serial.println(PinC);
        if((PinALast == HIGH) && (PinA == LOW)){if (PinB == LOW){Serial.println("Right")}else{Serial.println("Left")}}else{Serial.println("None")}

      }
}
