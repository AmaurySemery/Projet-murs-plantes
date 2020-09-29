#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <WiFiMulti.h>
#include <Arduino.h>
#include <HTTPClient.h>
#include "gravity_soil_moisture_sensor.h"
#include <LiquidCrystal.h>

#define USE_SERIAL Serial

LiquidCrystal LCD (4, 23, 25, 14, 13, 15);

GravitySoilMoistureSensor gravity_sensor;
WiFiMulti wifiMulti;
const char* ssid = "POP_SENSORS";  // Mettre votre SSID Wifi
const char* password = "P0PS3NS0RS!";  // Mettre votre mot de passe Wifi

int mn5 = 300000;
int mn10 = 600000;
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
  LCD.begin(16, 2) ;
  if (!gravity_sensor.Setup(sensorPin1)) {
    Serial.println("Le capteur 1 d'humidité au sol n'a pas été détecté.");
    LCD.print("Attention !");
    LCD.setCursor(0, 1);
    LCD.print("Erreur capteur 1");
    delay(3000);
    LCD.clear();
  } else {
    Serial.println("Le capteur 1 d'humidité au sol est opérationnel !");
    LCD.print("Capteur 1 :");
    LCD.setCursor(0, 1);
    LCD.print("OK !");
    delay(3000);
    LCD.clear();
  }
  if (!gravity_sensor.Setup(sensorPin2)) {
    Serial.println("Le capteur 2 d'humidité au sol n'a pas été détecté.");
    LCD.print("Attention !");
    LCD.setCursor(0, 1);
    LCD.print("Erreur capteur 2");
    delay(3000);
    LCD.clear();
  } else {
    Serial.println("Le capteur 2 d'humidité au sol est opérationnel !");
    LCD.print("Capteur 2 :");
    LCD.setCursor(0, 1);
    LCD.print("OK !");
    delay(3000);
    LCD.clear();
  }
  if (!gravity_sensor.Setup(sensorPin3)) {
    Serial.println("Le capteur 3 d'humidité au sol n'a pas été détecté.");
    LCD.print("Attention !");
    LCD.setCursor(0, 1);
    LCD.print("Erreur capteur 3");
    delay(3000);
    LCD.clear();
  } else {
    Serial.println("Le capteur 3 d'humidité au sol est opérationnel !");
    LCD.print("Capteur 3 :");
    LCD.setCursor(0, 1);
    LCD.print("OK !");
    delay(3000);
    LCD.clear();
  }


  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  wifiMulti.addAP(ssid, password);

  LCD.print("Lancement du");
  LCD.setCursor(0, 1);
  LCD.print("programme !");
  delay(3000);
  LCD.clear();

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

  Serial.print("{\"sensor1\":");
  Serial.print(sensor1Convert);
  Serial.print(",\"sensor2\":");
  Serial.print(sensor2Convert);
  Serial.print(",\"sensor3\":");
  Serial.print(sensor3Convert);
  Serial.print(",\"minimum\":");
  Serial.print(minimum());
  Serial.print(",\"maximum\":");
  Serial.print(maximum());
  Serial.print(",\"alerte\":");
  Serial.print(alerte());
  Serial.print(",\"moyenne\":");
  Serial.print(moyenne);
  Serial.println("}");

  int sen1 = sensor1Convert;
  int sen2 = sensor2Convert;
  int sen3 = sensor3Convert;
  int mi = minimum();
  int ma = maximum();
  int al = alerte();
  int moy = moyenne;


  if ((wifiMulti.run() == WL_CONNECTED)) { // Si c'est connecté, ça fait ce qu'il y a en dessous

    HTTPClient http; // va créer un objet qui s'appelle HTTPClient qui va permettre de lancer des requêtes en HTTP

    USE_SERIAL.println("[DEBG] " + String(sen1) + String(sen2) + String(sen3) + String(mi) + String(ma) + String(al) + String(moy));

    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS

    http.begin("http://node03.popschool-willems.fr:1880/mod1/" + String(sen1)+ "/" + String(sen2) + "/" +String(sen3) ); //HTTP => démarre connexion vers le serveur mentionné/

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
      LCD.print("Retour HTTP :");
      LCD.setCursor(0, 1);
      LCD.print(payload);
        if (payload == "50") {
          USE_SERIAL.println("Coucou");
        }
        if (payload == "OFF") {
          digitalWrite(4, LOW);
        }
      }
    } else { // sinon, il dit que ça ne fonctionne pas
      USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      LCD.print("Erreur :");
      LCD.setCursor(0, 1);
      LCD.print("Requete HTTP");
    }
    http.end();
  }
  delay(mn10);
  LCD.clear();
  
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

int alerte() {
  if (maximum() - minimum() >= 10) {
    LCD.print("Mesures Err :");
    LCD.setCursor(0, 1);
    LCD.print("Min:");
    LCD.print(minimum());
    LCD.print(" ; ");
    LCD.print("Max:");
    LCD.print(maximum());
    delay(3000);
    LCD.clear();
    return (1);
  }
  else {
    LCD.print("Mesures OK :");
    LCD.setCursor(0, 1);
    LCD.print("Min:");
    LCD.print(minimum());
    LCD.print(" ; ");
    LCD.print("Max:");
    LCD.print(maximum());
    delay(3000);
    LCD.clear();
    return (0);
  }
}
