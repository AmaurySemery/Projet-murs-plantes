#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <WiFiMulti.h>
#include <Arduino.h>
#include <HTTPClient.h>
#include "gravity_soil_moisture_sensor.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

GravitySoilMoistureSensor gravity_sensor;

int sensorPin1 = 2;

void setup() {
  Serial.begin(115200);
  if (!gravity_sensor.Setup(sensorPin1)) {
  Serial.println("Le capteur 1 d'humidité au sol n'a pas été détecté.");
    lcd.print("Capteur 1 : Err !");
    delay(3000);
    lcd.clear();
}
else {
    Serial.println("Le capteur 1 d'humidité au sol est opérationnel !");
    lcd.print("Capteur 1 : Ok !");
    delay(3000);
    lcd.clear();
  }
  }

void loop() {
  uint16_t value1 = analogRead(sensorPin1);
  lcd.print(value1);
  delay(5000);
  lcd.clear();}
