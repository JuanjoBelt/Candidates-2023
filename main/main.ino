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
  ultraT.init(8, 7); // Ultrasonico techo
  ultraS.init(3, 4); // Ultrasonico suelo
  IR1.init(A0); // IR Izquierdo
  IR2.init(A1); // IR Derecho
  color.init(); // Color
  lcd.init(); // LCD

}

/* ---------------------------------
             VOID LOOP
--------------------------------- */

void loop() { 

  
  lcd.print("Esperando", "detectar zona...");
  // Laberinto
  if(1){
    lcd.print("Zona A:", "Laberinto");
    delay(1000);
    laberinto();
    motors.right(); // Posicionarse
  }
  // Rampa
  else if(color.read() == "Celeste"){
    lcd.print("Zona A2:", "Rampa chida");
    delay(1000);
    rampa();
  }
  
  
  //checaultra();

  /*
  motors.giro180();
  delay(2000);
  */
}

/* ---------------------------------
             Secciones
--------------------------------- */

void laberinto(){

  const int margen = 15;

  // Frente libre:
  if(ultraS.read() > margen){
    lcd.print("Adelante", color.read());
    motors.front();
    delay(250);
    motors.stop();
    delay(1000);
    laberinto();
    return;
  }
  // Checa tu derecha:
  else {
    lcd.print("Bloqueado", color.read());
    motors.back();
    delay(150);
    motors.stop();
    delay(1000);
    
    lcd.print("Reviso a la derecha");
    motors.right();
    delay(1000);

    if(ultraS.read() > margen){
      laberinto();
      return;
    }

    // Checa tu izquierda:
    else {
      lcd.print("Checar la izquierda", color.read());
      motors.left();
      delay(1000);
      motors.left();
      delay(1000);

      if(ultraS.read() > margen){
        laberinto();
        return;
      }

      else {
        lcd.print("Dar la vuelta 180", color.read());
        motors.left();
        delay(1000);
        laberinto();
        return;
      }
    }
  }
}

void rampa(){

  while(color.read() != "Rosa"){
    if (ultraS.read() > 10){
      motors.back();
      delay(500);
      motors. stop();
      delay(1000);
    }
    else {
      motors.back();
      delay(150);
      motors.stop();
      delay(1000);
      motors.turn();
      motors.turn();
      motors.turn();
    }
  }
}

void checaultra(){
  float n = ultraS.read();
  Serial.println(n);
  lcd.print(String(n));
  delay(400);
}

void zoneSL(){
  lcd.print("Zona C", "Seguidor de linea");

  while(1){ // Para siempre
    while(IR1.readL() == "Suelo" && IR2.readL() == "Suelo" ){ // Mientras los infrarrojos detecten suelo
      motors.front(); // Avanza
    }
    motors.stop(); // Detenerse
    if(IR1.readL() == "Checkpoint" && IR2.readL() == "Checkpoint"){
      delay(4000);
      while(IR1.readL() == "Checkpoint" && IR2.readL() == "Checkpoint"){
        motors.front();
      }
      motors.stop();
    }
    else if(IR1.readL() == "Linea" || IR2.readL() == "Linea"){ // Si hay líneas...
      if(IR1.read() == "Linea"){ // Si hay línea en el infrarrojo izquierdo
        motors.left();
      }
      else {
        motors.right();
      }
    }
  }
}

void zoneSL2(){
  lcd.print("Zona C", "Seguidor de linea");

  while(1){
    while (color.read() == "VerdeOsc") {
      motors.front();
      delay(200);
    }
    motors.stop();
    delay(200);
    // Girar:
    while (color.read() != "VerdeOsc"){
      motors.turn();
    }
  }
}
