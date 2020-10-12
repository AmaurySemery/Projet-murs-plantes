#include <Arduino.h>
#include "gravity_soil_moisture_sensor.h"

GravitySoilMoistureSensor gravity_sensor;

int sensorPin1 = A0;
int sensorPin2 = A1;


void setup(){
  Serial.begin(115200);
}

void loop() {
 //Read YL-69 value
   uint16_t value1 = analogRead(sensorPin1);
   uint16_t value1 = analogRead(sensorPin2);

Serial.print("Capteur 1 : ");
Serial.println(sensorPin1); 
Serial.print("Capteur 2 : ");
Serial.println(sensorPin2);
delay(5000);
}
