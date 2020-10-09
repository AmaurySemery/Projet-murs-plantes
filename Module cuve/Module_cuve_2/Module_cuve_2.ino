#include <HCSR04.h>      
#include <WiFi.h>  // Utilisation de la librairie WiFi.h
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <Arduino.h>

//#define USE_SERIAL Serial

LiquidCrystal_I2C lcd(0x2F,16,2);

// Le capteur SR04M a une portée de 20cm à 8m

const int trigPin = 11;
const int echoPin = 12;
int maDistance = 0;
int hauteur_maxi = 10;
int hauteur_restante;
float pourcentage;

UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);

void setup() {
lcd.init();
 lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Lancement du");
  lcd.setCursor(0,1);
  lcd.print("programme !");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
    Serial.begin(115200);


}
void loop() {maDistance = distanceSensor.measureDistanceCm();
  Serial.println(maDistance);
  hauteur_restante = hauteur_maxi - maDistance;

 Serial.print("Contenu : ");
 Serial.print( hauteur_restante);
 Serial.println(" cm.");

pourcentage = (hauteur_restante * 100) / hauteur_maxi;

Serial.print("Niveau de remplissage de la cuve : ");
Serial.print( pourcentage, 2);
delay(5000);
}
