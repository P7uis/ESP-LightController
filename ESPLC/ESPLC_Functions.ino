void SerialStructure() {

  // Send structure over serial
  RoofLightStructure.RLArray = RoofLights[RLMenuPosition][1];
  RoofLightStructure.RLDelay = RoofLights[RLMenuPosition][2];
  RoofLightStructure.RLState = RLState;
  unsigned long uBufSize = sizeof(RLStruct);
  char pBuffer[uBufSize];

  memcpy(pBuffer, &RoofLightStructure, uBufSize);
  for(int i = 0; i<uBufSize;i++) {
    Serial.print(pBuffer[i]);
  }
  Serial.println(); // Might need to delete this not sure

}