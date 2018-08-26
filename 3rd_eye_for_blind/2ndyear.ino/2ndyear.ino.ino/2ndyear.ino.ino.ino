#include <ESP8266WiFi.h>
#include <Ultrasonic.h>

#define timeInterval 30000 // time between each trigger


const char* ssid = "Jo jio";
const char* password = "jone0007";

const char* host = "maker.ifttt.com";
const char* privateKey = "bvXcKeFiepUqjiA1nNrZPPZFlV7-BUvfJNlHuGoFS1v";
const char* event = "danger";

long lastTime = 0; // holds previous time trigger was sent
Ultrasonic ultrasonic(D5, D6);
Ultrasonic us2(D2, D3);
int distance,dis2;
void setup() {
Serial.begin(115200); // initialize serial communication

delay(100);
// We start by connecting to a WiFi network
pinMode(D7,OUTPUT);
  Serial.println();
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
}

void loop() {
// Read sensor inputs
// get temperature reading in Celsius

// Check if any reads failed and exit early (to try again).
distance = ultrasonic.read();
  dis2 = us2.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  Serial.println(dis2);
  if(distance > 100 || dis2 > 100)
  digitalWrite(D7,HIGH);
  else
    digitalWrite(D7,LOW);
if((distance > 10 || dis2 > 10) && millis()- lastTime > timeInterval){ // temperature is less than 30 deg

Serial.print("connecting to ");
Serial.println(host);
WiFiClient client;
const int httpPort = 80;
if (!client.connect(host, httpPort)) {
Serial.println("connection failed");
return;
}
// We now create a URI for the request
String url = "/trigger/";
url += event;
url += "/with/key/";
url += privateKey;
url += "?value1=";
url += String(distance);
Serial.print("Requesting URL: ");
Serial.println(url);
// This will send the request to the server
client.print(String("GET ") + url + " HTTP/1.1\r\n" +
"Host: " + host + "\r\n" +
"Connection: close\r\n\r\n");
unsigned long timeout = millis();
while (client.available() == 0) {
if (millis() - timeout > 5000) {
Serial.println(">>> Client Timeout !");
client.stop();
return;
}
}
// Read all the lines of the reply from server and print them to Serial
while(client.available()){
String line = client.readStringUntil('\r');
Serial.print(line);
}
Serial.println();
Serial.println("closing connection");
lastTime = millis(); // save time of last trigger
}
}
