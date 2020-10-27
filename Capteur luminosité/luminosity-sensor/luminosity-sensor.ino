void setup() {
  Serial.begin(115200);
  Serial.println("On ouvre le programme pour capter la lumière !");
}
void loop() {
  int valeur = analogRead(A0);

  Serial.println(valeur);
  delay(5000);
}
