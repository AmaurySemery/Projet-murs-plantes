//****************************************************************************
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
volatile int f_wdt = 1;             
unsigned long tempo_desiree =900; // 15mn=900 secondes
unsigned long compteur_reveil = 0;
unsigned long compteur_travail=0;
unsigned long debut_travail=0;
unsigned long fin_travail =0;
unsigned long total_travail=0;
//****************************************************************************

/* Trappe automatique poulallier en fonction des seuils de lumière jour et nuit.
-  ouverture et fermeture sur seuil de lumière.
- arrêt moteur par contact fin de course.
- arrêt moteur au bout de 8 secondes si le temps normal de 5 secondes dépassé,
en cas de mécanique ou contact défectueux.
 */

/* déclaration des constantes pour les noms des broches */
const int led = 13; // led du module nano
const int ldr = A7; // LDR sur broche A7
const int moteur = A6; // mesure courant moteur
const int fermer = 2; // commande relais de fermeture
const int ouvrir = 3; // commande relais d'ouverture
const int  haut = 4; // fin de course
const int bas = 5; // fin de course

/* déclaration des variables */
int nuit = 900; // seuil nuit
int jour = 80;  // seuil jour
unsigned long debut=0; // temps début de rotation

void setup() {
  // initialisation des broches entrée/sortie
 pinMode(ldr, INPUT);
 pinMode(fermer, OUTPUT);
 pinMode(ouvrir, OUTPUT);
 pinMode(haut, INPUT_PULLUP);
 pinMode(bas, INPUT_PULLUP);
 //****************************************************************************
 setup_watchdog(9);
 Serial.begin(57600);
 //****************************************************************************
}

void loop()
{
  //****************************************************************************
  debut_travail =  millis();
  if (f_wdt == 1)
  {
    compteur_reveil++;
       Serial.print("reveil pour la  ");
       Serial.print(compteur_reveil,DEC);
       if (compteur_reveil==1){Serial.println(" ere fois");}
       else {Serial.println(" eme fois");}
       //ici, on peut mettre le prog si le temps de sommeil
       //est de 8 secondes.et virer le if ((compteur_reveil*8)>= tempo_desiree)
       //mais si le temps désiré est > 8secondes, on entre dans
       //le if ((compteur_reveil*8)>= tempo_desiree)
    if ((compteur_reveil*8)>= tempo_desiree)
    {
      compteur_travail++;
  delay(2000); //le temps de boire un café et d'etre opérationnel
  //****************************************************************************   
//lecture de l'état des entrées
int ouvert = digitalRead(haut); // 1 au repos
int ferme = digitalRead(bas);
int seuil = analogRead(ldr);
// action
 //Il fait jour et la trappe est fermé déclenche l'ouverture et compte le temps. 
 if(seuil < jour && ferme == 0){digitalWrite(ouvrir, 1);debut=millis();};
 // arrêt forcé du moteur si son temps de fonctionnement est supérieur au temps normal.
 if(millis() - debut > 8000){digitalWrite(ouvrir, 0);digitalWrite(fermer, 0);};
 // arrêt moteur quand la trappe est ouverte
 if(ouvert == 0){digitalWrite(ouvrir, 0);};
 // Il fait nuit et la trappe est ouverte déclenche la fermeture et le compteur de temps moteur
 if(seuil > nuit && ouvert == 0){digitalWrite(fermer, 1);debut = millis();}
 if(ferme == 0){digitalWrite(fermer, 0);};
 delay(10);
 //****************************************************************************   
       Serial.print("travail car il y a eu  ");
       Serial.print((compteur_reveil*8),DEC);
       Serial.println(" secondes de sommeil ");
       Serial.print("il y a ");
       Serial.print((compteur_travail*32),DEC);
       Serial.println(" secondes de fonctionnement ");
    // fin des mesures ici si sommeil >8 secondes
    compteur_reveil = 0;
 }
    fin_travail=millis();
    total_travail=total_travail +(fin_travail-debut_travail);
    Serial.print("temps total de travail =  ");
    Serial.print(total_travail);Serial.println("  ms  ");
    delay(2000); //pour laisser le temps aux "serial.print" de se fairent
    f_wdt = 0; // Ne pas oublier d'initialiser le flag, sinon pas de sommeil
    enterSleep(); //Revenir en mode veille
 //****************************************************************************
 }
}
// Watchdog Interrupt Service est exécité lors d'un timeout du WDT
ISR(WDT_vect)
{
  if (f_wdt == 0)
  {
    f_wdt = 1; // flag global }
  }
}
// paramètre : 0=16ms, 1=32ms, 2=64ms, 3=128ms, 4=250ms,
//           : 5=500ms, 6=1 sec,7=2 sec, 8=4 sec, 9=8 sec
void setup_watchdog(int ii) {
  byte bb;
  int ww;
  if (ii > 9 ) ii = 9;   // pour 8 secondes
  bb = ii & 7;
  if (ii > 7) bb |= (1 << 5);
  bb |= (1 << WDCE);
  ww = bb;
  // Clear the reset flag
  MCUSR &= ~(1 << WDRF);
  // start timed sequence
  WDTCSR |= (1 << WDCE) | (1 << WDE);
  // set new watchdog timeout value
  WDTCSR = bb;
  WDTCSR |= _BV(WDIE);
}

void enterSleep(void) {
  Serial.print(".....zzzzzzzzzzzzzz  ");
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode(); //Entre dans le mode veille choisi
  //le micro passe en sommeil pour 8 secondes
  // Le programme va reprendre ici après le timeout du WDT
  sleep_disable(); // La 1ère chose à faire est de désactiver le mode veille
  Serial.println("..............fin sommeil ");
}
