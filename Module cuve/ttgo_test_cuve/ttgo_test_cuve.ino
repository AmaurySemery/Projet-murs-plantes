
#include <UltrasonicSensor.h>

UltrasonicSensor ultrasonic(0, 4);

void setup() {
  Serial.begin(115200);
  
}

void loop() {
  int distance = ultrasonic.distanceInCentimeters();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(5000);
}
