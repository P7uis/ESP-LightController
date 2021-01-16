#include <Tone32.h>

// Piezo buzzer pin & channel
int BUZZER_PIN = 16;
int BUZZER_CHANNEL = 0;


#define N_D4  294
#define N_F4  349
#define N_G4  392
#define N_GS4 415
#define N_A4  440
#define N_D5  587


int const TEMPO = 1200;

int melody[] = {
  N_D4, N_D4, N_D5, N_A4, 0, N_GS4, N_G4, N_F4, N_D4, N_F4, N_G4};

int noteDurations[] = {
  16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16};

//melody = 266 notes

void setup() {
  int melody_len = sizeof(melody)/sizeof(melody[0]);

  for (int thisNote = 0; thisNote < melody_len; thisNote++) {
    int noteDuration = TEMPO / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration, BUZZER_CHANNEL);
    int pauseBetweenNotes = noteDuration * 1.45;
    delay(pauseBetweenNotes);
    noTone(BUZZER_PIN, BUZZER_CHANNEL);
    tone(BUZZER_PIN, NOTE_B6, 100, BUZZER_CHANNEL);
  }
}

void loop() {}
