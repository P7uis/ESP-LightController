#include <ESP8266WiFi.h>
#include <espnow.h>

typedef struct struct_rgbw {
    int R;
    int G;
    int B;
    int W;
} struct_rgbw;

//Red
const int rpin = 4;

//Green
const int gpin = 12;

//Blue
const int bpin = 14;

//White
const int wpin = 13;

struct_rgbw RGBW;

// Callback when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&RGBW, incomingData, sizeof(RGBW));
}
 
void setup() {

  //initialize digital pin LED_BUILTIN as an output.
  //RED
  pinMode(rpin, OUTPUT);

  //Green
  pinMode(gpin, OUTPUT);

  //Blue
  pinMode(bpin, OUTPUT);

  //White
  pinMode(wpin, OUTPUT);
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    //Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Set ESP-NOW Role
  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);
  
  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {
}
