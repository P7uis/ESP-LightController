#include <ESP8266WiFi.h>
#include <espnow.h>


uint8_t UnderGlowMac[] = {0xDC, 0x4F, 0x22, 0x1C, 0x8D, 0x2C};

int state = 0;

//Structure example to send data
//Must match the receiver structure
typedef struct struct_message {
    int state;
} struct_message;

struct_message Message;

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0){
    Serial.println("Delivery success");
  }
  else{
    Serial.println("Delivery fail");
  }
}

void setup(){
    //Enable serial
    Serial.begin(115200);

    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
 
    // Init ESP-NOW
    if (esp_now_init() != 0) {
      Serial.println("Error initializing ESP-NOW");
      return;
    }
  
    // Set ESP-NOW Role
    esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

    // Once ESPNow is successfully Init, we will register for Send CB to
    // get the status of Trasnmitted packet
    esp_now_register_send_cb(OnDataSent);
    
    // Register peer
    esp_now_add_peer(UnderGlowMac, ESP_NOW_ROLE_COMBO, 1, NULL, 0);
}

void loop(){

  if(state == 3){
      state = 0;
    }
  
  Message.state = state;

  // Send message via ESP-NOW
  esp_now_send(UnderGlowMac, (uint8_t *) &Message, sizeof(Message));

  

  Serial.print("Sent state: ");
  Serial.println(Message.state);

  state++;

  delay(5000);

}
