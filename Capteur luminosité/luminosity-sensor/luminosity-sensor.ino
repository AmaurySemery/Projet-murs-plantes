int sensorPin = 34; //define analog pin 2
int value = 0;
int alerte = 32;
int redpin = 18; //select the pin for the red LED
int bluepin =19; // select the pin for the  blue LED
int greenpin = 21;// select the pin for the green LED

void setup() {
  Serial.begin(9600);
  Serial.println("Lancement du programme !");
  pinMode(alerte,OUTPUT);
  pinMode(redpin, OUTPUT);
   pinMode(bluepin, OUTPUT);
   pinMode(greenpin, OUTPUT);}

 

void loop() {
  value = analogRead(sensorPin); 

  if (value<1000)
  {
    Serial.println(value, DEC);
     // light intensity
     // high values for bright environment
     // low values for dark environment
   digitalWrite(alerte,HIGH);
   digitalWrite(redpin,HIGH);
   digitalWrite(bluepin,LOW);
   digitalWrite(greenpin,LOW);
   delay(2000);
    }
 if (value>1000 and value<1000) {
  Serial.println(value, DEC);
 digitalWrite(alerte,LOW);
 digitalWrite(greenpin,HIGH);
   digitalWrite(redpin,LOW);
   digitalWrite(bluepin,LOW);
 delay(2000);}

 if (value>2000){
  Serial.println(value, DEC);
  digitalWrite(alerte,LOW);
  digitalWrite(bluepin,HIGH);
   digitalWrite(redpin,LOW);
   digitalWrite(greenpin,LOW);
   delay(2000);
 }

  delay(5000); 
}
