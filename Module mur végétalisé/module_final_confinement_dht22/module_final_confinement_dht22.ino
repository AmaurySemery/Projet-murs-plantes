#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4
#define DHTTYPE    DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);
WiFiMulti wifiMulti;

const char* ssid = "freebox_IPLMWO";
const char* password = "F4CAE54A9B34";

int sensorPin1 = 34;
int sensorPin2 = 32;
int sensorPin3 = 35;
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
  
  uint16_t value1 = analogRead(sensorPin1);
  float division1 = value1 / a;
  int sensor1convert = b - division1;
  Serial.println("Pourcentage d'humidité du mur végétalisé :");
  Serial.print("Capteur 1 : ");
  Serial.print(sensor1convert);
  Serial.println(" %");
  uint16_t value2 = analogRead(sensorPin2);
  float division2 = value2 / a;
  int sensor2convert = b - division2;
  Serial.print("Capteur 2 : ");
  Serial.print(sensor2convert);
  Serial.println(" %");
  uint16_t value3 = analogRead(sensorPin3);
  float division3 = value3 / a;
  int sensor3convert = b - division3;
  Serial.print("Capteur 3 : ");
  Serial.print(sensor3convert);
  Serial.println(" %");
  Serial.println("----------------");

  int sen1 = sensor1convert;
  int sen2 = sensor2convert;
  int sen3 = sensor3convert;
  int temp = event.temperature;

    if((wifiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;
        
        Serial.println("[DEBG] " + String(sen1) + String(sen2) + String(sen3) + String(temp));
        http.begin("http://node03.popschool-willems.fr:1880/mod1/" + String(sen1)+ "/" + String(sen2) + "/" +String(sen3)+ "/" +String(temp));
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

  delay(720000);}
