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

//LiquidCrystal lcd(25, 14, 23, 13, 22, 21);

int buttonPin=25;
int boutonappui = 0; // variable lorsque j'appuie sur le bouton
int etatbouton = 0; // etat dans lequel se trouve le bouton
int bouton_pasappui = 0;// variable lorsque je n'appuie pas sur le bouton
//int buttonState = 0;
int PinLed=14;
int sensorPin1 = 32;  
int sensorPin2 = 33;
int sensorPin3 = 35;
float a = 40.95;
float b = 100;
float c = 1200;
float d = 29.304;
float g = 3;

void setup() {
//lcd.begin(16, 2);
//lcd.clear();
//lcd.print("Hellow, world!");
//lcd.setCursor(0,1);
//lcd.print("LCD with ESP32");
  pinMode(buttonPin, INPUT_PULLUP);  
  pinMode(PinLed,OUTPUT);
  Serial.begin(115200);
Serial.println("Bienvenue sur le programme Moisture Sensor !");
Serial.println("**********");
Serial.println("Avant de commencer, nous allons procéder à une série de tests.");
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
Serial.print("Dans le programme, a = 40,95, il devrait donc donner ce même résultat : ");
Serial.println(a);
Serial.print("De même, b = 100, le résultat devrait encore être le même : ");
Serial.println(b);
Serial.println("**********");
float e = c / a;
Serial.print("Je fais le calcul 1200/40.95 et ça devrait donner environ 30 : ");
Serial.println(e);
float f = b - d;
Serial.print("Je fais le calcul 100 - 29.304 et ça devrait donner environ 71 : ");
Serial.println(f);
//WiFi.begin(ssid,password);  // Initialisation avec WiFi.begin / ssid et password
//Serial.print("Attente de connexion ...");  // Message d'attente de connexion
//while(WiFi.status() != WL_CONNECTED)  // Test connexion
//{Serial.print(".");  // Affiche des points .... tant que connexion n'est pas OK
//delay(1000);}
//Serial.println("\n");
//Serial.println("Connexion établie !");  // Affiche connexion établie
//Serial.println("Si les tests sont bons, on peut commencer le programme !");
//Serial.println("**********");



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
float somme = sensor1Convert1 + sensor2Convert1 + sensor3Convert1;
float moyenne = somme / g;

Serial.printf("Valeur de l'entrée analogique du capteur 1 : %d\n", value1);
Serial.print("Ce qui donne ");
Serial.print(sensor1Convert1);
Serial.println("% d'humidité.");
Serial.printf("Valeur de l'entrée analogique du capteur 2 : %d\n", value2);
Serial.print("Ce qui donne ");
Serial.print(sensor2Convert1);
Serial.println("% d'humidité.");
Serial.printf("Valeur de l'entrée analogique du capteur 3 : %d\n", value3);
Serial.print("Ce qui donne ");
Serial.print(sensor3Convert1);
Serial.println("% d'humidité.");
Serial.print("La moyenne entre les 3 capteurs donne : ");
Serial.print(moyenne);
Serial.println("% d'humidité.");
if (moyenne < 50) {digitalWrite(PinLed,HIGH);}
else {digitalWrite(PinLed,LOW);}

//int h = moyenne;


//if ((wifiMulti.run() == WL_CONNECTED)) { // Si c'est connecté, ça fait ce qu'il y a en dessous
//    USE_SERIAL.println("[DEBG] " + String(h));

//    USE_SERIAL.print("[HTTP] begin...\n");
// configure traged server and url
    //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
//    http.begin("https://10.130.1.217:1883/h/" + String(h)); //HTTP => démarre connexion vers le serveur mentionné

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

//    http.end();}

delay(50);}
else {Serial.println("**********");
delay(50);}
bouton_pasappui = etatbouton;}
}
