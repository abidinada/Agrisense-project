#include<Servo.h>
Servo servo1;
int servoPin=4;
int sensorPin=6;
int buzzer = 10;
int gazsensor = A5;
int valeur;
void setup() {
  // put your setup code here, to run once:
pinMode(sensorPin,INPUT);
servo1.attach(servoPin);
 pinMode(buzzer, OUTPUT);
  pinMode(gazsensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
valeur=digitalRead(sensorPin);
int gazvaleur = analogRead(gazsensor);

if(gazvaleur > 500){
  servo1.write(180);
  digitalWrite(buzzer,HIGH);
  } 
if(valeur==1){
  servo1.write(180);
  digitalWrite(buzzer,LOW);
  } 
if (valeur==0){
  servo1.write(0);
  digitalWrite(buzzer,LOW);  
}
}
