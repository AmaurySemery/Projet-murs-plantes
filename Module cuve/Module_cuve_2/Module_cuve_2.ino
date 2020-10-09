#include <HCSR04.h>      
#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <Arduino.h>

//#define USE_SERIAL Serial

LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {

lcd.init();
 lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hello, world!");
  delay(5000);

}
void loop() {
lcd.clear(); 
lcd.setCursor(0,0); // positionne le curseur à la colonne 1 et à la ligne 2 lcd.print("Hello World!"); delay(1000);

}
