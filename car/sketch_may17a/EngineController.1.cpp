#ifndef I2C
#define I2C
#include "I2CController.cpp"
#endif I2C


class EngineController {
  private:
    int power;
    I2CContoller* i2c;
  public:
    EngineController(I2CContoller* _i2c){
      i2c = _i2c;
      power = 0;
    }
    int getPower(){
      return power;
    }
    void setPower(int val){
      power = val;
    }
};