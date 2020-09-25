#include <HCSR04.h>
#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <Arduino.h>

#define USE_SERIAL Serial

// defines pins numbers / definition des broches du capteur
const int trigPin = 13;
const int echoPin = 2;
int maDistance = 0;
int hauteur_maxi = 10;
int hauteur_restante;
float pourcentage;
WiFiMulti wifiMulti;
const char* ssid = "POP_SENSORS";  // Mettre votre SSID Wifi
const char* password = "P0PS3NS0RS!";  // Mettre votre mot de passe Wifi
 
// Initialize sensor that uses digital pins trigPin and echoPin / initialisation du capteur avec les broches utilisees.
UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);
void setup() {
  // We initialize serial connection so that we could print values from sensor./ initialisation du port serie a 9600 band pour afficher les valeurs mesurees par le capteur.
  Serial.begin(115200);
  wifiMulti.addAP(ssid, password);
}
void loop() {
  // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters./ toutes les 500 millisecondes nous faisons une mesure et nous affichons la distance en centimetre sur le port serie.
  maDistance = distanceSensor.measureDistanceCm();
  hauteur_restante = hauteur_maxi - maDistance;

 Serial.print("Contenu : ");
 Serial.print( hauteur_restante);
 Serial.println(" cm.");

pourcentage = (hauteur_restante * 100) / hauteur_maxi;

Serial.print("Niveau de remplissage de la cuve : ");
Serial.print( pourcentage, 2);
Serial.println(" %");
if ((wifiMulti.run() == WL_CONNECTED)) { // Si c'est connecté, ça fait ce qu'il y a en dessous

    HTTPClient http; // va créer un objet qui s'appelle HTTPClient qui va permettre de lancer des requêtes en HTTP

    USE_SERIAL.println("[DEBG] " + String(maDistance) + String(hauteur_restante) + String(pourcentage));

    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS

    http.begin("http://node03.popschool-willems.fr:1880/mod2/" + String(pourcentage)); //HTTP => démarre connexion vers le serveur mentionné/

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
      Serial.print(payload);
        if (payload == "50") {
          USE_SERIAL.println("Coucou");
        }
        if (payload == "OFF") {
          digitalWrite(4, LOW);
        }
      }
    } else { // sinon, il dit que ça ne fonctionne pas
      USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();}
  delay(5000);
}
