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
 