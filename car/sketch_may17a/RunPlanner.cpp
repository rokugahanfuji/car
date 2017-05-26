#include "I2CController.cpp"
#include "PhotoSensorController.cpp"
#include "LunceController.cpp"
#include "EngineController.cpp"
#include "RunConducter.cpp"

class RunPlanner {
  private:
    I2CContoller* i2c;
    char nowState;
    enum STATE {
      STOP,
      RUN,
      CORVE,
      HIT,
    };

  public:
    RunPlanner(){
      i2c = new I2CContoller();
      nowState = STOP;
    }
    
    void run(){
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
};