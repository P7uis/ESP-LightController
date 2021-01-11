void ESPLC_Switches(){
    // If switch is flipped on and current state is off, change the value to on and send it to the lightcontroller
    if(RLSwitch == LOW && RLOnOff == false){
        RLOnOff = true;
        RLState = "1";
        RLArray = RoofLights[RLMenuPosition][1];
        RLDelay = RoofLights[RLMenuPosition][2];

        // Send structure over serial
        SerialStructure();
    }
    // If switch is flipped off and current state is on, change the value to off and send it to the lightcontroller
    else if(RLSwitch == HIGH && RLOnOff == true){
        RLOnOff = false;
        RLState = "0";
        RLArray = "00000";
        RLDelay = "00000";

        // Send structure over serial
        SerialStructure();
    }
}
