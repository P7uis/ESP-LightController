void ESP_LightController_Buzzer(int BuzzerTune){
  // Startup tune
  if(BuzzerTune == 0){
        tone(BUZZER_PIN, NOTE_D6, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        delay(10);
        tone(BUZZER_PIN, NOTE_C6, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        delay(20);
        tone(BUZZER_PIN, NOTE_B6, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
  }
  // Button click sound
  else if(BuzzerTune == 1){
        tone(BUZZER_PIN, NOTE_E6, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
  }
  // Button scroll right sound
  // <------------------------------------------------------------------------------------------[TODO]-----[Change sound because i don't know the sounds iself]-----------
  else if(BuzzerTune == 2){
        tone(BUZZER_PIN, NOTE_D4, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
  }
  // Button scroll leftsound
  // <------------------------------------------------------------------------------------------[TODO]-----[Change sound because i don't know the sounds iself]-----------
  else if(BuzzerTune == 3){
        tone(BUZZER_PIN, NOTE_C4, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
  }
}
