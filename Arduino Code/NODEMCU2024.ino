#define BLYNK_TEMPLATE_ID "TMPL3zmdGo5zB"
#define BLYNK_TEMPLATE_NAME "CABLE FAULT DETECTION"
#define BLYNK_AUTH_TOKEN "acJR9ooUOEDMer96Sr2aMANrT0XYs3JQ"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

 
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "PROJECT";
char pass[] = "DEMO2024";

 
String myString; // complete message from arduino, which consistors of snesors data
char rdata; // received charactors
 
//for temperature , pressure and altitude  
int rdistance,ydistance,bdistance;
 
BlynkTimer timer;
void setup()
{
  
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  //timer.setInterval(1000L, sensorvalue);
}
 
void loop()
{
   if (Serial.available()) 
   {
  Blynk.run();
   }
   
  if (Serial.available()) 
  {
    rdata = Serial.read(); 
    myString = myString+ rdata; 
    if( rdata == '\n')
    {
   String l = getValue(myString, ',', 0);
   String m = getValue(myString, ',', 1);
   String n = getValue(myString, ',', 2);


rdistance= l.toInt();
ydistance= m.toInt();
bdistance= n.toInt();


myString = "";
Serial.print("DIS:");
Serial.print(rdistance);
Serial.println();

Serial.print("R1:");
Serial.print(ydistance);
Serial.println();

Serial.print("R2:");
Serial.print(bdistance);
Serial.println();

Blynk.virtualWrite(V0, rdistance);
Blynk.virtualWrite(V1, ydistance);
Blynk.virtualWrite(V2, bdistance);


if(rdistance>0)
{
  Blynk.virtualWrite(V3,"Fault Detected at Location R");
  }

  if(ydistance>0)
{
  Blynk.virtualWrite(V4,"Fault Detected at Location Y");
  }

  if(bdistance>0)
{
  Blynk.virtualWrite(V5,"Fault Detected at Location B");
  }


///////////////////////////////
if(rdistance==0)
{
  Blynk.virtualWrite(V3,"NO Fault Detected");
  }

  if(ydistance==0)
{
  Blynk.virtualWrite(V4,"NO Fault Detected");
  }

  if(bdistance==0)
{
  Blynk.virtualWrite(V5,"NO Fault Detected");
  }
 }
  }
}
 

 
 
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
