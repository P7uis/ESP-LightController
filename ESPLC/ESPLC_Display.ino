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

      // Check if the string is longer than 16 (screens horizontal character limit) it will scroll through the words
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
    }
    // Prevent screen from refreshing/changing if no changes have been made
    LCDRefresh = false;
  }
}
