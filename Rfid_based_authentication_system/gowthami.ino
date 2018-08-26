
#include <SPI.h>
#include "MFRC522.h"
#define RST_PIN  9  // RST-PIN für RC522 - RFID - SPI - Modul GPIO5 
#define SS_PIN  10  // SDA-PIN für RC522 - RFID - SPI - Modul GPIO4 

/* wiring the MFRC522 to ESP8266 (ESP-12)
RST     = GPIO5
SDA(SS) = GPIO4 
MOSI    = GPIO13
MISO    = GPIO12
SCK     = GPIO14
GND     = GND
3.3V    = 3.3V
*/
//instance for coapclient



/*=======
const char* password = "*******";
>>>>>>> observe
*/
//ip address and default port of coap server in which your interested in



/*void callback_response(coapPacket &packet, IPAddress ip, int port) {
    char p[packet.payloadlen + 1];
    memcpy(p, packet.payload, packet.payloadlen);
    p[packet.payloadlen] = NULL;
    //response from coap server
 if(packet.type==3 && packet.code==0){
      Serial.println("ping ok");
    }
    Serial.println(p);
}
*/
//card code's
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
   
    Serial.begin(9600);
pinMode(3,OUTPUT);
pinMode(2,OUTPUT);
 
    Serial.println(" ");
SPI.begin();           // Init SPI bus
  mfrc522.PCD_Init();    // Init MFRC522
    // Connection info to WiFi network
  
}
//int i=0;
int a =0 ;
char b[20] ;
String s = String(" ");

void loop() {
    //bool state;
  

    // Requests

    //get request
    //int msgid = coap.get(ip,port,"hello");

    //put request 
    //arguments server ip address,default port,resource name, payload,payloadlength
    //int msgid =coap.put(ip,port,"resourcename","0",strlen("0"));
//int msgid =coap.put(ip,port,"/LED","hi ram",strlen("hi ram"));
    //post request
    //arguments server ip address,default port,resource name, payload,payloadlength
   // int msgid =coap.post(ip,port,"/LED",'0',strlen("0"));
   //--------------------------------------------------------------------
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
    // delay(50);
     //msgid =coap.post(ip,port,"/","0",strlen("0"));
     //delay(1000);
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    // delay(50);

    return;
  }
  // Show some details of the PICC (that is: the tag/card)
  //Serial.print(F("Card UID:"));


  s = String(dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size));
  Serial.println(s);
  if(s == " 0a 57 dd 2f")
 details();
 else
 {
  digitalWrite(3,HIGH);
    digitalWrite(2,HIGH);
  Serial.write("Invalid card");
  delay(3000);
  digitalWrite(3,LOW);
   digitalWrite(2,LOW); 
 }
 
 

 //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  mfrc522.PICC_HaltA();
  // Stop encryption on PCD
  mfrc522.PCD_StopCrypto1();
  //-------------------------------------------------------------------------
    
   
//int msgid =     coap.post(ip,port,"/LED","0",strlen("0"));

    //delete request
    //int msgid = coap.delet(ip,port,"resourcename");

    //ping
    //int msgid=coap.ping(ip,port);
    
    // int msgid=coap.observe(ip,port,"obs",a);
 
    //state= coap.loop();
    //Serial.println(state);
    // Serial.print("state=");
    //Serial.println(state);
    //if(state==true)
          //i=i+1;
  
    //Serial.print("i=");
    //Serial.println(i);
      //if(i==3)
    //{
        //Serial.println("cancel observe");
        //coap.observeCancel(ip,port,"resourcename");
    //}
 
 
    //Serial.println(msgid);
    //delay(1000);
}
String dump_byte_array(byte *buffer, byte bufferSize) {
  String str;
  for (byte i = 0; i < bufferSize; i++) {
    //Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    //Serial.print(buffer[i], HEX);
    str += String(buffer[i] < 0x10 ? " 0" : " ");
    str += String(buffer[i], HEX);


  }
  return str;
}
void details()
{
  Serial.println("------------------------------------------------------------");
  Serial.println(" Name : Gowthami\nCollege : KGiSL Institute of technology");
  Serial.println("------------------------------------------------------------");
}


