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
CEXCEPTION_T ex;

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
    TEST_ASSERT_EQUAL(2,i);
}

void test_orientation_expect_clockwise(void)
{
  initN(&pointPv12,0,0);
  initN(&pointPv15,2,8);
  initN(&pointTaruc,8,2);

    int i = orientation(&pointPv12,&pointPv15,&pointTaruc);
    TEST_ASSERT_EQUAL(1,i);
}

void test_orientation_expect_colinear(void)
{
  initN(&pointPv12,0,0);
  initN(&pointPv15,0,0);
  initN(&pointTaruc,0,0);

    int i = orientation(&pointPv12,&pointPv15,&pointTaruc);
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

  free(point1);
  free(point2);
  free(point3);

}


void test_Convex_Hull_Insert_A_Few_Points_To_Avl_With_Same_X_Coordinate(void)
{
  Point *p1 = pointCreate(2,3,"KL");
  Point *p2 = pointCreate(1,2,"Selangor");
  Point *p3 = pointCreate(1,0,"Ipoh");

  Node *point1 = (Node *)malloc(sizeof(Node));
  Node *point2 = (Node *)malloc(sizeof(Node));
  Node *point3 = (Node *)malloc(sizeof(Node));
  createNodeForPoints(point1,p1);
  createNodeForPoints(point2,p2);
  createNodeForPoints(point3,p3);

  Node *root = point2;

  Try
  {
  avladdPoint(&root,point1);
  avladdPoint(&root,point3);
  }
  Catch(ex)
  {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    ListInit(list);
    Item *item = (Item*)malloc(sizeof(Item));
    createItem(item,point3->data,NULL);
    StackPush(list,item);
    TEST_ASSERT_EQUAL(1,list->head->data->x);
    TEST_ASSERT_EQUAL(0,list->head->data->y);
  }
  TEST_ASSERT_EQUAL_NODE(NULL,point1,1,point2);

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

  free(point1);
  free(point2);
  free(point3);
}

// void test_Convex_Hull_Insert_2_Points_To_Avl_For_Sorting_Expect_1_Point_in_LinkedList_since_Convex_Hull_Is_Not_Possible(void)
// {
//   Point *p1 = pointCreate(2,0,"KL");
//   Point *p2 = pointCreate(1,1,"Selangor");
//
//   Node *point1 = (Node *)malloc(sizeof(Node));
//   Node *point2 = (Node *)malloc(sizeof(Node));
//   createNodeForPoints(point1,p1);
//   createNodeForPoints(point2,p2);
//
//   Node *root = point2;
//   avladdPoint(&root,point1);
//
//   TopHalf(&root,2,2);
//
//
//   free(point1);
//   free(point2);
// }


void test_Convex_Hull_Insert_6_Points_To_Avl_For_Sorting_Where_2_Points_With_Same_X_Expect_Convex_Hull_In_LinkedList_For_TopHalf(void)
{
  int i;
  Point *p1 = pointCreate(2,0,"KL");
  Point *p2 = pointCreate(1,1,"Selangor");
  Point *p3 = pointCreate(0,1,"Ipoh");
  Point *p4 = pointCreate(3,-1,"Kelantan");
  Point *p5 = pointCreate(3,0,"Pahang");
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
  avladdPoint(&root,point1);
  avladdPoint(&root,point2);
  avladdPoint(&root,point4);
  avladdPoint(&root,point6);
  Try
  {
    avladdPoint(&root,point5);
  }
  Catch(ex)
  {
    Item *item = (Item*)malloc(sizeof(Item));
    createItem(item,point5->data,NULL);
    LinkedList *check = (LinkedList*)malloc(sizeof(LinkedList));
    ListInit(check);
    StackPush(check,item);
    TEST_ASSERT_EQUAL(3,check->head->data->x);
    TEST_ASSERT_EQUAL(0,check->head->data->y);
  }

  Point *reverse = TopHalf(&root,5,5);
  TEST_ASSERT_EQUAL_POINT(0,1,"Ipoh",reverse);
  TEST_ASSERT_EQUAL_POINT(1,1,"Selangor",reverse+1);
  TEST_ASSERT_EQUAL_POINT(2,0,"KL",reverse+2);
  TEST_ASSERT_EQUAL_POINT(3,-1,"Kelantan",reverse+3);
  TEST_ASSERT_EQUAL_POINT(5,-2,"Johor",reverse+4);
  int n = 4;
  Point BackwardOrder[n];
  BackwardOrder[0].x = (reverse+n)->x;
  BackwardOrder[0].y = (reverse+n)->y;
  BackwardOrder[0].place = (reverse+n)->place;
  for(i=1 ; i<5 ; i++)
  {
    n--;
    BackwardOrder[i].x = (reverse+n)->x;
    BackwardOrder[i].y = (reverse+n)->y;
    BackwardOrder[i].place = (reverse+n)->place;
  }
  LinkedList *list = BottomHalf(BackwardOrder,2);
  TEST_ASSERT_EQUAL(5,list->head->data->x);
  TEST_ASSERT_EQUAL(3,list->head->next->data->x);
  TEST_ASSERT_EQUAL(0,list->tail->data->x);

  free(point1);
  free(point2);
  free(point3);
  free(point4);
  free(point5);
  free(point6);
}

