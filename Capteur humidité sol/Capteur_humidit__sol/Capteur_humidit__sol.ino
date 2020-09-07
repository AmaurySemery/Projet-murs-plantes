#include <Arduino.h>
#include "gravity_soil_moisture_sensor.h"

GravitySoilMoistureSensor gravity_sensor;

int PinLed=2;

void setup() {

  pinMode(PinLed,OUTPUT);
  Serial.begin(115200);
    uint8_t pin = 15;

    if (!gravity_sensor.Setup(pin)) {
        Serial.println("Gravity Soil Moisture Sensor was not detected. Check wiring!");
        while(1);
    } else {
        Serial.println("Gravity Soil Moisture Sensor init done.");
    }
}

void loop() {
    uint16_t value = gravity_sensor.Read();
int a = 40.95;
int b = 100;
float sensorConvert = value / a;
float sensorConvert1 = b - sensorConvert;
Serial.print("Ce qui donne ");
Serial.print(sensorConvert1);
Serial.println("% d'humidité.");

if (sensorConvert1 < 35) {digitalWrite(PinLed,HIGH);}
else {digitalWrite(PinLed,LOW);}
    

    delay(5000);
}
