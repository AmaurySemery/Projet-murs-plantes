int PinLed=3;

void setup() {
// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
pinMode(PinLed,OUTPUT);
}


void loop() {
// read the input on analog pin 0:
int sensorValue = analogRead(A0); Serial.println(sensorValue);
// convert 1023 to 100 (((10233x43.5)x20)/8900.1)
byte a = 23;
byte b = 20;
byte c = 8900.1;
int sensorConvert = sensorValue - 23; 
int sensorConvert1 = sensorConvert / 10; Serial.println(sensorConvert1);
if (sensorConvert1 > 60) {digitalWrite(PinLed,HIGH);}
else {digitalWrite(PinLed,LOW);}
delay(10000);
}

// Plus la terre sera humide, plus la valeur s’approchera de 0, plus elle sera sèche, plus la valeur s’approchera de 1023.
