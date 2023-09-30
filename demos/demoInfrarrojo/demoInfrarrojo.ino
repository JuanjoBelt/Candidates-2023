#include "Infrarrojo.h"

Infrarrojo IR1; // Izquierdo
Infrarrojo IR2; // Derecho

void setup(){
  Serial.begin(9600);
  IR1.init(A0);
  IR2.init(A1);
}

void loop(){
  if(IR1.readL() == 0) Serial.print("Linea");
  if(IR1.readL() == 1) Serial.print("Suelo");
  else Serial.print("Checkpoint");

  Serial.print(" & ");

  if(IR2.readL() == 0) Serial.println("Linea");
  if(IR2.readL() == 1) Serial.println("Suelo");
  else Serial.println("Checkpoint");

  delay(500);
}