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

// Lights on/off 
int RLSwitchPin = 14;
int RLSwitch = HIGH;
bool RLOnOff = false;
String RLState = "0";

// Beacon on/off  pin
int BeaconSwitchPin = 12;
int BeaconSwitch = HIGH;
bool BeaconOnOff = false;
String BeaconState = "0";

// Under Glow on/off
int UGSwitchPin = 27;
int UGSwitch = HIGH;
bool UGOnOff = false;
String UGState = "0";

// Indicator if screen has refreshed
bool LCDRefresh = true;

// Screen refresh rate (in ms)
const long RefreshInterval = 500; 

// Last moment that timer has "ticked"
unsigned long LastTick = 0;

// Click Lock
bool ClickLock = true;

