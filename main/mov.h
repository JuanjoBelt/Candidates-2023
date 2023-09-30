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
  void izqF();
  void derB();
  void izqB();
  void derF();

  int vR1 = 15;
  int vR2 = 11;
  int vL1 = 11;
  int vL2 = 10;

  int sR1 = 90;
  int sR2 = 89;
  int sL1 = 88;
  int sL2 = 88;

  public :
  void stop();
  void right();
  void left();
  void front();
  void back();
  void init();
  void turn();
  void giro180();

  protected :
} ;

