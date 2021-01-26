#include <ESP8266WiFi.h>
#include <espnow.h>

// Make the same structure to receive data
typedef struct ExtraStruct{
    int ExtraState;
  } ExtraStruct;

ExtraStruct ExtraStructure;

int State = 0;
int SwitchPin = 0;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&ExtraStructure, incomingData, sizeof(ExtraStructure));
  // DEBUG - Variable logging
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("State: ");
  Serial.println(ExtraStructure.ExtraState);

  // Turn of or on relay depending on state
  if (ExtraStructure.ExtraState == 1)
  {
      // Turn on relay
      digitalWrite(SwitchPin, LOW);
  }
  else{
      // Turn off relay
      digitalWrite(SwitchPin, HIGH);
  }
  
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  //DEBUG - enable onboard led to test without relays
  pinMode(SwitchPin, OUTPUT);
  digitalWrite(SwitchPin, HIGH);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  
}
