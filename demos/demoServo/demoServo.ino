/* ---------------------------------
               "BRONCO"
           El Robot del Norte
--------------------------------- */

#include <Servo.h>

/* ---------------------------------
            SERVO MOTORES
El parámetro es la velocidad angular
"90" sin movimiento
"0" gira en horario
"180" gira en antihorario
--------------------------------- */
Servo motorL2;
Servo motorL1;
Servo motorR2;
Servo motorR1;

void izq(int dir){ // Mover el par izquierdo de motores
  motorL1.write(90 + dir);
  motorL2.write(90 + dir);
}

void der(int dir){ // Mover el par derecho de motores
  motorR1.write(90 - dir);
  motorR2.write(90 - dir);
}

void mStop(){ // Parar los motores
  izq(0);
  der(0);
}

void mLeft(){ // Girar 90° a la izquierda
  izq(10);
  der(-10);
  delay(300);
  mStop();
}

void mRight(){ // Girar 90° a la derecha
  izq(-10);
  der(10);
  delay(300);
  mStop();
}

void mFront(){ // Mantener avance
  izq(10);
  der(10);
}

void mBack(){ // Mantener retroceso
  izq(-10);
  der(-10);
}



/* ---------------------------------
             VOID SETUP
--------------------------------- */

void setup() {
  Serial.begin(9600); 

  // Servomotores y pines:
  motorL2.attach(6);
  motorL1.attach(5);
  motorR2.attach(9);
  motorR1.attach(10);
}

/* ---------------------------------
             VOID LOOP
--------------------------------- */

void loop() {  
  
  // Desplazamos a la posición 180º
  mFront();
  delay(1000);

  mBack();
  delay(1000);

  mRight();
  mLeft();
  mRight();
  mLeft();
  // Esperamos 1 segundo
  delay(3000); 
  
}
