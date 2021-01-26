void ESPLC_Switches()
{
    
    // If switch is flipped on and current state is off, change the value to on and send it to the lightcontroller
    if (RLSwitch == LOW && RLOnOff == false)
    {

        RLOnOff = true;
        RLState = "1";

        // Send the state and array
        Serial.println("state" + RLState);
        delay(10); 
        Serial.println("array" + RLArray);
        delay(10); 
    }
    // If switch is flipped off and current state is on, change the value to off and send it to the lightcontroller
    else if (RLSwitch == HIGH && RLOnOff == true)
    {

        RLOnOff = false;
        RLState = "0";

        // Send just the state
        Serial.println("state" + RLState); 
        delay(10);
    }

    // If switch is flipped on and current state is off, change the value to on and send it to the lightcontroller
    if (BESwitch == LOW && BESwitchOnOff == false)
    {
        BESwitchOnOff = true;
        // Send data if option has already been sent
        if(BEInit){BeaconSender();}
    }
    // If switch is flipped off and current state is on, change the value to off and send it to the lightcontroller
    else if (BESwitch == HIGH && BESwitchOnOff == true)
    {
        BESwitchOnOff = false;
        if(BEInit){BeaconSender();}
    }

    // If switch is flipped on and current state is off, change the value to on and send it to the lightcontroller
    if (UGSwitch == LOW && UGOnOff == false)
    {
        UGOnOff = true;
        // TODO add underglow support
    }
    // If switch is flipped off and current state is on, change the value to off and send it to the lightcontroller
    else if (UGSwitch == HIGH && UGOnOff == true)
    {
        UGOnOff = false;
        // TODO add underglow support
    }
}