void test_Convex_Hull_Insert_6_Points_To_Avl_For_Sorting_Expect_Convex_Hull_In_LinkedList_For_TopHalf(void)
{
  int i;
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
  avladdPoint(&root,point1);
  avladdPoint(&root,point2);
  avladdPoint(&root,point4);
  avladdPoint(&root,point5);
  avladdPoint(&root,point6);

  Point *reverse = TopHalf(&root,6,6);
  TEST_ASSERT_EQUAL_POINT(0,1,"Ipoh",reverse);
  TEST_ASSERT_EQUAL_POINT(1,1,"Selangor",reverse+1);
  TEST_ASSERT_EQUAL_POINT(2,0,"KL",reverse+2);
  TEST_ASSERT_EQUAL_POINT(3,-1,"Kelantan",reverse+3);
  TEST_ASSERT_EQUAL_POINT(4,0,"Pahang",reverse+4);
  TEST_ASSERT_EQUAL_POINT(5,-2,"Johor",reverse+5);

  int n = 5;
  Point BackwardOrder[n];
  BackwardOrder[0].x = (reverse+n)->x;
  BackwardOrder[0].y = (reverse+n)->y;
  BackwardOrder[0].place = (reverse+n)->place;
  for(i=1 ; i<6 ; i++)
  {
    n--;
    BackwardOrder[i].x = (reverse+n)->x;
    BackwardOrder[i].y = (reverse+n)->y;
    BackwardOrder[i].place = (reverse+n)->place;
  }

  LinkedList *list = BottomHalf(BackwardOrder,6);
    TEST_ASSERT_EQUAL(5,list->head->data->x);
    TEST_ASSERT_EQUAL(3,list->head->next->data->x);
    TEST_ASSERT_EQUAL(0,list->tail->data->x);

  free(point1);
  free(point2);
  free(point3);
  free(point4);
  free(point5);
  free(point6);
}

