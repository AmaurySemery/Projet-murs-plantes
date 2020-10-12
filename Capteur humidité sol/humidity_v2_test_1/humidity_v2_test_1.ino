#include <Arduino.h>
#include "gravity_soil_moisture_sensor.h"

GravitySoilMoistureSensor gravity_sensor;

int sensorPin1 = 4;
int sensorPin2 = 36;
int sensorPin3 = 34;


void setup(){
  Serial.begin(115200);
  if (!gravity_sensor.Setup(sensorPin1)) {
    Serial.println("Le capteur 1 d'humidité au sol n'a pas été détecté.");
  } else {
    Serial.println("Le capteur 1 d'humidité au sol est opérationnel !");
  }
  if (!gravity_sensor.Setup(sensorPin2)) {
    Serial.println("Le capteur 2 d'humidité au sol n'a pas été détecté.");
  } else {
    Serial.println("Le capteur 2 d'humidité au sol est opérationnel !");
  }
  if (!gravity_sensor.Setup(sensorPin3)) {
    Serial.println("Le capteur 3 d'humidité au sol n'a pas été détecté.");
  } else {
    Serial.println("Le capteur 3 d'humidité au sol est opérationnel !");
}}

void loop() {
 //Read YL-69 value
   uint16_t value1 = analogRead(sensorPin1);
   uint16_t value2 = analogRead(sensorPin2);
   uint16_t value3 = analogRead(sensorPin3);

Serial.print("Capteur 1 : ");
Serial.println(value1); 
Serial.print("Capteur 2 : ");
Serial.println(value2);
Serial.print("Capteur 3 : ");
Serial.println(value3);
delay(5000);
}
