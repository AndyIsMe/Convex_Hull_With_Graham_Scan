#ifndef _ORIENTATION_H
#define _ORIENTATION_H
#include <math.h>
#include "list.h"

#define clockwise 1
#define anticlockwise 0
#define collinear 0

typedef struct Point Point;
struct Point
{
  int x,y;
  char *place;
  //double data;
};

int distp(Point p ,Point q);
int orientation(Point p,Point q,Point r);
 int PolarAngle(Point p , Point p0);
 int compare(const void *vp1,const void *vp2);
 int swap(Point p , Point p2);
 Point *convexHull(Point points[] , int n , int choice);

#endif // _ORIENTATION_H
