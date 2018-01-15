#include "unity.h"
#include "orientation.h"
#include "nodehelper.h"
#include "nodeverifier.h"
#include <stdio.h>
#include "list.h"
#include "Insert.h"
#include "Exception.h"
#include "CExceptionConfig.h"
// #include "Remove.h"
#include "Rotate.h"
#include "Node.h"
#include <stdlib.h>


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

void test_Convex_Hull_Create_Node(void)
{
  Point *p = pointCreate(2,3,"KL");
  Point *p1 = pointCreate(1,2,"Selangor");
  Point *p2 = pointCreate(0,0,"Ipoh");

  TEST_ASSERT_EQUAL(2,p->x);
  TEST_ASSERT_EQUAL(3,p->y);
  TEST_ASSERT_EQUAL("KL",p->place);
  TEST_ASSERT_EQUAL(1,p1->x);
  TEST_ASSERT_EQUAL(2,p1->y);
  TEST_ASSERT_EQUAL("Selangor",p1->place);
  TEST_ASSERT_EQUAL(0,p2->x);
  TEST_ASSERT_EQUAL(0,p2->y);
  TEST_ASSERT_EQUAL("Ipoh",p2->place);

  free(p);
  free(p1);
  free(p2);
}


void test_Convex_Hull_Insert_To_Avl_For_Sorting(void)
{
  Point *p = pointCreate(2,3,"KL");
  Point *p1 = pointCreate(1,2,"Selangor");
  Point *p2 = pointCreate(0,0,"Ipoh");

  Node *point1 = (Node *)malloc(sizeof(Node));
  Node *point2 = (Node *)malloc(sizeof(Node));
  Node *point3 = (Node *)malloc(sizeof(Node));
  createNodeForPoints(point1,&p);
  createNodeForPoints(point2,&p1);
  createNodeForPoints(point3,&p2);

  avladdPoint(&point1,point2);
  TEST_ASSERT_EQUAL_PTR(point2,point1->left);

  free(p);
  free(p1);
  free(p2);
}
