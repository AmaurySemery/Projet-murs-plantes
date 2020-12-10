int switchPin = 7; // Bouton connecté à la pin 2 (pull-up, LOW=bouton pressé)

  int val;        // variable pour lire l'état de l'entrée
  int val2;       // variable pour lire l'état de l'entrée (après un delai)
  int buttonState;   // variable pour mémoriser l'état du bouton

void setup() {
  pinMode(switchPin, INPUT);    // Le bouton est une entrée 
  Serial.begin(115200);
  
  buttonState = digitalRead(switchPin);   // lecture de l'état initial
}

void loop(){
  val = digitalRead(switchPin);      // Lecture de la valeur d'entrée
  Serial.println(val);
  delay(10);                         // 10 millisecondes
  val2 = digitalRead(switchPin);     // Relecture de l'entrée pour vérification de parasitage
  Serial.println(val2);

  if (val == val2) {                 // S'assurer que l'on a 2 lectures successives consistante!

    if (val != buttonState) {          // Le bouton a changer d'état!
      if (val == LOW) {                // Le bouton est il pressé?
        Serial.println("On !");
    }
    buttonState = val;                 // Sauver le nouvel état du bouton dans une variable
  }
}
}
