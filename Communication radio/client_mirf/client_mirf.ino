//=== exemple de code CLIENT nRF24L01 
// communication 2.4 Ghz bi directionnelle
// avec vérification de message bien  reçu
//
// tiptopboards.com 25 08 2013
// Adaptation d'après skyduino
//=============================================
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
 
void setup(){
  Serial.begin(9600);
   
  Mirf.cePin = 8; // CE sur D8
  Mirf.csnPin = 7; // CSN sur D7
  Mirf.spi = &MirfHardwareSpi; // On veut utiliser le port SPI hardware
  Mirf.init(); // Tout est bon ? Ok
 
  Mirf.channel = 0; // On va utiliser le canal 0 pour communiquer (128 canaux disponible, de 0 à 127)
  Mirf.payload = sizeof(unsigned long); // = 4, ici il faut déclarer la taille du "payload" soit du message qu'on va transmettre, au max 32 octets
  Mirf.config(); // Tout est bon ? Ok let's go !
   
  Mirf.setTADDR((byte *)"nrf02"); // Le 1er module va envoyer ses info au 2eme module
  Mirf.setRADDR((byte *)"nrf01"); // On définit ici l'adresse du 1er module
   
  Serial.println("Client");
}
 
void loop(){
  byte data_envoi[Mirf.payload];   // Tableau de 4 octets qui va stocker le message à envoyer
  byte data_retour[Mirf.payload];  // Tableau de 4 octets qui va stocker le message recu
 
  data_envoi[0]=random(125);  //Data à envoyer
  data_envoi[1]=random(125);
  data_envoi[2]=random(125);
  data_envoi[3]=random(125);
 
  Mirf.send(data_envoi); // Envoi des 4 octets
  while(Mirf.isSending()); // On attend tant que le message n'a pas été envoyé
   
  Serial.print("Envoi ");
  afficher_4_octets(data_envoi);
  delay(1);  //breve attente (sinon ne passe pas !)
   
   Mirf.getData(data_retour); // on récupère le message retourné
  Serial.print("Retour ");
  afficher_4_octets(data_retour);
  Serial.print(" ");
  //Comparer les deux
  int ok = comparer_4_octets(data_envoi, data_retour);
  Serial.print (ok);
  Serial.println(" erreurs");
  //delay(5);  //Paquet suivant
}

//Fonction affichage de contrôle
void afficher_4_octets(byte data[4])
{
for (int i=0;i<4;i++)
   {Serial.print(data[i]);
   Serial.print(" ");
   }
 }
 
 
 //Fonction de validation aller-retour
int comparer_4_octets(byte aller[4], byte retour[4])
{
  unsigned long entree = aller[0]+aller[1]*256+aller[2]*65536+aller[3]*16777216;
  unsigned long sortie = retour[0]+retour[1]*256+retour[2]*65536+retour[3]*16777216;
  //Serial.print(entree);
  //Serial.print(" et ");
  //Serial.println(sortie);
  if (entree==sortie) { return 0;}  //pas de décalage
  else {return 1;}  //1 erreur
}
