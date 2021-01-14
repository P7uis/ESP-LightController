void SerialStructure() {

  // Send structure over serial

  Serial.println("array" + RLArray);
  delay(100);
  Serial.println("delay" + RLDelay);
  delay(100);
  Serial.println("state" + RLState); 

}

void BeaconSender(int Beacon){

  typedef struct BeaconStruct {
    int BeaconState;
  } BeaconStruct;

  BeaconStruct BeaconStructure;
  BeaconStructure.BeaconState = Beacon;
  
  if (Beacon == 0){esp_err_t result = esp_now_send(0, (BeaconMac) &BeaconStructure, sizeof(BeaconStruct));}
  else if (Beacon == 1){esp_err_t result = esp_now_send(0, (ExtraMac) &BeaconStructure, sizeof(BeaconStruct));}
  
  
  
  
}

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char macStr[18];
  Serial.print("Packet to: ");
  // Copies the sender mac address to a string
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(macStr);
  Serial.print(" send status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
