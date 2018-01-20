#ifndef _ORIENTATION_H
#define _ORIENTATION_H
#include <math.h>
#include "list.h"
#include "Node.h"
#include "Insert.h"
#include "Remove.h"
#include "Exception.h"
#include "CExceptionConfig.h"

#define clockwise 1
#define anticlockwise 0
#define collinear 0


#define avladdPoint(root,nodeToAdd)  avl_Insert(root,nodeToAdd,(Compare)CompareX)
#define avlremovePoint(root,nodeToRemove)  *RemoveN(root,nodeToRemove,(Compare)CompareXToRemove)

int distp(Point p ,Point q);
int orientation(Point *p,Point *q,Point *r);

Point *pointCreate(int x,int y, char* place);
Node *SearchMinX(Node **rootPtr);
Node *SearchMaxX(Node **rootPtr);
int CompareX(Point *p, Node *refNode);
Point *TopHalf(Node **root,int n,int m);
LinkedList *BottomHalf(Point *root,int n);
// LinkedList *TopHalf(Node **root,int n);
// LinkedList *BottomHalf(Node **root,int n);
void createNodeForPoints(Node *node,Point *data);
int CompareXToRemove(int x, Node *refNode);

#endif // _ORIENTATION_H
