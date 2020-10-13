

int sensorPin1 = 13;
int sensorPin2 = 27;
int sensorPin3 = 14;
float a = 40.95;
int b = 100;


void setup() {
  Serial.begin(115200);
  }

void loop() {
  uint16_t value1 = analogRead(sensorPin1);
  float division1 = value1 / a;
  int sensor1convert = b - division1;
  Serial.println("Pourcentage d'humidité du mur végétalisé :");
  Serial.print("Capteur 1 : ");
  Serial.print(sensor1convert);
  Serial.println(" %");
  uint16_t value2 = analogRead(sensorPin2);
  float division2 = value2 / a;
  int sensor2convert = b - division2;
  Serial.print("Capteur 2 : ");
  Serial.print(sensor2convert);
  Serial.println(" %");
  uint16_t value3 = analogRead(sensorPin3);
  float division3 = value3 / a;
  int sensor3convert = b - division3;
  Serial.print("Capteur 3 : ");
  Serial.print(sensor3convert);
  Serial.println(" %");
  Serial.println("----------------");

  delay(5000);}
