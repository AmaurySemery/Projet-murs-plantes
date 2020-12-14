const int Pushbutton = 12; //bouton-poussoir connecté à la broche D4
const int LED = 7; //LED connectée à la broche D7
int value = 0;     // Variable pour lire l'état du bouton-poussoir

void setup() {
  // put your setup code here, to run once:
 pinMode (LED, OUTPUT); //La broche du LED est configurée comme sortie
 pinMode (Pushbutton, INPUT); //La broche du bouton-poussoir est configurée comme entrée avec une resistance pull-up externe
}

void loop() {
  // mettre votre code principal ici, qui va s'exécuter de façon répétée:
value = digitalRead(Pushbutton); //Lire l'état du bouton-poussoir
if (value == LOW) //Si le bouton est appuyé
    {
       delay(10); //10 milliseconds anti-rebond
       if (value == LOW) //vérifier encore so le bouton est toujours appuyé
    {
        digitalWrite(LED, HIGH); //LED est allumée
        delay(5000); //pause de 5 Second 
        digitalWrite(LED, LOW); //LED est éteinte
    }
    }
}
