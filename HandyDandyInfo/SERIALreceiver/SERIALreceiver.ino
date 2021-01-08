//Receiver code
 #include <SoftwareSerial.h>
 SoftwareSerial link(2, 0); // Rx, Tx
  
  char cString[50];
  byte chPos = 0;
  byte ch = 0;
  char dataStr[50];
  ////////////////////////////////////////////
  void setup() 
  {
    link.begin(115200); //setup software serial
    Serial.begin(9600);    //setup serial monitor
  }
  ////////////////////////////////////////////
  void loop()  
  {  
 // if (link.available())
 //     Serial.write(link.read());
 // if (Serial.available())
 //     link.write(Serial.read());  
   
   
   while(link.available())
   {
    //read incoming char by char:
     ch = link.read();
     cString[chPos] = ch;
     chPos++;     

   }
   cString[chPos] = 0; //terminate cString
   chPos = 0;
   
   Serial.print(cString);
    
  }
  //////////////////////////////////////////////////////
