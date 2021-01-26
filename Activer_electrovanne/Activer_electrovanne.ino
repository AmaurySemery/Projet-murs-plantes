int PinElectro = 4;    // N° de broche utilisée en sortie pour piloter l'électrovanne
 
void setup()
{
  pinMode(PinElectro, OUTPUT); // déclarer en sortie la broche solenoidPin (n°4)
}
 
void loop() {
  digitalWrite(PinElectro, HIGH);  // Mettre la sortie PinElectro au niveau HAUT 5V
  delay(10000);                      // Attendre 1000 ms (1s)
  digitalWrite(PinElectro, LOW);   // Mettre la sortie PinElectro au niveau BAS 0V
  delay(10000);                      // Attendre 1000 ms (1s)
}
