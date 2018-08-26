#include <hcsr04.h>
#define TRIG_PIN  2
#define ECHO_PIN  3
HCSR04 sensor;

//------------------------------------------------------------------------------
void setup() {         
  sensor.init(TRIG_PIN, ECHO_PIN);
  //sensor.setCalibration(calibration);
  //sensor.setOffset(offset);
  Serial.begin(9600);
  
}
long distance;
 
void loop(){

  distance = sensor.readAccurateDisctanceInCm();
  
Serial.println(distance);
  delay(500);
}

