#include "nodehelper.h"


extern Point pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa\
            ,pointBlockA,pointBlockB,pointBlockC,pointBlockE;

void initN(Point *points,int x,int y)
{
  points->x = x;
  points->y = y;
}


void initNnode(void){
  pointPv12.place = "PV12";
  pointPv15.place = "PV15";
  pointTaruc.place = "TARUC";
  pointBlockD.place = "Block D";
  pointGK.place = "Genting Klang";
  pointWangsa.place = "WangsaMaju";
  pointBlockA.place = "Block A";
  pointBlockB.place = "Block B";
  pointBlockC.place = "Block C";
  pointBlockE.place = "Block E";
}
