/*
int IR0 = A0;
int IR1 = A1;

void setup(){

  Serial.begin(9600);
  pinMode(IR1, INPUT) ; //Sensor infrarrojo como entrada
  pinMode(IR0, INPUT);

}
 
void loop() {

  int valor0 = analogRead(IR0); //leemos el valor del sensor infrarrojo
  int valor1 = analogRead(IR1);
  Serial.print(valor0);
  Serial.print(" & ");
  Serial.println(valor1);
  delay(500);
}
*/

#include "Infrarrojo.h"

Infrarrojo IR1; // Izquierdo
Infrarrojo IR2; // Derecho

void setup(){
  Serial.begin(9600);
  IR1.init(A0);
  IR2.init(A1);
}

void loop(){
  if(IR1.readL()) Serial.print("Linea");
  else Serial.print("Suelo");

  Serial.print(" & ");

  if(IR2.readL()) Serial.println("Linea");
  else Serial.println("Suelo");

  delay(500);
}