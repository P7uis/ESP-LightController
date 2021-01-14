void ESPLC_Switches()
{
    
    // If switch is flipped on and current state is off, change the value to on and send it to the lightcontroller
    if (RLSwitch == LOW && RLOnOff == false)
    {

        RLOnOff = true;
        RLState = "1";

        // Send just the state instead of all other variables, i wonder why i sent them all in the first place
        Serial.println("state" + RLState); 
    }
    // If switch is flipped off and current state is on, change the value to off and send it to the lightcontroller
    else if (RLSwitch == HIGH && RLOnOff == true)
    {

        RLOnOff = false;
        RLState = "0";

        // Send just the state 
        Serial.println("state" + RLState); 
    }
}
