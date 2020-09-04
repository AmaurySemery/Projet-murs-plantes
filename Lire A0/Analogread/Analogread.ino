const int entreeAnalogique = 15;  // GPIO 33
      
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(entreeAnalogique));
  delay(500);
}
