// Make a data structure to send over serial or esp-now and then use memcpy to hopefully receive all data seperated into variables
typedef struct RLStruct {
  String RLArray;
  String RLDelay;
  int RLState;
} RLStruct;

RLStruct RoofLightStructure;

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);
    
}

void loop() {
  // Honestly don't know if this works but here's to hoping

  // Maybe add a var to lock updating while

  if (Serial1.available()) {
    delay(2000); //Wait 2 seconds to allow all serial data sent to be received together
    memcpy(&RoofLightStructure, Serial1.read(), sizeof(RoofLightStructure));// Does this work? idk
    String lightcycle[] = RoofLightStructure.RLArray.Split(",");// Does this work? idk
    Serial1.println(RoofLightStructure.RLArray);// Does this work? idk
    Serial1.println(RoofLightStructure.RLDelay);// Does this work? idk
    Serial1.println(RoofLightStructure.RLState);// Does this work? idk
  }
  
  
  for (int i=0; i<sizeof lightcycle/sizeof lightcycle[0]; i++) {
  {
    // Does this work? idk
    |Serial1.println(lightcycle[i]);
  }
  

}