#ifndef _ORIENTATION_H
#define _ORIENTATION_H
#include <math.h>
#include "list.h"
#include "Node.h"
#include "Insert.h"

#define clockwise 1
#define anticlockwise 0
#define collinear 0


#define avladdPoint(root,nodeToAdd)  avl_Insert(root,nodeToAdd,(Compare)CompareX)


int distp(Point p ,Point q);
int orientation(Point p,Point q,Point r);
 int PolarAngle(Point p , Point p0);
 //int compare(const void *vp1,const void *vp2);
 int swap(Point p , Point p2);
 Point *convexHull(Point points[] , int n , int choice);


Point *pointCreate(int x,int y, char* place);
Node *SearchMinX(Node **rootPtr);
int CompareX(Point *p, Node *refNode);
int TopHalf(Node **root,Point *point);
void createNodeForPoints(Node *node,Point *data);

#endif // _ORIENTATION_H
