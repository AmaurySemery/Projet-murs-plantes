#include <HCSR04.h>    

const int trigPin = RX;
const int echoPin = TX;
int maDistance = 0;

UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);


void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(115200);
}

void loop() {
maDistance = distanceSensor.measureDistanceCm();
Serial.println(maDistance);
delay(5000);
}
