#include <Arduino.h>
#include "mov.h"

void mov::init(){
  motorL2.attach(6);
  motorL1.attach(5);
  motorR2.attach(9);
  motorR1.attach(10);
  

  stop();

  Serial.println("Motores inicializados...");
}

void mov::izqF(){ // Mover el par izquierdo de motores
  motorL1.write(sL1 + vL1);
  motorL2.write(sL2 + vL2);
}

void mov::izqB(){ // Mover el par izquierdo de motores
  motorL1.write(sL1 - vL1);
  motorL2.write(sL2 - vL2);
}

void mov::derF(){ // Mover el par derecho de motores
  motorR1.write(sR1 - vR1);
  motorR2.write(sR2 - vR2);
}

void mov::derB(){ // Mover el par derecho de motores
  motorR1.write(sR1 + vR1);
  motorR2.write(sR2 + vR2);
}

void mov::stop(){ // Parar los motores
  motorL1.write(sL1);
  motorL2.write(sL2);
  motorR1.write(sR1);
  motorR2.write(sR2);
}

void mov::right(){ // Girar 90° a la izquierda
  izqF();
  derB();
  delay(350);
  stop();
  delay(1000);
  izqF();
  derB();
  delay(300);
  stop();
  delay(1000);
}

void mov::left(){ // Girar 90° a la derecha
  izqB();
  derF();
  delay(650);
  stop();
}

void mov::front(){ // Mantener avance
  izqF();
  derF();
}

void mov::back(){ // Mantener retroceso
  izqB();
  derB();
}

void mov::turn(){ // Girar un poco a la izquierda
  izqF();
  derB();
  delay(100);
  stop();
}

void mov::giro180(){ // Girar 90° a la derecha
  izqB();
  derF();
  delay(1300);
  stop();
}