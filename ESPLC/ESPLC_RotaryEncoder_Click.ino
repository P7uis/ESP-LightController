void ESPLC_RotaryEncoder_Click()
{
  // Check if button is pressed and click lock is true, this prevents constant clicking as long as the button is pressed, so you need to release it to click again
  if (ClickLock && PinC == LOW)
  {
    // Disable clicking until the button has been released
    ClickLock = false;

    // Check if in main menu
    if(MenuIndex == 0){
      // Set the menu index of the position of the main menu + 1 because 0 in main menu is roof lights but in index it is the main menu again
      MenuIndex = MainMenuPosition+1;
    }
    // Check if in roof light menu
    else if(MenuIndex == 1){
      // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (RLMenuPosition == RLMenuLength){
        MenuIndex = 0; 
        // Reset rooflight positions to 0 after switching menu
        RLMenuPosition = 0;
        }
      // If selected option is first index, move to static menu
      else if (RLMenuPosition == 0){MenuIndex = 11;}
      // If selected option is last index -4, move to Inside Out menu
      else if (RLMenuPosition == RLMenuLength-4){MenuIndex = 14;}
      // If selected option is last index -3, move to Outside In menu
      else if (RLMenuPosition == RLMenuLength-3){MenuIndex = 15;}
      // If selected option is last index -2, move to left menu
      else if (RLMenuPosition == RLMenuLength-2){MenuIndex = 12;}
      // If selected option is last index -1, move to right menu
      else if (RLMenuPosition == RLMenuLength-1){ MenuIndex = 13;}
      else{

        RLArray = RoofLights[RLMenuPosition][1];
        RLDelay = RoofLights[RLMenuPosition][2];
        // Send structure over serial
        SerialStructure();
        
      }     
    }
    // Check if in roof light static menu
    else if(MenuIndex == 11){
      
      // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (RLStaticMenuPosition == RLStaticMenuLength){
        MenuIndex = 1;
        // Reset position to 0 after switching menu
        RLStaticMenuPosition = 0;
      }
      else{
        
        RLArray = RLStatic[RLStaticMenuPosition][1];
        RLDelay = RLStatic[RLStaticMenuPosition][2];
        // Send structure over serial
        SerialStructure();

        // Reset static menu position
        RLStaticMenuPosition = 0;

        // Exit to Rooflight menu on send 
        MenuIndex = 1;
      }
    }
    // Check if in roof light Left menu
    else if(MenuIndex == 12){
      // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (RLLeftMenuPosition == RLLeftMenuLength){
        MenuIndex = 1;
        // Reset position to 0 after switching menu
        RLLeftMenuPosition = 0;
        }
      else{
        
        RLArray = RLLeft[RLLeftMenuPosition][1];
        RLDelay = RLLeft[RLLeftMenuPosition][2];
        // Send structure over serial
        SerialStructure();

        // Reset static menu position
        RLLeftMenuPosition = 0;

        // Exit to Rooflight menu on send 
        MenuIndex = 1;
        
      }     
    }
    // Check if in roof light Right menu
    else if(MenuIndex == 13){
      // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (RLRightMenuPosition == RLRightMenuLength){
        MenuIndex = 1;
        // Reset position to 0 after switching menu
        RLRightMenuPosition = 0;
        }
      else{
        
        RLArray = RLRight[RLRightMenuPosition][1];
        RLDelay = RLRight[RLRightMenuPosition][2];
        // Send structure over serial
        SerialStructure();

        // Reset static menu position
        RLRightMenuPosition = 0;

        // Exit to Rooflight menu on send 
        MenuIndex = 1;
        
      }     
    }
    // Check if in roof light IO menu
    else if(MenuIndex == 14){
      // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (RLIOMenuPosition == RLIOMenuLength){
        MenuIndex = 1;
        // Reset position to 0 after switching menu
        RLIOMenuPosition = 0;
        }
      else{
        
        RLArray = RLIO[RLIOMenuPosition][1];
        RLDelay = RLIO[RLIOMenuPosition][2];
        // Send structure over serial
        SerialStructure();

        // Reset static menu position
        RLIOMenuPosition = 0;

        // Exit to Rooflight menu on send 
        MenuIndex = 1;
        
      }     
    }
    // Check if in roof light OI menu
    else if(MenuIndex == 15){
      // If the selected option is the last one it will return to the main menu (assuming the "BACK" option is always last)
      if (RLOIMenuPosition == RLOIMenuLength){
        MenuIndex = 1;
        // Reset position to 0 after switching menu
        RLOIMenuPosition = 0;
        }
      else{
        
        RLArray = RLOI[RLOIMenuPosition][1];
        RLDelay = RLOI[RLOIMenuPosition][2];
        // Send structure over serial
        SerialStructure();

        // Reset static menu position
        RLOIMenuPosition = 0;

        // Exit to Rooflight menu on send 
        MenuIndex = 1;
        
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
        BeaconSender(BeaconMenuPosition);
      }
    }
    // Play a click sound
    ESPLC_Buzzer(1);
  }
  // If the clicklock is false and the button is not pressed it will reset the lock so you can continue clicking!
  else if(!ClickLock && PinC == HIGH) ClickLock = true;
}
