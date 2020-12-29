void ESP_LightController_RotaryEncoder_Scroll()
{
  // Detect scrolling activity
  if ((PinALast == HIGH) && (PinA == LOW))
  {
    // Reset screen and menu option lenght variables
    lcd.clear();
    CountCurrent = 0, CountNext = 0, CountPrevious = 0;

    // Prevent scrolling until proccess is complete
    ScrollLock = true;

    // Detect if user is in main menu
    if (Screen_MainMenu)
    {
      // Scroll right
      if (PinB == HIGH)
      {
        // Play a scroll right sound
        ESP_LightController_Buzzer(2);

        // Reset to first menu option if the user reaches the end, making it an infinite loop
        if (MainMenuPosition == MainMenuLength)MainMenuPosition = 0;

        // Increase position when scrolling to the right
        else MainMenuPosition++;

        //Update the previous menu option and reset to beginning if needed
        SelectionPrevious = MainMenuPosition - 1;
        if (SelectionPrevious < 0)SelectionPrevious = MainMenuLength;

        //Update the next menu option and reset to beginning if needed
        SelectionNext = MainMenuPosition + 1;
        if (SelectionNext > MainMenuLength)SelectionNext = 0;
      }
      // Scroll left
      else
      {
        // Play a scroll left sound
        ESP_LightController_Buzzer(3);

        // Reset to last menu option if the user reaches the start, making it an infinite loop
        if (MainMenuPosition == 0)MainMenuPosition = MainMenuLength;

        // Decrease position when scrolling to the left
        else MainMenuPosition--;

        //Update the previous menu option and reset to beginning if needed
        SelectionPrevious = MainMenuPosition - 1;
        if (SelectionPrevious < 0)SelectionPrevious = MainMenuLength;

        //Update the next menu option and reset to beginning if needed
        SelectionNext = MainMenuPosition + 1;
        if (SelectionNext > MainMenuLength)SelectionNext = 0;
      }

      MainMenuOption = MainMenuOptions[MainMenuPosition];
    }

    else if (Screen_RoofLights)
    {
      // TODO
    }

  }
  PinALast = PinA;
}
