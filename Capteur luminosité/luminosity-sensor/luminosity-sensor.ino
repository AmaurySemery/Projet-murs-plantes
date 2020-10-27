int sensorPin = 35;

void setup() {
  Serial.begin(9600);
}
void loop() {
  int valeur = analogRead(sensorPin);

  Serial.println(valeur);
  delay(250);
}
