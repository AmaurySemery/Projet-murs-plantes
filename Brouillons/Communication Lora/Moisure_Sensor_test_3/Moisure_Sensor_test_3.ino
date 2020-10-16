#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <WiFiMulti.h>
#include <Arduino.h>
#include <HTTPClient.h>
#include "gravity_soil_moisture_sensor.h"

#define USE_SERIAL Serial


GravitySoilMoistureSensor gravity_sensor;
WiFiMulti wifiMulti;

#define gravity_sensor_pin 15

const char* ssid = "POP_SENSORS";  // Mettre votre SSID Wifi
const char* password = "P0PS3NS0RS!";  // Mettre votre mot de passe Wifi

byte bGlobalErr;
int PinLed=2;
char MS_dat[5];


void setup() {

InitMS();
InitLED();
Serial.begin(115200);

    if (!gravity_sensor.Setup(PinCap)) {
        Serial.println("Le capteur d'humidité au sol n'a pas été détecté.");
        while(1);
    } else {
        Serial.println("Le capteur d'humidité au sol est opérationnel !");
    }
Serial.println("\n");
  WiFi.begin(ssid,password);  // Initialisation avec WiFi.begin / ssid et password
  Serial.print("Attente de connexion ...");  // Message d'attente de connexion
  while(WiFi.status() != WL_CONNECTED)  // Test connexion
{Serial.print(".");  // Affiche des points .... tant que connexion n'est pas OK
delay(100);}
  Serial.println("\n");
  Serial.println("Connexion établie !");  // Affiche connexion établie

}

void InitMS() 
// Initialise le capteur Moisture sensor
{pinMode(gravity_sensor_pin, OUTPUT);}

void InitLED()
// Initialise la Led
{pinMode(PinLed,OUTPUT);}

void ReadMS()
// Lit la valeur d'humidité du sol
{
bGlobalErr = 0;
byte MS_in;
byte i;

MS_in = digitalRead(gravity_sensor_pin);
if(MS_in){
  bGlobalErr=1;
  return;}
MS_in = digitalRead(gravity_sensor_pin);

if(!MS_in){
  bGlobalErr=2;
  return;}
for(i=0;i<5;i++)
MS_dat[i] = read_MS_dat();
pinMode(gravity_sensor_pin,OUTPUT);
byte MS_check_sum = MS_dat[0]+MS_dat[1]+MS_dat[2]+MS_dat[3];
if(MS_dat[4]!=MS_check_sum)
bGlobalErr=3;
}

byte read_MS_dat(){
  byte i=0;
  byte result=0;
  for(i=0;i<8;i++)
  {while(digitalRead(gravity_sensor_pin)==LOW);
  if(digitalRead(gravity_sensor_pin)==HIGH)
  result |=(1<<(7-i));
  while(digitalRead(gravity_sensor_pin)==HIGH);}
  return result;
    
  }

uint16_t calcByte(uint16_t crc, uint8_t b)
{
uint32_t i;
crc = crc ^ (uint32_t)b << 8; 
for ( i = 0; i < 8; i++)
{
if ((crc & 0x8000) == 0x8000)
crc = crc << 1 ^ 
0x1021;
else
crc = crc << 1;
}
return crc & 0xffff;
}

uint16_t CRC16(uint8_t *pBuffer,uint32_t length)
{
uint16_t wCRC16 = 0;
uint32_t i;
if (( pBuffer == 0 )||( length == 0 ))
{
return 0;
}
for ( i = 0; i < length; i++)
{
wCRC16 = calcByte(wCRC16, pBuffer[i]);
}
return wCRC16;
}

void loop() {

ReadMS();
char data[50] = {0} ;
// Utiliser Data[0]. Data[1], Data[2] pour exprimer le deviceID.
data[0] = X;
data[1] = X;
data[2] = X;
data[3] = MS_dat[0]; 
// ajouter la valeur de l'humidité

switch (bGlobalErr) 
// traiter le retour de lecture 
{
case 0:
Serial.print("Humdity = ");
Serial.print(data
[3], DEC); 
Serial.print("% 
");
break;
case 1:
Serial.println("Error 1: MS start condition 1 not met.");
break;
case 2:
Serial.println("Error 2: MS start condition 2 not met.");
break;
case 3:
Serial.println("Error 3: MS checksum error.");
break;
default:
Serial.println("Error: Unrecognized code encountered.");
break
;
}


uint16_t value = gravity_sensor.Read(PinCap);
int a = 40.95;
int b = 100;
float sensorConvert = value / a;
float sensorConvert1 = b - sensorConvert;
Serial.printf("Valeur de l'entrée analogique du capteur : %d\n", value);
Serial.print("Ce qui donne ");
Serial.print(sensorConvert1);
Serial.println("% d'humidité.");
if (sensorConvert1 < 35) {digitalWrite(PinLed,HIGH);}
else {digitalWrite(PinLed,LOW);}

int h = sensorConvert1;


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
