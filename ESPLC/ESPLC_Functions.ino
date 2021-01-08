void SerialStructure() {

  // Send structure over serial
  RLArray = RoofLights[RLMenuPosition][1];
  RLDelay = RoofLights[RLMenuPosition][2];

  Serial.println("array" + RLArray);
  delay(20);
  Serial.println("delay" + RLDelay);
  delay(20);
  Serial.println("state" + RLState); 

}