// Check if in roof light OI menu
      if(MenuIndex == 13){
        // Reset to last if already on the first one
        if(RLOIMenuPosition == 0) RLOIMenuPosition = RLOIMenuLength;
        else RLOIMenuPosition--; 
      }