/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_orientation_expect_anticlockwise(void);
extern void test_orientation_expect_clockwise(void);
extern void test_orientation_expect_colinear(void);
extern void test_Convex_Hull_Create_Node(void);
extern void test_Convex_Hull_Insert_To_Avl_For_Sorting(void);
extern void test_Convex_Hull_Insert_A_Few_Points_To_Avl_For_Sorting(void);
extern void test_Convex_Hull_Insert_A_Few_Points_To_Avl_With_Same_X_Coordinate(void);
extern void test_Convex_Hull_Insert_A_Few_Points_To_Avl_For_Sorting_And_Remove(void);
extern void test_Convex_Hull_Insert_2_Points_To_Avl_For_Sorting_Expect_1_Point_in_LinkedList_since_Convex_Hull_Is_Not_Possible(void);
extern void test_Convex_Hull_In_Graham_Scan_Insert_6_Points_To_Avl_For_Sorting_Where_2_Points_With_Same_X_Expect_Convex_Hull(void);
extern void test_Convex_Hull_In_Graham_Scan_Insert_6_Points_To_Avl_For_Sorting_Expect_Convex_Hull_(void);
extern void test_Convex_Hull_In_Graham_Scan_Insert_8_Points_To_Avl_For_Sorting_Expect_Convex_Hull_(void);
extern void test_Convex_Hull_In_Graham_Scan_Insert_10_Points_In_Worst_Case_Scenario_To_Avl_For_Sorting_Expect_Convex_Hull_(void);


/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_orientation.c");
  RUN_TEST(test_orientation_expect_anticlockwise, 22);
  RUN_TEST(test_orientation_expect_clockwise, 32);
  RUN_TEST(test_orientation_expect_colinear, 42);
  RUN_TEST(test_Convex_Hull_Create_Node, 52);
  RUN_TEST(test_Convex_Hull_Insert_To_Avl_For_Sorting, 65);
  RUN_TEST(test_Convex_Hull_Insert_A_Few_Points_To_Avl_For_Sorting, 86);
  RUN_TEST(test_Convex_Hull_Insert_A_Few_Points_To_Avl_With_Same_X_Coordinate, 112);
  RUN_TEST(test_Convex_Hull_Insert_A_Few_Points_To_Avl_For_Sorting_And_Remove, 150);
  RUN_TEST(test_Convex_Hull_Insert_2_Points_To_Avl_For_Sorting_Expect_1_Point_in_LinkedList_since_Convex_Hull_Is_Not_Possible, 178);
  RUN_TEST(test_Convex_Hull_In_Graham_Scan_Insert_6_Points_To_Avl_For_Sorting_Where_2_Points_With_Same_X_Expect_Convex_Hull, 205);
  RUN_TEST(test_Convex_Hull_In_Graham_Scan_Insert_6_Points_To_Avl_For_Sorting_Expect_Convex_Hull_, 282);
  RUN_TEST(test_Convex_Hull_In_Graham_Scan_Insert_8_Points_To_Avl_For_Sorting_Expect_Convex_Hull_, 370);
  RUN_TEST(test_Convex_Hull_In_Graham_Scan_Insert_10_Points_In_Worst_Case_Scenario_To_Avl_For_Sorting_Expect_Convex_Hull_, 501);

  return (UnityEnd());
}
