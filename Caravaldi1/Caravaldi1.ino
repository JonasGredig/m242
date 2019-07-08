#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

boolean started;
byte btn;
int currentTime = 0;

void setup() {
       
  Timer1.initialize();
  MFS.initialize(&Timer1);
                             // initialize multi-function shield library
  displayText("Jonas Timer", 320);
  started = false;
}


 void loop() {

        btn = MFS.getButton();
        if (started) {
          currentTime++;
        } 

        if (btn == BUTTON_1_PRESSED && started == true) {
          started = false;
        } else if (btn == BUTTON_1_PRESSED && started == false) {
          started = true;
        }

        if (btn == BUTTON_2_PRESSED && started == false && currentTime != 0) {
          displayText("RESET", 80);
          currentTime = 0;
        }

        MFS.write(currentTime);
        delay(1000);
}

void displayText(char message[], int speed) {
       
       char displayActualSize[5] = "    ";
       int messageLength = strlen(message);
  
       for(int i = 0; i < messageLength+4; i++) {
         for(int j = 0; j < 3; j++) {
           displayActualSize[j] = displayActualSize[j+1];
         }
         displayActualSize[3] = message[i];
         MFS.write(displayActualSize);
         delay(speed);
       }
     }
