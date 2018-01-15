#include "build/temp/_test_orientation.c"
#include "Node.h"
#include "Rotate.h"
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



    int i = orientation(pointPv12,pointPv15,pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_clockwise(void)

{

  initN(&pointPv12,0,0);

  initN(&pointPv15,2,8);

  initN(&pointTaruc,8,2);



    int i = orientation(pointPv12,pointPv15,pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_colinear(void)

{

  initN(&pointPv12,0,0);

  initN(&pointPv15,0,0);

  initN(&pointTaruc,0,0);



    int i = orientation(pointPv12,pointPv15,pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

}



void test_Convex_Hull_Create_Node(void)

{

  Point *p = pointCreate(2,3,"KL");

  Point *p1 = pointCreate(1,2,"Selangor");

  Point *p2 = pointCreate(0,0,"Ipoh");



  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((p->x)), (

 ((void *)0)

 ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((p->y)), (

 ((void *)0)

 ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(("KL")), (UNITY_INT)((p->place)), (

 ((void *)0)

 ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((p1->x)), (

 ((void *)0)

 ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((p1->y)), (

 ((void *)0)

 ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(("Selangor")), (UNITY_INT)((p1->place)), (

 ((void *)0)

 ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((p2->x)), (

 ((void *)0)

 ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((p2->y)), (

 ((void *)0)

 ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(("Ipoh")), (UNITY_INT)((p2->place)), (

 ((void *)0)

 ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);



  free(p);

  free(p1);

  free(p2);

}



void test_Convex_Hull_Create_Node_Insert_To_Avl_For_Sorting(void)

{

  Point *p = pointCreate(2,3,"KL");

  Point *p1 = pointCreate(1,2,"Selangor");

  Point *p2 = pointCreate(0,0,"Ipoh");



  Node *root = 

              ((void *)0)

                  ;

  TopHalf(&root,p1);

  UnityAssertEqualNumber((UNITY_INT64)((&p1)), (UNITY_INT64)((root)), (

 ((void *)0)

 ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_HEX64);



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



  avl_Insert(&point1,point2,(Compare)CompareX);

  UnityAssertEqualNumber((UNITY_INT64)((point2)), (UNITY_INT64)((point1->left)), (

 ((void *)0)

 ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_HEX64);



  free(p);

  free(p1);

  free(p2);

}
