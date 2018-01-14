#ifndef _NODEVERIFIER_H
#define _NODEVERIFIER_H
#include "orientation.h"

#define TEST_ASSERT_EQUAL_POINT(x,y,place,points) \
                          testAssertEqualNode(x,y,place,points,__LINE__)

void testAssertEqualNode(int x , int y, char *place, Point *points,int lineNo);

#endif // _NODEVERIFIER_H
