const int flotteurbasPin = 7;     // the number of the pushbutton pin
const int flotteurhautPin = 2;
//const int relaisPin =  13;      // the number of the LED pin

// variables will change:
int flotteurbasState = 0;         // variable for reading the pushbutton status
int flotteurhautState = 1;

void setup() {
  // initialize the relais pin as an output:
//  pinMode(relaisPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(flotteurbasPin, INPUT);
  pinMode(flotteurhautPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // read the state of the flotteur value:
  flotteurbasState = digitalRead(flotteurbasPin);
  Serial.print("Lecture flotteur bas : ");
  Serial.println(flotteurbasState);
  flotteurhautState = digitalRead(flotteurhautPin);
  Serial.print("Lecture flotteur haut : ");
  Serial.println(flotteurhautState);

  // check if the flotteurbas is up
  // if it is, the flotteurbasState is HIGH:
  if (flotteurbasState == LOW) {
    // turn LED on:
    //digitalWrite(relaisPin, HIGH); // pompe en marche
    Serial.print("Fonctionnement flotteur bas : ");
    Serial.println("On !");
  } if (flotteurbasState == HIGH) {
    // turn LED off:
    //digitalWrite(relaisPin, LOW);
    Serial.print("Fonctionnement flotteur bas : ");
    Serial.println("Off !");
  }
  if (flotteurhautState == LOW) {
   // turn led off
  //  digitalWrite(relaisPin, LOW);
  Serial.print("Fonctionnement flotteur haut : On !");
  } if (flotteurhautState == HIGH) {
   // turn LED on
    //digitalWrite(relaisPin, HIGH);
    Serial.print("Fonctionnement flotteur haut : ");
    Serial.println("Off !");
  }
  delay(2000);
}
