/*
#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup(void) {
  Serial.begin(9600);
 
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}

void loop(void) {
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);
  Serial.print("Red: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("Green: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("Blue: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("Color: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
  delay(500);
} 
*/


#include <Adafruit_TCS34725.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,TCS34725_GAIN_4X);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }

  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hola hola hola");
  lcd.setCursor(0,1);
  lcd.print("Ywrobot Arduino!");
}

void loop() {
  // put your main code here, to run repeatedly:
  float red,green,blue;
  tcs.getRGB(&red,&green,&blue);
  int R = int(red);
  int G = int(green);
  int B = int(blue);
  String color = "";
  if((R-G>50)&(R-B>50)){
    color = "Red";
  }
  if((G-B>10)&(G-R>30)){
    color = "Green";
  }
  if ((B-G>20)&(B-R>40)){
    color = "Blue";
  }
  if ((R-B>40)&(G-B>40)){
    color = "Yellow";
  }
  Serial.print("R: ");
  Serial.print(int(red));
  Serial.print("   G: ");
  Serial.print(int(green));
  Serial.print("   B: ");
  Serial.print(int(blue));
  Serial.print("   Color: ");
  Serial.print(color);
  Serial.println();

  delay(500);
}