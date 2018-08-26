
#include <SoftwareSerial.h>
int vib_pin=2;
SoftwareSerial mySerial(9, 8); // RX, TX
SoftwareSerial gsm(11, 10);
void setup() {
  pinMode(vib_pin,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(57600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
 mySerial.begin(9600);
 //gsm.begin(9600);
}
char a ;
String gpsData ;

void loop() {
  int val;

  if (mySerial.available()) {
    a = mySerial.read();
    gpsData += a;
   
  }
  
  if(gpsData.length() > 41){
  Serial.println(gpsData);
  mySerial.end();
  gsm.begin(9600);
  while(1)
  {
    val = digitalRead(vib_pin);
    if(val==LOW)
  {
    Serial.println(gpsData);
    SendMessage();
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
   }
   else
   digitalWrite(LED_BUILTIN,LOW); 
  }

  }
  
/*  val=digitalRead(vib_pin);
 // while(val);
 Serial.println(val);
  if(val==LOW)
  {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
   }
   else
   digitalWrite(LED_BUILTIN,LOW);
 */  
}
//Sending message
void SendMessage()
{
  gsm.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  gsm.println("AT+CMGS=\"+918072076020\"\r"); // Replace x with mobile number
  delay(1000);
  gsm.println("The vehicle repared_Location:"+gpsData);// The SMS text you want to send
  delay(100);
   gsm.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

