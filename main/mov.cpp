#include <Arduino.h>
#include "mov.h"

void mov::init(){
  motorL2.attach(6);
  motorL1.attach(5);
  motorR2.attach(9);
  motorR1.attach(10);
  

  motorL1.write(90);
  motorL2.write(90);
  motorR1.write(90);
  motorR2.write(90);

  Serial.println("Motores inicializados...");
}

void mov::izq(int dir){ // Mover el par izquierdo de motores
  motorL1.write(90 + dir);
  motorL2.write(90 + dir);
}

void mov::der(int dir){ // Mover el par derecho de motores
  motorR1.write(90 - dir);
  motorR2.write(90 - dir);
}

void mov::stop(){ // Parar los motores
  izq(0);
  der(0);
}

void mov::left(){ // Girar 90° a la izquierda
  izq(vel);
  der(-vel);
  delay(300);
  stop();
}

void mov::right(){ // Girar 90° a la derecha
  izq(-vel);
  der(vel);
  delay(300);
  stop();
}

void mov::front(){ // Mantener avance
  izq(vel);
  der(vel);
}

void mov::back(){ // Mantener retroceso
  izq(-vel);
  der(-vel);
}