const unsigned long DUREE_MIN_OSMOL = 20000; // Durée minimum d'osmolation en milliseconde (20000ms = 20s)
 
// Déclarations des connexions sur carte et des variables
const byte PIN_RELAIS = 12; // Numéro du pin pour le relais
const byte PIN_CAPTEUR = 9; // Numéro du pin pour les capteurs de niveau
unsigned long temps_debut_osmolation; // Variable de type long non signée pour enregristrer un temps
 
void setup() { // Initialisation du programme
  pinMode(PIN_CAPTEUR, INPUT_PULLUP); // Affecte le mode Entrée au pin capteur. En l'absence de branchement, la résistance interne Pullup tire vers un état HIGH non aléatoire.
  pinMode(PIN_RELAIS, OUTPUT); // Affecte le mode Sortie (envoi d'un signal) au pin du relais
  Serial.begin(115200);
}
 
void loop() { // Programme en boucle
  if (digitalRead(PIN_CAPTEUR) == LOW) { // Si le pin du capteur est LOW (contact pullup fermé, flotteur bas)
    digitalWrite(PIN_RELAIS, HIGH); // Envoie du courant au pin relais, la pompe injecte de l'eau
    Serial.println("Off");
    temps_debut_osmolation = millis(); // Affecte le temps actuel au début d'osmolation
  }
  else { // Sinon, si le flotteur est en haut
    if (millis() > temps_debut_osmolation + DUREE_MIN_OSMOL) { // Si la durée d'osmolation dépasse la durée min
      digitalWrite(PIN_RELAIS, LOW); // N'envoie plus de courant sur le pin relais, la pompe s'arrête
      Serial.println("On");
    }
  }
}
