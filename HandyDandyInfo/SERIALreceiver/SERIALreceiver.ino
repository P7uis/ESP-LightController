//Receiver code
 #include <SoftwareSerial.h>
 SoftwareSerial link(2); // Rx pin defined, TX not defined
  
  char cString[200];
  byte chPos = 0;
  byte ch = 0;
  char dataStr[1];
  ////////////////////////////////////////////
  void setup() 
  {
    link.begin(115200); //setup software serial
    Serial.begin(115200);    //setup serial monitor
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
