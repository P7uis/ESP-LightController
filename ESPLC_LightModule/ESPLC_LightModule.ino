#include <ESP8266WiFi.h>
#include <espnow.h>

// Make the same structure to receive data
typedef struct ESPRelayStructure {
  String ESPRelayArray;
} ESPRelayStructure;

ESPRelayStructure ESPRS;

int State = 0;
int SwitchPin = 0;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&ESPRS, incomingData, sizeof(ESPRS));
  // DEBUG - Variable logging
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("State: ");
  Serial.println(ESPRS.ESPRelayArray);

  // Get state of current light (need to adjust for every different module (0,1),(1,2),(2,3),(3,4),(4))
  State = ESPRS.ESPRelayArray.substring(0,1).toInt();
  if (State == 1)
  {
      //TODO Turn on relay (also still need to define relay pin)

      //DEBUG - turn on onboard led
      digitalWrite(SwitchPin, LOW);
  }
  else{
      //TODO Turn off relay (also still need to define relay pin)

      //DEBUG  - turn off onboard led
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
