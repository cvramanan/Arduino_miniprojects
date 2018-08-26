
void setup() {
  // put your setup code here, to run once:
pinMode(3,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);
pinMode(10,OUTPUT);
digitalWrite(10,LOW);
//Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(3)){
digitalWrite(10,HIGH);

}
else
digitalWrite(10,LOW);
if(digitalRead(5)){
digitalWrite(10,HIGH);

}
else
digitalWrite(10,LOW);

}
