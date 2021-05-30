//Datasheet for this TYWE3L board
//https://developer.tuya.com/en/docs/iot/wifie3lpinmodule?id=K9605uj1ar87n


//Red
const int rpin = 4;

//Green
const int gpin = 12;

//Blue
const int bpin = 14;

//White
const int wpin = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //RED
  pinMode(rpin, OUTPUT);

  //Green
  pinMode(gpin, OUTPUT);

  //Blue
  pinMode(bpin, OUTPUT);

  //White
  pinMode(wpin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //RED
  digitalWrite(rpin, HIGH);
  delay(1000);
  digitalWrite(rpin, LOW);

  //GREEN
  digitalWrite(gpin, HIGH);
  delay(1000);
  digitalWrite(gpin, LOW);

  //BLUE
  digitalWrite(bpin, HIGH);
  delay(1000);
  digitalWrite(bpin, LOW);

  //White
  digitalWrite(wpin, HIGH);
  delay(1000);
  digitalWrite(wpin, LOW);

  digitalWrite(rpin, HIGH);
  digitalWrite(gpin, HIGH);
  digitalWrite(bpin, HIGH);
  digitalWrite(wpin, HIGH);
  delay(10000);
  digitalWrite(rpin, LOW);
  digitalWrite(gpin, LOW);
  digitalWrite(bpin, LOW);
  digitalWrite(wpin, LOW);
  delay(5000);
  
}
