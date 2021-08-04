/*#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>*/

#include <MQUnifiedsensor.h>

#include <SimpleDHT.h>
#include <gravity_soil_moisture_sensor.h>
//#include <FirebaseArduino.h>
#include <SoftwareSerial.h>
SoftwareSerial SendData(5,6);

// Set these to run example.
/*#define FIREBASE_HOST "smartfarminnovation-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "D2Z6ovMFeciTRXfxh4hadCj2Q5MQFqwRHFMfPWya"
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"*/



int digitalPin = 2;
SimpleDHT11 dht11(digitalPin);

byte temperature= 0;
byte humidity= 0;
int get_data;


int percentageT;
int mapt_low= 0;
int mapt_high= 50;

int percentageH;
int maph_low= 20;
int maph_high= 90;

int analogPin = A0;
int moisture;
int percentage;

int map_low= 796;
int map_high= 238;

int analogPin1 = A4;
int smoke;
int percentages;

int maps_low= 0;
int maps_high= 800;




void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

  /*delay (1000);
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
  Firebase.begin (FIREBASE_HOST, FIREBASE_AUTH); */
  //SimpleDHT1.begin ();

}

void loop() {

  //Getting soil moisture data from the soil moisture sensor
  moisture = analogRead(analogPin);

  //error handling in getting soil moisture data from sensor
  /*if (isnan (moisture) {
    Serial.println ("Failed to read from soil moisture sensor!")};
    return;*/

    
  // outputting sensor temperature data to the serial monitor
  Serial.print("Moisture: ");
  Serial.print(moisture);
  Serial.print("mm");

  //Initializing moisture data into the firebase realtime database
 // String firebaseMoist = String (moisture) + String ("mm");
  

  //Conversion of soil moisture readings to percentage
  percentage = map(moisture, map_low, map_high, 0, 100);
  Serial.print("| Percentage : ");
  Serial.print(percentage);

  //Initializing moisture data in percentage into the firebase realtime database
  //String firebaseMoistPercentage = String (percentage) + String ("%");

  Serial.println("%");

  delay(5000);
  

  //Getting soil temperature and humidity reading from the DHT11 sensor
  get_data = dht11.read(&temperature, &humidity, NULL);

  //error handling in getting DHT11 data
  /*if (isnan ((int)temperature) || isnan ((int)humidity)) {
    Serial.println ("Failed to read from DHT sensor!")};
    return;*/
    
  // outputting sensor temperature data to the serial monitor 
  Serial.print("Temperature : ");
  Serial.print((int)temperature);
  Serial.print("*C");

  //Initializing data into the firebase realtime database
 // String firebaseTemp = String ((int)temperature) + String ("°C");

  //Conversion of soil tempersture readings to percentage
  percentageT = map((int)temperature, mapt_low, mapt_high, 0, 100);
  Serial.print("|  Percentage : ");
  Serial.print(percentageT);

  //Initializing temperature data in percentage into the firebase realtime database
 // String firebaseTempPercentageT = String (percentageT) + String ("%");

  Serial.println("%");

  delay(5000);
  
  // outputting soil sensor humidity data to the serial monitor 
  Serial.print("Humidity : ");
  Serial.print((int)humidity);
  Serial.print("RH");

  //Initializing soil humidity data into the firebase realtime database
  //String firebaseHumid = String ((int)humidity) + String ("RH");
  
  
  //Conversion of soil humidity readings to percentage
  percentageH = map((int)humidity, maph_low, maph_high, 0, 100);
  Serial.print("|  Percentage : ");
  Serial.print(percentageH);

  //Initializing moisture data in percentage into the firebase realtime database
  //String firebaseHumidPercentageH = String (percentageH) + String ("%");

  Serial.println("%");
  
  delay(5000);

  //Getting MQ2 gas data
  smoke = analogRead(analogPin1);

  
  //error handling in getting soil CO2 level data from sensor
  /*if (isnan (smoke) {
    Serial.println ("Failed to read from MQ2 sensor!")};
    return;*/

  //Outputting CO2 level to the serial monitor
  Serial.print("Carbon dioxide : ");
  Serial.print(smoke);
  Serial.print("ppm");
  
  
  //Initializing soil humidity data into the firebase realtime database
  //String firebaseSmoke = String (smoke) + String ("ppm");

  
  //Conversion of soil CO2 readings to percentage
  percentages = map(smoke, maps_low, maps_high, 0, 100);
  Serial.print("|  Percentage : ");
  Serial.print(percentages);

   //Initializing soil humidity data in percentage into the firebase realtime database
  //String firebaseSmokePercentageS = String (percentages) + String ("%");

  Serial.println("%");


  delay(5000);
  
  // put your main code here, to run repeatedly:

  //Pushing real-time data into the firebase real-time database
 /* Firebase.pushString ("Soil moisture", firebaseMoist);
  Firebase.pushString ("Soil moisture Percentage", firebaseMoistPercentage);
  Firebase.pushString ("Humidity", firebaseHumid);
  Firebase.pushString ("Humidity Percentage", firebaseHumidPercentageH); 
  Firebase.pushString ("Temperature", firebaseTemp);
  Firebase.pushString ("Temperature Percentage", firebaseTempPercentageT);
  Firebase.pushString ("Carbon dioxide", firebaseSmoke);
  Firebase.pushString ("Carbon dioxide Percentage", firebaseSmokePercentageS);*/

  // put your main code here, to run repeatedly:
}
