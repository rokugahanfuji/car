#include "RunPlanner.cpp"

RunPlanner* rp;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  rp = new RunPlanner();
}

void loop() {
  // put your main code here, to run repeatedly:
  //int val = analogRead(0);
  //val = map(val,0,1023,0,255);p
  //Serial.println(i2c->fetchPhotoValue());
  //i2c->sendSpeed();
  //Serial.println(analogRead(0)); 
  rp->run();
}
