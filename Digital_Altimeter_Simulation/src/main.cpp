#include <Arduino.h>
#include <liquidCrystal.h>
#include <stdio.h>
#include <cmath>

LiquidCrystal altLCD(10,9,5,4,3,2);
int potPin = A2;
float potRead;
int ledPin = 11;
bool ledWarn = LOW;
unsigned long previousTime = 0;
const unsigned long interval = 300;
char buffer[20] = "";
char rbuffer[20] = "";
int alt;
int prevAlt;
float vertRateConv;
int vertRate;
float deltaTime=0.0;
float altConversion;
int setAlt = 1000; //will be used later for actually setting the altimeter




void setup() {
  Serial.begin(115200);
  altLCD.begin(16,2);
  altLCD.setCursor(0,0);
  altLCD.print("Altitude: ");
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);

  //inital altitude setup for pot 
  potRead = analogRead(potPin);
  altConversion = (potRead/1023)*10000.0;
  alt = round(altConversion);
  prevAlt = alt;
  
}

void loop() {
  
  potRead = analogRead(potPin);
  altConversion = (potRead/1023)*10000.0;
  alt = round(altConversion);

  

  if(altConversion >= 8200.0)
  { 
    ledWarn = HIGH;
    altLCD.setCursor(0,1);
    altLCD.print("Warning!H");

  }
  else if(altConversion >= 7800.0 && altConversion <=8200.0)
  {
    
  }
  else if(altConversion> setAlt - 50 && altConversion <= setAlt)
  {

  }
  else if(altConversion < setAlt)
  {
    ledWarn = HIGH;
    altLCD.setCursor(0,1);
    altLCD.print("Warning!L");
  }
  else
  {
    ledWarn = LOW;
    altLCD.setCursor(0,1);
    altLCD.print("Climb Rt:");
  }
  sprintf(buffer,"%7d",alt);
  digitalWrite(ledPin, ledWarn);
  altLCD.setCursor(9,0);
  altLCD.print(buffer);

  if(millis() - previousTime >= interval)
  {
    deltaTime = millis() - previousTime;
    vertRateConv = (alt - prevAlt)/(deltaTime)*1000*60;
    vertRate = round(vertRateConv);
    prevAlt = alt;
    previousTime = millis();
    sprintf(rbuffer, "%7d",vertRate);
    altLCD.setCursor(9,1);
    altLCD.print(rbuffer);


    Serial.print(altConversion);
    Serial.print(" ");
    Serial.print(potRead);
    Serial.print(" ");
    Serial.println(ledWarn);
  }

   /*Serial.print(altConversion);
    Serial.print(" ");
    Serial.print(potRead);
    Serial.print(" ");
    Serial.println(ledWarn);
*/
    
    

  
}

