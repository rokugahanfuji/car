#include <Wire.h>

typedef uint8_t byte;

class I2CContoller {

  private:
    int count = 0;
    
  public:

    I2CContoller(){
      Wire.begin();
      Wire.setClock(400000);
    }

    enum I2C {
      PHOTO_PIC = 0b1010010,
      WHEEL_PIC = 0b1010011,
    };

    byte fetchPhotoValue(){
      if (Wire.requestFrom(PHOTO_PIC,1) > 0) {;
        while(Wire.available()) {
          byte val = Wire.read();
          return val;
        }
      }
    }
    
    void sendSpeed(){
      Wire.beginTransmission(WHEEL_PIC);
      Wire.write(count);
      Wire.endTransmission();
      count++;
    }

};