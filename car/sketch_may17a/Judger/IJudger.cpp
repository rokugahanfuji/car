#ifndef I2C_CPP
#define I2C_CPP
#include "I2CController.cpp"
#endif

class IJudger{
  private:
    int WHITE;
    int BLACK;
    I2CContoller *i2c;
  public:
    IJudger(I2CController *_i2c){
        i2c = _i2c;
    }

    virtual void judgeValues() = 0;
};