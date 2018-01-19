#include "orientation.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int distp(Point p ,Point q)
{
  return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}
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


Point *pointCreate(int x,int y, char* place)
{
  Point *newPoint = (Point *)malloc(sizeof(Point));
  newPoint->x = x;
  newPoint->y = y;
  newPoint->place = place;

  return newPoint;
}

LinkedList *TopHalf(Node **root,int n)
{
  Node *smallestX,*nextSmallest,*furtherSmallest;
  LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
  //Find the starting point and place it into a linkedlist
  //Also Remove the smallest node in the AVL tree
  //So that the next smallest node will not clash
  smallestX = SearchMinX(root);
  Point *min = (smallestX->data);
  int *PointToRemove = (int*)((uintptr_t)smallestX->data->x);
  avlremovePoint(root,PointToRemove);

  //Making sure 3 points are extracted
  //With point(smallest X) push to linkedlist
  //while other 2 points are extract out from AVL to do comparison
  //To make Convex Hull possible
  nextSmallest = SearchMinX(root);
  Point *nextMin = nextSmallest->data;
  PointToRemove = (int*)((uintptr_t)nextSmallest->data->x);
  avlremovePoint(root,PointToRemove);
  furtherSmallest = SearchMinX(root);
  Point *furtherMin = furtherSmallest->data;
  PointToRemove = (int*)((uintptr_t)furtherSmallest->data->x);
  avlremovePoint(root,PointToRemove);

  Item *Initial = (Item *)malloc(sizeof(Item));
  ListInit(list);
  createItem(Initial,min,NULL);
  StackPush(list,Initial);

  Item *next = (Item *)malloc(sizeof(Item));
  Item *further = (Item *)malloc(sizeof(Item));

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
          }
      }
  return list;
}

LinkedList *BottomHalf(Node **root,int n)
{
  Node *LargestX,*nextLargest,*furtherLargest;
  LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
  //Find the starting point and place it into a linkedlist
  //Also Remove the Largest node in the AVL tree
  //So that the next Largest node will not clash
  LargestX = SearchMaxX(root);
  Point *max = (LargestX->data);
  int *PointToRemove = (int*)((uintptr_t)LargestX->data->x);
  avlremovePoint(root,PointToRemove);

  //Making sure 3 points are extracted
  //With point(Largest X) push to linkedlist
  //while other 2 points are extract out from AVL to do comparison
  //To make Convex Hull possible
  nextLargest = SearchMaxX(root);
  Point *nextMax = nextLargest->data;
  PointToRemove = (int*)((uintptr_t)nextLargest->data->x);
  avlremovePoint(root,PointToRemove);
  furtherLargest = SearchMaxX(root);
  Point *furtherMax = furtherLargest->data;
  PointToRemove = (int*)((uintptr_t)furtherLargest->data->x);
  avlremovePoint(root,PointToRemove);

  Item *Initial = (Item *)malloc(sizeof(Item));
  ListInit(list);
  createItem(Initial,max,NULL);
  StackPush(list,Initial);

  Item *next = (Item *)malloc(sizeof(Item));
  Item *further = (Item *)malloc(sizeof(Item));

      for(int i=1 ; i<n ; i++)
      {
         if(orientation(list->tail->data,nextMax,furtherMax)==2)
         {
           if(list->head->data==list->tail->data)
           {
             nextMax = furtherMax;
             furtherLargest = SearchMaxX(root);
             PointToRemove = (int*)((uintptr_t)furtherLargest->data->x);
             avlremovePoint(root,PointToRemove);
             furtherMax = furtherLargest->data;
           }
           else
           {
             nextMax = list->tail->data;
             next = (Item *)malloc(sizeof(Item));
             createItem(next,nextMax,NULL);
             StackPop(list,next);
           }
         }
         else if(orientation(list->tail->data,nextMax,furtherMax)==1)
         {
          next = (Item *)malloc(sizeof(Item));
          createItem(next,nextMax,NULL);
          StackPush(list,next);
            if(*root!=NULL)
            {
              max = nextMax;
              nextMax = furtherMax;
              furtherLargest = SearchMaxX(root);
              PointToRemove = (int*)((uintptr_t)furtherLargest->data->x);
              avlremovePoint(root,PointToRemove);
              furtherMax = furtherLargest->data;
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
            nextMax = furtherMax;
            furtherLargest = SearchMaxX(root);
            PointToRemove = (int*)((uintptr_t)furtherLargest->data->x);
            avlremovePoint(root,PointToRemove);
            furtherMax = furtherLargest->data;

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

Node *SearchMaxX(Node **rootPtr)
{
  Node *temp;
  Node *current = (*rootPtr)->right;

  if(current!=NULL)
  {
    if(current->right != NULL)
      SearchMaxX(&(*rootPtr)->right);
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


void createNodeForPoints(Node *node,Point *data){
    node->left = NULL;
    node->right = NULL;
    node->balanceFactor =0;
    node->data = data;
}
