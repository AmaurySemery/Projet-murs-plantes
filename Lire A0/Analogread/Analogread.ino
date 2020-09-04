int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  int sensorValue = analogRead(A0);
  val = analogRead(sensorValue);  // read the input pin
  Serial.println(val);          // debug value
  delay(5000);
}
