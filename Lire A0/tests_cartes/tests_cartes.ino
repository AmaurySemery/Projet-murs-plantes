#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <WiFiMulti.h>
#include <Arduino.h>
#include <HTTPClient.h>
#include "gravity_soil_moisture_sensor.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

GravitySoilMoistureSensor gravity_sensor;
