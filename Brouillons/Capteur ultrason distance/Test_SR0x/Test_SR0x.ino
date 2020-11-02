int trig = 2;
int echo = 3;
long lecture_echo;
long cm;

void setup(){

pinMode(trig, OUTPUT);
digitalWrite(trig, LOW);
pinMode(echo, INPUT);
Serial.begin(9600);

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
delay(1500);
}
