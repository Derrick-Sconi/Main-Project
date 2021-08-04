//libraries for parsing data to firebase
#include <ESP8266Firebase.h>
#include <ArduinoJson.h>

//Include Lib for Arduino to Nodemcu
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>


#define FIREBASE_HOST "smartfarminnovation-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "D2Z6ovMFeciTRXfxh4hadCj2Q5MQFqwRHFMfPWya"
#define WIFI_SSID "ESI'S iphone"
#define WIFI_PASSWORD "12345678"

SoftwareSerial receiveData(D6, D5);

byte temperature = 0;
byte humidity = 0;
int percentageH;
int percentageT;
int percentageS;
int percentage;
int moisture;
int smoke;

void setup() {
//  delay (1000);

Serial.begin(9600)
    WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
    Serial.print ("Connecting to");
    Serial.print (WIFI_SSID);
    while (WiFi.status()!= WL_CONNECTED) {
    Serial.print (".");
    delay (500);
    }
    Serial.println ();
    Serial.print ("Connected to");
    Serial.print (" ");
    Serial.println (WIFI_SSID);
    Serial.print ("IP Address is:");
    Serial.println (WiFi.localIP ());
    Firebase.begin (FIREBASE_HOST, FIREBASE_AUTH); 

  

  receiveData.begin(4800)




}

void loop() {

  if (receiveData.available) {
    moisture = moisture.parseInt;
    temperature = temperature.parseInt;
    humidity = humidity.parseFloat;
    smoke = smoke.parseFloat;

    percentage = percentage.parseInt;
    percentageT = percentageT.parseInt;
    percentageH = percentageH.parseFloat;
    percentageS = percentageS.parseFloat;
    
  }
}
