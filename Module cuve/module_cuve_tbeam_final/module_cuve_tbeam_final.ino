#include <UltrasonicSensor.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

UltrasonicSensor ultrasonic(0, 4);
LiquidCrystal_I2C lcd(0x27,16,2);

WiFiMulti wifiMulti;

int hauteur_maxi = 130; // modifier suivant la hauteur de la cuve
const char* ssid = "POP_SENSORS";
const char* password = "P0PS3NS0RS!";

void setup() {
  Serial.begin(115200);
  wifiMulti.addAP(ssid, password);
}

void loop() {
  int distance = ultrasonic.distanceInCentimeters();
  int hauteur_restante = hauteur_maxi - distance;
  int pourcentage = (hauteur_restante * 100) / hauteur_maxi;
  Serial.print("Distance capteur/surface: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.print("Niveau de liquide restant estimé dans la cuve : ");
  Serial.print(hauteur_restante);
  Serial.println(" cm");
  Serial.print("Niveau de remplissage de la cuve : ");
  Serial.print(pourcentage);
  Serial.println(" %");
  Serial.println("-----------------");

if ((wifiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    Serial.println("[DEBG] " + String(distance) + String(hauteur_restante) + String(pourcentage));
    http.begin("http://node03.popschool-willems.fr:1880/mod2/" + String(pourcentage));
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);}}
    else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();}
  
  delay(5000);
}
