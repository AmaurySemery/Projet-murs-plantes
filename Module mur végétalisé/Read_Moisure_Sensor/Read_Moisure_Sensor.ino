int PinLed=2;

void setup() {
// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
pinMode(PinLed,OUTPUT);
}


void loop() {
// read the input on analog pin 0:
int sensorValue = analogRead(A0); 
Serial.print("La valeur retenue par A0 [de 0 (humide) à 1023 (sec)] est de "); 
Serial.print(sensorValue); 
Serial.println(".");
// convert 1023 to 100 (((1023x43.5)x20)/8900.1) => ne fonctionne pas, donc j'ai fait (1023-23)/10)
int a = 43.5;
int b = 20;
int c = 8900.1;
float sensorConvert = sensorValue * a;
float sensorConvert1 = sensorConvert * b;
float sensorConvert2 = sensorConvert1 / c; 
Serial.print("Ce qui donne ");
Serial.print(sensorConvert2);
Serial.println("% d'aridité.");
if (sensorConvert2 > 50) {digitalWrite(PinLed,HIGH);}
else {digitalWrite(PinLed,LOW);}
delay(10000);
}

// Plus la terre sera humide, plus la valeur s’approchera de 0, plus elle sera sèche, plus la valeur s’approchera de 1023.
