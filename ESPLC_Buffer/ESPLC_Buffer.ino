//Receiver code
#include <SoftwareSerial.h>
SoftwareSerial link(2); // Rx

char cString[200];
byte chPos = 0;
byte ch = 0;
char dataStr[1];

int i = 0;

bool updated = true;

String RLArray;
String RLDelay = 100;
String RLState = 0;
String CurrentInput;
  
void setup(){

    link.begin(115200); //setup software serial
    Serial.begin(115200);    //setup serial monitor
    link.write(Serial.read());  
}   

void loop(){    

   while(link.available())
   {
    //read incoming char by char:
     ch = link.read();
     cString[chPos] = ch;
     chPos++;     
     updated = true;
   }
   // write chars to variable
   if(updated){
      updated = false;
      cString[chPos] = 0; //terminate cString
      chPos = 0;
      // get the first 5 chars to indicate which variable to convert
      Currentinput = cString.substring(0,5);
      if(Currentinput == "array"){
        RLArray = cString.substring(5);
      }
      else if(Currentinput == "delay"){
        RLDelay = cString.substring(5).toInt();
      }
      else if(Currentinput == "state"){
        RLState = cString.substring(5).toInt();
      }
   }
  // if the array is filled filled continue
  if(RLArray != NULL){
    if(i >= RLArray.length()){i = 0;}
    Serial.println(RLArray.substring(i, i+5));
    i += 6;
    delay(RLDelay);
  }
  
    
}