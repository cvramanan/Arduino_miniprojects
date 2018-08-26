#include <Ultrasonic.h>
#define TRIG_PIN1    4
#define ECHO_PIN1    3
#define TRIG_PIN2    5
#define ECHO_PIN2    6



int distance1, distance2;
Ultrasonic ultrasonic1(TRIG_PIN1,ECHO_PIN1);
Ultrasonic ultrasonic2(TRIG_PIN2, TRIG_PIN2);
void setup() {         


  
  Serial.begin(9600);
  
}

void loop(){


distance1 = ultrasonic1.read();

//Serial.println(distance1);
if(distance1 < 20)
{
  
if(distance1 < 10)
Serial.println("bw");
if(distance1 > 10)
Serial.println("fw");
}

delay(500);
  // Do something with measured distance value
}

