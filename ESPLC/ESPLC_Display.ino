void ESPLC_Display()
{
  if(LCDRefresh){
    // Reset screen if indicated to
    lcd.clear();
    // Display main menu option
    if (MainMenu)
    {
      lcd.setCursor(0, 0);
      lcd.print(MainMenuOptions[MainMenuPosition]);
    }
    // Prevent screen from refreshing/changing if no changes have been made
    LCDRefresh = false;
  }
}
