#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

WiFiMulti wifiMulti;

const char* ssid = "POP_SENSORS";
const char* password = "P0PS3NS0RS!";

int sensorPin1 = 32;
int sensorPin2 = 34;
int sensorPin3 = 35;
float a = 40.95;
int b = 100;


void setup() {
  Serial.begin(115200);
wifiMulti.addAP(ssid, password);
  }

void loop() {
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

    if((wifiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;

        Serial.print("[HTTP] begin...\n");
        // configure traged server and url
        //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
        http.begin("http://example.com/index.html"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

  delay(5000);}
