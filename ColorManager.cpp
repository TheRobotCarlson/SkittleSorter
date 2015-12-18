#include "ColorManager.h"

using namespace std;

ColorManager::ColorManager(int binNum,float* dev,float tol){
  _tolerance=tol;
  bins = new float*[binNum];
  for(int i=0; i<binNum;i++){
   bins[i] = new float[6]; //3 for lower range, 3 for upper range
  }
  _dev = dev;
}

int ColorManager::placeBin(int r,int g, int b){
  
}
  
