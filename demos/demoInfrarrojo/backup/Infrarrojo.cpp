#include<Arduino.h>
#include "Infrarrojo.h"

void Infrarrojo :: init(int _pin){
  pin = _pin;
  pinMode(pin, INPUT); //Sensor infrarrojo como entrada
}

int Infrarrojo :: read(){ // Lectura analógica
  valor = analogRead(pin);
  return valor;
}

int Infrarrojo :: readL(){ // Está sobre linea?
  valor = analogRead(pin);
  if (valor > sens) return 1; // Sí está
  else return 0; // No está
}