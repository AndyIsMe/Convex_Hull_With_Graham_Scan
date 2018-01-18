#include "build/temp/_test_orientation.c"
#include "Node.h"
#include "Rotate.h"
#include "Remove.h"
#include "CExceptionConfig.h"
#include "Exception.h"
#include "Insert.h"
#include "list.h"
#include "nodeverifier.h"
#include "nodehelper.h"
#include "orientation.h"
#include "unity.h"








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



    int i = orientation(&pointPv12,&pointPv15,&pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_clockwise(void)

{

  initN(&pointPv12,0,0);

  initN(&pointPv15,2,8);

  initN(&pointTaruc,8,2);



    int i = orientation(&pointPv12,&pointPv15,&pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_colinear(void)

{

  initN(&pointPv12,0,0);

  initN(&pointPv15,0,0);

  initN(&pointTaruc,0,0);



    int i = orientation(&pointPv12,&pointPv15,&pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

}



void test_Convex_Hull_Create_Node(void)

{

  Point *p = pointCreate(2,3,"KL");

  Point *p1 = pointCreate(1,2,"Selangor");

  Point *p2 = pointCreate(0,0,"Ipoh");



  testAssertEqualPoint(2,3,"KL",p,58);

  testAssertEqualPoint(1,2,"Selangor",p1,59);

  testAssertEqualPoint(0,0,"Ipoh",p2,60);



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



  avl_Insert(&point1,point2,(Compare)CompareX);

  testAssertEqualNode(point2,

 ((void *)0)

 ,-1,point1,83);



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



  avl_Insert(&root,point1,(Compare)CompareX);

  avl_Insert(&root,point3,(Compare)CompareX);

  testAssertEqualNode(point3,point1,0,point2,110);



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



  avl_Insert(&root,point1,(Compare)CompareX);

  avl_Insert(&root,point3,(Compare)CompareX);

  testAssertEqualNode(point3,point1,0,point2,138);

  *RemoveN(&root,point1->data->x,(Compare)CompareXToRemove);

  testAssertEqualNode(point3,

 ((void *)0)

 ,-1,point2,140);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((point1->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(141), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((point1->data->y)), (

 ((void *)0)

 ), (UNITY_UINT)(142), UNITY_DISPLAY_STYLE_INT);



  free(p1);

  free(p2);

  free(p3);

  free(point1);

  free(point2);

  free(point3);

}



void xtest_Convex_Hull_Insert_A_Few_Points_To_Avl_For_Sorting_Expect_Convex_Hull_In_LinkedList(void)

{

  Point *p1 = pointCreate(4,4,"KL");

  Point *p2 = pointCreate(3,3,"Selangor");

  Point *p3 = pointCreate(2,3,"Ipoh");

  Point *head,*next,*tail;



  Node *point1 = (Node *)malloc(sizeof(Node));

  Node *point2 = (Node *)malloc(sizeof(Node));

  Node *point3 = (Node *)malloc(sizeof(Node));

  createNodeForPoints(point1,p1);

  createNodeForPoints(point2,p2);

  createNodeForPoints(point3,p3);



  Node *root = point2;



  avl_Insert(&root,point1,(Compare)CompareX);

  avl_Insert(&root,point3,(Compare)CompareX);

  LinkedList *list = TopHalf(&root,3);

  if (((((Point*)(list->head->data))) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(171))));};

  head = (Point*)(list->head->data);

  next = (Point*)(list->head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((head->x)), (

 ((void *)0)

 ), (UNITY_UINT)(174), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((next->x)), (

 ((void *)0)

 ), (UNITY_UINT)(175), UNITY_DISPLAY_STYLE_INT);

  if ((((list->tail)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(176))));};







  free(p1);

  free(p2);

  free(p3);

}
