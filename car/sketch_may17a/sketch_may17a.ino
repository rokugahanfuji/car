#include "RunPlanner.cpp"

RunPlanner* rp;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  rp = new RunPlanner();
}

void loop() {
  rp->run();
}
