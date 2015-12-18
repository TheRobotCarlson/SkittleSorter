#include "Bin.h"


Bin::Bin(int colorVals[3], float dev[3]) {
  num = 1;
  for (int i = 0; i < 3; i++) {
    movAvg[i] = colorVals[i];
    bounds[i][0] = colorVals[i] - (2 * dev[i]);
    bounds[i][1] = colorVals[i] - (dev[i]);
    bounds[i][2] = colorVals[i] + (dev[i]);
    bounds[i][3] = colorVals[i] + (2 * dev[i]);
  }
}

void Bin::addVal(int colorVals[3], float dev[3]) {
  num++;
  for (int i = 0; i < 3; i++) {
    _addColor(colorVals[i], dev[i], i);
  }
}

void Bin::_addColor(int colorVal, float dev, int i) {
  //If our upper bound is larger than the new val's maximum range
  //then shrink our upper bound
  if ((colorVal + (2 * dev)) < bounds[i][3]) {
    bounds[i][3] = (((num - 1) * bounds[i][3]) + colorVal) / num; //average bound
  }
  if ((colorVal - (2 * dev)) > bounds[i][0]) {
    bounds[i][0] = (((num - 1) * bounds[i][0]) + colorVal) / num;
  }
  movAvg[i] = (((num - 1) * movAvg[i]) + colorVal) / num;
}


