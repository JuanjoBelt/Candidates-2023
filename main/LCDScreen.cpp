#include <Arduino.h>
#include "LCDScreen.h"

LiquidCrystal_I2C scr(0x27,20,4);

void LCDScreen::init(){
  scr.init();  // initialize the lcd 
  scr.backlight();
  Serial.println("LCD Inicializada...");
}

void LCDScreen::print(String msg1, String msg2){
  scr.clear();

  if(msg1.length() <= segH){
    dist = (segH-msg1.length())/2;
  }
  else {
    dist = 0;
  }
  scr.setCursor(dist,0);
  scr.print(msg1);

  if(msg2.length() <= segH){
    dist = (segH-msg2.length())/2;
  }
  else {
    dist = 0;
  }
  scr.setCursor(dist,1);
  scr.print(msg2);
}

void LCDScreen::print(String msg1){
  scr.clear();

  if(msg1.length() <= segH){
    dist = (segH-msg1.length())/2;
  }
  else {
    dist = 0;
  }
  scr.setCursor(dist,0);
  scr.print(msg1);
}