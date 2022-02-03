#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "uY0FBePpTwP1O23lUF_esRf1-GipXlcE";
char ssid[] = "Suri_prime";
char pass[] = "5mhzennkns";
BlynkTimer timer;
int relayInput = 2; 
int inputPin = 13;
int val = 0;
int count;
void level() {
  val = digitalRead(inputPin); 
     if (val == HIGH)
      {
        digitalWrite(relayInput,HIGH);
        delay(1000);
   } 
   else 
   { 
        count=count+1;
        Blynk.virtualWrite(V0, count);
        digitalWrite(relayInput, LOW);
        delay(1000);
        digitalWrite(relayInput,HIGH);
        delay(3000);     
   } 
}
void setup() {
  pinMode(relayInput, OUTPUT); 
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(10L, level);
}
void loop() {
  Blynk.run();
  timer.run();
}
