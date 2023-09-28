/* ---------------------------------
               "BRONCO"
           El Robot del Norte

Electrónica: Kevin Ávila
Mecánica: Gustavo 
Programación: Juanjo Beltrán
--------------------------------- */

#include "mov.h" // Nuestra librería de movimiento
#include "LCDScreen.h" // Nuestra librería de LCD
#include "Ultrasonic.h" // Nuestra librería de ultrasónico

/* ---------------------------------
          INSTANCIAR OBJETOS
--------------------------------- */
mov motors; // Motores
LCDScreen lcd; // LCD
Ultrasonic ultraS; // Suelo
Ultrasonic ultraT; // Techo

/* ---------------------------------
             VOID SETUP
--------------------------------- */

void setup() {

  Serial.begin(9600); 
  motors.init(); // Movimiento
  lcd.init(); // LCD
  ultraT.init(8, 7);
  ultraS.init(3, 4);

}

/* ---------------------------------
             VOID LOOP
--------------------------------- */

void loop() {  
  float n = ultraS.read();
  Serial.println(n);

  if(n > 20){
    lcd.print("Adelante");
    Serial.println("Adelante");
    motors.front();
  }
  else {
    lcd.print("Bloqueado");
    Serial.println("Bloqueado");
    motors.left();
  }
  
  delay(1000);
}
