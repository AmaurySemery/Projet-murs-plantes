#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN A0
#define DHTTYPE    DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);

//create an RF24 object
RF24 radio(9, 10);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  radio.begin();
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);

  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature : "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  int temp = event.temperature;
  //Send message to receiver
  const char text[] = temp;
  radio.write(&text);
  
  delay(1000);
}
