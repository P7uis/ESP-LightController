void SerialStructure()
{

  // Send structure over serial

  Serial.println("array" + RLArray);
  delay(20);
  Serial.println("delay" + RLDelay);
  delay(20);
  Serial.println("state" + RLState);
}

void BeaconSender()
{

  typedef struct BeaconStruct
  {
    int BeaconState;
  } BeaconStruct;

  BeaconStruct BeaconStructure;
  // Check if main switch is off, this overwrites the menu selections
  if (!BESwitchOnOff)
  {
    BeaconStructure.BeaconState = 0;
    esp_err_t BeaconSend = esp_now_send(BeaconMac, (uint8_t *)&BeaconStructure, sizeof(BeaconStruct));
    esp_err_t ExtraSend = esp_now_send(ExtraMac, (uint8_t *)&BeaconStructure, sizeof(BeaconStruct));
  }
  else
  {
    // Check if need to enable/disable the beacon
    if (BeaconOnOff)
    {
      BeaconStructure.BeaconState = 1;
      esp_err_t BeaconSend = esp_now_send(BeaconMac, (uint8_t *)&BeaconStructure, sizeof(BeaconStruct));
    }
    else
    {
      BeaconStructure.BeaconState = 0;
      esp_err_t BeaconSend = esp_now_send(BeaconMac, (uint8_t *)&BeaconStructure, sizeof(BeaconStruct));
    }
    // Check if need to enable/disable the extra relay
    if (ExtraOnOff)
    {
      BeaconStructure.BeaconState = 1;
      esp_err_t ExtraSend = esp_now_send(ExtraMac, (uint8_t *)&BeaconStructure, sizeof(BeaconStruct));
    }
    else
    {
      BeaconStructure.BeaconState = 0;
      esp_err_t ExtraSend = esp_now_send(ExtraMac, (uint8_t *)&BeaconStructure, sizeof(BeaconStruct));
    }
  }
  delay(20);
}

void UGSender()
{

  typedef struct UGStruct
  {
    int UGState;
  } UGStruct;

  UGStruct UnderGlowStructure;
  // Check if main switch is off, this overwrites the menu selections
  if (!UGOnOff)
  {
    UnderGlowStructure.UGState = 999;
    esp_err_t BeaconSend = esp_now_send(UnderGlowMac, (uint8_t *)&UnderGlowStructure, sizeof(UGStruct));
  }
  else
  {
     if (UGMenuLength -1 == UGMenuPosition){
      UnderGlowStructure.UGState = 999;
     }
     else{
      UnderGlowStructure.UGState = UGMenuPosition;}
      esp_err_t BeaconSend = esp_now_send(UnderGlowMac, (uint8_t *)&UnderGlowStructure, sizeof(UGStruct));
  }
  
  delay(20);
}

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
  char macStr[18];
  Serial.print("Packet to: ");
  // Copies the sender mac address to a string
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(macStr);
  Serial.print(" send status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
