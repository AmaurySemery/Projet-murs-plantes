#include <UltrasonicSensor.h>

UltrasonicSensor ultrasonic(2, 4);

int hauteur_totale = 105; // modifier suivant la hauteur de la cuve


void setup() {
  Serial.begin(115200);
  
}

void loop() {
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
  Serial.println("-----------------");
  delay(5000);
}
