void SerialStructure() {

  // Send structure over serial

  Serial.println("array" + RLArray);
  delay(100);
  Serial.println("delay" + RLDelay);
  delay(100);
  Serial.println("state" + RLState); 

}
