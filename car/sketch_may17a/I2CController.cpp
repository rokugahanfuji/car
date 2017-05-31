#include <Arduino.h>
#include <Wire.h>

typedef uint8_t byte;

class I2CContoller {

  private:
    int count = 0;
    I2CContoller* i2c;
  public:

    I2CContoller(){
      Wire.begin();
      Wire.setClock(400000);
    }

    enum I2C {
      PHOTO_PIC = 0b1010010,
      WHEEL_PIC = 0b1010011,
    };

    void fetchPhotoValue(byte* val){
      int count = 0;
      if (Wire.requestFrom(PHOTO_PIC,5) > 0) {;
        while(Wire.available()) {
          val[count] = Wire.read();
          count++;
        }
      }
      /*
      for(int i = 0;i<5;i++){
        Serial.print(val[i]);
        Serial.print(",");
      }
      Serial.print("\n");
      */
    }

/*
    byte fetchPhotoValue(){
      byte val;
      if (Wire.requestFrom(PHOTO_PIC,5) > 0) {;
        while(Wire.available()) {
          val = Wire.read();
          Serial.println(val);
        }
        
      }
      delay(500);
      return val;
    }
  */
    void sendSpeed(){
      Wire.beginTransmission(WHEEL_PIC);
      Wire.write(count);
      Wire.endTransmission();
      count++;
    }

};