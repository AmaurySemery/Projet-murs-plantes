int sensorPin = 34; //define analog pin 2
int value = 0; 

void setup() {
  Serial.begin(9600);
  Serial.println("Lancement du programme !");
} 

void loop() {
  value = analogRead(sensorPin); 
  Serial.println(value, DEC); // light intensity
                // high values for bright environment
                // low values for dark environment
  delay(5000); 
}
