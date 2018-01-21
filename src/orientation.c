#include "orientation.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//return 0 ---> collinear
//return 1 ---> clockwise
//return 2 ---> anticlockwise
int orientation(Point *p,Point *q,Point *r)
{
  int val = (q->y - p->y) * (r->x - q->x) - (q->x - p->x) * (r->y - q->y);

  if(val > 0)
    return 1;
  else if(val < 0)
    return 2;
  else
    return 0;
}

void createNodeForPoints(Node *node,Point *data){
    node->left = NULL;
    node->right = NULL;
    node->balanceFactor =0;
    node->data = data;
}


Point *pointCreate(int x,int y, char* place)
{
  Point *newPoint = (Point *)malloc(sizeof(Point));
  newPoint->x = x;
  newPoint->y = y;
  newPoint->place = place;

  return newPoint;
}
// n = number of loops needed for clockwise direction points
// to be stored into the linked list
// m = number of points in the avl tree
Point *TopHalf(Node **root,int n,int m)
{
  Node *smallestX,*nextSmallest,*furtherSmallest;
  LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
  Point reverse[m];
  //Find the starting point and place it into a linkedlist
  //Also Remove the smallest node in the AVL tree
  //So that the same smallest points won't be taken during recursive in the avl tree
  if(((*root)->left == NULL)||(*root)->right == NULL)
  {
    Throw(createException("Convex Hull not possible\n",NODE_DUPLICATE_EXIST));
  }
  smallestX = SearchMinX(root);
  Point *min = (smallestX->data);
  reverse[0].x = min->x;
  reverse[0].y = min->y;
  reverse[0].place = min->place;
  int *PointToRemove = (int*)((uintptr_t)smallestX->data->x);
  avlremovePoint(root,PointToRemove);

  //Making sure 3 points are extracted
  //With point(smallest X) push to linkedlist
  //while other 2 points are extract out from AVL to do comparison
  //To make Convex Hull possible
  nextSmallest = SearchMinX(root);
  Point *nextMin = nextSmallest->data;
  reverse[1].x = nextMin->x;
  reverse[1].y = nextMin->y;
  reverse[1].place = nextMin->place;
  PointToRemove = (int*)((uintptr_t)nextSmallest->data->x);
  avlremovePoint(root,PointToRemove);
  furtherSmallest = SearchMinX(root);
  Point *furtherMin = furtherSmallest->data;
  reverse[2].x = furtherMin->x;
  reverse[2].y = furtherMin->y;
  reverse[2].place = furtherMin->place;
  PointToRemove = (int*)((uintptr_t)furtherSmallest->data->x);
  avlremovePoint(root,PointToRemove);

  Item *Initial = (Item *)malloc(sizeof(Item));
  ListInit(list);
  createItem(Initial,min,NULL);
  StackPush(list,Initial);

  Item *next = (Item *)malloc(sizeof(Item));
  Item *further = (Item *)malloc(sizeof(Item));
  m = 1;
      for(int i=1 ; i<n ; i++)
      {
         if(orientation(list->tail->data,nextMin,furtherMin)==2)
         {
           if(list->head->data==list->tail->data)
           {
             furtherSmallest = SearchMinX(root);
             PointToRemove = (int*)((uintptr_t)furtherSmallest->data->x);
             avlremovePoint(root,PointToRemove);
             furtherMin = furtherSmallest->data;
             reverse[2+m].x = furtherMin->x;
             reverse[2+m].y = furtherMin->y;
             reverse[2+m].place = furtherMin->place;
             m++;
           }
           else
           {
             nextMin = list->tail->data;
             next = (Item *)malloc(sizeof(Item));
             createItem(next,nextMin,NULL);
             StackPop(list,next);
           }
         }
         else if(orientation(list->tail->data,nextMin,furtherMin)==1)
         {
          next = (Item *)malloc(sizeof(Item));
          createItem(next,nextMin,NULL);
          StackPush(list,next);
            if(*root!=NULL)
            {
              min = nextMin;
              nextMin = furtherMin;
              furtherSmallest = SearchMinX(root);
              PointToRemove = (int*)((uintptr_t)furtherSmallest->data->x);
              avlremovePoint(root,PointToRemove);
              furtherMin = furtherSmallest->data;
              reverse[2+m].x = furtherMin->x;
              reverse[2+m].y = furtherMin->y;
              reverse[2+m].place = furtherMin->place;
              m++;
            }
            else
            {
              further = (Item*)malloc(sizeof(Item));
              createItem(further,furtherMin,NULL);
              StackPush(list,further);
            }
          }
          else
          {
            nextMin = furtherMin;
            furtherSmallest = SearchMinX(root);
            PointToRemove = (int*)((uintptr_t)furtherSmallest->data->x);
            avlremovePoint(root,PointToRemove);
            furtherMin = furtherSmallest->data;
            reverse[2+m].x = furtherMin->x;
            reverse[2+m].y = furtherMin->y;
            reverse[2+m].place = furtherMin->place;
            m++;
          }
      }
      //Result of the top half Convex Hull will be printed
      Item *TempPoint = NULL;
      Item *TempPoint1 = list->head;
      printf("Convex Hull(Top Half) coordinates :(%d,%d)[%s]\n",list->head->data->x,list->head->data->y,list->head->data->place);
      while(list->head->data != list->tail->data)
      {
        TempPoint1 = TempPoint1->next;
        list->head = TempPoint1;
        printf("Convex Hull(Top Half) coordinates :(%d,%d)[%s]\n",list->head->data->x,list->head->data->y,list->head->data->place);

      }
      printf("\n\n" );
      int z = &(reverse[0]);
      return z;
}
//  n = number of points passed in
LinkedList *BottomHalf(Point root[],int n)
{
  LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
  //Store largest x Point into a pointer structure
  //And Store it into a linked list to indicate the starting point
  //is from the back
  Point *max = (Point*)malloc(sizeof(Point));
  max->x = root[0].x;
  max->y = root[0].y;
  max->place = root[0].place;

  //2 more points with the following largest x Point are
  //put into a pointer structure
  //for further comparison between three points
  //to make Convex Hull possible
  Point *nextMax = (Point*)malloc(sizeof(Point));
  nextMax->x = root[1].x;
  nextMax->y = root[1].y;
  nextMax->place = root[1].place;

  Point *furtherMax = (Point*)malloc(sizeof(Point));
  furtherMax->x = root[2].x;
  furtherMax->y = root[2].y;
  furtherMax->place = root[2].place;

  Item *Initial = (Item *)malloc(sizeof(Item));
  ListInit(list);
  createItem(Initial,max,NULL);
  StackPush(list,Initial);

  Item *next = (Item *)malloc(sizeof(Item));
  Item *further = (Item *)malloc(sizeof(Item));
  int x;
  int y;
  char *place;
      for(int i=3 ; i<n+1 ; i++)
      {
         if(orientation(list->tail->data,nextMax,furtherMax)==2)
         {
           if(list->head->data==list->tail->data)
           {
             x = furtherMax->x;
             y = furtherMax->y;
             place = furtherMax->place;
             nextMax = (Point*)malloc(sizeof(Point));
             nextMax->x = x;
             nextMax->y = y;
             nextMax->place = place;
             furtherMax->x = root[i].x;
             furtherMax->y = root[i].y;
             furtherMax->place = root[i].place;
           }
           else
           {
             nextMax = list->tail->data;
             next = (Item *)malloc(sizeof(Item));
             createItem(next,nextMax,NULL);
             StackPop(list,next);
             i--;
           }
         }
         else if(orientation(list->tail->data,nextMax,furtherMax)==1)
         {
          next = (Item *)malloc(sizeof(Item));
          createItem(next,nextMax,NULL);
          StackPush(list,next);
            if(furtherMax->x != root[n-1].x)
            {
              x = nextMax->x;
              y = nextMax->y;
              place = nextMax->place;
              max = (Point*)malloc(sizeof(Point));
              max->x = x;
              max->y = y;
              max->place = place;
              x = furtherMax->x;
              y = furtherMax->y;
              place = furtherMax->place;
              nextMax = (Point*)malloc(sizeof(Point));
              nextMax->x = x;
              nextMax->y = y;
              nextMax->place = place;
              furtherMax->x = root[i].x;
              furtherMax->y = root[i].y;
              furtherMax->place = root[i].place;
            }
            else
            {
              further = (Item*)malloc(sizeof(Item));
              createItem(further,furtherMax,NULL);
              StackPush(list,further);
            }
          }
          else
          {
            x = furtherMax->x;
            y = furtherMax->y;
            place = furtherMax->place;
            nextMax = (Point*)malloc(sizeof(Point));
            nextMax->x = x;
            nextMax->y = y;
            nextMax->place = place;
            furtherMax->x = root[i].x;
            furtherMax->y = root[i].y;
            furtherMax->place = root[i].place;

          }
      }
  return list;
}


Node *SearchMinX(Node **rootPtr)
{
  Node *temp;
  Node *current = (*rootPtr)->left;

  if(current!=NULL)
  {
    if(current->left != NULL)
      SearchMinX(&(*rootPtr)->left);
    else
    {
        return current;
    }
  }
  else
    {
      temp = *rootPtr;
      return temp;
    }
}

int CompareX(Point *p, Node *refNode)
{

	int data1 = refNode->data->x;

  int data2 = p->x;

  if (data2 < data1)
  {
    return 1;
  }
  else if(data2 > data1)
  {
    return -1;
  }
  else
    return 0;
}

int CompareXToRemove(int x, Node *refNode)
{
	int dataX = refNode->data->x;

  if (x < dataX)
  {
    return 1;
  }
  else if(x > dataX)
  {
    return -1;
  }
  else
    return 0;
}
