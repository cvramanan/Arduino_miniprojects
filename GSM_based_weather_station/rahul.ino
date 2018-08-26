const int sensor=A0; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
#include "MQ135.h"
#define ANALOGPIN A1  //  Define Analog PIN on Arduino Board
#define RZERO 206.85    //  Define RZERO Calibration Value
MQ135 gasSensor = MQ135(ANALOGPIN);
//gsm
 #include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
void setup()
{
pinMode(sensor,INPUT); // Configuring pin A1 as input
Serial.begin(9600);
  float rzero = gasSensor.getRZero();
   mySerial.begin(9600); 
  delay(3000);
  Serial.print("MQ135 RZERO Calibration Value : ");
  Serial.println(rzero);
}
void loop() 
{
   float ppm = gasSensor.getPPM();
   delay(1000);
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
//tempf=(vout*1.8)+32; // Converting to Fahrenheit 
Serial.print("in DegreeC=");
Serial.print("\t");
Serial.print(tempc);
Serial.println();
Serial.print("CO2 ppm value : ");
  Serial.println(ppm);
/*Serial.print("in Fahrenheit=");
Serial.print("\t");
Serial.print(tempf);
Serial.println();
*/
//sms
SendMessage(tempc,ppm);
delay(1000); //Delay of 1 second for ease of viewing 
}
 void SendMessage(float temp,float ppm )
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917667635512\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("temp:"+String(temp)+" ppm:"+String(ppm));// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
