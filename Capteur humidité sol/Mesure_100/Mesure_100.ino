int PinLed=3;

void setup() {
// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
pinMode(PinLed,OUTPUT);
}


void loop() {
// read the input on analog pin 0:
int sensorValue = analogRead(A0); Serial.println(sensorValue);
byte a = 43.5;
byte b = 20;
byte c = 8900.1;
int sensorConvert = sensorValue * a; 
int sensorConvert1 = sensorConvert * b;
int sensorConvert2 = sensorConvert1 / c; Serial.println(sensorConvert2);
if (sensorConvert2 > 60) {digitalWrite(PinLed,HIGH);}
else {digitalWrite(PinLed,LOW);}
delay(10000);
}

// Plus la terre sera humide, plus la valeur s’approchera de 0, plus elle sera sèche, plus la valeur s’approchera de 1023.
