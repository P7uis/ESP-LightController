// Make a data structure to send over serial or esp-now and then use memcpy to hopefully receive all data seperated into variables
typedef struct RLStruct {
  String RLArray;
  String RLDelay;
  int RLState;
} RLStruct;

RLStruct RoofLightStructure;

byte input[sizeof(RoofLightStructure)];

int i = 0;

int RLArrayLen = 0;

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);
    
}

void loop() {
  // Honestly don't know if this works but here's to hoping

  // If receiving data
  if (Serial.available()) {
    delay(2000); //Wait 2 seconds to allow all serial data sent to be received together
    while (Serial.available())
    {
      input[i] == Serial.read(); //convert all bytes into an array? idk honestly
      i++;
    }

    // convert the bytes which should be the same as the structure rooflightstructure to that, idk how it works or even if it works
    memcpy(&RoofLightStructure, input, sizeof(RoofLightStructure));
    
    Serial1.println("Printing received data converted");
    Serial1.println(RoofLightStructure.RLArray);// Does this work? idk
    Serial1.println(RoofLightStructure.RLDelay);// Does this work? idk
    Serial1.println(RoofLightStructure.RLState);// Does this work? idk

    // Set var to length of array string to loop through it every 6 indexes (01010,)
    RLArrayLen = RoofLightStructure.RLArray.length();    
  }
  if(i >= RLArrayLen){i = 0;}
  Serial1.println(RoofLightStructure.RLArray.substring(i, i+5));
  i += 6;
  delay(RoofLightStructure.RLDelay.toInt());
}
