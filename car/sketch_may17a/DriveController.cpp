#ifndef I2C_CPP
#define I2C_CPP
#include "I2CController.cpp"
#endif

class DriveController {
  private:
    int power;
    int direction;
    I2CController* i2c;
  public:
    DriveController(I2CController* _i2c){
      i2c = _i2c;
      power = 0;
      direction = 0;
    }

    void updateValue(){

    }

    int getPower(){
      return power;
    }
    void setPower(int val){
      power = val;
    }
    int getDirection(){
      return direction;
    }
    void setDirection(int val){
      direction = val;
    }
};