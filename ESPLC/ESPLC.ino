// Library - LCD with I2C module
#include <LiquidCrystal_I2C.h>

// Library - Piezo buzzer
#include <Tone32.h>

// Library - ESP NOW
#include <esp_now.h>

// Library - WiFi
#include <WiFi.h>

// Neopixel library for the 1st led
#include <Adafruit_NeoPixel.h>

// Variables
#include "ESPLC_Variables.h"
#include "ESPLC_Variables_Menu.h"

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, 16, 2);  

// Mac adresses of beacon, extra relay and the undergrow
uint8_t BeaconMac[] = {0xDC, 0x4F, 0x22, 0x58, 0x68, 0x36};
uint8_t ExtraMac[] = {0x84, 0x0D, 0x8E, 0x97, 0x97, 0xFC};
//uint8_t UnderGlowMac[] = {0xB4, 0xE6, 0x2D, 0x97, 0x62, 0x1D};
uint8_t UnderGlowMac[] = {0xDC, 0x4F, 0x22, 0x1C, 0x8D, 0x2C};

void setup(){

    //Enable serial
    Serial.begin(115200);
    
    // Initialize encoder pins
    pinMode(EncoderPinA, INPUT_PULLUP);
    pinMode(EncoderPinB, INPUT_PULLUP);
    pinMode(EncoderPinC, INPUT_PULLUP);

    //Initialize switch pins
    pinMode(RLSwitchPin, INPUT_PULLUP);
    pinMode(BESwitchPin, INPUT_PULLUP);
    pinMode(UGSwitchPin, INPUT_PULLUP);

    // Initialize the LCD
    lcd.init();

    // Turn on the LCD backlight                      
    lcd.backlight();

    WiFi.mode(WIFI_STA);
 
    if (esp_now_init() != ESP_OK) {
        //Serial.println("Error initializing ESP-NOW");
        return;
    }
    
    esp_now_register_send_cb(OnDataSent);
    
    // register peer
    esp_now_peer_info_t peerInfo;
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    // register first peer
    memcpy(peerInfo.peer_addr, BeaconMac, 6);
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        //Serial.println("Failed to add peer");
        return;
    }
    // register second peer
    memcpy(peerInfo.peer_addr, ExtraMac, 6);
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        //Serial.println("Failed to add peer");
        return;
    }
    /// register third peer
    memcpy(peerInfo.peer_addr, UnderGlowMac, 6);
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        //Serial.println("Failed to add peer");
        return;
    }

    ESPLC_LED_SETUP();

    // Play startup tune (if you haven't disabled the jingle and decided to add code more code in the setup make sure to keep this last as an indicator of complete startup)
    ESPLC_Buzzer(0);

}
void loop(){

    // This is a timer that refreshes the screen every x miliseconds
    if (millis() - LastTick >= RefreshInterval) {
        // Update last tick moment
        LastTick = millis();
        // Tell other functions that screen has cleared
        LCDRefresh = true;
    }

    // Read pin input
    PinA = digitalRead(EncoderPinA);
    PinB = digitalRead(EncoderPinB);
    PinC = digitalRead(EncoderPinC);
    RLSwitch = digitalRead(RLSwitchPin);
    BESwitch = digitalRead(BESwitchPin);
    UGSwitch = digitalRead(UGSwitchPin);

    // Switch actions
    ESPLC_Switches();

    // Scroll actions
    ESPLC_RotaryEncoder_Scroll();

    // Click actions
    ESPLC_RotaryEncoder_Click();

    // Show menu on display
    ESPLC_Display();

}
