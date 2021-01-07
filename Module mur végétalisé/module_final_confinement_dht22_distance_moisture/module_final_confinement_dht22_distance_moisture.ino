#include <UltrasonicSensor.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN A0
#define DHTTYPE    DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);

UltrasonicSensor ultrasonic(2, 4);

int hauteur_totale = 105; // modifier suivant la hauteur de la cuve


void setup() {
  Serial.begin(115200);
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
  Serial.println("-----------------");
  delay(5000);
}
