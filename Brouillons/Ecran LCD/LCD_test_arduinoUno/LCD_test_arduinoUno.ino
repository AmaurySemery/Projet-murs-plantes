#include <LiquidCrystal.h>

// définit un objet lcd avec les entrées sorties de l'Arduino en paramètre
//RS_pin EN_pin BUS1 BUS2 BUS3 BUS4
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
 // défini le nombre de caractère et de ligne de l'écran
 lcd.begin(16, 2);
}

void loop() {
 //On va d'abord effacer tout les caractères sur l'écran:
 lcd.clear();
 lcd.setCursor(0, 0); //ici, on se positionne en haut à gauche de l'écran
 lcd.print("Hello, funLAB!!!"); //Le texte qu'on affiche sur l'écran à l'endroit positionné
 delay(500); //On attend 500ms 

// Après 500ms d'attente, on affiche la seconde ligne
 lcd.setCursor(0, 1); //On se place sur la deuxième ligne
 lcd.print("salut les geeks!");
 delay(500);
// On attends 500ms, puis on repart en haut de la fonction loop()

 }
