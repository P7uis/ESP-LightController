//Serial Reader variables and libraries
#include <SoftwareSerial.h>
SoftwareSerial link(2); // Rx

// Vars of incoming serial bytes
char cString[200];
byte chPos = 0;
byte ch = 0;
char dataStr[1];

// Standard var for looping through var
int i = 0;

// To prevent unnecessarily converting input bytes to variables if no new data has been received
bool updated = true;

// To prevent unlimited sending of "off" state
bool statelock = true;

// Variables of converted data
String CurrentInput;
String CurrentInputPrefix;
String RLArray;
int RLState;
int RLDelay;

String PrevCycle;

// Last moment that timer has "ticked"
unsigned long LastTick = 0;

// ESP-NOW variables and libraries
#include <ESP8266WiFi.h>
#include <espnow.h>

// Mac addresses of light relay modules
uint8_t ESPRelay1[] = {0x84, 0x0D, 0x8E, 0x97, 0x97, 0xDF};
uint8_t ESPRelay2[] = {0x84, 0x0D, 0x8E, 0x97, 0x97, 0xE0};
uint8_t ESPRelay3[] = {0x84, 0x0D, 0x8E, 0x97, 0x97, 0xE1};
uint8_t ESPRelay4[] = {0x84, 0x0D, 0x8E, 0x97, 0x98, 0x02};
uint8_t ESPRelay5[] = {0x84, 0x0D, 0x8E, 0x97, 0x98, 0x09};


// Make a structure to send data
typedef struct ESPRelayStructure {
  String ESPRelayArray;
} ESPRelayStructure;

ESPRelayStructure ESPRS;

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  char macStr[18];
  //Serial.print("Packet to:");
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
         mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  //Serial.print(macStr);
  //Serial.print(" send status: ");
  if (sendStatus == 0){
    //Serial.println("Delivery success");
  }
  else{
    //Serial.println("Delivery fail");
  }
}
  
void setup(){

    link.begin(115200); //setup software serial
    Serial.begin(74880);    //setup serial monitor

    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    // Init ESP-NOW
    if (esp_now_init() != 0) {
      //Serial.println("Error initializing ESP-NOW");
      return;
    }

     esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  
    // Once ESPNow is successfully Init, we will register for Send CB to
    // get the status of Trasnmitted packet
    esp_now_register_send_cb(OnDataSent);

    // Register peerS
    esp_now_add_peer(ESPRelay1, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
    esp_now_add_peer(ESPRelay2, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
    esp_now_add_peer(ESPRelay3, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
    esp_now_add_peer(ESPRelay4, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
    esp_now_add_peer(ESPRelay5, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}   

void loop(){    

   while(link.available())
   {
    //read incoming char by char:
     ch = link.read();
     cString[chPos] = ch;
     chPos++;     
     updated = true;
   }

   // If received incoming data, convert to needed variables
   if(updated){
     
      // Make sure to not run this every loop unless new data is received
      updated = false;

      // Terminate chararray, this is needed to convert to a string for some reason
      cString[chPos] = 0;
      chPos = 0;
      
      //Convert char array to string
      CurrentInput = String(cString);

      // get the first 5 chars to indicate which variable to convert
      CurrentInputPrefix = CurrentInput.substring(0,5);

      if(CurrentInputPrefix == "array"){
        RLArray = CurrentInput.substring(5);
        // Reset counter to loop through array when receiving a new array
        i = 0;
      }
      else if(CurrentInputPrefix == "delay"){
        RLDelay = CurrentInput.substring(5).toInt();
      }
      else if(CurrentInputPrefix == "state"){
        RLState = CurrentInput.substring(5).toInt();
      }


  /*    // DEBUG - print raw input
      Serial.println("----------------------------------------------------------------------");
      Serial.print("input raw: ");
      Serial.println(cString);
      Serial.println("----------------------------------------------------------------------");
      Serial.println("input converted: " + CurrentInput);
      Serial.println("----------------------------------------------------------------------");
      Serial.println("Current array variable: " + RLArray);
      Serial.println("----------------------------------------------------------------------");
      Serial.print("Current delay variable: ");
      Serial.println(RLDelay);
      Serial.println("----------------------------------------------------------------------");
      Serial.print("Current state variable: ");
      Serial.println(RLState);
      Serial.println("----------------------------------------------------------------------");
      */
   }



    
    // If state is on
    if(RLState != NULL && RLState == 1){

      // if switched on
      statelock = true;

      // if the variables are filled continue
      if(RLArray != NULL && RLDelay != NULL && RLState != NULL){

        // This is the replacement for the delay to possibly give a more consistent "in between time" of each cycle
        // If we were to simply put a delay, the rest of the program will add to that time aswell, now it wil just check if the total passed time equals or is longer than the delay variable
        if (millis() - LastTick >= RLDelay) {
            
            //TODO add lock for static input
            //if(RLArray.substring(i, i+5))

            // Update last tick moment
            LastTick = millis();

            // Reset array to 0 if at end of array minus 1 
            if(i >= RLArray.length()-6){i = 0;}

            // Send message via ESP-NOW
            ESPRS.ESPRelayArray = RLArray.substring(i, i+5);
            esp_now_send(0, (uint8_t *) &ESPRS, sizeof(ESPRS));
            
            // Go to next index of array
            i += 6;
        }
      }
      else{Serial.println("Input not complete");}
    }

    // If state is off
    else if(statelock){
      statelock = false;

      // Send message via ESP-NOW
      ESPRS.ESPRelayArray = "00000";
      esp_now_send(0, (uint8_t *) &ESPRS, sizeof(ESPRS));

      // DEBUG - log converted array in serial
      Serial.print("Array[x]: ");
      Serial.println(ESPRS.ESPRelayArray);
    }
  
    
}