void xtest_Convex_Hull_Inser_10_Points_To_Avl_For_Sorting_Expect_Convex_Hull_In_Worst_Case_In_LinkedList_For_TopHalf(void)
{
  int i;
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

  avladdPoint(&root,A);
  avladdPoint(&root,B);
  avladdPoint(&root,C);
  avladdPoint(&root,D);
  avladdPoint(&root,E);
  avladdPoint(&root,G);
  avladdPoint(&root,H);
  avladdPoint(&root,I);
  avladdPoint(&root,J);
  Point *reverse = TopHalf(&root,16,10);
  TEST_ASSERT_EQUAL_POINT(34,124,"KL",reverse);
  TEST_ASSERT_EQUAL_POINT(45,147,"Selangor",reverse+1);
  TEST_ASSERT_EQUAL_POINT(54,109,"Ipoh",reverse+2);
  TEST_ASSERT_EQUAL_POINT(66,157,"Kelantan",reverse+3);
  TEST_ASSERT_EQUAL_POINT(71,124,"Pahang",reverse+4);
  TEST_ASSERT_EQUAL_POINT(82,169,"Penang",reverse+5);
  TEST_ASSERT_EQUAL_POINT(88,124,"Kuantan",reverse+6);
  TEST_ASSERT_EQUAL_POINT(98,184,"Kedah",reverse+7);
  TEST_ASSERT_EQUAL_POINT(108,144,"Perak",reverse+8);
  TEST_ASSERT_EQUAL_POINT(120,200,"Malacca",reverse+9);

  int n = 9;
  Point BackwardOrder[n];
  BackwardOrder[0].x = (reverse+n)->x;
  BackwardOrder[0].y = (reverse+n)->y;
  BackwardOrder[0].place = (reverse+n)->place;
  for(i=1 ; i<10 ; i++)
  {
    n--;
    BackwardOrder[i].x = (reverse+n)->x;
    BackwardOrder[i].y = (reverse+n)->y;
    BackwardOrder[i].place = (reverse+n)->place;
  }
  LinkedList *list = BottomHalf(BackwardOrder,22);
  TEST_ASSERT_NOT_NULL((Point*)(list->head->data));
  TEST_ASSERT_EQUAL(120,list->head->data->x);
  TEST_ASSERT_EQUAL(108,list->head->next->data->x);
  TEST_ASSERT_EQUAL(88,list->head->next->next->data->x);
  TEST_ASSERT_EQUAL(54,list->head->next->next->next->data->x);
  TEST_ASSERT_EQUAL(34,list->tail->data->x);

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

// void xtest_Convex_Hull_Insert_6_Points_To_Avl_For_Sorting_Expect_Convex_Hull_In_LinkedList_For_BottomHalf(void)
// {
//   Point *p1 = pointCreate(2,0,"KL");
//   Point *p2 = pointCreate(1,1,"Selangor");
//   Point *p3 = pointCreate(0,1,"Ipoh");
//   Point *p4 = pointCreate(3,-1,"Kelantan");
//   Point *p5 = pointCreate(4,0,"Pahang");
//   Point *p6 = pointCreate(5,-2,"Johor");
//
//   Node *point1 = (Node *)malloc(sizeof(Node));
//   Node *point2 = (Node *)malloc(sizeof(Node));
//   Node *point3 = (Node *)malloc(sizeof(Node));
//   Node *point4 = (Node *)malloc(sizeof(Node));
//   Node *point5 = (Node *)malloc(sizeof(Node));
//   Node *point6 = (Node *)malloc(sizeof(Node));
//   createNodeForPoints(point1,p1);
//   createNodeForPoints(point2,p2);
//   createNodeForPoints(point3,p3);
//   createNodeForPoints(point4,p4);
//   createNodeForPoints(point5,p5);
//   createNodeForPoints(point6,p6);
//
//   Node *root = point3;
//
//   avladdPoint(&root,point1);
//   avladdPoint(&root,point2);
//   avladdPoint(&root,point4);
//   avladdPoint(&root,point5);
//   avladdPoint(&root,point6);
//   LinkedList *list = BottomHalf(&root,6);
//   TEST_ASSERT_NOT_NULL((Point*)(list->head->data));
//   TEST_ASSERT_EQUAL(5,list->head->data->x);
//   TEST_ASSERT_EQUAL(3,list->head->next->data->x);
//   TEST_ASSERT_EQUAL(0,list->tail->data->x);
//
//   free(point1);
//   free(point2);
//   free(point3);
//   free(point4);
//   free(point5);
//   free(point6);
// }

// void xtest_Convex_Hull_Inser_10_Points_To_Avl_For_Sorting_Expect_Convex_Hull_In_Worst_Case_In_LinkedList_For_BottomHalf(void)
// {
//   Point *p1 = pointCreate(34,124,"KL");
//   Point *p2 = pointCreate(45,147,"Selangor");
//   Point *p3 = pointCreate(54,109,"Ipoh");
//   Point *p4 = pointCreate(66,157,"Kelantan");
//   Point *p5 = pointCreate(71,124,"Pahang");
//   Point *p6 = pointCreate(82,169,"Penang");
//   Point *p7 = pointCreate(88,124,"Kuantan");
//   Point *p8 = pointCreate(98,184,"Kedah");
//   Point *p9 = pointCreate(108,144,"Perak");
//   Point *p10 = pointCreate(120,200,"Malacca");
//
//   Node *A = (Node *)malloc(sizeof(Node));
//   Node *B = (Node *)malloc(sizeof(Node));
//   Node *C = (Node *)malloc(sizeof(Node));
//   Node *D = (Node *)malloc(sizeof(Node));
//   Node *E = (Node *)malloc(sizeof(Node));
//   Node *F = (Node *)malloc(sizeof(Node));
//   Node *G = (Node *)malloc(sizeof(Node));
//   Node *H = (Node *)malloc(sizeof(Node));
//   Node *I = (Node *)malloc(sizeof(Node));
//   Node *J = (Node *)malloc(sizeof(Node));
//   createNodeForPoints(A,p1);
//   createNodeForPoints(B,p2);
//   createNodeForPoints(C,p3);
//   createNodeForPoints(D,p4);
//   createNodeForPoints(E,p5);
//   createNodeForPoints(F,p6);
//   createNodeForPoints(G,p7);
//   createNodeForPoints(H,p8);
//   createNodeForPoints(I,p9);
//   createNodeForPoints(J,p10);
//
//   Node *root = F;
//
//   avladdPoint(&root,A);
//   avladdPoint(&root,B);
//   avladdPoint(&root,C);
//   avladdPoint(&root,D);
//   avladdPoint(&root,E);
//   avladdPoint(&root,G);
//   avladdPoint(&root,H);
//   avladdPoint(&root,I);
//   avladdPoint(&root,J);
//   LinkedList *list = BottomHalf(&root,14);
//   TEST_ASSERT_NOT_NULL((Point*)(list->head->data));
//   TEST_ASSERT_EQUAL(120,list->head->data->x);
//   TEST_ASSERT_EQUAL(108,list->head->next->data->x);
//   TEST_ASSERT_EQUAL(88,list->head->next->next->data->x);
//   TEST_ASSERT_EQUAL(54,list->head->next->next->next->data->x);
//   TEST_ASSERT_EQUAL(34,list->tail->data->x);
//   free(A);
//   free(B);
//   free(C);
//   free(D);
//   free(E);
//   free(F);
//   free(G);
//   free(H);
//   free(I);
//   free(J);
// }
