#ifndef I2C_CPP
#define I2C_CPP
#include "I2CController.cpp"
#include <Arduino.h>
#endif 

#include "PhotoSensorController.cpp"
#include "DriveController.cpp"
#include "LunceController.cpp"
#include "Judger/IJudger.cpp"
#include "Judger/BinaryJudger.cpp"

class RunPlanner {
  public : 
  typedef enum {
      STOP,
      RUN,
      CORVE,
      HIT,
    } STATE;

  private:
    STATE nowState;
    I2CController* i2c;
    PhotoSensorController *photo;
    DriveController *drive;
    IJudger = *judger;

  public:
    RunPlanner(){
      nowState = STOP;
      i2c = new I2CController();
      photo = new PhotoSensorController(i2c);
      drive = new DriveController(i2c);
      judger = new BinaryJudger(i2c);
    }
    
    void run(){
      update();

      switch (nowState){
        case STOP:
          break;
        case RUN:
          break;
        case CORVE:
          break;
        case HIT:
          break;
        default :
          break;
      }
      debug();
    }

    void update(){
      photo->updateValue();
      drive->updateValue();
    }

    void setState(STATE st){
      nowState = st;
    }

    STATE getState(){
      return nowState;
    }

    void debug(){
      Serial.println("-----------------------");
      Serial.println("LEFT  MLEFT MRIGH RIGHT");
      Serial.print(photo->getLeft());
      Serial.print("\t");
      Serial.print("  ");
      Serial.print(photo->getMidleft());
      Serial.print("\t");
      Serial.print("");
      Serial.print(photo->getMidright());
      Serial.print("\t");
      Serial.print("  ");
      Serial.print(photo->getRight());
      Serial.println();
      delay(500);
    }
    
};