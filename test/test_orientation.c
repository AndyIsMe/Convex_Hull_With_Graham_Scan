#include "unity.h"
#include "orientation.h"
#include "nodehelper.h"
#include "nodeverifier.h"
#include <stdio.h>
#include "list.h"

void setUp(void)
{
    initNnode();
}
void tearDown(void){}

void test_orientation_expect_anticlockwise(void)
{
  initN(&pointPv12,0,0);
  initN(&pointPv15,4,4);
  initN(&pointTaruc,1,2);

    int i = orientation(pointPv12,pointPv15,pointTaruc);
    TEST_ASSERT_EQUAL(2,i);
}

void test_orientation_expect_clockwise(void)
{
  initN(&pointPv12,0,0);
  initN(&pointPv15,2,8);
  initN(&pointTaruc,8,2);

    int i = orientation(pointPv12,pointPv15,pointTaruc);
    TEST_ASSERT_EQUAL(1,i);
}

void test_orientation_expect_colinear(void)
{
  initN(&pointPv12,0,0);
  initN(&pointPv15,0,0);
  initN(&pointTaruc,0,0);

    int i = orientation(pointPv12,pointPv15,pointTaruc);
    TEST_ASSERT_EQUAL(0,i);
}

void test_(void){
  initN(&pointPv12,0,3);
  initN(&pointPv15,1,1);
  initN(&pointTaruc,2,2);
  initN(&pointBlockD,4,4);
  initN(&pointGK,0,0);
  initN(&pointWangsa,1,2);
  initN(&pointBlockA,3,1);
  initN(&pointBlockB,3,3);
  Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa\
                ,pointBlockA,pointBlockB};

  int n = (sizeof(start))/(sizeof(start[0]));
  Point *end = (convexHull(start , n , clockwise));

  //TEST_ASSERT_EQUAL(6,n);
  //TEST_ASSERT_EQUAL_POINT(0,0,"Genting Klang",end);
  //TEST_ASSERT_EQUAL_POINT(0,3,"PV12",end+1);
  //TEST_ASSERT_EQUAL_POINT(3,3,"WangsaMaju",end+2);
  //TEST_ASSERT_EQUAL_POINT(3,0,"Block D",end+3);
}
