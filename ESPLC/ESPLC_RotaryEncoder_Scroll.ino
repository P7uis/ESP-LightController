void ESPLC_RotaryEncoder_Scroll()
{
  // Detect scrolling activity
  if ((PinALast == HIGH) && (PinA == LOW))
  {   
    // Scroll right
    if (PinB == LOW)
    {
      // Check if in main menu
      if(MenuIndex == 0){
        // Reset to 0 if already on the last one
        if(MainMenuPosition == MainMenuLength) MainMenuPosition = 0;
        else MainMenuPosition++; 
      }
      // Check if in roof light menu
      else if(MenuIndex == 1){
        // Reset to 0 if already on the last one
        if(RLMenuPosition == RLMenuLength) RLMenuPosition = 0;
        else RLMenuPosition++; 
      }
      // Check if in roof light static menu
      else if(MenuIndex == 11){
        // Reset to 0 if already on the last one
        if(RLStaticMenuPosition == RLStaticMenuLength) RLStaticMenuPosition = 0;
        else RLStaticMenuPosition++; 
      }
      // Check if in roof light left menu
      else if(MenuIndex == 12){
        // Reset to 0 if already on the last one
        if(RLLeftMenuPosition == RLLeftMenuLength) RLLeftMenuPosition = 0;
        else RLLeftMenuPosition++; 
      }
      // Check if in roof light Right menu
      else if(MenuIndex == 13){
        // Reset to 0 if already on the last one
        if(RLRightMenuPosition == RLRightMenuLength) RLRightMenuPosition = 0;
        else RLRightMenuPosition++; 
      }
      // Check if in roof light IO menu
      else if(MenuIndex == 14){
        // Reset to 0 if already on the last one
        if(RLIOMenuPosition == RLIOMenuLength) RLIOMenuPosition = 0;
        else RLIOMenuPosition++; 
      }
      // Check if in roof light OI menu
      else if(MenuIndex == 15){
        // Reset to 0 if already on the last one
        if(RLOIMenuPosition == RLOIMenuLength) RLOIMenuPosition = 0;
        else RLOIMenuPosition++; 
      }
      // Check if in underglow menu
      else if(MenuIndex == 2){
        // Reset to 0 if already on the last one
        if(UGMenuPosition == UGMenuLength) UGMenuPosition = 0;
        else UGMenuPosition++; 
      }
      // Check if in beacon menu
      else if(MenuIndex == 3){
        // Reset to 0 if already on the last one
        if(BeaconMenuPosition == BeaconMenuLength) BeaconMenuPosition = 0;
        else BeaconMenuPosition++; 
      }
      // Play a scroll right sound
      ESPLC_Buzzer(2);
    }
    // Scroll left
    else
    {
      // Check if in main menu
      if(MenuIndex == 0){
        // Reset to last if already on the first one
        if(MainMenuPosition == 0) MainMenuPosition = MainMenuLength;
        else MainMenuPosition--; 
      }
      // Check if in roof light menu
      if(MenuIndex == 1){
        // Reset to last if already on the first one
        if(RLMenuPosition == 0) RLMenuPosition = RLMenuLength;
        else RLMenuPosition--; 
      }
      // Check if in roof light static menu
      if(MenuIndex == 11){
        // Reset to last if already on the first one
        if(RLStaticMenuPosition == 0) RLStaticMenuPosition = RLStaticMenuLength;
        else RLStaticMenuPosition--; 
      }
      // Check if in roof light Left menu
      if(MenuIndex == 12){
        // Reset to last if already on the first one
        if(RLLeftMenuPosition == 0) RLLeftMenuPosition = RLLeftMenuLength;
        else RLLeftMenuPosition--; 
      }
      // Check if in roof light Right menu
      if(MenuIndex == 13){
        // Reset to last if already on the first one
        if(RLRightMenuPosition == 0) RLRightMenuPosition = RLRightMenuLength;
        else RLRightMenuPosition--; 
      }
      // Check if in roof light IO menu
      if(MenuIndex == 14){
        // Reset to last if already on the first one
        if(RLIOMenuPosition == 0) RLIOMenuPosition = RLIOMenuLength;
        else RLIOMenuPosition--; 
      }
      // Check if in roof light OI menu
      if(MenuIndex == 15){
        // Reset to last if already on the first one
        if(RLOIMenuPosition == 0) RLOIMenuPosition = RLOIMenuLength;
        else RLOIMenuPosition--; 
      }
      // Check if in underglow menu
      if(MenuIndex == 2){
        // Reset to last if already on the first one
        if(UGMenuPosition == 0) UGMenuPosition = UGMenuLength;
        else UGMenuPosition--; 
      }
      // Check if in beacon menu
      if(MenuIndex == 3){
        // Reset to last if already on the first one
        if(BeaconMenuPosition == 0) BeaconMenuPosition = BeaconMenuLength;
        else BeaconMenuPosition--; 
      }
      // Play a scroll left sound
      ESPLC_Buzzer(3);  
    }
    // Make sure the screen resets after these changes
    LCDRefresh = true;
  }
  PinALast = PinA;
}
