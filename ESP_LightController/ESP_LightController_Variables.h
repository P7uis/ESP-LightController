// Toggle serial output for debugging
bool SerialDebug = true;

// Rotary endcoder pins
int EncoderPinA = 2;
int EncoderPinB = 4;
int EncoderPinC = 15;

// Rotary encoder pin states
int PinALast  = HIGH;
int PinA      = HIGH;
int PinB      = HIGH;
int PinC      = HIGH;

// Prevention for holding the click button
bool HoldLock = true;

// Prevention for scroll thing
bool ScrollLock = true;

// Roof light switch pin
int RoofLightSwitch = 12;

// Underglow switch pin
int UnderglowSwitch = 14;

// Piezo buzzer pin & channel
int BUZZER_PIN = 16;
int BUZZER_CHANNEL = 0;

// Screen refresh indicator
bool LCDRefresh = false;

// Screen refresh rate (in ms)
const long RefreshInterval = 500; 

// Last moment that timer has "ticked"
unsigned long LastTick = 0;

// Menu Walkthrough states
bool Screen_MainMenu          = true;
bool Screen_RoofLights        = false;
bool Screen_UnderGlow         = false;
bool Screen_Beacon            = false;
bool Screen_UNDEFIEND01       = false; //Rename this to something else later
bool Screen_UNDEFIEND02       = false; //Rename this to something else later

// Used for centering text
int StartPosition = 0;

// These are used to scroll through strings that are longer than the screen itself 
int CountCurrent = 0;
int CountNext = 0;
int CountPrevious = 0;
