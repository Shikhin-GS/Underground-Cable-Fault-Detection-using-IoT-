#include <Wire.h> 
#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
SoftwareSerial espSerial(2,3);
LiquidCrystal_I2C lcd(0x27,16,2);

#define sensor A0  

#define relay1 11
#define relay2 12
#define relay3 13


#define C1GLED 4
#define C2GLED 5
#define C3GLED 6
#define C1RLED 7
#define C2RLED 8
#define C3RLED 9
#define buzzer 10

int read_ADC=0;
int distance;

int rdistance;
int ydistance;
int bdistance;

String cdata;

void setup() {
//Serial.begin(9600);
espSerial.begin(9600);
pinMode(sensor, INPUT); 
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(relay3, OUTPUT);
pinMode(C1GLED, OUTPUT);
pinMode(C2GLED, OUTPUT);
pinMode(C3GLED, OUTPUT);
pinMode(C1RLED, OUTPUT);
pinMode(C2RLED, OUTPUT);
pinMode(C3RLED, OUTPUT);
pinMode(buzzer, OUTPUT);    

lcd.begin();
lcd.setCursor(0, 0); // set the cursor to column 0, line 2
lcd.print("CABLE FAULT DTEC");
lcd.setCursor(0, 1); // set the cursor to column 0, line 2
lcd.print("BIET COLLEGE DVG");
delay(5000);
lcd.clear();
}

void data()
{
read_ADC = analogRead(sensor); 
distance = read_ADC/100;
//Serial.print("Dis:");
//Serial.println(distance);
if(distance>9)distance = 0;
}

void loop(){
 ///// DATA C1
lcd.setCursor(0,0);
lcd.print("R");
lcd.setCursor(1,0);
lcd.print(":");  

digitalWrite(relay1,HIGH);
digitalWrite(relay2,LOW);
digitalWrite(relay3,LOW);  
delay(500);
data();
lcd.setCursor(0,1);

if(distance>0)
{
 lcd.print(distance); 
 lcd.print("KM");
 digitalWrite(C1GLED,LOW);
 digitalWrite(C1RLED,HIGH);
 digitalWrite(buzzer,HIGH); 
 rdistance=distance;
 //Serial.println("rdist:");
 //Serial.println(rdistance);
 }

else
{
 lcd.print("NF!");
 digitalWrite(C1GLED,HIGH);
 digitalWrite(C1RLED,LOW);
 digitalWrite(buzzer,LOW);
 rdistance=distance;
 //Serial.println("rdist:");
 //Serial.println(rdistance);
 
  }

lcd.setCursor(6,0);
lcd.print("Y");
lcd.setCursor(7,0);
lcd.print(":");  

digitalWrite(relay1,LOW);
digitalWrite(relay2,HIGH);
digitalWrite(relay3,LOW);  
delay(500);
data();
lcd.setCursor(6,1);

if(distance>0)
{
 lcd.print(distance); 
 lcd.print("KM");
 digitalWrite(C2GLED,LOW);
 digitalWrite(C2RLED,HIGH);
 digitalWrite(buzzer,HIGH);
 ydistance=distance;
 //Serial.println("ydist:");
 //Serial.println(ydistance);
 }

else
{
 lcd.print("NF!");
 digitalWrite(C2GLED,HIGH);
 digitalWrite(C2RLED,LOW);
 digitalWrite(buzzer,LOW);
 ydistance=distance;
 //Serial.println("ydist:");
 //Serial.println(ydistance);
  }

lcd.setCursor(12,0);
lcd.print("B");
lcd.setCursor(13,0);
lcd.print(":"); 
digitalWrite(relay1,LOW);
digitalWrite(relay2,LOW);
digitalWrite(relay3,HIGH);  
delay(500);
data();
lcd.setCursor(12,1);

if(distance>0)
{
 lcd.print(distance); 
 lcd.print("KM");
 digitalWrite(C3GLED,LOW);
 digitalWrite(C3RLED,HIGH);
 digitalWrite(buzzer,HIGH);
 bdistance=distance;
 //Serial.println("bdist:");
 //Serial.println(bdistance);
 }

else
{
  lcd.print("NF!");
   digitalWrite(C3GLED,HIGH);
   digitalWrite(C3RLED,LOW);
   digitalWrite(buzzer,LOW);
   bdistance=distance;
   //Serial.println("bdist:");
   //Serial.println(bdistance);
  }


  ////////////////////ESP8266
    if(espSerial.available())
    {
      /////UNTI1
//       Serial.print("RDis: ");
//       Serial.print(rdistance);
//       Serial.println();
//
//       Serial.print("YDis: ");
//       Serial.print(ydistance);
//       Serial.println();
//
//       Serial.print("BDis: ");
//       Serial.print(bdistance);
//       Serial.println();
       
       cdata = cdata + rdistance+","+ydistance+","+bdistance;
       //Serial.println(cdata); 
       espSerial.println(cdata);
       cdata = ""; 
  }

}
