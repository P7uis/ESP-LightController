#include <ESP8266WiFi.h>
#include <espnow.h>

// REPLACE WITH THE MAC Address of your receiver 
uint8_t Light1[] = {0x2C, 0xF4, 0xF32, 0x6, 0xD4, 0x41};
uint8_t Light2[] = {0xBC, 0xDD, 0xC2, 0x51, 0xE5, 0xE6};

// Updates DHT readings every 10 seconds
long interval; 
long currentMillis;
long previousMillis = 0;
long RGBold[] = {random(0,256),random(0,256),random(0,256)};
long RGBnew[] = {random(0,256),random(0,256),random(0,256)};
int state = 0;
int step = 5;

//Structure example to send data
//Must match the receiver structure
typedef struct struct_message {
    int state;
} struct_message;

typedef struct struct_rgbw {
    int R;
    int G;
    int B;
    int W;
} struct_rgbw;

struct_rgbw RGBW;

struct_message incomingReadings;

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  //Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0){
    //Serial.println("Delivery success");
  }
  else{
    //Serial.println("Delivery fail");
  }
}

// Callback when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&incomingReadings, incomingData, sizeof(incomingReadings));
  //Serial.print("Bytes received: ");
  //Serial.println(len);
  state = incomingReadings.state;
}
 
void setup() {
  // Init Serial Monitor
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
  esp_now_add_peer(Light1, ESP_NOW_ROLE_COMBO, 1, NULL, 0);
  esp_now_add_peer(Light2, ESP_NOW_ROLE_COMBO, 1, NULL, 0);
  
  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {
  /*if(state == 1){ */
    currentMillis = millis();
    if (currentMillis - previousMillis >= 100) {
      previousMillis = currentMillis;
      if(RGBold[0]+step >= RGBnew[0] && RGBold[1]+step >= RGBnew[1] && RGBold[2]+step >= RGBnew[2]){
          RGBnew[0] = random(0,250);
          RGBnew[1] = random(0,250);
          RGBnew[2] = random(0,250);
          Serial.println("----------------------------------------SWITCH-------------");
      }
        if(RGBold[0] < RGBnew[0]){RGBold[0] += step;}
        else{RGBold[0] -= step;}

        if(RGBold[1] < RGBnew[1]){RGBold[1] += step;}
        else{RGBold[1] -= step;}

        if(RGBold[2] < RGBnew[2]){RGBold[2] += step;}
        else{RGBold[2] -= step;}
 
      RGBW.R = RGBold[0];
      RGBW.G = RGBold[1];
      RGBW.B = RGBold[2];
      RGBW.W = 0;
      
      
          Serial.print("old ");
          Serial.print(RGBold[0]);
          Serial.print(" ");
          Serial.print(RGBold[1]);
          Serial.print(" ");
          Serial.println(RGBold[2]);
          Serial.print("new ");
          Serial.print(RGBnew[0]);
          Serial.print(" ");
          Serial.print(RGBnew[1]);
          Serial.print(" ");
          Serial.println(RGBnew[2]);
          /*
      Serial.print("R: ");
      Serial.println(RGBW.R);
      
      Serial.print("G: ");
      Serial.println(RGBW.G);
      
      Serial.print("B: ");
      Serial.println(RGBW.B);
      
      Serial.print("W: ");
      Serial.println(RGBW.W);*/
      esp_now_send(Light1, (uint8_t *) &RGBW, sizeof(RGBW));
      esp_now_send(Light2, (uint8_t *) &RGBW, sizeof(RGBW));
    }
  //}
  /*  
  else{
    interval = 1000; 
    currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      Serial.println("State off");
      RGBW.R = 0;
      RGBW.G = 0;
      RGBW.B = 0;
      RGBW.W = 0;
      Serial.print("R: ");
      Serial.println(RGBW.R);
      
      Serial.print("G: ");
      Serial.println(RGBW.G);
      
      Serial.print("B: ");
      Serial.println(RGBW.B);
      
      Serial.print("W: ");
      Serial.println(RGBW.W);
      esp_now_send(Light1, (uint8_t *) &RGBW, sizeof(RGBW));
      esp_now_send(Light2, (uint8_t *) &RGBW, sizeof(RGBW));
    }
  }*/
}
