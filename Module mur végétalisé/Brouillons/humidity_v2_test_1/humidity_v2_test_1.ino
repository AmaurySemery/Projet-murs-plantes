#include <Arduino.h>
#include "gravity_soil_moisture_sensor.h"

GravitySoilMoistureSensor gravity_sensor;

int sensorPin1 = 4;
int sensorPin2 = 36;
int sensorPin3 = 34;
float a = 40.95;
float b = 100;
float c = 1200;
float d = 29.304;
float g = 3;


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
   int sensor1Convert = value1 / a;
   uint16_t value2 = analogRead(sensorPin2);
   int sensor2Convert = value2 / a;
   uint16_t value3 = analogRead(sensorPin3);
   int sensor3Convert = value3 / a;
  int somme = sensor1Convert + sensor2Convert + sensor3Convert;
  int moyenne = somme / g;

  Serial.print("{\"sensor1\":");
  Serial.print(sensor1Convert);
  Serial.print(",\"sensor2\":");
  Serial.print(sensor2Convert);
  Serial.print(",\"sensor3\":");
  Serial.print(sensor3Convert);
  Serial.print(",\"moyenne\":");
  Serial.print(moyenne);
  Serial.print(",\"minimum\":");
  Serial.print(minimum());
  Serial.print(",\"maximum\":");
  Serial.print(maximum());
  Serial.println("}");
delay(5000);
}

int maximum() {
  uint16_t value1 = analogRead(sensorPin1);
  float sensor1Convert = value1 / a;
  uint16_t value2 = analogRead(sensorPin2);
  float sensor2Convert = value2 / a;
  uint16_t value3 = analogRead(sensorPin3);
  float sensor3Convert = value3 / a;
  if (sensor1Convert > sensor2Convert and sensor1Convert > sensor3Convert) {
    return (sensor1Convert);
  }
  if (sensor2Convert > sensor1Convert and sensor2Convert > sensor3Convert) {
    return (sensor2Convert);
  }
  else {
    return (sensor3Convert);
  }
}

int minimum() {
  uint16_t value1 = analogRead(sensorPin1);
  float sensor1Convert = value1 / a;
  uint16_t value2 = analogRead(sensorPin2);
  float sensor2Convert = value2 / a;
  uint16_t value3 = analogRead(sensorPin3);
  float sensor3Convert = value3 / a;
  if (sensor1Convert < sensor2Convert and sensor1Convert < sensor3Convert) {
    return (sensor1Convert);
  }
  if (sensor2Convert < sensor1Convert and sensor2Convert < sensor3Convert) {
    return (sensor2Convert);
  }
  else {
    return (sensor3Convert);
  }
}
