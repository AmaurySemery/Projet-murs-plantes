#include <Arduino.h>
#include "gravity_soil_moisture_sensor.h"


GravitySoilMoistureSensor gravity_sensor;

int sensorPin1 = 13;

void setup() {
  Serial.begin(115200);
  }

void loop() {
  uint16_t value1 = analogRead(sensorPin1);
  Serial.print("Capteur 1 : ");
  Serial.println(value1);

  delay(5000);}
