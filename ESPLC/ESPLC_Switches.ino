void ESPLC_Switches(){
    // If switch is flipped on and current state is off, change the value to on and send it to the lightcontroller
    if(RLSwitch == LOW && RLOnOff == false){
        RLOnOff = true;
        // Send light off (t for true) signal through serial to light controller
        Serial.write('t');
    }
    // If switch is flipped off and current state is on, change the value to off and send it to the lightcontroller
    else if(RLSwitch == HIGH && RLOnOff == true){
        RLOnOff = false;
        // Send light off (f for false) signal through serial to light controller
        Serial.write('f');
    }
}