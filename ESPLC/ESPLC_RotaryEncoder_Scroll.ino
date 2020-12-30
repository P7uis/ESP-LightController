void ESPLC_RotaryEncoder_Scroll()
{
  // Detect scrolling activity
  if ((PinALast == HIGH) && (PinA == LOW))
  {   
    // Scroll right
    if (PinB == LOW)
    {
      if(MainMenu){
        // Reset to 0 if already on the last one
        if(MainMenuPosition == MainMenuLength) MainMenuPosition = 0;
        else MainMenuPosition++; 
      }
      // Play a scroll right sound
      ESPLC_Buzzer(2);
    }
    // Scroll left
    else
    {
      if(MainMenu){
        // Reset to last if already on the first one
        if(MainMenuPosition == 0) MainMenuPosition = MainMenuLength;
        else MainMenuPosition--; 
      }
      // Play a scroll left sound
      ESPLC_Buzzer(3);  
    }
    // Make sure the screen resets after these changes
    LCDRefresh = true;
  }
  PinALast = PinA;
}
