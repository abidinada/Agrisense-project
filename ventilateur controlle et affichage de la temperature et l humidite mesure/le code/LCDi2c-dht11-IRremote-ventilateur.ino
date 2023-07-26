#include <DHT.h>
#include<Adafruit_Sensor.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>
LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(4,DHT11);
int temp;
int humidity;
const byte IR_ReceivePIN = 2;
#define fan 10
void setup(){
 dht.begin();

 lcd.init();
 lcd.backlight();

 Serial.begin(9600);

 IrReceiver.begin(IR_ReceivePIN,ENABLE_LED_FEEDBACK);
 
 pinMode(fan,OUTPUT);
 digitalWrite(fan,LOW);
}

void loop() {
  
 delay(2000);
 temp=dht.readTemperature();
 humidity=dht.readHumidity();
 //lcd va afficher la temperature et l humidite detectees par dht11 
 lcd.setCursor(0,0);
 lcd.print("temperature: ");
 lcd.print(temp);
 lcd.print("C");
 lcd.setCursor(0,1);
 lcd.print(" humidity:");
 lcd.print(humidity);
 lcd.print("%");
 //si la temperature est elevee le ventilateur tourne automatiquement
 if(temp>=37){
   analogWrite(fan,300);
   delay(5000);
   analogWrite(fan,1000);
   delay(5000);
 }
 // je peux aussi controler le ventilateur a l aide du IRremote 
 if(IrReceiver.decode()){
 String ir_code= String(IrReceiver.decodedIRData.command,HEX);
 Serial.println(ir_code);
 IrReceiver.resume();
 
 if(ir_code=="c"){
   analogWrite(fan,300);
   delay(5000);
   analogWrite(fan,1000);
   delay(5000);
   
 } 
 else digitalWrite(fan,LOW);

}
}

