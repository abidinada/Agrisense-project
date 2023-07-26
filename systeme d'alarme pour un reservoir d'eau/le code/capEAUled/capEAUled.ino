#define capteurPin A0
#define buzzer 5
#define buzGND 7
int ledrouge=2;
int ledverte=3;

int value=0;
void setup() {
  // put your setup code here, to run once:
pinMode(ledrouge,OUTPUT);
pinMode(ledverte,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(buzGND,OUTPUT);
digitalWrite(buzGND,LOW);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
value=analogRead(capteurPin);
Serial.print("niveau d'eau :");
Serial.print(value);
Serial.println("%");
delay(1000);
if(value>0 && value<300 ){
  digitalWrite(ledrouge,HIGH);
  digitalWrite(ledverte,LOW);
  digitalWrite(buzzer,HIGH);
} 
if (value>300)
{
   digitalWrite(ledrouge,LOW);
  digitalWrite(ledverte,HIGH);
  digitalWrite(buzzer,LOW);
}

}

