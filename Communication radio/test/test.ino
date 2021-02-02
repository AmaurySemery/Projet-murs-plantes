// SimpleTx - the master or the transmitter
#include <printf.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


#define CE_PIN   9
#define CSN_PIN 10

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL,0xF0F0F0F0D2LL };


RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

char dataToSend[10] = "Message";
char txNum = '0';


unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second


void setup() {

    Serial.begin(9600);

    Serial.println("SimpleTx Starting");

    radio.begin();
    radio.setChannel(9);
    radio.setAutoAck(0);
    radio.setRetries(15,15);
    radio.setDataRate(RF24_1MBPS);
    radio.setPALevel(RF24_PA_MIN);
    radio.setPayloadSize(32);
    radio.openReadingPipe(1,pipes[0]);
    radio.openWritingPipe(pipes[1]);
    radio.stopListening();
    radio.setCRCLength(RF24_CRC_DISABLED);
    radio.powerUp(); //alimente le module nrf24l01+

    printf_begin();  
    radio.printDetails();                   // Dump the configuration of the rf unit for debugging
    //Serial.println(radio.available());

}

void loop() {
    currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {
    bool rslt;
    Serial.println(dataToSend);
    rslt = radio.write( &dataToSend, sizeof(dataToSend) );
    // Always use sizeof() as it gives the size as the number of bytes.
    // For example if dataToSend was an int sizeof() would correctly return 2
        prevMillis = millis();
    }
}
