// printDetails.ino
// Permet de différencier un nRF24L01 d’un nRF24L01+

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

RF24 radio( 9, 10 );

void setup()
{
  Serial.begin( 115200 );
  printf_begin();
  radio.begin();
  radio.printDetails();
}

void loop(){}
