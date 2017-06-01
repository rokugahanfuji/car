#ifndef I2C_CPP
#define I2C_CPP
#include "I2CController.cpp"
#endif

class RunConducter {
  
  private:
  I2CContoller* i2c;
  public:
  RunConducter(I2CContoller* _i2c){
    i2c = _i2c;
  }

};