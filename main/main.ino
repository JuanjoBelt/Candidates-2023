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
#include "Infrarrojo.h" // Nuestra librería de Infrarrojo
#include "ColorSensor.h" // Nuestra librería del Sensor de Color

/* ---------------------------------
          INSTANCIAR OBJETOS
--------------------------------- */
mov motors; // Motores
LCDScreen lcd; // LCD
Ultrasonic ultraS; // Ultrasonico suelo
Ultrasonic ultraT; // Ultrasonico techo
Infrarrojo IR1; // IR Izquierdo
Infrarrojo IR2; // IR Derecho
ColorSensor color; // Color

/* ---------------------------------
             VOID SETUP
--------------------------------- */

void setup() {

  Serial.begin(9600); 
  motors.init(); // Movimiento
  lcd.init(); // LCD
  ultraT.init(8, 7); // Ultrasonico techo
  ultraS.init(3, 4); // Ultrasonico suelo
  IR1.init(A0); // IR Izquierdo
  IR2.init(A1); // IR Derecho
  color.init(); // Color

}

/* ---------------------------------
             VOID LOOP
--------------------------------- */

void loop() {  
  float n = ultraS.read();
  Serial.println(n);

  if(n > 20){
    lcd.print("Adelante", String(n));
    motors.front();
  }
  else {
    lcd.print("Bloqueado", String(n));
    motors.left();
  }
  
  delay(500);
}
