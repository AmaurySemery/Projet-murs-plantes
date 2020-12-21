#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 33
#define DHTTYPE    DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);
WiFiMulti wifiMulti;

const char* ssid = "freebox_IPLMWO";
const char* password = "F4CAE54A9B34";

int sensorPin = 35;
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
        
        Serial.println("[DEBG] " + String(sen) + String(temp));
        http.begin("http://node03.popschool-willems.fr:1880/mod1/" + String(sen)+ "/" +String(temp));
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

  delay(10000000);
  }
