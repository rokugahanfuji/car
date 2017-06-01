#ifndef I2C_CPP
#define I2C_CPP
#include "I2CController.cpp"
#endif

class DirectionController {
  private:
    int direction;
    I2CContoller* i2c;
  public:
    DirectionController(I2CContoller* _i2c){
      i2c = _i2c;
      direction = 0;
    }
    int getDirection(){
      return direction;
    }
    void setDirection(int val){
      direction = val;
    }
};