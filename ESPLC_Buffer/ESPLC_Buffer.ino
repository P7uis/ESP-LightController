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
int RLDelay;
int RLState;
String CurrentInput;
String CurrentInputPrefix;
  
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

   // If received incoming data, convert to needed variables
   if(updated){
      // Make sure to not run this every loop unless new data is received
      updated = false;

      // Terminate chararray, this is needed to convert to a string for some reason
      cString[chPos] = 0;
      chPos = 0;
      
      //Convert char array to string
      CurrentInput = String(cString);

      // DEBUG - print raw input
      Serial.print("input raw: ");
      Serial.println(cString);
      // DEBUG - print converted string input
      Serial.println("input converted: " + CurrentInput);


      // get the first 5 chars to indicate which variable to convert
      CurrentInputPrefix = CurrentInput.substring(0,5);

      if(CurrentInputPrefix == "array"){
        RLArray = CurrentInput.substring(5);
      }
      else if(CurrentInputPrefix == "delay"){
        RLDelay = CurrentInput.substring(5).toInt();
      }
      else if(CurrentInputPrefix == "state"){
        RLState = CurrentInput.substring(5).toInt();
      }

        // DEBUG - print converted variables
        Serial.println("Current array variable: " + RLArray);

        Serial.print("Current delay variable: ");
        Serial.println(RLDelay);

        Serial.print("Current state variable: ");
        Serial.println(RLState);
   }

  // if the variables are filled continue
  if(RLArray != NULL && RLDelay != NULL && RLState != NULL){
    // Loop through array
    if(i >= RLArray.length()){i = 0;}
    Serial.println(RLArray.substring(i, i+5));
    i += 6;
    delay(RLDelay);
  }
  else{Serial.println("Input not complete");}
  
    
}
