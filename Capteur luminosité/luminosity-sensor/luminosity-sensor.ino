int sensorPin = 34; //define analog pin 2
int value = 0;
int alerte = 32;


void setup() {
  Serial.begin(9600);
  Serial.println("Lancement du programme !");
  pinMode(alerte,OUTPUT);

} 

void loop() {
  value = analogRead(sensorPin); 
  Serial.println(value, DEC); // light intensity
                // high values for bright environment
                // low values for dark environment
  if (value<1400)
  {
   digitalWrite(alerte,HIGH);
   Serial.println("Alerte : on");
   delay(2000);
    }
 else {
 digitalWrite(alerte,LOW);
 Serial.println("Alerte : off");
 delay(2000);}


  delay(5000); 
}
