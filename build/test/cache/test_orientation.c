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




ExceptionPtr ex;



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



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp3((

 NewFrame

 ), ((void *)0)) 

 == 0) { if (1)

  {

  avl_Insert(&root,point1,(Compare)CompareX);

  avl_Insert(&root,point3,(Compare)CompareX);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A))

  {

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));

    ListInit(list);

    Item *item = (Item*)malloc(sizeof(Item));

    createItem(item,point3->data,

                                ((void *)0)

                                    );

    listAdd(list,item);;

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list->head->data->x)), (

   ((void *)0)

   ), (UNITY_UINT)(139), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list->head->data->y)), (

   ((void *)0)

   ), (UNITY_UINT)(140), UNITY_DISPLAY_STYLE_INT);

  }

  testAssertEqualNode(

 ((void *)0)

 ,point1,1,point2,142);



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

  testAssertEqualNode(point3,point1,0,point2,167);

  *RemoveN(&root,point1->data->x,(Compare)CompareXToRemove);

  testAssertEqualNode(point3,

 ((void *)0)

 ,-1,point2,169);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((point1->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(170), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((point1->data->y)), (

 ((void *)0)

 ), (UNITY_UINT)(171), UNITY_DISPLAY_STYLE_INT);



  free(point1);

  free(point2);

  free(point3);

}



void test_Convex_Hull_Insert_2_Points_To_Avl_For_Sorting_Expect_1_Point_in_LinkedList_since_Convex_Hull_Is_Not_Possible(void)

{

  Point *p1 = pointCreate(2,0,"KL");

  Point *p2 = pointCreate(1,1,"Selangor");



  Node *point1 = (Node *)malloc(sizeof(Node));

  Node *point2 = (Node *)malloc(sizeof(Node));

  createNodeForPoints(point1,p1);

  createNodeForPoints(point2,p2);



  Node *root = point2;

  avl_Insert(&root,point1,(Compare)CompareX);



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp3((

 NewFrame

 ), ((void *)0)) 

 == 0) { if (1)

  {

    TopHalf(&root,2,2);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A))

  {

    dumpException(ex);

  }



  free(point1);

  free(point2);

}





