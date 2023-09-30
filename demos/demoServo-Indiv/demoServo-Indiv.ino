#include <Servo.h>

//Servo motor;
Servo motor2;
//Servo motor4;
//Servo motor23;

void setup() {
  // put your setup code here, to run once:
  //motor.attach(10);
  //motor4.attach(9);
  motor2.attach(10);
  //motor23.attach(10);
  //motor.write(90);
  motor2.write(90);
  //motor4.write(90);
  //motor23.write(90);
}

void loop() {
  //motor.write(90+10);
  //motor2.write(90-10);
  //motor4.write(90+5);
  //motor23.write(90-10);
  //delay(500);
  //motor.write(90);
  //motor2.write(140);
  //motor4.write(90);
  //motor23.write(90);
  
  motor2.write(105);
  delay(3000);
  motor2.write(90);
  delay(3000);
}
