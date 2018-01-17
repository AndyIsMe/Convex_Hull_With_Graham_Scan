#ifndef _NODEVERIFIER_H
#define _NODEVERIFIER_H
#include "orientation.h"

#define TEST_ASSERT_EQUAL_POINT(x,y,place,points) \
                          testAssertEqualPoint(x,y,place,points,__LINE__)
#define TEST_ASSERT_EQUAL_NODE(left,right,bf,node) \
                          testAssertEqualNode(left,right,bf,node,__LINE__)
void testAssertEqualPoint(int x , int y, char *place, Point *points,int lineNo);
void testAssertEqualNode(Node *left, Node *right, int bf, Node *node,int lineNo);
#endif // _NODEVERIFIER_H
