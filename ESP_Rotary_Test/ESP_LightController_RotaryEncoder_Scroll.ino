void ESP_LightController_RotaryEncoder_Scroll()
{
  // Detect scrolling activity
  if ((PinALast == HIGH) && (PinA == LOW))
  {    
      lcd.clear();
      // Scroll right
      if (PinB == LOW)
      {
        scrollcount++;
        // Play a scroll right sound
        ESP_LightController_Buzzer(2);
        lcd.setCursor(0, 0);
        lcd.print("Right");
        lcd.setCursor(0, 1);
        lcd.print(scrollcount);
      }
      // Scroll left
      else
      {
        scrollcount++;
        // Play a scroll left sound
        ESP_LightController_Buzzer(3);  
        lcd.setCursor(0, 0);      
        lcd.print("Left");
        lcd.setCursor(0, 1);
        lcd.print(scrollcount);
      }

  }
  PinALast = PinA;
}
