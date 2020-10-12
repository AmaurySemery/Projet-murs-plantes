#include <Arduino.h>
#include "gravity_soil_moisture_sensor.h"

GravitySoilMoistureSensor gravity_sensor;

int sensorPin1 = A0;
int sensorPin2 = A1;
int sensorPin3 = A3;


void setup(){
  Serial.begin(115200);
}

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
