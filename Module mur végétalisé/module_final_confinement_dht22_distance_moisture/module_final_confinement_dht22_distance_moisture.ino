#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <UltrasonicSensor.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN A0
#define DHTTYPE    DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);
WiFiMulti wifiMulti;

const char* ssid = "freebox_IPLMWO";
const char* password = "F4CAE54A9B34";

UltrasonicSensor ultrasonic(2, 4);

int hauteur_totale = 105; // modifier suivant la hauteur de la cuve
int sensorPin = A1;
float a = 40.95;
int b = 100;

void setup() {
  Serial.begin(115200);
  wifiMulti.addAP(ssid, password);
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
}

void loop() {
  sensors_event_t event;
  dht.temperature().getEvent(&event);

  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature : "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  int distance = ultrasonic.distanceInCentimeters();
  int hauteur_restante = hauteur_totale - distance;
  int pourcentage = (hauteur_restante * 100) / hauteur_totale;
  Serial.print("Distance capteur/surface: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.print("Niveau de liquide restant estimé dans la cuve : ");  
  Serial.print(hauteur_restante);
  Serial.println(" cm");
  Serial.print("Niveau de remplissage de la cuve : ");
  Serial.print(pourcentage);
  Serial.println(" %");

  uint16_t value = analogRead(sensorPin);
  float division = value / a;
  int sensorconvert = b - division;
  Serial.print("Pourcentage d'humidité du mur végétalisé : ");
  Serial.print(sensorconvert);
  Serial.println(" %");
  Serial.println("----------------");

  int sen = sensorconvert;
  int temp = event.temperature;

  if((wifiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;
        
        Serial.println("[DEBG] " + String(sen) + String(temp) + String(distance) + String(hauteur_restante) + String(pourcentage));
        http.begin("http://node03.popschool-willems.fr:1880/mod1/" + String(sen)+ "/" +String(temp) + "/" + String(pourcentage));
        int httpCode = http.GET();
        if(httpCode > 0) {
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                Serial.println("Réception du message à partir de Node-Red : ok");
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
            Serial.println("Réception du message à partir de Node-Red : échec");
        }

        http.end();
    }
  delay(5000);
}