void test_Convex_Hull_In_Graham_Scan_Insert_6_Points_To_Avl_For_Sorting_Where_2_Points_With_Same_X_Expect_Convex_Hull(void)

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

  avl_Insert(&root,point1,(Compare)CompareX);

  avl_Insert(&root,point2,(Compare)CompareX);

  avl_Insert(&root,point4,(Compare)CompareX);

  avl_Insert(&root,point6,(Compare)CompareX);

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp3((

 NewFrame

 ), ((void *)0)) 

 == 0) { if (1)

  {

    avl_Insert(&root,point5,(Compare)CompareX);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A))

  {

    dumpException(ex);

    Item *item = (Item*)malloc(sizeof(Item));

    createItem(item,point5->data,

                                ((void *)0)

                                    );

    LinkedList *check = (LinkedList*)malloc(sizeof(LinkedList));

    ListInit(check);

    listAdd(check,item);;

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((check->head->data->x)), (

   ((void *)0)

   ), (UNITY_UINT)(245), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check->head->data->y)), (

   ((void *)0)

   ), (UNITY_UINT)(246), UNITY_DISPLAY_STYLE_INT);

  }



  Point *reverse = TopHalf(&root,5,5);

  testAssertEqualPoint(0,1,"Ipoh",reverse,250);

  testAssertEqualPoint(1,1,"Selangor",reverse+1,251);

  testAssertEqualPoint(2,0,"KL",reverse+2,252);

  testAssertEqualPoint(3,-1,"Kelantan",reverse+3,253);

  testAssertEqualPoint(5,-2,"Johor",reverse+4,254);

  int n = 5;

  Point BackwardOrder[n];

  n--;

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

  n = 5;

  LinkedList *list = BottomHalf(BackwardOrder,n);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((list->head->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(270), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((list->head->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(271), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list->tail->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(272), UNITY_DISPLAY_STYLE_INT);



  free(point1);

  free(point2);

  free(point3);

  free(point4);

  free(point5);

  free(point6);

}



void test_Convex_Hull_In_Graham_Scan_Insert_6_Points_To_Avl_For_Sorting_Expect_Convex_Hull_(void)

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

  avl_Insert(&root,point1,(Compare)CompareX);

  avl_Insert(&root,point2,(Compare)CompareX);

  avl_Insert(&root,point4,(Compare)CompareX);

  avl_Insert(&root,point5,(Compare)CompareX);

  avl_Insert(&root,point6,(Compare)CompareX);



  Point *reverse = TopHalf(&root,6,6);

  testAssertEqualPoint(0,1,"Ipoh",reverse,313);

  testAssertEqualPoint(1,1,"Selangor",reverse+1,314);

  testAssertEqualPoint(2,0,"KL",reverse+2,315);

  testAssertEqualPoint(3,-1,"Kelantan",reverse+3,316);

  testAssertEqualPoint(4,0,"Pahang",reverse+4,317);

  testAssertEqualPoint(5,-2,"Johor",reverse+5,318);



  int n = 6;

  Point BackwardOrder[n];

  n--;

  BackwardOrder[0].x = (reverse+n)->x;

  BackwardOrder[0].y = (reverse+n)->y;

  BackwardOrder[0].place = (reverse+n)->place;

  for(i=1 ; i<7 ; i++)

  {

    n--;

    BackwardOrder[i].x = (reverse+n)->x;

    BackwardOrder[i].y = (reverse+n)->y;

    BackwardOrder[i].place = (reverse+n)->place;

  }

  n = 6;

  LinkedList *list = BottomHalf(BackwardOrder,n);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((list->head->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(335), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((list->head->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(336), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list->tail->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(337), UNITY_DISPLAY_STYLE_INT);



  free(point1);

  free(point2);

  free(point3);

  free(point4);

  free(point5);

  free(point6);

}

void test_Convex_Hull_In_Graham_Scan_Insert_8_Points_To_Avl_For_Sorting_Expect_Convex_Hull_(void)

{

  int i;

  Point *p1 = pointCreate(58,170,"Japan");

  Point *p2 = pointCreate(130,170,"Malaysia");

  Point *p3 = pointCreate(141,156,"Philippines");

  Point *p4 = pointCreate(135,109,"USA");

  Point *p5 = pointCreate(42,109,"Korea");

  Point *p6 = pointCreate(67,148,"Brunei");

  Point *p7 = pointCreate(99,160,"Saudi Arabia");

  Point *p8 = pointCreate(120,120,"Thailand");



  Node *A = (Node *)malloc(sizeof(Node));

  Node *B = (Node *)malloc(sizeof(Node));

  Node *C = (Node *)malloc(sizeof(Node));

  Node *D = (Node *)malloc(sizeof(Node));

  Node *E = (Node *)malloc(sizeof(Node));

  Node *F = (Node *)malloc(sizeof(Node));

  Node *G = (Node *)malloc(sizeof(Node));

  Node *H = (Node *)malloc(sizeof(Node));

  createNodeForPoints(A,p1);

  createNodeForPoints(B,p2);

  createNodeForPoints(C,p3);

  createNodeForPoints(D,p4);

  createNodeForPoints(E,p5);

  createNodeForPoints(F,p6);

  createNodeForPoints(G,p7);

  createNodeForPoints(H,p8);



  Node *root = F;



  avl_Insert(&root,A,(Compare)CompareX);

  avl_Insert(&root,B,(Compare)CompareX);

  avl_Insert(&root,C,(Compare)CompareX);

  avl_Insert(&root,D,(Compare)CompareX);

  avl_Insert(&root,E,(Compare)CompareX);

  avl_Insert(&root,G,(Compare)CompareX);

  avl_Insert(&root,H,(Compare)CompareX);

  Point *reverse = TopHalf(&root,11,8);

  testAssertEqualPoint(42,109,"Korea",reverse,409);

  testAssertEqualPoint(58,170,"Japan",reverse+1,410);

  testAssertEqualPoint(67,148,"Brunei",reverse+2,411);

  testAssertEqualPoint(99,160,"Saudi Arabia",reverse+3,412);

  testAssertEqualPoint(120,120,"Thailand",reverse+4,413);

  testAssertEqualPoint(130,170,"Malaysia",reverse+5,414);

  testAssertEqualPoint(135,109,"USA",reverse+6,415);

  testAssertEqualPoint(141,156,"Philippines",reverse+7,416);



  int n = 8;

  Point BackwardOrder[n];

  n--;

  BackwardOrder[0].x = (reverse+n)->x;

  BackwardOrder[0].y = (reverse+n)->y;

  BackwardOrder[0].place = (reverse+n)->place;

  for(i=1 ; i<9 ; i++)

  {

    n--;

    BackwardOrder[i].x = (reverse+n)->x;

    BackwardOrder[i].y = (reverse +n)->y;

    BackwardOrder[i].place = (reverse+n)->place;

  }

  n = 8;

  LinkedList *list = BottomHalf(BackwardOrder,n);

  if (((((Point*)(list->head->data))) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(433))));};

  UnityAssertEqualNumber((UNITY_INT)((141)), (UNITY_INT)((list->head->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(434), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((156)), (UNITY_INT)((list->head->data->y)), (

 ((void *)0)

 ), (UNITY_UINT)(435), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Philippines")), (const char*)((list->head->data->place)), (

 ((void *)0)

 ), (UNITY_UINT)(436));

  UnityAssertEqualNumber((UNITY_INT)((135)), (UNITY_INT)((list->head->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(437), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((109)), (UNITY_INT)((list->head->next->data->y)), (

 ((void *)0)

 ), (UNITY_UINT)(438), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(("USA")), (UNITY_INT)((list->head->next->data->place)), (

 ((void *)0)

 ), (UNITY_UINT)(439), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((42)), (UNITY_INT)((list->tail->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(440), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((109)), (UNITY_INT)((list->tail->data->y)), (

 ((void *)0)

 ), (UNITY_UINT)(441), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(("Korea")), (UNITY_INT)((list->tail->data->place)), (

 ((void *)0)

 ), (UNITY_UINT)(442), UNITY_DISPLAY_STYLE_INT);



  free(A);

  free(B);

  free(C);

  free(D);

  free(E);

  free(F);

  free(G);

  free(H);

}

void test_Convex_Hull_In_Graham_Scan_Insert_10_Points_In_Worst_Case_Scenario_To_Avl_For_Sorting_Expect_Convex_Hull_(void)

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



  avl_Insert(&root,A,(Compare)CompareX);

  avl_Insert(&root,B,(Compare)CompareX);

  avl_Insert(&root,C,(Compare)CompareX);

  avl_Insert(&root,D,(Compare)CompareX);

  avl_Insert(&root,E,(Compare)CompareX);

  avl_Insert(&root,G,(Compare)CompareX);

  avl_Insert(&root,H,(Compare)CompareX);

  avl_Insert(&root,I,(Compare)CompareX);

  avl_Insert(&root,J,(Compare)CompareX);

  Point *reverse = TopHalf(&root,16,10);

  testAssertEqualPoint(34,124,"KL",reverse,548);

  testAssertEqualPoint(45,147,"Selangor",reverse+1,549);

  testAssertEqualPoint(54,109,"Ipoh",reverse+2,550);

  testAssertEqualPoint(66,157,"Kelantan",reverse+3,551);

  testAssertEqualPoint(71,124,"Pahang",reverse+4,552);

  testAssertEqualPoint(82,169,"Penang",reverse+5,553);

  testAssertEqualPoint(88,124,"Kuantan",reverse+6,554);

  testAssertEqualPoint(98,184,"Kedah",reverse+7,555);

  testAssertEqualPoint(108,144,"Perak",reverse+8,556);

  testAssertEqualPoint(120,200,"Malacca",reverse+9,557);



  int n = 10;

  Point BackwardOrder[n];

  n--;

  BackwardOrder[0].x = (reverse+n)->x;

  BackwardOrder[0].y = (reverse+n)->y;

  BackwardOrder[0].place = (reverse+n)->place;

  for(i=1 ; i<11 ; i++)

  {

    n--;

    BackwardOrder[i].x = (reverse+n)->x;

    BackwardOrder[i].y = (reverse+n)->y;

    BackwardOrder[i].place = (reverse+n)->place;

  }

  n = 10;

  LinkedList *list = BottomHalf(BackwardOrder,n);

  if (((((Point*)(list->head->data))) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(574))));};

  UnityAssertEqualNumber((UNITY_INT)((120)), (UNITY_INT)((list->head->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(575), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((108)), (UNITY_INT)((list->head->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(576), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((88)), (UNITY_INT)((list->head->next->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(577), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((54)), (UNITY_INT)((list->head->next->next->next->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(578), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((34)), (UNITY_INT)((list->tail->data->x)), (

 ((void *)0)

 ), (UNITY_UINT)(579), UNITY_DISPLAY_STYLE_INT);



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
