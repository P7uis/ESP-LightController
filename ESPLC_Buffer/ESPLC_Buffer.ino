//Receiver Code

char str[4];

void setup() {
    Serial.begin(115200);
}

void loop() {
  int i=0;

  if (Serial1.available()) {
    delay(100); //allows all serial sent to be received together
    while(Serial1.available() && i<4) {
      str[i++] = Serial1.read();
    }
    str[i++]='\0';
  }

  if(i>0) {
    Serial.println(str,4);
  }
}