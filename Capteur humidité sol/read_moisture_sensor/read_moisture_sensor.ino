#define wait 5000

void setup(){
  // Init serial port (115200 bauds)  
  Serial.begin(115200);
}

void loop() {
 // put your main code here, to run repeatedly:
 int a4 = analogRead(15);  //v1.2

 
 Serial.print("Valeur de l'entrée analogique : ");
 Serial.println(a4);
 delay(wait);
}
