const int entreeAnalogique = 15;
int PinLed=2;

String rssi = "RSSI --";
String packSize = "--";
String packet ;

void setup() {
// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
pinMode(PinLed,OUTPUT);
}


void loop() {
// read the input on analog pin 0:
int sensorValue = analogRead(entreeAnalogique); 
Serial.print("La valeur retenue par A0 [de 0 (humide) à 4095 (sec)] est de "); 
Serial.print(sensorValue); 
Serial.println(".");
// convert 4095 to 100 (4095/40.95=100)
int a = 40.95;
int b = 100;
float sensorConvert = sensorValue / a;
float sensorConvert1 = b - sensorConvert;
Serial.print("Ce qui donne ");
Serial.print(sensorConvert1);
Serial.println("% d'humidité.");
if (sensorConvert1 < 35) {digitalWrite(PinLed,HIGH);}
else {digitalWrite(PinLed,LOW);}
delay(10000);
}

// Plus la terre sera humide, plus la valeur s’approchera de 0, plus elle sera sèche, plus la valeur s’approchera de 4095.
