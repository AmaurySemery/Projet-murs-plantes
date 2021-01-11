#include <SPI.h>
#include <NRFLite.h>

NRFLite _radio;
uint8_t _data;

void setup()
{
    _radio.init(1, 9, 10); // Set radio to Id = 1, along with the CE and CSN pins
}

void loop()
{
    _data++;
    _radio.send(0, &_data, sizeof(_data)); // Send data to the radio with Id = 0
    delay(1000);
}
