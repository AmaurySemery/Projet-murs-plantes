#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <WiFiMulti.h>
#include <Arduino.h>
#include <HTTPClient.h>
#include "gravity_soil_moisture_sensor.h"
#include <LiquidCrystal.h>

#define USE_SERIAL Serial

GravitySoilMoistureSensor gravity_sensor;
WiFiMulti wifiMulti;
HTTPClient http; // va créer un objet qui s'appelle HTTPClient qui va permettre de lancer des requêtes en HTTP

const char* ssid = "POP_SENSORS";  // Mettre votre SSID Wifi
const char* password = "P0PS3NS0RS!";  // Mettre votre mot de passe Wifi

int sensorPin1 = 32;  
int sensorPin2 = 33;
int sensorPin3 = 35;
float a = 40.95;
float b = 100;
float c = 1200;
float d = 29.304;
float g = 3;

void setup() {
  Serial.begin(115200);
    if (!gravity_sensor.Setup(sensorPin1)) {
        Serial.println("Le capteur 1 d'humidité au sol n'a pas été détecté.");
        while(1);
    } else {
        Serial.println("Le capteur 1 d'humidité au sol est opérationnel !");
    }
        if (!gravity_sensor.Setup(sensorPin2)) {
        Serial.println("Le capteur 2 d'humidité au sol n'a pas été détecté.");
        while(1);
    } else {
        Serial.println("Le capteur 2 d'humidité au sol est opérationnel !");
    }
        if (!gravity_sensor.Setup(sensorPin3)) {
        Serial.println("Le capteur 3 d'humidité au sol n'a pas été détecté.");
        while(1);
    } else {
        Serial.println("Le capteur 3 d'humidité au sol est opérationnel !");
    }
    
    USE_SERIAL.begin(115200);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);}
wifiMulti.addAP(ssid,password);
}


void loop() {
uint16_t value1 = analogRead(sensorPin1);
int sensor1Convert = value1 / a;
uint16_t value2 = analogRead(sensorPin2);
int sensor2Convert = value2 / a;
uint16_t value3 = analogRead(sensorPin3);
int sensor3Convert = value3 / a;
int somme = sensor1Convert + sensor2Convert + sensor3Convert;
int moyenne = somme / g;

// Affichage des données sur le moniteur

Serial.print("Sensor 1 : ");
Serial.print(sensor1Convert);
Serial.println(" %");
Serial.print("Sensor 2 : ");
Serial.print(sensor2Convert);
Serial.println(" %");
Serial.print("Sensor 3 : ");
Serial.print(sensor3Convert);
Serial.println(" %");
Serial.println("*****");

int sen1 = sensor1Convert;
int sen2 = sensor2Convert;
int sen3 = sensor3Convert;
int mi = minimum();
int ma = maximum();
int al = alerte();
int moy = moyenne;

if ((wifiMulti.run() == WL_CONNECTED)) { // Si c'est connecté, ça fait ce qu'il y a en dessous
    USE_SERIAL.println("[DEBG] " + String(sen1)+ String(sen2) + String(sen3) + String(mi) + String(ma) + String(al) + String(moy));

    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
    http.begin("http://node03.popschool-willems.fr/sen1/" + String(sen1)+"/sen2/"+ String(sen2)+"/sen3/"+ String(sen3)+"/mi/"+ String(mi)+"/ma/"+ String(ma)+"/al/"+ String(al)+"/moy"+ String(moy)); //HTTP => démarre connexion vers le serveur mentionné

    USE_SERIAL.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET(); // soumet une requête de type "get", puis récupère résultat qui sera collée dans HTTP

    // httpCode will be negative on error
    if (httpCode > 0) { // si c'est supérieur à 0, il refait un test)
      // HTTP header has been send and Server response header has been handled
      USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) { // Si ça s'est bien passé, il refait une variable où il met le getString puis affiche à l'écran => on a reçu un code 200
        String payload = http.getString();
        USE_SERIAL.println(payload);
        if (payload == "ON") {
        Serial.println("Serveur trouvé !");
        }
        if (payload == "OFF") {
        Serial.println("Le serveur n'a pas été trouvé.");
        }
      }
    } else { // sinon, il dit que ça ne fonctionne pas
     USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    }
    http.end();
    delay(10000);}

int maximum(){
uint16_t value1 = analogRead(sensorPin1);
float sensor1Convert = value1 / a;
uint16_t value2 = analogRead(sensorPin2);
float sensor2Convert = value2 / a;
uint16_t value3 = analogRead(sensorPin3);
float sensor3Convert = value3 / a;
if(sensor1Convert>sensor2Convert and sensor1Convert>sensor3Convert){
  return(sensor1Convert);}
if(sensor2Convert>sensor1Convert and sensor2Convert>sensor3Convert){
  return(sensor2Convert);}
else{
  return(sensor3Convert);}}

int minimum(){
uint16_t value1 = analogRead(sensorPin1);
float sensor1Convert = value1 / a;
uint16_t value2 = analogRead(sensorPin2);
float sensor2Convert = value2 / a;
uint16_t value3 = analogRead(sensorPin3);
float sensor3Convert = value3 / a;
if(sensor1Convert<sensor2Convert and sensor1Convert<sensor3Convert){
  return(sensor1Convert);}
if(sensor2Convert<sensor1Convert and sensor2Convert<sensor3Convert){
  return(sensor2Convert);}
else{
  return(sensor3Convert);}}

int alerte(){
if (maximum()-minimum() >= 10){
  return(1);}
else{
  return(0);}}
