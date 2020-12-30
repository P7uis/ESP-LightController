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

      // Define starting position based on lenght of string and if it is even or odd
      if (MainMenuOptions[MainMenuPosition].length() % 2)StartPosition = 16 / 2 - (MainMenuOptions[MainMenuPosition].length() + 1) / 2;
      else StartPosition = 16 / 2 - MainMenuOptions[MainMenuPosition].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (MainMenuOptions[MainMenuPosition].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(MainMenuOptions[MainMenuPosition]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(MainMenuOptions[MainMenuPosition].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > MainMenuOptions[MainMenuPosition].length() - 16)CountCurrent = 0;
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
      else if (LCDRefresh) {
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
      if (RLMenuOptions[RLMenuPosition].length() % 2)StartPosition = 16 / 2 - (RLMenuOptions[RLMenuPosition].length() + 1) / 2;
      else StartPosition = 16 / 2 - RLMenuOptions[RLMenuPosition].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (RLMenuOptions[RLMenuPosition].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(RLMenuOptions[RLMenuPosition]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(RLMenuOptions[RLMenuPosition].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > RLMenuOptions[RLMenuPosition].length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (RLMenuOptions[SelectionPrevious].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(RLMenuOptions[SelectionPrevious]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(RLMenuOptions[SelectionPrevious].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > RLMenuOptions[SelectionPrevious].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (RLMenuOptions[SelectionNext].length() < 8) {
        lcd.setCursor(16 - RLMenuOptions[SelectionNext].length(), 1);
        lcd.print(RLMenuOptions[SelectionNext]);
      }
      else if (LCDRefresh) {
        lcd.setCursor(9, 1);
        lcd.print(RLMenuOptions[SelectionNext].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > RLMenuOptions[SelectionNext].length() - 7)CountNext = 0;
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
      else if (LCDRefresh) {
        lcd.setCursor(9, 1);
        lcd.print(UGMenuOptions[SelectionNext].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > UGMenuOptions[SelectionNext].length() - 7)CountNext = 0;
      }
    }
    //Check if in the beacon menu
    else if(MenuIndex == 3){
      // Define previous and next items indexes and reset if needed
      SelectionPrevious = BeaconMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = BeaconMenuLength;
      SelectionNext = BeaconMenuPosition + 1;
      if (SelectionNext > BeaconMenuLength)SelectionNext = 0;

      // Define starting position based on lenght of string and if it is even or odd
      if (BeaconMenuOptions[BeaconMenuPosition].length() % 2)StartPosition = 16 / 2 - (BeaconMenuOptions[BeaconMenuPosition].length() + 1) / 2;
      else StartPosition = 16 / 2 - BeaconMenuOptions[BeaconMenuPosition].length() / 2;

      // Check if the string is longer than 16 (screens horizontal character limit) otherwise it will scroll through the words
      if (BeaconMenuOptions[BeaconMenuPosition].length() < 16) {
        lcd.setCursor(StartPosition, 0);
        lcd.print(BeaconMenuOptions[BeaconMenuPosition]);
      }
      else{
        lcd.setCursor(0, 0);
        lcd.print(BeaconMenuOptions[BeaconMenuPosition].substring(CountCurrent, CountCurrent + 16));
        CountCurrent++;
        if (CountCurrent > BeaconMenuOptions[BeaconMenuPosition].length() - 16)CountCurrent = 0;
      }

      // Previous Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words
      if (BeaconMenuOptions[SelectionPrevious].length() < 8) {
        lcd.setCursor(0, 1);
        lcd.print(BeaconMenuOptions[SelectionPrevious]);
      }
      else{
        lcd.setCursor(0, 1);
        lcd.print(BeaconMenuOptions[SelectionPrevious].substring(CountPrevious, CountPrevious + 7));
        CountPrevious++;
        if (CountPrevious > BeaconMenuOptions[SelectionPrevious].length() - 7)CountPrevious = 0;
      }

      // The divider of the previous and next options
      lcd.setCursor(7, 1);
      lcd.print("<>");
      
      // Next Option - Check if the string is longer than 7 character (half of the bottom display) otherwise it will scroll through the words 
      if (BeaconMenuOptions[SelectionNext].length() < 8) {
        lcd.setCursor(16 - BeaconMenuOptions[SelectionNext].length(), 1);
        lcd.print(BeaconMenuOptions[SelectionNext]);
      }
      else if (LCDRefresh) {
        lcd.setCursor(9, 1);
        lcd.print(BeaconMenuOptions[SelectionNext].substring(CountNext, CountNext + 7));
        CountNext++;
        if (CountNext > BeaconMenuOptions[SelectionNext].length() - 7)CountNext = 0;
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
