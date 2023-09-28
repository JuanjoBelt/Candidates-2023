#include "LCDScreen.h"

  LCDScreen lcd;

void setup()
{
  lcd.init();
  lcd.print("Hola", "Mundo!");
}

void loop(){

}