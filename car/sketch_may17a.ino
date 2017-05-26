void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

class RunPlanner {
  
};

class RunConducter {
  
};

class I2CContoller {
  private:
  
  public:
    enum ID : int {
      PIC1 = 0x00,
      PIC2 = 0x01,
      PIC3 = 0x02,
      PIC4 = 0x03,
    };
};

class PhotoSensorController {
  private:
    int left;
    int midleft;
    int right;
    int midright;
  
  public:
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



class EngineController {
  private:

  public:
};

class LunceController {
  private:
  
  public:
};


void loop() {
  // put your main code here, to run repeatedly:
  //int val = analogRead(0);
  //val = map(val,0,1023,0,255);
  Serial.println(analogRead(0));
  
  delay(100);
}
