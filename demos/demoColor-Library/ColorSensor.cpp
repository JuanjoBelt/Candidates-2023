#include<Arduino.h>
#include "ColorSensor.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,TCS34725_GAIN_4X);

void ColorSensor :: init(){
  if (tcs.begin()) {
    Serial.println("Sensor de color inicializado...");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}

void ColorSensor :: printRGB(){
  tcs.getRGB(&red,&green,&blue);
  R = int(red);
  G = int(green);
  B = int(blue);
  Serial.print("R: ");
  Serial.print(R);
  Serial.print("   G: ");
  Serial.print(G);
  Serial.print("   B: ");
  Serial.println(B);
}

String ColorSensor :: read(){
  tcs.getRGB(&red,&green,&blue);
  R = int(red);
  G = int(green);
  B = int(blue);
  
  if((R-G>50) & (R-B>50)){
    color = "Rojo";
  }
  else if((G-B>10) & (G-R>30)){
    color = "Verde";
  }
  else if ((B-G>20) & (B-R>40)){
    color = "Azul";
  }
  else if ((R-B>40) & (G-B>40)){
    color = "Amarillo";
  }
  else {
    color = "Otro";
  }

  return color;
}