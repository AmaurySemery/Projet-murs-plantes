const int entreeAnalogique = 35;  // GPIO 33
      
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(analogRead(entreeAnalogique));
  delay(500);
}
