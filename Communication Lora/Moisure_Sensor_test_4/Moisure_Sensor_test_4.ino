#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <WiFiMulti.h>
#include <Arduino.h>
#include <HTTPClient.h>
#include "gravity_soil_moisture_sensor.h"

#define USE_SERIAL Serial

GravitySoilMoistureSensor gravity_sensor;
WiFiMulti wifiMulti;
HTTPClient http; // va créer un objet qui s'appelle HTTPClient qui va permettre de lancer des requêtes en HTTP

const char* ssid = "POP_SENSORS";  // Mettre votre SSID Wifi
const char* password = "P0PS3NS0RS!";  // Mettre votre mot de passe Wifi

int buttonPin=15;
int boutonappui = 0; // variable lorsque j'appuie sur le bouton
int etatbouton = 0; // etat dans lequel se trouve le bouton
int bouton_pasappui = 0;// variable lorsque je n'appuie pas sur le bouton
//int buttonState = 0;
int PinLed1=2;
int PinLed2=13;
int PinLed3=14;
int sensorPin1 = 32;  
int sensorPin2 = 33;
int sensorPin3 = 35;
int a = 40.95;
int b = 100;


void setup() {

  pinMode(buttonPin, INPUT_PULLUP);  
  pinMode(PinLed1,OUTPUT);
  pinMode(PinLed2,OUTPUT);
  pinMode(PinLed3,OUTPUT);
  Serial.begin(115200);
Serial.println("Bienvenue sur le programme Moisture Sensor");
//    if (!gravity_sensor.Setup(entreeAnalogique)) {
//        Serial.println("Le capteur d'humidité au sol n'a pas été détecté.");
//        while(1);
//    } else {
//        Serial.println("Le capteur d'humidité au sol est opérationnel !");
//    }
//  WiFi.begin(ssid,password);  // Initialisation avec WiFi.begin / ssid et password
//  Serial.print("Attente de connexion ...");  // Message d'attente de connexion
//  while(WiFi.status() != WL_CONNECTED)  // Test connexion
//{Serial.print(".");  // Affiche des points .... tant que connexion n'est pas OK
//delay(100);}
//  Serial.println("\n");
//  Serial.println("Connexion établie !");  // Affiche connexion établie

}


void loop() {
etatbouton = digitalRead(buttonPin);
if (etatbouton != bouton_pasappui){
if (etatbouton == LOW) {
uint16_t value1 = analogRead(sensorPin1);
float sensor1Convert1 = value1 / a;
float sensor1Convert2 = b - sensor1Convert1;
uint16_t value2 = analogRead(sensorPin2);
float sensor2Convert1 = value2 / a;
float sensor2Convert2 = b - sensor2Convert1;
uint16_t value3 = analogRead(sensorPin3);
float sensor3Convert1 = value3 / a;
float sensor3Convert2 = b - sensor3Convert1;

Serial.printf("Valeur de l'entrée analogique du capteur 1 : %d\n", value1);
Serial.print("Ce qui donne ");
Serial.print(sensor1Convert2);
Serial.println("% d'humidité.");
if (sensor1Convert2 < 35) {digitalWrite(PinLed1,HIGH);}
else {digitalWrite(PinLed1,LOW);}
Serial.printf("Valeur de l'entrée analogique du capteur 2 : %d\n", value2);
Serial.print("Ce qui donne ");
Serial.print(sensor2Convert2);
Serial.println("% d'humidité.");
if (sensor2Convert2 < 60) {digitalWrite(PinLed2,HIGH);}
else {digitalWrite(PinLed2,LOW);}
Serial.printf("Valeur de l'entrée analogique du capteur 3 : %d\n", value3);
Serial.print("Ce qui donne ");
Serial.print(sensor3Convert2);
Serial.println("% d'humidité.");
if (sensor3Convert2 < 35) {digitalWrite(PinLed3,HIGH);}
else {digitalWrite(PinLed3,LOW);}
delay(50);}
else {Serial.println("**********");
delay(50);}
bouton_pasappui = etatbouton;}

//int h = sensorConvert1;


//if ((wifiMulti.run() == WL_CONNECTED)) { // Si c'est connecté, ça fait ce qu'il y a en dessous
//    USE_SERIAL.println("[DEBG] " + String(h));

//    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
//    http.begin("https://192.168.1.200:1883/h/" + String(h)); //HTTP => démarre connexion vers le serveur mentionné

//    USE_SERIAL.print("[HTTP] GET...\n");
    // start connection and send HTTP header
//    int httpCode = http.GET(); // soumet une requête de type "get", puis récupère résultat qui sera collée dans HTTP

    // httpCode will be negative on error
//    if (httpCode > 0) { // si c'est supérieur à 0, il refait un test)
      // HTTP header has been send and Server response header has been handled
//      USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
//      if (httpCode == HTTP_CODE_OK) { // Si ça s'est bien passé, il refait une variable où il met le getString puis affiche à l'écran => on a reçu un code 200
//        String payload = http.getString();
//        USE_SERIAL.println(payload);
//        if (payload == "ON") {
//          digitalWrite(4, HIGH);
//        }
//        if (payload == "OFF") {
//          digitalWrite(4, LOW);
//        }
//      }
//    } else { // sinon, il dit que ça ne fonctionne pas
//      USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
//    }

//    http.end();    }
}
