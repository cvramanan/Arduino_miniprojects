#include "dweetESP8266.h"
#define THIG_NAME  "heartrate001"  // Put here your thing name
#define WIFISSID "monisha"
#define PASSWORD "monisha2023"

dweet client;
//pulse sensor
int PulseSensorPurplePin = A0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0



int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550;            // Determine which Signal to "count as a beat", and which to ingore.


// The SetUp Function:
void setup(){
    Serial.begin(115200);
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
    pinMode(LED_BUILTIN,OUTPUT);
}
 String val;
void loop(){
   Signal = analogRead(PulseSensorPurplePin); 
    val = String(Signal);
    client.add("shiva", val); // specifies the args of type "String"
    client.sendAll(THIG_NAME);
    if(Signal > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
     digitalWrite(LED_BUILTIN,HIGH);
   } else {
     digitalWrite(LED_BUILTIN,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
   }

    delay(50);
}
