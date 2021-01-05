// Library - LCD with I2C module
#include <LiquidCrystal_I2C.h>

// Library - Piezo buzzer
#include <Tone32.h>

// Library - ESP NOW
#include <esp_now.h>

// Library - WiFi
#include <WiFi.h>

// Variables
#include "ESPLC_Variables.h"
#include "ESPLC_Variables_menu.h"

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, 16, 2);  

/*
// Make a seperate task on core 2 for the loop that controlls the lights
TaskHandle_t RoofLightsTask;

void RoofLightsLoop( void * pvParameters ){

  for(;;){
    Serial.println("ff testen rooflightloop");
    Serial.println(xPortGetCoreID());
      //TODO something something
  }
}
*/


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

/*
     xTaskCreatePinnedToCore(
                    RoofLightsLoop,   //Task function.
                    "RoofLightsLoop",     //name of task.
                    10000,       // Stack size of task
                    NULL,        // parameter of the task
                    1,           // priority of the task
                    &RoofLightsTask,      // Task handle to keep track of created task 
                    0);          // pin task to core 0
*/
    // Play startup tune (if you haven't disabled the jingle and decided to add code more code in the setup make sure to keep this last as an indicator of complete startup)
    ESPLC_Buzzer(0);

}

void loop(){

    if(SerialDebug){
        Serial.print("MenuPos: ");
        Serial.println(MainMenuPosition);
        Serial.print("MenuOption: ");
        Serial.println(MainMenuOptions[MainMenuPosition]);
        Serial.print("Screen refreshed: ");
        Serial.println(LCDRefresh);
        
        Serial.println("ff testen normalloop");
        Serial.println(xPortGetCoreID());
    }

    // This is a timer that refreshes the screen every x miliseconds
    if (millis() - LastTick >= RefreshInterval) {
        // Update last tick moment
        LastTick = millis();

        // Tell other functions that screen has cleared
        LCDRefresh = true;
    }

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
