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

 ,-1,point1,79);



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

  testAssertEqualNode(point3,point1,0,point2,103);



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

  testAssertEqualNode(point3,point1,0,point2,128);

  *RemoveN(&root,point1->data->x,(Compare)CompareXToRemove);

  testAssertEqualNode(point3,

 ((void *)0)

 ,-1,point2,130);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((point1->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((point1->data->y)), (

 ((void *)0)

 ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);



  free(point1);

  free(point2);

  free(point3);

}



void test_Convex_Hull_Insert_6_Points_To_Avl_For_Sorting_Expect_Convex_Hull_In_LinkedList_For_TopHalf(void)

{

  Point *p1 = pointCreate(2,0,"KL");

  Point *p2 = pointCreate(1,1,"Selangor");

  Point *p3 = pointCreate(0,1,"Ipoh");

  Point *p4 = pointCreate(3,-1,"Kelantan");

  Point *p5 = pointCreate(4,0,"Pahang");

  Point *p6 = pointCreate(5,-2,"Johor");



  Node *point1 = (Node *)malloc(sizeof(Node));

  Node *point2 = (Node *)malloc(sizeof(Node));

  Node *point3 = (Node *)malloc(sizeof(Node));

  Node *point4 = (Node *)malloc(sizeof(Node));

  Node *point5 = (Node *)malloc(sizeof(Node));

  Node *point6 = (Node *)malloc(sizeof(Node));

  createNodeForPoints(point1,p1);

  createNodeForPoints(point2,p2);

  createNodeForPoints(point3,p3);

  createNodeForPoints(point4,p4);

  createNodeForPoints(point5,p5);

  createNodeForPoints(point6,p6);



  Node *root = point3;



  avl_Insert(&root,point1,(Compare)CompareX);

  avl_Insert(&root,point2,(Compare)CompareX);

  avl_Insert(&root,point4,(Compare)CompareX);

  avl_Insert(&root,point5,(Compare)CompareX);

  avl_Insert(&root,point6,(Compare)CompareX);

  Node *tempRoot = root;

  LinkedList *list = TopHalf(&root,6);

  if (((((Point*)(list->head->data))) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(170))));};

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list->head->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(171), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list->head->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(172), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((list->head->next->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(173), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((list->tail->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(174), UNITY_DISPLAY_STYLE_INT);

  LinkedList *listBottom = BottomHalf(&tempRoot,6);

  if (((((Point*)(listBottom->head->data))) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(176))));};

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((listBottom->head->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(177), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((listBottom->head->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(178), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((listBottom->tail->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(179), UNITY_DISPLAY_STYLE_INT);



  free(point1);

  free(point2);

  free(point3);

  free(point4);

  free(point5);

  free(point6);

}



void xtest_Convex_Hull_Inser_10_Points_To_Avl_For_Sorting_Expect_Convex_Hull_In_Worst_Case_In_LinkedList_For_TopHalf(void)

{

  Point *p1 = pointCreate(34,124,"KL");

  Point *p2 = pointCreate(45,147,"Selangor");

  Point *p3 = pointCreate(54,109,"Ipoh");

  Point *p4 = pointCreate(66,157,"Kelantan");

  Point *p5 = pointCreate(71,124,"Pahang");

  Point *p6 = pointCreate(82,169,"Penang");

  Point *p7 = pointCreate(88,124,"Kuantan");

  Point *p8 = pointCreate(98,184,"Kedah");

  Point *p9 = pointCreate(108,144,"Perak");

  Point *p10 = pointCreate(120,200,"Malacca");



  Node *A = (Node *)malloc(sizeof(Node));

  Node *B = (Node *)malloc(sizeof(Node));

  Node *C = (Node *)malloc(sizeof(Node));

  Node *D = (Node *)malloc(sizeof(Node));

  Node *E = (Node *)malloc(sizeof(Node));

  Node *F = (Node *)malloc(sizeof(Node));

  Node *G = (Node *)malloc(sizeof(Node));

  Node *H = (Node *)malloc(sizeof(Node));

  Node *I = (Node *)malloc(sizeof(Node));

  Node *J = (Node *)malloc(sizeof(Node));

  createNodeForPoints(A,p1);

  createNodeForPoints(B,p2);

  createNodeForPoints(C,p3);

  createNodeForPoints(D,p4);

  createNodeForPoints(E,p5);

  createNodeForPoints(F,p6);

  createNodeForPoints(G,p7);

  createNodeForPoints(H,p8);

  createNodeForPoints(I,p9);

  createNodeForPoints(J,p10);



  Node *root = F;



  avl_Insert(&root,A,(Compare)CompareX);

  avl_Insert(&root,B,(Compare)CompareX);

  avl_Insert(&root,C,(Compare)CompareX);

  avl_Insert(&root,D,(Compare)CompareX);

  avl_Insert(&root,E,(Compare)CompareX);

  avl_Insert(&root,G,(Compare)CompareX);

  avl_Insert(&root,H,(Compare)CompareX);

  avl_Insert(&root,I,(Compare)CompareX);

  avl_Insert(&root,J,(Compare)CompareX);

  LinkedList *listTop = TopHalf(&root,16);

  if (((((Point*)(listTop->head->data))) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(235))));};

  UnityAssertEqualNumber((UNITY_INT)((34)), (UNITY_INT)((listTop->head->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(236), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((45)), (UNITY_INT)((listTop->head->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(237), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((120)), (UNITY_INT)((listTop->tail->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(238), UNITY_DISPLAY_STYLE_INT);



  free(A);

  free(B);

  free(C);

  free(D);

  free(E);

  free(F);

  free(G);

  free(H);

  free(I);

  free(J);

}



void xtest_Convex_Hull_Insert_6_Points_To_Avl_For_Sorting_Expect_Convex_Hull_In_LinkedList_For_BottomHalf(void)

{

  Point *p1 = pointCreate(2,0,"KL");

  Point *p2 = pointCreate(1,1,"Selangor");

  Point *p3 = pointCreate(0,1,"Ipoh");

  Point *p4 = pointCreate(3,-1,"Kelantan");

  Point *p5 = pointCreate(4,0,"Pahang");

  Point *p6 = pointCreate(5,-2,"Johor");



  Node *point1 = (Node *)malloc(sizeof(Node));

  Node *point2 = (Node *)malloc(sizeof(Node));

  Node *point3 = (Node *)malloc(sizeof(Node));

  Node *point4 = (Node *)malloc(sizeof(Node));

  Node *point5 = (Node *)malloc(sizeof(Node));

  Node *point6 = (Node *)malloc(sizeof(Node));

  createNodeForPoints(point1,p1);

  createNodeForPoints(point2,p2);

  createNodeForPoints(point3,p3);

  createNodeForPoints(point4,p4);

  createNodeForPoints(point5,p5);

  createNodeForPoints(point6,p6);



  Node *root = point3;



  avl_Insert(&root,point1,(Compare)CompareX);

  avl_Insert(&root,point2,(Compare)CompareX);

  avl_Insert(&root,point4,(Compare)CompareX);

  avl_Insert(&root,point5,(Compare)CompareX);

  avl_Insert(&root,point6,(Compare)CompareX);

  LinkedList *list = BottomHalf(&root,6);

  if (((((Point*)(list->head->data))) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(282))));};

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((list->head->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(283), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((list->head->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(284), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list->tail->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(285), UNITY_DISPLAY_STYLE_INT);



  free(point1);

  free(point2);

  free(point3);

  free(point4);

  free(point5);

  free(point6);

}



void xtest_Convex_Hull_Inser_10_Points_To_Avl_For_Sorting_Expect_Convex_Hull_In_Worst_Case_In_LinkedList_For_BottomHalf(void)

{

  Point *p1 = pointCreate(34,124,"KL");

  Point *p2 = pointCreate(45,147,"Selangor");

  Point *p3 = pointCreate(54,109,"Ipoh");

  Point *p4 = pointCreate(66,157,"Kelantan");

  Point *p5 = pointCreate(71,124,"Pahang");

  Point *p6 = pointCreate(82,169,"Penang");

  Point *p7 = pointCreate(88,124,"Kuantan");

  Point *p8 = pointCreate(98,184,"Kedah");

  Point *p9 = pointCreate(108,144,"Perak");

  Point *p10 = pointCreate(120,200,"Malacca");



  Node *A = (Node *)malloc(sizeof(Node));

  Node *B = (Node *)malloc(sizeof(Node));

  Node *C = (Node *)malloc(sizeof(Node));

  Node *D = (Node *)malloc(sizeof(Node));

  Node *E = (Node *)malloc(sizeof(Node));

  Node *F = (Node *)malloc(sizeof(Node));

  Node *G = (Node *)malloc(sizeof(Node));

  Node *H = (Node *)malloc(sizeof(Node));

  Node *I = (Node *)malloc(sizeof(Node));

  Node *J = (Node *)malloc(sizeof(Node));

  createNodeForPoints(A,p1);

  createNodeForPoints(B,p2);

  createNodeForPoints(C,p3);

  createNodeForPoints(D,p4);

  createNodeForPoints(E,p5);

  createNodeForPoints(F,p6);

  createNodeForPoints(G,p7);

  createNodeForPoints(H,p8);

  createNodeForPoints(I,p9);

  createNodeForPoints(J,p10);



  Node *root = F;



  avl_Insert(&root,A,(Compare)CompareX);

  avl_Insert(&root,B,(Compare)CompareX);

  avl_Insert(&root,C,(Compare)CompareX);

  avl_Insert(&root,D,(Compare)CompareX);

  avl_Insert(&root,E,(Compare)CompareX);

  avl_Insert(&root,G,(Compare)CompareX);

  avl_Insert(&root,H,(Compare)CompareX);

  avl_Insert(&root,I,(Compare)CompareX);

  avl_Insert(&root,J,(Compare)CompareX);

  LinkedList *list = BottomHalf(&root,14);

  if (((((Point*)(list->head->data))) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(341))));};

  UnityAssertEqualNumber((UNITY_INT)((120)), (UNITY_INT)((list->head->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(342), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((108)), (UNITY_INT)((list->head->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(343), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((88)), (UNITY_INT)((list->head->next->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(344), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((54)), (UNITY_INT)((list->head->next->next->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(345), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((34)), (UNITY_INT)((list->tail->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(346), UNITY_DISPLAY_STYLE_INT);

  free(A);

  free(B);

  free(C);

  free(D);

  free(E);

  free(F);

  free(G);

  free(H);

  free(I);

  free(J);

}
