#define BLYNK_PRINT Serial    
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define an A0
char auth[] = "Auth Code";
char ssid[] = "Wifi Username";
char pass[] = "Wifi Password";
 
void setup()
{ pinMode(an,INPUT);
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
   
}

void loop()
{
  int valeur = analogRead(an);
  moisture=map(valeur,1017,100,0,100);
  if(moisture<30){
    Blynk.notify("arroser les plantes")
  }
  Serial.print("soil moisture = ");
  Serial.print(moisture);
  Serial.println(" % ");
  delay(100);
  Blynk.run();
}
