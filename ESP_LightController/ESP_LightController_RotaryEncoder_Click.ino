void ESP_LightController_RotaryEncoder_Click()
{
  // Check if button is pressed
  if (PinC == HIGH)
  {
    // Make sure that holding the button counts as one press instead of one million
    if (HoldLock)
    {
      // Reset screen and menu option lenght variables
      lcd.clear();
      CountCurrent = 0, CountNext = 0, CountPrevious = 0;

      // Main menu
      if (Screen_MainMenu)
      {
        // Play a click sound
        ESP_LightController_Buzzer(1);

        // Make sure the user can't scroll during the proccess
        ScrollLock = true;

        // Clear the previous and next menu options
        SelectionPrevious = 0;
        SelectionNext = 0;

        // Disable main menu as the user is going to another one
        Screen_MainMenu = false;

        // Change to the chosen menu
        if(MainMenuOption=="RoofLights")Screen_RoofLights = true;
        else if(MainMenuOption=="UnderGlow")Screen_UnderGlow = true;
        else if(MainMenuOption=="Beacon")Screen_Beacon = true;
      }

      else if (Screen_RoofLights)
      {
        // TODO
      }

      // Disable the lock of the click button (You can go back to your clicking duties!)
      HoldLock = false;

    }

  }
  // I honestly don't remember why this needs to be true because i forgot the up-down 
  else HoldLock = true;
}
