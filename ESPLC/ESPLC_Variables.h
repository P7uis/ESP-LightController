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

// Piezo buzzer pin & channel
int BUZZER_PIN = 16;
int BUZZER_CHANNEL = 0;

// Lights on/off switch pin
int RLSwitchPin = 12;

// Lights on/off switch pin
int RLSwitch = HIGH;

// Lights on/off boolean
bool RLOnOff = false;
String RLState = "0";

// Indicator if screen has refreshed
bool LCDRefresh = true;

// Screen refresh rate (in ms)
const long RefreshInterval = 500; 

// Last moment that timer has "ticked"
unsigned long LastTick = 0;

// Click Lock
bool ClickLock = true;

String RLArray;
String RLDelay;