class PhotoSensorController {
  private:
    int left;
    int midleft;
    int right;
    int midright;
  
  public:
    PhotoSensorController(){
      left = 0;
      midleft = 0;
      right = 0;
      midright = 0;
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