class ColorManager{
  
  public:
    ColorManager(int binNum,float tol);
    float* bins;
    int placeBin(int r,int g, int b);
  private:
    float _tolerance;
};
    
    
