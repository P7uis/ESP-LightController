void ESPLC_Switches(){
    // If switch is flipped on and current state is off, change the value to on and send it to the lightcontroller
    if(RLSwitch == LOW && RLOnOff == false){
        
        RLOnOff = true;
        RLState = "1";

        if (RLInitialized)
        {
            RLArray = RoofLights[RLMenuPosition][1];
            RLDelay = RoofLights[RLMenuPosition][2];
        }
        else if (RLStaticInitialized)
        {
            RLArray = RLStatic[RLStaticMenuPosition][1];
            RLDelay = RLStatic[RLStaticMenuPosition][2];
        }
        else if (RLLeftInitialized)
        {
            RLArray = RLLeft[RLLeftMenuPosition][1];
            RLDelay = RLLeft[RLLeftMenuPosition][2];
        }
        else if (RLRightInitialized)
        {
            RLArray = RLRight[RLRightMenuPosition][1];
            RLDelay = RLRight[RLRightMenuPosition][2];
        }
        else{
            RLArray = "00000";
            RLDelay = "00000";

        }     

        // Send structure over serial
        SerialStructure();
    }
    // If switch is flipped off and current state is on, change the value to off and send it to the lightcontroller
    else if(RLSwitch == HIGH && RLOnOff == true){
        
        RLOnOff = false;
        RLState = "0";

        if (RLInitialized)
        {
            RLArray = RoofLights[RLMenuPosition][1];
            RLDelay = RoofLights[RLMenuPosition][2];
        }
        else if (RLStaticInitialized)
        {
            RLArray = RLStatic[RLStaticMenuPosition][1];
            RLDelay = RLStatic[RLStaticMenuPosition][2];
        }
        else if (RLLeftInitialized)
        {
            RLArray = RLLeft[RLLeftMenuPosition][1];
            RLDelay = RLLeft[RLLeftMenuPosition][2];
        }
        else if (RLRightInitialized)
        {
            RLArray = RLRight[RLRightMenuPosition][1];
            RLDelay = RLRight[RLRightMenuPosition][2];
        }
        else{
            RLArray = "00000";
            RLDelay = "00000";

        }

        // Send structure over serial
        SerialStructure();
    }
}
