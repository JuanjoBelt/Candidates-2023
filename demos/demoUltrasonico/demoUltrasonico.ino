#include "Ultrasonic.h"

Ultrasonic ultra1;
Ultrasonic ultra2;
float n, m;

void setup()
{
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  ultra1.init(8, 7);
  ultra2.init(3, 4);

}
void loop()
{
  
  n = ultra1.read();
  m = ultra2.read();
  Serial.print(n);
  Serial.print(" | ");
  Serial.println(m);
  delay(500);
}
 