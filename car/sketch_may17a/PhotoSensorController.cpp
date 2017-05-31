#ifndef I2C
#define I2C
#include "I2CController.cpp"
#endif I2C

class PhotoSensorController {
  private:
    int left;
    int midleft;
    int right;
    int midright;
    I2CContoller* i2c;
  
  public:
    PhotoSensorController(I2CContoller* _i2c){
      i2c = _i2c;
      left = 0;
      midleft = 0;
      right = 0;
      midright = 0;
    }

    void getValueI2C(){
        byte values[5] = {0,0,0,0,0};
        i2c->fetchPhotoValue(values);
        left     = ((int)values[0]) << 2;
        left     = left + ((int)values[4]/64 & 0b00000011);
        midleft  = ((int)values[1]) << 2;
        midleft  = midleft + ((int)values[4]/16 & 0b00000011);
        midright = ((int)values[2]) << 2;
        midright = midright + ((int)values[4]/4 & 0b00000011);
        right    = ((int)values[3]) << 2;
        right    = right + ((int)values[4] & 0b00000011);
        
        
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