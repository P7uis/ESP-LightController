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
    if (BeaconSwitch == LOW && BeaconOnOff == false)
    {

        BeaconOnOff = true;
    }
    // If switch is flipped off and current state is on, change the value to off and send it to the lightcontroller
    else if (BeaconSwitch == HIGH && BeaconOnOff == true)
    {

        BeaconOnOff = false;
    }
}
