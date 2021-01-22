#include <SoftwareSerial.h>
#include <SPI.h>
#include <NRFLite.h>

SoftwareSerial myserial(7, 8); //Define virtual serial port name as myseria,Rx is port 7, Tx is port 8

const static uint8_t RADIO_ID = 0;       // Our radio's id.  The transmitter will send to this id.
const static uint8_t PIN_RADIO_CE = 9;
const static uint8_t PIN_RADIO_CSN = 10;

struct RadioPacket // Any packet up to 32 bytes can be sent.
{
    uint8_t FromRadioId;
    uint32_t OnTimeMillis;
    uint32_t FailedTxCount;
    uint32_t Moisture;
    uint32_t Temperature;
    uint32_t LvlWater;
};

NRFLite _radio;
RadioPacket _radioData;

void setup()
{
  myserial.begin(115200); //Initialize virtual serial port
  Serial.begin(115200); //Initialize Arduino default serial port
  if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
    {
        Serial.println("Cannot communicate with radio");
        while (1); // Wait here forever.
    }
}

void loop()
{
while (_radio.hasData())
    {
        _radio.readData(&_radioData); // Note how '&' must be placed in front of the variable name.

        String msg = "Radio ";
        msg += _radioData.FromRadioId;
        msg += ", ";
        msg += _radioData.FailedTxCount;
        msg += " Failed TX, ";
        msg += _radioData.Moisture;
        msg += "% Moisture Humidity, ";
        msg += _radioData.Temperature;
        msg += "° Temperature, ";
        msg += _radioData.LvlWater;
        msg += "% Water level.";
        
        Serial.println(msg);

  
  while(1){
  while (myserial.available()) {
    Serial.write(myserial.read());//if Serial received data, output it via mySerial.
  }
  while(Serial.available()) {
    myserial.write(Serial.read());//if myserial received data, output it via Serial.
  }
}
    }}
