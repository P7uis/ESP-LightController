void ESP_LightController_Menu_Walkthrough()
{

  if (Screen_MainMenu)
  {

    //if (ScrollLock) {
      SelectionPrevious = MainMenuPosition - 1;
      if (SelectionPrevious < 0)SelectionPrevious = MainMenuLength;
      SelectionNext = MainMenuPosition + 1;
      if (SelectionNext > MainMenuLength)SelectionNext = 0;
      //ScrollLock = false;
    //}
    if (LCDRefresh)lcd.clear();

    //current
    //Round odd numbers up
    if (MainMenuOption.length() % 2)StartPosition = 16 / 2 - (MainMenuOption.length() + 1) / 2;
    else StartPosition = 16 / 2 - MainMenuOption.length() / 2;
    if (MainMenuOption.length() < 16) {
      lcd.setCursor(StartPosition, 0);
      lcd.print(MainMenuOption);
    }
    else if (LCDRefresh) {
      lcd.setCursor(0, 0);
      lcd.print(MainMenuOption.substring(CountCurrent, CountCurrent + 16));
      CountCurrent++;
      if (CountCurrent > MainMenuOption.length() - 16)CountCurrent = 0;

    }

    //previous
    if (MainMenuOptions[SelectionPrevious].length() < 8) {
      lcd.setCursor(0, 1);
      lcd.print(MainMenuOptions[SelectionPrevious]);
    }
    else if (LCDRefresh) {
      lcd.setCursor(0, 1);
      lcd.print(MainMenuOptions[SelectionPrevious].substring(CountNext, CountNext + 7));
      CountNext++;
      if (CountNext > MainMenuOptions[SelectionPrevious].length() - 7)CountNext = 0;
    }

    //divider
    lcd.setCursor(7, 1);
    lcd.print("<>");

    //next
    if (MainMenuOptions[SelectionNext].length() < 8) {
      lcd.setCursor(16 - MainMenuOptions[SelectionNext].length(), 1);
      lcd.print(MainMenuOptions[SelectionNext]);
    }
    else if (LCDRefresh) {
      lcd.setCursor(9, 1);
      lcd.print(MainMenuOptions[SelectionNext].substring(CountPrevious, CountPrevious + 7));
      CountPrevious++;
      if (CountPrevious > MainMenuOptions[SelectionNext].length() - 7)CountPrevious = 0;
    }
    LCDRefresh = false;
  }

  else if (Screen_RoofLights)
  {
// TODO
  }
}
