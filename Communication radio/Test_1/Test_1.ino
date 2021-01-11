#include <SPI.h>
#include <NRFLite.h>

NRFLite _radio;
uint8_t _data;

void setup()
{
    Serial.begin(115200);
    _radio.init(0, 9, 10); // Set radio to Id = 0, along with its CE and CSN pins
}

void loop()
{
    while (_radio.hasData())
    {
        _radio.readData(&_data);
        Serial.println(_data);
    }
}
