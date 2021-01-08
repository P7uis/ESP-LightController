void SerialStructure() {

  // Send structure over serial
  RLArray = RoofLights[RLMenuPosition][1];
  RLDelay = RoofLights[RLMenuPosition][2];

  Serial.println("array" + RLArray);
  delay(100);
  Serial.println("delay" + RLDelay);
  delay(100);
  Serial.println("state" + RLState); 

}
