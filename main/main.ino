/* ---------------------------------
               "BRONCO"
           El Robot del Norte
--------------------------------- */

#include <Servo.h>


Servo motorL2;
Servo motorL1;
Servo motorR2;
Servo motorR1;


/* ---------------------------------
            SERVO MOTORES
El parámetro es la velocidad angular
"90" sin movimiento
"0" gira en horario
"180" gira en antihorario
--------------------------------- */

void izq(int dir){
  motorL1.write(90 + dir);
  motorL2.write(90 + dir);
}

void der(int dir){
  motorR1.write(90 - dir);
  motorR2.write(90 - dir);
}

void mStop(){
  izq(0);
  der(0);
}

void mLeft(){
  izq(10);
  der(-10);
  delay(300);
  mStop();
}

void mRight(){
  izq(-10);
  der(10);
  delay(300);
  mStop();
}



/* ---------------------------------
             VOID SETUP
--------------------------------- */

void setup() {
  Serial.begin(9600); 

  // Servomotores:
  motorL2.attach(6);
  motorL1.attach(5);
  motorR2.attach(9);
  motorR1.attach(10);

}

/* ---------------------------------
             VOID LOOP
--------------------------------- */

void loop() {  
  
  /*
  // Desplazamos a la posición 0º
  motorR1.write(-1);
  Serial.println("-1");
  // Esperamos 1 segundo
  delay(5000);*/
  
  
  // Desplazamos a la posición 180º
  der(10);
  izq(0);
  delay(5000);

  der(0);
  izq(10);
  // Esperamos 1 segundo
  delay(5000);

  /*
  motorR1.write(180);
  Serial.println("180");
  // Esperamos 1 segundo
  delay(5000);
  */
  
  
}
