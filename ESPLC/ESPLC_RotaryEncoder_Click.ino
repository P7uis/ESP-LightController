void ESPLC_RotaryEncoder_Click()
{
  // Check if button is pressed
  if (PinC == LOW)
  {
    // Play a click sound
    ESPLC_Buzzer(1);
  }
}
