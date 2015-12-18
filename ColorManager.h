#include "Bin.h"
class ColorManager{
  
  public:
    ColorManager(int binNum,float dev[3],float tol);
    float** bins;
    int placeBin(int r,int g, int b);
  private:
    float _tolerance;
    float _dev[3];
};
    
    
