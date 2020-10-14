
#include <UltrasonicSensor.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

UltrasonicSensor ultrasonic(0, 4);
LiquidCrystal_I2C lcd(0x27,16,2);

int hauteur_maxi = 100; // modifier suivant la hauteur de la cuve

void setup() {
  Serial.begin(115200);
}

void loop() {
  int distance = ultrasonic.distanceInCentimeters();
  int hauteur_restante = hauteur_maxi - distance;
  int pourcentage = (distance * 100) / hauteur_maxi;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.print("Niveau de remplissage de la cuve : ");
  Serial.print(pourcentage);
  Serial.println(" %");
  Serial.println("-----------------");
  delay(5000);
}
