void ESPLC_Display()
{
  if(LCDRefresh){
    // Reset screen if indicated to
    lcd.clear();
    
    // Check if in main menu
    if (MenuIndex == 0)
    {
      // Define previous and next items indexes and reset if needed
      SelectionPrevious = MainMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = MainMenuLength;
      SelectionNext = MainMenuPosition + 1;
      if (SelectionNext > MainMenuLength)SelectionNext = 0;

      MainMenuSelection = MainMenuOptions[MainMenuPosition];

      // Edit main menu display variable if switched on/off and or is selected
      // Rooflights
      if(MainMenuPosition == 0 && RLOnOff){MainMenuSelection = "["+MainMenuSelection+"]";}
      // UnderGlow  
      else if(MainMenuPosition == 1 && UGOnOff){MainMenuSelection = "["+MainMenuSelection+"]";}
      // Extra
      else if(MainMenuPosition == 2){
        if (BEInit && ExtraOnOff){MainMenuSelection = MainMenuSelection+"-On";}
        else {MainMenuSelection = MainMenuSelection+"-Off";}
        if(BESwitchOnOff){MainMenuSelection = "["+MainMenuSelection+"]";}
      }
      // Beacon
      else if(MainMenuPosition == 3){
        if (BEInit && BeaconOnOff){MainMenuSelection = MainMenuSelection+"-On";}
        else {MainMenuSelection = MainMenuSelection+"-Off";}
        if(BESwitchOnOff){MainMenuSelection = "["+MainMenuSelection+"]";}
      }

      // Define starting position based on lenght of string and if it is even or odd
      if (MainMenuSelection.length() % 2)StartPosition = 16 / 2 - (MainMenuSelection.length() + 1) / 2;
      else StartPosition = 16 / 2 - MainMenuSelection.length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (MainMenuSelection.length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(MainMenuSelection);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(MainMenuSelection.substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > MainMenuSelection.length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (MainMenuOptions[SelectionPrevious].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(MainMenuOptions[SelectionPrevious]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(MainMenuOptions[SelectionPrevious].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > MainMenuOptions[SelectionPrevious].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (MainMenuOptions[SelectionNext].length() < 8) {
        lcd.setCursor(16 - MainMenuOptions[SelectionNext].length(), 1);
        lcd.print(MainMenuOptions[SelectionNext]);
      }
      else{
        lcd.setCursor(9, 1);
        lcd.print(MainMenuOptions[SelectionNext].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > MainMenuOptions[SelectionNext].length() - 7)CountNext = 0;
      }
    }
    // Check if in Roof Light Menu
    else if(MenuIndex == 1){
      // Define previous and next items indexes and reset if needed
      SelectionPrevious = RLMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = RLMenuLength;
      SelectionNext = RLMenuPosition + 1;
      if (SelectionNext > RLMenuLength)SelectionNext = 0;

      // Define starting position based on lenght of string and if it is even or odd
      if (RoofLights[RLMenuPosition][0].length() % 2)StartPosition = 16 / 2 - (RoofLights[RLMenuPosition][0].length() + 1) / 2;
      else StartPosition = 16 / 2 - RoofLights[RLMenuPosition][0].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (RoofLights[RLMenuPosition][0].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(RoofLights[RLMenuPosition][0]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(RoofLights[RLMenuPosition][0].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > RoofLights[RLMenuPosition][0].length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (RoofLights[SelectionPrevious][0].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(RoofLights[SelectionPrevious][0]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(RoofLights[SelectionPrevious][0].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > RoofLights[SelectionPrevious][0].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (RoofLights[SelectionNext][0].length() < 8) {
        lcd.setCursor(16 - RoofLights[SelectionNext][0].length(), 1);
        lcd.print(RoofLights[SelectionNext][0]);
      }
      else{
        lcd.setCursor(9, 1);
        lcd.print(RoofLights[SelectionNext][0].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > RoofLights[SelectionNext][0].length() - 7)CountNext = 0;
      }
    }
    // Check if in Roof Light Static Menu
    else if(MenuIndex == 11){
      // Define previous and next items indexes and reset if needed
      SelectionPrevious = RLStaticMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = RLStaticMenuLength;
      SelectionNext = RLStaticMenuPosition + 1;
      if (SelectionNext > RLStaticMenuLength)SelectionNext = 0;

      // Define starting position based on lenght of string and if it is even or odd
      if (RLStatic[RLStaticMenuPosition][0].length() % 2)StartPosition = 16 / 2 - (RLStatic[RLStaticMenuPosition][0].length() + 1) / 2;
      else StartPosition = 16 / 2 - RLStatic[RLStaticMenuPosition][0].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (RLStatic[RLStaticMenuPosition][0].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(RLStatic[RLStaticMenuPosition][0]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(RLStatic[RLStaticMenuPosition][0].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > RLStatic[RLStaticMenuPosition][0].length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (RLStatic[SelectionPrevious][0].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(RLStatic[SelectionPrevious][0]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(RLStatic[SelectionPrevious][0].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > RLStatic[SelectionPrevious][0].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (RLStatic[SelectionNext][0].length() < 8) {
        lcd.setCursor(16 - RLStatic[SelectionNext][0].length(), 1);
        lcd.print(RLStatic[SelectionNext][0]);
      }
      else{
        lcd.setCursor(9, 1);
        lcd.print(RLStatic[SelectionNext][0].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > RLStatic[SelectionNext][0].length() - 7)CountNext = 0;
      }
    }
    // Check if in Roof Light Left Menu
    else if(MenuIndex == 12){
      // Define previous and next items indexes and reset if needed
      SelectionPrevious = RLLeftMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = RLLeftMenuLength;
      SelectionNext = RLLeftMenuPosition + 1;
      if (SelectionNext > RLLeftMenuLength)SelectionNext = 0;

      // Define starting position based on lenght of string and if it is even or odd
      if (RLLeft[RLLeftMenuPosition][0].length() % 2)StartPosition = 16 / 2 - (RLLeft[RLLeftMenuPosition][0].length() + 1) / 2;
      else StartPosition = 16 / 2 - RLLeft[RLLeftMenuPosition][0].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (RLLeft[RLLeftMenuPosition][0].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(RLLeft[RLLeftMenuPosition][0]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(RLLeft[RLLeftMenuPosition][0].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > RLLeft[RLLeftMenuPosition][0].length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (RLLeft[SelectionPrevious][0].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(RLLeft[SelectionPrevious][0]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(RLLeft[SelectionPrevious][0].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > RLLeft[SelectionPrevious][0].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (RLLeft[SelectionNext][0].length() < 8) {
        lcd.setCursor(16 - RLLeft[SelectionNext][0].length(), 1);
        lcd.print(RLLeft[SelectionNext][0]);
      }
      else{
        lcd.setCursor(9, 1);
        lcd.print(RLLeft[SelectionNext][0].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > RLLeft[SelectionNext][0].length() - 7)CountNext = 0;
      }
    }
    // Check if in Roof Light Right Menu
    else if(MenuIndex == 13){
      // Define previous and next items indexes and reset if needed
      SelectionPrevious = RLRightMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = RLRightMenuLength;
      SelectionNext = RLRightMenuPosition + 1;
      if (SelectionNext > RLRightMenuLength)SelectionNext = 0;

      // Define starting position based on lenght of string and if it is even or odd
      if (RLRight[RLRightMenuPosition][0].length() % 2)StartPosition = 16 / 2 - (RLRight[RLRightMenuPosition][0].length() + 1) / 2;
      else StartPosition = 16 / 2 - RLRight[RLRightMenuPosition][0].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (RLRight[RLRightMenuPosition][0].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(RLRight[RLRightMenuPosition][0]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(RLRight[RLRightMenuPosition][0].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > RLRight[RLRightMenuPosition][0].length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (RLRight[SelectionPrevious][0].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(RLRight[SelectionPrevious][0]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(RLRight[SelectionPrevious][0].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > RLRight[SelectionPrevious][0].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (RLRight[SelectionNext][0].length() < 8) {
        lcd.setCursor(16 - RLRight[SelectionNext][0].length(), 1);
        lcd.print(RLRight[SelectionNext][0]);
      }
      else{
        lcd.setCursor(9, 1);
        lcd.print(RLRight[SelectionNext][0].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > RLRight[SelectionNext][0].length() - 7)CountNext = 0;
      }
    }
    // Check if in Roof Light IO Menu
    else if(MenuIndex == 14){
      // Define previous and next items indexes and reset if needed
      SelectionPrevious = RLIOMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = RLIOMenuLength;
      SelectionNext = RLIOMenuPosition + 1;
      if (SelectionNext > RLIOMenuLength)SelectionNext = 0;

      // Define starting position based on lenght of string and if it is even or odd
      if (RLIO[RLIOMenuPosition][0].length() % 2)StartPosition = 16 / 2 - (RLIO[RLIOMenuPosition][0].length() + 1) / 2;
      else StartPosition = 16 / 2 - RLIO[RLIOMenuPosition][0].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (RLIO[RLIOMenuPosition][0].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(RLIO[RLIOMenuPosition][0]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(RLIO[RLIOMenuPosition][0].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > RLIO[RLIOMenuPosition][0].length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (RLIO[SelectionPrevious][0].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(RLIO[SelectionPrevious][0]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(RLIO[SelectionPrevious][0].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > RLIO[SelectionPrevious][0].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (RLIO[SelectionNext][0].length() < 8) {
        lcd.setCursor(16 - RLIO[SelectionNext][0].length(), 1);
        lcd.print(RLIO[SelectionNext][0]);
      }
      else{
        lcd.setCursor(9, 1);
        lcd.print(RLIO[SelectionNext][0].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > RLIO[SelectionNext][0].length() - 7)CountNext = 0;
      }
    }
    // Check if in Roof Light OI Menu
    else if(MenuIndex == 15){
      // Define previous and next items indexes and reset if needed
      SelectionPrevious = RLOIMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = RLOIMenuLength;
      SelectionNext = RLOIMenuPosition + 1;
      if (SelectionNext > RLOIMenuLength)SelectionNext = 0;

      // Define starting position based on lenght of string and if it is even or odd
      if (RLOI[RLOIMenuPosition][0].length() % 2)StartPosition = 16 / 2 - (RLOI[RLOIMenuPosition][0].length() + 1) / 2;
      else StartPosition = 16 / 2 - RLOI[RLOIMenuPosition][0].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (RLOI[RLOIMenuPosition][0].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(RLOI[RLOIMenuPosition][0]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(RLOI[RLOIMenuPosition][0].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > RLOI[RLOIMenuPosition][0].length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (RLOI[SelectionPrevious][0].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(RLOI[SelectionPrevious][0]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(RLOI[SelectionPrevious][0].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > RLOI[SelectionPrevious][0].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (RLOI[SelectionNext][0].length() < 8) {
        lcd.setCursor(16 - RLOI[SelectionNext][0].length(), 1);
        lcd.print(RLOI[SelectionNext][0]);
      }
      else{
        lcd.setCursor(9, 1);
        lcd.print(RLOI[SelectionNext][0].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > RLOI[SelectionNext][0].length() - 7)CountNext = 0;
      }
    }
    // Check if in Roof Light Flash Menu
    else if(MenuIndex == 16){
      // Define previous and next items indexes and reset if needed
      SelectionPrevious = RLFlashMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = RLFlashMenuLength;
      SelectionNext = RLFlashMenuPosition + 1;
      if (SelectionNext > RLFlashMenuLength)SelectionNext = 0;

      // Define starting position based on lenght of string and if it is even or odd
      if (RLFlash[RLFlashMenuPosition][0].length() % 2)StartPosition = 16 / 2 - (RLFlash[RLFlashMenuPosition][0].length() + 1) / 2;
      else StartPosition = 16 / 2 - RLFlash[RLFlashMenuPosition][0].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (RLFlash[RLFlashMenuPosition][0].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(RLFlash[RLFlashMenuPosition][0]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(RLFlash[RLFlashMenuPosition][0].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > RLFlash[RLFlashMenuPosition][0].length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (RLFlash[SelectionPrevious][0].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(RLFlash[SelectionPrevious][0]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(RLFlash[SelectionPrevious][0].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > RLFlash[SelectionPrevious][0].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (RLFlash[SelectionNext][0].length() < 8) {
        lcd.setCursor(16 - RLFlash[SelectionNext][0].length(), 1);
        lcd.print(RLFlash[SelectionNext][0]);
      }
      else{
        lcd.setCursor(9, 1);
        lcd.print(RLFlash[SelectionNext][0].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > RLFlash[SelectionNext][0].length() - 7)CountNext = 0;
      }
    }
    // Check if in the underglow menu
    else if(MenuIndex == 2){
      // Define previous and next items indexes and reset if needed
      SelectionPrevious = UGMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = UGMenuLength;
      SelectionNext = UGMenuPosition + 1;
      if (SelectionNext > UGMenuLength)SelectionNext = 0;

      // Define starting position based on lenght of string and if it is even or odd
      if (UGMenuOptions[UGMenuPosition].length() % 2)StartPosition = 16 / 2 - (UGMenuOptions[UGMenuPosition].length() + 1) / 2;
      else StartPosition = 16 / 2 - UGMenuOptions[UGMenuPosition].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (UGMenuOptions[UGMenuPosition].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(UGMenuOptions[UGMenuPosition]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(UGMenuOptions[UGMenuPosition].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > UGMenuOptions[UGMenuPosition].length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (UGMenuOptions[SelectionPrevious].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(UGMenuOptions[SelectionPrevious]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(UGMenuOptions[SelectionPrevious].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > UGMenuOptions[SelectionPrevious].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (UGMenuOptions[SelectionNext].length() < 8) {
        lcd.setCursor(16 - UGMenuOptions[SelectionNext].length(), 1);
        lcd.print(UGMenuOptions[SelectionNext]);
      }
      else{
        lcd.setCursor(9, 1);
        lcd.print(UGMenuOptions[SelectionNext].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > UGMenuOptions[SelectionNext].length() - 7)CountNext = 0;
      }
    }
    // Error message if the indexes aren't found
    else{
      lcd.setCursor(0, 0);
      lcd.print("ERROR MENU INDEX");
      lcd.setCursor(0, 1);
      lcd.print("OUT OF SCOPE");
    }
    // Prevent screen from refreshing/changing if no changes have been made
    LCDRefresh = false;
  }
}
