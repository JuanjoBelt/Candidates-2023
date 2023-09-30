/* ---------------------------------
            SERVO MOTORES
El parámetro es la velocidad angular
"90" sin movimiento
"0" gira en horario
"180" gira en antihorario
--------------------------------- */

#include <Servo.h>

class mov {
  private :
  int vel = 5;
  Servo motorL2;
  Servo motorL1;
  Servo motorR2;
  Servo motorR1;
  void izq(int dir);
  void der(int dir);

  public :
  void stop();
  void right();
  void left();
  void front();
  void back();
  void init();
  
  protected :
} ;

