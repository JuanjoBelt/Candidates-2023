/* ---------------------------------
               "BRONCO"
           El Robot del Norte

Electrónica: Kevin Ávila
Mecánica: Gustavo 
Programación: Juanjo Beltrán
--------------------------------- */

#include "mov.h" // Nuestra librería de movimiento
#include "LCDScreen.h" // Nuestra librería de LCD

/* ---------------------------------
          INSTANCIAR OBJETOS
--------------------------------- */
mov m;
LCDScreen lcd;

/* ---------------------------------
             VOID SETUP
--------------------------------- */

void setup() {

  Serial.begin(9600); 
  m.init(); // Movimiento
  lcd.init(); // LCD

}

/* ---------------------------------
             VOID LOOP
--------------------------------- */

void loop() {  

  lcd.print("Adelante");
  m.front();
  delay(1000);
  lcd.print("Atras");
  m.back();
  delay(1000);
  lcd.print("Izquierda");
  m.left();
  lcd.print("Derecha");
  m.right();
  lcd.print("...");
  delay(2000);
  
}
