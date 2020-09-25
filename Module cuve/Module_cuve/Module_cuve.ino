#include <HCSR04.h>

// defines pins numbers / definition des broches du capteur
const int trigPin = 13;
const int echoPin = 2;
int maDistance = 0;
int hauteur_maxi = 10;
int hauteur_restante;
float pourcentage;
 
// Initialize sensor that uses digital pins trigPin and echoPin / initialisation du capteur avec les broches utilisees.
UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);
void setup() {
  // We initialize serial connection so that we could print values from sensor./ initialisation du port serie a 9600 band pour afficher les valeurs mesurees par le capteur.
  Serial.begin(115200); 
}
void loop() {
  // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters./ toutes les 500 millisecondes nous faisons une mesure et nous affichons la distance en centimetre sur le port serie.
  maDistance = distanceSensor.measureDistanceCm();
  Serial.println(maDistance);
  hauteur_restante = hauteur_maxi - maDistance;

 Serial.print("hauteur restante : ");
 Serial.println( hauteur_restante);

pourcentage = (hauteur_restante * 100) / hauteur_maxi;

Serial.print("pourcentage : ");
Serial.print( pourcentage, 2);
Serial.println(" %");
  delay(5000);
}
