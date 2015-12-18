// Author: Brian Carlson
// Purpose: keeps track of the statistics for each bin
// Last updated: 12/18/2015
class Bin{
  
  public:
    Bin(int colorVals[3],float dev[3]);
    float movAvg[3];
    void addVal(int colorVals[3],float dev[3]);
    float bounds[3][4];
    int num;
    
   private:
     void _addColor(int val,float dev,int i);
};
    
