//Optimisation de la consommation

#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
volatile int f_wdt = 1;
unsigned long tempo_desiree = 32; // mettre un multiple de 8, mais pas obligatoire
unsigned long compteur_reveil = 0;
unsigned long compteur_travail=0;
unsigned long debut_travail=0;
unsigned long fin_travail =0;
unsigned long total_travail=0;
// Watchdog Interrupt Service est exécité lors d'un timeout du WDT
ISR(WDT_vect)
{
  if (f_wdt == 0)
  {
    f_wdt = 1; // flag global }
  }
}
// paramètre : 0=16ms, 1=32ms, 2=64ms, 3=128ms, 4=250ms, 5=500ms, 6=1 sec,7=2 sec, 8=4 sec, 9=8 sec
void setup_watchdog(int ii) {
  byte bb;
  int ww;
  if (ii > 9 ) ii = 9;
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

//************* SETUP *************
void setup() {
  //Optimisation de la consommation
  //power_adc_disable(); // Convertisseur Analog / Digital pour les entrées analogiques
  //power_spi_disable();
  //power_twi_disable();
  // Si pas besoin de communiquer par l'usb
  //power_usart0_disable();
  //Extinction des timers, attention timer0 utilisé par millis ou delay
  //power_timer0_disable();
  //power_timer1_disable();
  //power_timer2_disable();

  setup_watchdog(9);
  Serial.begin(57600);
}

//************* LOOP *************

void loop()
{ debut_travail =  millis();
  if (f_wdt == 1)
  {
     compteur_reveil++;
    // Effectuer le programme ici si sommeil demandé = 8 secondes
       Serial.print("reveil pour la  ");
       Serial.print(compteur_reveil,DEC);
       if (compteur_reveil==1){Serial.println(" ere fois");}
       else {Serial.println(" eme fois");}
   // fin des mesures ici si sommeil = 8 secondes
    if ((compteur_reveil*8)>= tempo_desiree)
    {
      compteur_travail++;
    // Effectuer le programme ici si sommeil demandé >8 secondes
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
  }
}
