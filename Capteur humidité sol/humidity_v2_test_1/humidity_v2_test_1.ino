#define wait 5000

void setup(){
  Serial.begin(115200);
}

void loop() {
 //Read YL-69 value
 int a5 = analogRead(2); 
 
 Serial.print("{\"YL69\":");
 Serial.print(a5);
 Serial.println("}");
 delay(wait);
}
