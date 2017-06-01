#ifndef I2C_CPP
#define I2C_CPP
#include "I2CController.cpp"
#endif 

class PhotoSensorController {
  private:
    int left;
    int midleft;
    int right;
    int midright;
    I2CContoller* i2c;
  
  public:
    PhotoSensorController(I2CController* _i2c){
      i2c = _i2c;
      left = 0;
      midleft = 300;
      right = 0;
      midright = 0;
    }

    void updateValue(){
        byte values[5] = {0,0,0,0,0};
        if (i2c->getValue(values,5,I2CContoller::PHOTO_PIC) == true) {
          left     = ((int)values[0]) << 2;
          left     = left + (values[4] >> 6) & 0b00000011;
          midleft  = ((int)values[1]) << 2;
          midleft  = midleft + (values[4] >> 4) & 0b00000011;
          midright = ((int)values[2]) << 2;
          midright = midright + (values[4] >> 2) & 0b00000011;
          right    = ((int)values[3]) << 2;
          right    = right + values[4] & 0b00000011;
        }
    }

    int getLeft(){
      return left;
    }
    
    int getMidleft(){
      return midleft;
    }

    int getRight(){
      return right;
    }

    int getMidright(){
      return midright;
    }

    void setLeft(int val){
      left = val;
    }
    void setMidleft(int val){
      midleft = val;
    }
    void setRight(int val){
      right = val;
    }
    void setMidright(int val){
      midright = val;
    }
};