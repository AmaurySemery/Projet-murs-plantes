/*
Lorsqu'on appui sur le bouton (broche 12), la DEL «L» (broche 13) de la carte s'illumine.
*/

int etatInterrupteur;

void setup() {
        // Configuration de la broche 12 en tant qu'entree numerique.
        pinMode(12,INPUT);

        // Configuration de la broche 13 en tant que sortie numerique
        pinMode(7,OUTPUT);
}

void loop() {

        // Lire l'etat de la broche 12.
        etatInterrupteur = digitalRead(12);

        // Changer l'etat de la broche 13 selon
        // l'etat de l'interrupteur
        if ( etatInterrupteur == LOW ) {
                digitalWrite(7,HIGH);
        } else if ( etatInterrupteur == HIGH ) {
                digitalWrite(7,LOW);
        }

}
