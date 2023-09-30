#include <Adafruit_TCS34725.h>

class ColorSensor {
  private :
  float red,green,blue;
  int R, G, B;
  String color;
  int sens = 15;


  public :
  void init();
  void printRGB();
  String read();
  String readAlt();
  
  protected :
};