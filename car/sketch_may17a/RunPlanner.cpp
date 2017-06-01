#ifndef I2C_CPP
#define I2C_CPP
#include "I2CController.cpp"
#include <Arduino.h>
#endif 

#include "PhotoSensorController.cpp"
#include "DirectionController.cpp"
#include "LunceController.cpp"
#include "EngineController.cpp"
#include "RunConducter.cpp"

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
    I2CContoller* i2c;
    PhotoSensorController *photo;
    EngineController *engine;
    RunConducter *conducter;

  public:
    RunPlanner(){
      nowState = STOP;
      i2c = new I2CContoller();
      photo = new PhotoSensorController(i2c);
      engine = new EngineController(i2c);
      conducter = new RunConducter(i2c);
    }
    
    void run(){
      getValues();

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
    }

    void getValues(){
      photo->updateValue();
    }

    void setState(STATE st){
      nowState = st;
    }

    STATE getState(){
      return nowState;
    }

    void debug(){
      Serial.print(photo->getLeft());
      Serial.print(" ");
      Serial.print(photo->getMidleft());
      Serial.print(" ");
      Serial.print(photo->getMidright());
      Serial.print(" ");
      Serial.print(photo->getRight());
      Serial.println(" ");
    }
    
};