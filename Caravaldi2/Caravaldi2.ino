#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();
  MFS.initialize(&Timer1);
 
}


void loop() {
   displayText("Simple Quiz", 100);
  
  int randomNr = rand() % 20 + 1;
  int randomNr2 = rand() % 20 + 1;

  MFS.write(randomNr);
  MFS.beep(1);
  delay(500);
  MFS.write("PLUS");
  MFS.beep(1);
  delay(500);
  MFS.write(randomNr2);
  MFS.beep(1);
  delay(500);

  int userinput = 0;
  int btnPressed = 0;
  while (btnPressed < 3) {
      byte btn = MFS.getButton();
      if (btn == BUTTON_1_PRESSED) {
        userinput++;
      }
      if (btn == BUTTON_2_PRESSED) {
        userinput--;
      }
      if (btn == BUTTON_3_PRESSED) {
        btnPressed = 3;
      }
      MFS.write(userinput);
  }
  int result = randomNr + randomNr2;
  if (userinput == result) {
    MFS.write("Yes");
    MFS.beep(10);
  } else {
    MFS.write("no");
    MFS.beep(30);
    delay(300);
    MFS.beep(30);
  }

  delay(5000);
  
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
