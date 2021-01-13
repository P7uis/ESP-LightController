void ESPLC_RotaryEncoder_Click()
{
  // Check if button is pressed and click lock is true, this prevents constant clicking as long as the button is pressed, so you need to release it to click again
  if (ClickLock && PinC == LOW)
  {
    // Disable clicking until the button has been released
    ClickLock = false;

    //DEBUG - check if cliced
    //Serial.println("DEBUG: Button clicked");

    // Check if in main menu
    if(MenuIndex == 0){
      // Set the menu index of the position of the main menu + 1 because 0 in main menu is roof lights but in index it is the main menu again
      MenuIndex = MainMenuPosition+1;
      // Reset position to 0 after switching menu
      MainMenuPosition = 0;
    }
    // Check if in roof light menu
    else if(MenuIndex == 1){
      // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (RLMenuPosition == RLMenuLength){
        MenuIndex = 0; 
        Serial.print("Clicked on back should be 9 - "); 
        Serial.println(RLMenuPosition);
        Seriial.print("Should set menu index to 0 - ");
        Serial.println(MenuIndex);
        // Reset position to 0 after switching menu
        RLMenuPosition = 0;
        }
      // If selected option is first index, move to static menu
      else if (RLMenuPosition == 0){
        MenuIndex = 11; 
        Serial.print("Clicked on static should be 0 - "); 
        Serial.println(RLMenuPosition);
        Seriial.print("Should set menu index to 11 - ");
        Serial.println(MenuIndex);
        // Reset position to 0 after switching menu
        RLMenuPosition = 0;
        }
      // If selected option is first index, move to left menu
      else if (RLMenuPosition == RLMenuLength-2){
        MenuIndex = 12; 
        Serial.print("Clicked on left should be 7 - "); 
        Serial.println(RLMenuPosition);
        Seriial.print("Should set menu index to 12 - ");
        Serial.println(MenuIndex);
        // Reset position to 0 after switching menu
        RLMenuPosition = 0;
        }
      // If selected option is first index, move to right menu
      else if (RLMenuPosition == RLMenuLength-1){
        MenuIndex = 13; 
        Serial.print("Clicked on right should be 8 - "); 
        Serial.println(RLMenuPosition);
        Seriial.print("Should set menu index to 13 - ");
        Serial.println(MenuIndex);
        // Reset position to 0 after switching menu
        RLMenuPosition = 0;
        }
      else{
        
        Serial.print("Clicked other position, should be an individual array to send - "); 
        Serial.println(RLMenuPosition);

        RLInitialized = true;
        RLStaticInitialized = false;
        RLLeftInitialized = false;
        RLRightInitialized = false;

        RLArray = RoofLights[RLMenuPosition][1];
        RLDelay = RoofLights[RLMenuPosition][2];
        // Send structure over serial
        SerialStructure();
        
      }     
    }
    // Check if in roof light static menu
    else if(MenuIndex == 11){
      // If the selected option is the last one it will return to the RL menu (assuming the "BACK" option is always last)
      if (RLStaticMenuPosition == RLStaticMenuLength){
        MenuIndex = 1;
        // Reset position to 0 after switching menu
        RLStaticMenuPosition = 0;
        }
      else{
        
        RLInitialized = false;
        RLStaticInitialized = true;
        RLLeftInitialized = false;
        RLRightInitialized = false;
        RLArray = RLStatic[RLStaticMenuPosition][1];
        RLDelay = RLStatic[RLStaticMenuPosition][2];
        // Send structure over serial
        SerialStructure();
        
      }     
    }
    // Check if in roof light Left menu
    else if(MenuIndex == 12){
      // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (RLLeftMenuPosition == RLLeftMenuLength){
        MenuIndex = 0;
        // Reset position to 0 after switching menu
        RLLeftMenuPosition = 0;}
      else{
        
        RLInitialized = false;
        RLStaticInitialized = false;
        RLLeftInitialized = true;
        RLRightInitialized = false;
        RLArray = RLLeft[RLLeftMenuPosition][1];
        RLDelay = RLLeft[RLLeftMenuPosition][2];
        // Send structure over serial
        SerialStructure();
        
      }     
    }
    // Check if in roof light Right menu
    else if(MenuIndex == 13){
      // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (RLRightMenuPosition == RLRightMenuLength){
        MenuIndex = 0;
        // Reset position to 0 after switching menu
        RLRightMenuPosition = 0;
        }
      else{
        
        RLInitialized = false;
        RLStaticInitialized = false;
        RLLeftInitialized = false;
        RLRightInitialized = true;
        RLArray = RLRight[RLRightMenuPosition][1];
        RLDelay = RLRight[RLRightMenuPosition][2];
        // Send structure over serial
        SerialStructure();
        
      }     
    }
    // Check if in underglow menu
    else if(MenuIndex == 2){
       // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (UGMenuPosition == UGMenuLength){
        MenuIndex = 0;
        // Reset position to 0 after switching menu
        UGMenuPosition = 0;
      }
      else{
        // Loop through the other options
        switch (UGMenuPosition) {
          case 1:
            // TODO preset 1
            break;
          case 2:
            // TODO preset 2 etc...
            break;
        }
      }
    }
    // Check if in beacon menu
    else if(MenuIndex == 3){
      // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (BeaconMenuPosition == BeaconMenuLength){
        MenuIndex = 0;
        // Reset position to 0 after switching menu
        BeaconMenuPosition = 0;
      }
      else{
        // Loop through the other options
        switch (BeaconMenuPosition) {
          case 1:
            // TODO ON
            break;
          case 2:
            // TODO OFF
            break;
        }
      }
    }
    // Play a click sound
    ESPLC_Buzzer(1);
  }
  // If the clicklock is false and the button is not pressed it will reset the lock so you can continue clicking!
  else if(!ClickLock && PinC == HIGH) ClickLock = true;
}
