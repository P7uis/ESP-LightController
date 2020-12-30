void ESPLC_Display()
{
  if(LCDRefresh){
    // Reset screen if indicated to
    lcd.clear();
    
    // Display main menu option
    if (MainMenu)
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
    // Prevent screen from refreshing/changing if no changes have been made
    LCDRefresh = false;
  }
}
