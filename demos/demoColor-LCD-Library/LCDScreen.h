#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

class LCDScreen {
  private :
  int dist; // Distancia lateral para centrar
  int segH = 16; // Segmentos horizontales de LCD

  public :
  void print(String msg1, String msg2);
  void print(String msg1);
  void init();
  
  protected :
} ;
