//#include <SPI.h>
//#include <NRFLite.h>

//const static uint8_t RADIO_ID = 0;       // Our radio's id.  The transmitter will send to this id.
//const static uint8_t PIN_RADIO_CE = 9;
//const static uint8_t PIN_RADIO_CSN = 10;

int PinElectro1 = 4;    // N° de broche utilisée en sortie pour piloter l'électrovanne
int PinElectro2 = 5;

//struct RadioPacket // Any packet up to 32 bytes can be sent.
//{
//    uint8_t FromRadioId;
//    uint32_t OnTimeMillis;
//    uint32_t FailedTxCount;
//    uint32_t Moisture;
//    uint32_t Temperature;
//    uint32_t LvlWater;
//};

//NRFLite _radio;
//RadioPacket _radioData;

void setup()
{
  Serial.begin(115200);
  pinMode(PinElectro1, OUTPUT); // déclarer en sortie la broche solenoidPin (n°4)
  pinMode(PinElectro2, OUTPUT); // déclarer en sortie la broche solenoidPin (n°4)
//  if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
//    {Serial.println("Cannot communicate with radio");
//        while (1); // Wait here forever.
//        }
}
 
void loop() {
//  while (_radio.hasData())
//    {
//        _radio.readData(&_radioData); // Note how '&' must be placed in front of the variable name.

//        String msg = "Radio ";
//        msg += _radioData.FromRadioId;
//        msg += ", ";
//        msg += _radioData.FailedTxCount;
//        msg += " Failed TX, ";
//        msg += _radioData.Moisture;
//        msg += "% Moisture Humidity, ";
//        msg += _radioData.Temperature;
//        msg += "° Temperature, ";
//        msg += _radioData.LvlWater;
//        msg += "% Water level.";
        
        

//        Serial.println(msg);
//    }
  digitalWrite(PinElectro1, HIGH);  // Mettre la sortie PinElectro au niveau HAUT 5V
  Serial.println("Electrovanne : activée !");
  delay(10000);                      // Attendre 1000 ms (1s)
  digitalWrite(PinElectro1, LOW);   // Mettre la sortie PinElectro au niveau BAS 0V
  Serial.println("Electrovanne : désactivée !");
  delay(10000);                      // Attendre 1000 ms (1s)
  //  digitalWrite(PinElectro2, HIGH);  // Mettre la sortie PinElectro au niveau HAUT 5V
//  delay(10000);                      // Attendre 1000 ms (1s)
//  digitalWrite(PinElectro2, LOW);   // Mettre la sortie PinElectro au niveau BAS 0V
//  delay(10000);                      // Attendre 1000 ms (1s)

}
