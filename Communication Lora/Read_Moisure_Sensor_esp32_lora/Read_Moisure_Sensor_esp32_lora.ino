#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <WiFiMulti.h>

#include <HTTPClient.h>

#define USE_SERIAL Serial
#define moisturepin 15 // Broche sur laquelle est branché le moisure sensor

WiFiMulti wifiMulti;

const char* ssid = "POP_SENSORS";  // Mettre votre SSID Wifi
const char* password = "P0PS3NS0RS!";  // Mettre votre mot de passe Wifi
const int entreeAnalogique = 15;
int PinLed=2;

void setup() {  
  pinMode(PinLed,OUTPUT);
  Serial.begin(115200);   // Initialisation du moniteur série à 115200
  delay(1000);

  Serial.println("\n");
  WiFi.begin(ssid,password);  // Initialisation avec WiFi.begin / ssid et password
  Serial.print("Attente de connexion ...");  // Message d'attente de connexion
  while(WiFi.status() != WL_CONNECTED)  // Test connexion
{Serial.print(".");  // Affiche des points .... tant que connexion n'est pas OK
delay(100);}
  Serial.println("\n");
  Serial.println("Connexion etablie !");  // Affiche connexion établie
}

void loop() { 
int sensorValue = analogRead(entreeAnalogique); 
Serial.print("La valeur retenue par A0 [de 0 (humide) à 4095 (sec)] est de "); 
Serial.print(sensorValue); 
Serial.println(".");
// convert 4095 to 100 (4095/40.95=100)
int a = 40.95;
int b = 100;
float sensorConvert = sensorValue / a;
float sensorConvert1 = b - sensorConvert;
Serial.print("Ce qui donne ");
Serial.print(sensorConvert1);
Serial.println("% d'humidité.");

if (sensorConvert1 < 35) {digitalWrite(PinLed,HIGH);}
else {digitalWrite(PinLed,LOW);

if ((wifiMulti.run() == WL_CONNECTED)) { // Si c'est connecté, ça fait ce qu'il y a en dessous
    HTTPClient http; // va créer un objet qui s'appelle HTTPClient qui va permettre de lancer des requêtes en HTTP
    USE_SERIAL.println("[DEBG] " + String(h));

    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
    http.begin("http://node03.popschool-willems.fr/#flow/b7090afb.bd8ce/H/" + String(h)); //HTTP => démarre connexion vers le serveur mentionné

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
          digitalWrite(4, HIGH);
        }
        if (payload == "OFF") {
          digitalWrite(4, LOW);
        }
      }
    } else { // sinon, il dit que ça ne fonctionne pas
      USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();    }

    delay(5000);
}
