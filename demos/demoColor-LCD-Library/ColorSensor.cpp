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

String ColorSensor :: rgb(){
  tcs.getRGB(&red,&green,&blue);
  R = int(red);
  G = int(green);
  B = int(blue);
  String ans = "R" + String(R) + " G" + String(G) + " B" + String(B);
  return ans;
}

String ColorSensor :: readAlt(){
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

String ColorSensor :: read(){
  tcs.getRGB(&red, &green, &blue);
  R = int(red);
  G = int(green);
  B = int(blue);

  color = "otro";

  int rojo[3] = {165, 68, 58};
  int Green[3] = {82 ,130 , 62};
  int VerdeOsc[3] = {73, 142, 85};

  int amar[3] = {117, 98, 39};
  
  int Azul[3] = {112, 134, 152};
  int Celeste[3]= {50, 109, 100};
  int Rosa[3]= {119, 94, 81};
  int Blanco[3]={90, 95, 63};
  int Violeta[3]={ 175, 84, 96};
  
  int Negro[3]= {100, 91, 57};

  if( (R > (rojo[0] - sens) && R < (rojo[0] + sens) ) &&
      (G > (rojo[1] - sens) && G < (rojo[1] + sens) ) && 
      (B > (rojo[2] - sens) && B < (rojo[2] + sens) ) ){
    color = "Rojo";
  }

  if( (R > (amar[0] - sens) && R < (amar[0] + sens) ) &&
      (G > (amar[1] - sens) && G < (amar[1] + sens) ) && 
      (B > (amar[2] - sens) && B < (amar[2] + sens) ) ){
    color = "Amarillo";
  }
    if( (R > (Green[0] - sens) && R < (Green[0] + sens) ) &&
      (G > (Green[1] - sens) && G < (Green[1] + sens) ) && 
      (B > (Green[2] - sens) && B < (Green[2] + sens) ) ){
    color = "Verde";
  }

  if( (R > (Azul[0] - sens) && R < (Azul[0] + sens) ) &&
      (G > (Azul[1] - sens) && G < (Azul[1] + sens) ) && 
      (B > (Azul[2] - sens) && B < (Azul[2] + sens) ) ){
    color = "Azul";
  }

  if( (R > (Celeste[0] - sens) && R < (Celeste[0] + sens) ) &&
      (G > (Celeste[1] - sens) && G < (Celeste[1] + sens) ) && 
      (B > (Celeste[2] - sens) && B < (Celeste[2] + sens) ) ){
    color = "Celeste";
  }

  if( (R > (Rosa[0] - sens) && R < (Rosa[0] + sens) ) &&
      (G > (Rosa[1] - sens) && G < (Rosa[1] + sens) ) && 
      (B > (Rosa[2] - sens) && B < (Rosa[2] + sens) ) ){
    color = "Rosa";
  }

  if( (R > (Blanco[0] - sens) && R < (Blanco[0] + sens) ) &&
      (G > (Blanco[1] - sens) && G < (Blanco[1] + sens) ) && 
      (B > (Blanco[2] - sens) && B < (Blanco[2] + sens) ) ){
    color = "Blanco";
  }

  if( (R > (Violeta[0] - sens) && R < (Violeta[0] + sens) ) &&
      (G > (Violeta[1] - sens) && G < (Violeta[1] + sens) ) && 
      (B > (Violeta[2] - sens) && B < (Violeta[2] + sens) ) ){
    color = "Violeta";
  }

  if( (R > (VerdeOsc[0] - sens) && R < (VerdeOsc[0] + sens) ) &&
      (G > (VerdeOsc[1] - sens) && G < (VerdeOsc[1] + sens) ) && 
      (B > (VerdeOsc[2] - sens) && B < (VerdeOsc[2] + sens) ) ){
    color = "VerdeOsc";
  }

  if( (R > (Negro[0] - sens) && R < (Negro[0] + sens) ) &&
      (G > (Negro[1] - sens) && G < (Negro[1] + sens) ) && 
      (B > (Negro[2] - sens) && B < (Negro[2] + sens) ) ){
    color = "Negro";
  }
  return color;
}