#ifndef I2C
#define I2C
#include "I2CController.cpp"
#endif I2C

class RunConducter {
  
  private:
  I2CContoller* i2c;
  public:
  RunConducter(I2CContoller* _i2c){
    i2c = _i2c;
  }

};