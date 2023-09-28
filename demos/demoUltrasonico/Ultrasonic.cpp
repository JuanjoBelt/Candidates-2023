#include <Arduino.h>
#include "Ultrasonic.h"

void Ultrasonic :: init(int trig, int echo){
  PinTrig = trig;
  PinEcho = echo;
  // Ponemos el pin Trig en modo salida
  pinMode(PinTrig, OUTPUT);
  // Ponemos el pin Echo en modo entrada
  pinMode(PinEcho, INPUT);
}

float Ultrasonic :: read(){
  iniciarTrigger();

  tiempo = pulseIn(PinEcho, HIGH);
  distancia = tiempo * 0.000001 * VelSon / 2.0;
  return distancia;
}

void Ultrasonic :: iniciarTrigger(){
  // Ponemos el Triiger en estado bajo y esperamos 2 ms
  digitalWrite(PinTrig, LOW);
  delayMicroseconds(2);
  
  // Ponemos el pin Trigger a estado alto y esperamos 10 ms
  digitalWrite(PinTrig, HIGH);
  delayMicroseconds(10);
  
  // Comenzamos poniendo el pin Trigger en estado bajo
  digitalWrite(PinTrig, LOW);
}