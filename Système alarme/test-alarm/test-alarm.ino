int tiger=2;
int echo=3;
int a=12;
int Duration,Distance;
int redpin = 11; //select the pin for the red LED
int bluepin =10; // select the pin for the  blue LED
int greenpin = 9;// select the pin for the green LED

void setup(){
   pinMode(tiger,OUTPUT);
   pinMode(echo,INPUT);
   Serial.begin(9600);
   pinMode(a,OUTPUT);
   pinMode(redpin, OUTPUT);
   pinMode(bluepin, OUTPUT);
   pinMode(greenpin, OUTPUT);}

void loop(){
   digitalWrite(tiger,HIGH);
   delayMicroseconds(1000);
   digitalWrite(tiger,LOW);
   Duration=pulseIn(echo,HIGH);
   Distance=(Duration/2)/29.1;
  
if (Distance<10){
   digitalWrite(a,HIGH);
   digitalWrite(redpin,HIGH);
   digitalWrite(bluepin,LOW);
   digitalWrite(greenpin,LOW);
   Serial.print(Distance);
   Serial.println("cm");
   delay(200);}
    
if (Distance>10 and Distance<20){
   digitalWrite(greenpin,HIGH);
   digitalWrite(redpin,LOW);
   digitalWrite(bluepin,LOW);
   Serial.print(Distance);
   Serial.println("cm");
   delay(200);}
  
if (Distance>20) {
   digitalWrite(bluepin,HIGH);
   digitalWrite(redpin,LOW);
   digitalWrite(greenpin,LOW);
   Serial.print(Distance);
   Serial.println("cm");
   delay(200);}

   delay(5000);}
