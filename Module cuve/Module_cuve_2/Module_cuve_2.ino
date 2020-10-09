#include <HCSR04.h>      
#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <Arduino.h>

//#define USE_SERIAL Serial

LiquidCrystal_I2C lcd(0x2F,16,2);


void setup() {

lcd.init();
 lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hello, world!");

}
void loop() {
}
