#include <Arduino.h>
#include <Wire.h>

typedef uint8_t byte;

class I2CContoller {

  private:
    I2CContoller* i2c;
  public:
    I2CController(){
      Wire.begin();
      Wire.setClock(400000);
    }

    typedef enum {
      PHOTO_PIC = 0b1010010,
      DRIVE_PIC = 0b1010011,
      RANCE_PIC = 0b0000000,
    } PIC_ID;

    boolean getValue(byte* val,int n,PIC_ID pic){
      if (Wire.requestFrom(pic,n) > 0) {
        int count = 0;
        while(Wire.available()) {
          val[count] = Wire.read();
          count++;
        }
        return true;
      }
      return false;
    }

    void sendValue(byte* val,int n,PIC_ID pic){
      Wire.beginTransmission(pic);
      Wire.write(val,n);
      Wire.endTransmission();
    }
};