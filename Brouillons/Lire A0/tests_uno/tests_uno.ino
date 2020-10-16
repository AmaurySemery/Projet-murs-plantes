#include <Arduino.h>
#include "gravity_soil_moisture_sensor.h"


GravitySoilMoistureSensor gravity_sensor;

int sensorPin1 = A2;
int sensorPin2 = A1;

void setup() {
  Serial.begin(115200);
  }

void loop() {
  uint16_t value1 = analogRead(sensorPin1);
  Serial.print("Capteur 1 : ");
  Serial.println(value1);
  uint16_t value2 = analogRead(sensorPin2);
  Serial.print("Capteur 2 : ");
  Serial.println(value2);
  Serial.println("------------------");

  delay(5000);}
