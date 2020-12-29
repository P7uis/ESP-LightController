#include <Tone32.h>

#define BUZZER_PIN 16
#define BUZZER_CHANNEL 0

void setup() {
  
  //STARTUP TONE
  tone(BUZZER_PIN, NOTE_D6, 100, BUZZER_CHANNEL);
  noTone(BUZZER_PIN, BUZZER_CHANNEL);
  delay(10);
  tone(BUZZER_PIN, NOTE_C6, 100, BUZZER_CHANNEL);
  noTone(BUZZER_PIN, BUZZER_CHANNEL);
  delay(20);
  tone(BUZZER_PIN, NOTE_B6, 100, BUZZER_CHANNEL);
  noTone(BUZZER_PIN, BUZZER_CHANNEL);
  delay(200);
  
  }

void loop() {

  //BUTTON CLICK tone
  tone(BUZZER_PIN, NOTE_D6, 100, BUZZER_CHANNEL);
  noTone(BUZZER_PIN, BUZZER_CHANNEL);

  delay(5000);

  
  
  }
