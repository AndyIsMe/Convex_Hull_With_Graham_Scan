#include "unity.h"
#include "orientation.h"
#include "nodehelper.h"
#include "nodeverifier.h"
#include <stdio.h>
#include "list.h"
#include "Insert.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "Remove.h"
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

  TEST_ASSERT_EQUAL_POINT(2,3,"KL",p);
  TEST_ASSERT_EQUAL_POINT(1,2,"Selangor",p1);
  TEST_ASSERT_EQUAL_POINT(0,0,"Ipoh",p2);

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
  createNodeForPoints(point1,p);
  createNodeForPoints(point2,p1);
  createNodeForPoints(point3,p2);

  avladdPoint(&point1,point2);
  TEST_ASSERT_EQUAL_NODE(point2,NULL,-1,point1);

  free(p);
  free(p1);
  free(p2);
  free(point1);
  free(point2);
  free(point3);
}

void test_Convex_Hull_Insert_A_Few_Points_To_Avl_For_Sorting(void)
{
  Point *p1 = pointCreate(2,3,"KL");
  Point *p2 = pointCreate(1,2,"Selangor");
  Point *p3 = pointCreate(0,0,"Ipoh");

  Node *point1 = (Node *)malloc(sizeof(Node));
  Node *point2 = (Node *)malloc(sizeof(Node));
  Node *point3 = (Node *)malloc(sizeof(Node));
  createNodeForPoints(point1,p1);
  createNodeForPoints(point2,p2);
  createNodeForPoints(point3,p3);

  Node *root = point2;

  avladdPoint(&root,point1);
  avladdPoint(&root,point3);
  TEST_ASSERT_EQUAL_NODE(point3,point1,0,point2);

  free(p1);
  free(p2);
  free(p3);
  free(point1);
  free(point2);
  free(point3);

}

void test_Convex_Hull_Insert_A_Few_Points_To_Avl_For_Sorting_And_Remove(void)
{
  Point *p1 = pointCreate(2,3,"KL");
  Point *p2 = pointCreate(1,2,"Selangor");
  Point *p3 = pointCreate(0,0,"Ipoh");

  Node *point1 = (Node *)malloc(sizeof(Node));
  Node *point2 = (Node *)malloc(sizeof(Node));
  Node *point3 = (Node *)malloc(sizeof(Node));
  createNodeForPoints(point1,p1);
  createNodeForPoints(point2,p2);
  createNodeForPoints(point3,p3);

  Node *root = point2;

  avladdPoint(&root,point1);
  avladdPoint(&root,point3);
  TEST_ASSERT_EQUAL_NODE(point3,point1,0,point2);
  avlremovePoint(&root,point1->data->x);
  TEST_ASSERT_EQUAL_NODE(point3,NULL,-1,point2);
  TEST_ASSERT_EQUAL(2,point1->data->x);
  TEST_ASSERT_EQUAL(3,point1->data->y);

  free(p1);
  free(p2);
  free(p3);
  free(point1);
  free(point2);
  free(point3);
}

void test_Convex_Hull_Insert_A_Few_Points_To_Avl_For_Sorting_Expect_Convex_Hull_In_LinkedList(void)
{
  Point *p1 = pointCreate(4,4,"KL");
  Point *p2 = pointCreate(3,3,"Selangor");
  Point *p3 = pointCreate(2,3,"Ipoh");
  Point *check;

  Node *point1 = (Node *)malloc(sizeof(Node));
  Node *point2 = (Node *)malloc(sizeof(Node));
  Node *point3 = (Node *)malloc(sizeof(Node));
  createNodeForPoints(point1,p1);
  createNodeForPoints(point2,p2);
  createNodeForPoints(point3,p3);

  Node *root = point2;

  avladdPoint(&root,point1);
  avladdPoint(&root,point3);
  LinkedList *list = TopHalf(&root);
  //TEST_ASSERT_EQUAL_NODE(point3,point1,0,point2);
  // TEST_ASSERT_NOT_NULL((Point*)(list->head->));
  //check = (Point*)(list->head->data);
  //TEST_ASSERT_EQUAL(1,check->x);
  //TEST_ASSERT_EQUAL_NODE(point3,point1,0,point2);

  free(p1);
  free(p2);
  free(p3);
}
