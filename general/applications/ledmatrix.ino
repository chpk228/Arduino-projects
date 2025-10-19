#include "LedControl.h"

LedControl lc=LedControl(12,11,10,1);

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}

void loop() {
  lc.setLed(0,0,0,true);
  delay(100);
  lc.setLed(0,0,0,false);

  lc.setLed(0,7,7,true);
  delay(100);
  lc.setLed(0,7,7,false);

  for(int row=0; row<8; row++) {
    for(int col=0; col<8; col++) {
      lc.setLed(0,row,col,true);
      delay(10);
    }
  }
  lc.clearDisplay(0);
}
