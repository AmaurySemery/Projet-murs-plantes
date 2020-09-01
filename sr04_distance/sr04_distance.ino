#include



LiquidCrystal lcd(12,11,5,4,3,2);

int trig = 8;
int echo = 9;
long lecture_echo;
long cm;

void setup(){

pinMode(trig, OUTPUT);
digitalWrite(trig, LOW);
pinMode(echo, INPUT);
Serial.begin(9600);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print ("TUTOS IHM 3D");
delay (2000);
lcd.clear();
Serial.println ("Bienvenue sur les tutoriels d'IHM 3D");
}

void loop(){

digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
lecture_echo = pulseIn(echo,HIGH);
cm = lecture_echo /58;
Serial.print("Distance en cm :");
Serial.println(cm);
lcd.setCursor (4,0);
lcd.print ("DISTANCE:");
lcd.setCursor (3,1);
lcd.print (cm);
lcd.setCursor (7,1);
lcd.print ("CM");
delay(500);
  //lcd.clear();
