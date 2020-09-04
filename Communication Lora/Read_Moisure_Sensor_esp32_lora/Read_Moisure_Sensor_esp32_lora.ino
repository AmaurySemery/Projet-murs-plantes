#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>  
#include "SSD1306.h" 
#include "images.h"

#define SCK     5    // GPIO5  -- SX1278's SCK
#define MISO    19   // GPIO19 -- SX1278's MISnO
#define MOSI    27   // GPIO27 -- SX1278's MOSI
#define SS      18   // GPIO18 -- SX1278's CS
#define RST     14   // GPIO14 -- SX1278's RESET
#define DI0     26   // GPIO26 -- SX1278's IRQ(Interrupt Request)
#define BAND  433E6

unsigned int counter = 0;

String rssi = "RSSI --";
String packSize = "--";
String packet ;

const int entreeAnalogique = 15;
int PinLed=2;

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
delay(50000);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
delay(1000); // wait for a second
}

// Plus la terre sera humide, plus la valeur s’approchera de 0, plus elle sera sèche, plus la valeur s’approchera de 4095.
