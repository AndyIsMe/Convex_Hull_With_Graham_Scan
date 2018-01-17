#include "orientation.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

Point p0;

int distp(Point p ,Point q)
{
  return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}
//return 0 ---> collinear
//return 1 ---> clockwise
//return 2 ---> anticlockwise
int orientation(Point p,Point q,Point r)
{
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if(val > 0)
    return 1;
  else if(val < 0)
    return 2;
  else
    return 0;
}

int PolarAngle(Point p , Point p0)
{
    return atan2(p.y - p0.y,p.x - p0.x);
}

int swap(Point p , Point p2)
{
  Point temp = p;
  p = p2;
  p2 = temp;
}

// int compare(const void *vp,const void *vp1)
// {
//   Point *p1 = (Point *)vp;
//   Point *p2 = (Point *)vp1;
//   printf("p1%s\n",p1->place );
//   printf("p2%s\n",p2->place );
//   int o = orientation(p0 , *p1 , *p2);
//   if(o == 0)
//   {
//     if(distp(p0,*p2)<=distp(p0,*p1))
//       return 1;
//     else
//       return -1;
//   }
//   if(o == 2)
//     return -1;
//   else
//     return  1;
// }

Point *pointCreate(int x,int y, char* place)
{
  Point *newPoint = (Point *)malloc(sizeof(Point));
  newPoint->x = x;
  newPoint->y = y;
  newPoint->place = place;

  return newPoint;
}

LinkedList *TopHalf(Node **root)
{
  int i ;
  Node *smallestX,*nextSmallest;
  LinkedList *list;
  //Find the starting point and place it into a linkedlist
  smallestX = SearchMinX(root);
  Point *min = (smallestX->data);
  Item *Initial = (Item *)malloc(sizeof(Item));
  createItem(Initial,min,NULL);
  ListInit(&list);
  StackPush(&list,Initial);
  int *PointToRemove = (int*)(uintptr_t)smallestX->data->x;
  avlremovePoint(root,PointToRemove);
  //Making sure 3 points are extracted
  //With point(smallest X) push to linkedlist
  //while other 2 points are extract out to do comparison
  //To make Convex Hull possible
  for(i = 0 ; i<2 ; i++)
  {
    nextSmallest = SearchMinX(root);
    Point *nextMin = nextSmallest->data;
    //PointToRemove = ((Point*)(smallestX->data));
    //avlremovePoint(root,PointToRemove);
  }
  return list;

  // while(root != NULL)
  //  {
  //    smallestX = SearchMinX(root);
  //    Point min = smallestX->data;
  //    AddPointToList(data,smallestX);
  //    Item *Initial = (Item *)malloc(sizeof(Item));
  //    createItem(Initial, (void*)&min,NULL);
  //    ListInit(&list);
  //    StackPush(&list, Initial);
  //    int *PointToRemove = (int*)((uintptr_t)(smallestX->data->x));
  //    avlremovePoint(root,PointToRemove);
  //  }
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
      if(current->right != NULL)
        return current->right;
      else
        return current;
    }
  }
  else
    temp = *rootPtr;
    return temp;
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

int avlSortBottomHalf(Node **root , Point *point)
{
  Node *largestX;
}

void createNodeForPoints(Node *node,Point *data){
    node->left = NULL;
    node->right = NULL;
    node->balanceFactor =0;
    node->data = data;
}


// Point *convexHull(Point points[] , int n , int choice)
// {
//   int x , y;
//   int i;
//   int l = 0;
//   Point *result = (Point*)malloc(sizeof(Point) * 1001);
//   //Search for the bottom most point
//   for(i = 1 ; i < n ; i++)
//   {
//     if(points[l].x>points[i].x)
//       l = i;
//     else if((points[l].x==points[i].x)&&(points[l].y>points[i].y))
//       l = i;
//   }
//   //Place the bottom most point to array 0
//   //points[0] = points[l];
//   // points[8].x = NULL;
//   // points[8].y = NULL;
//   // points[8].place = NULL;
//   int p = l;
//   int count = 0;
//   //l = 0;
//   // points[l].x = NULL;
//   // points[l].y = NULL;
//   // points[l].place = NULL;
//   int j;
//   int min = 1;
//
//   int next;
//   if(n<3)
//   {
//     for(i=0;i<n-1;i++)
//     {
//       result[count] = points[i];
//     }
//     printf("n is %d , which is smaller than 3\n",n);
//     printf("Therefore , Convex hull not possible\n");
//   }
//   else
//   {
//     do{
//       result[count] = points[p];
//       count++;
//       i = 0;
//       for(i=0;i<n-1;i++)
//       {
//         next = i+1;
//         if(points[i].x>points[next].x)
//         next = i;
//         else if(points[i].x==points[next].x && points[i].y>points[next].y)
//         next = i;
//       }
//       p = next;
//     }while(p!=l);
//   }
//   // for(i=1;i<n;i++)
//   // {
//   //    current = i;
//   //    next = i + 1;
//   //     if(PolarAngle(points[next],p0)<PolarAngle(points[current],p0))
//   //     {
//   //       points[min] = points[next];
//   //       points[next].x = NULL;
//   //       points[next].y = NULL;
//   //       points[next].place = NULL;
//   //       min++;
//   //     }
//   //     else if(orientation)
//   // }
//   // for(i=1;i<n;i++)
//   // {
//   //   // next = i +1;
//   // if(PolarAngle(points[next],p0)==PolarAngle(points[current],p0))
//   // {
//   //        if((points[next].x == p0.x)&&(points[next].y == p0.y)\
//   //        ||(points[current].x== p0.x)&&(points[current].x==p0.x))
//   //         {
//   //           //     skip cause comparing same coordinates
//   //         }
//   //        if(distp(p0,points[next])<distp(p0,points[current]))
//   //          points[min] = points[next];
//   //          min++;
//   // }
//   // else
//   // {
//   //   points[min] = points[next];
//   //   min++;
//   // }
// printf("Points %s\n",result[0].place);
// printf("Points %s\n",result[1].place);
// printf("Points %s\n",result[2].place);
// printf("Points %s\n",result[3].place);
// printf("Points %s\n",result[4].place);
// printf("Points %s\n",result[5].place);
// printf("Points %s\n",result[6].place);
//
//
//   //qsort(&points[1],n-1,sizeof(Point),compare);
//   // printf("1 %s\n",points[0].place );
//   // printf("2 %s\n",points[1].place );
//   // printf("3 %s\n",points[2].place );
//   // printf("4 %s\n",points[3].place );
//   // printf("5 %s\n",points[4].place );
//   //  printf("6 %s\n",points[5].place );
//   //  printf("7 %s\n",points[6].place );
//   //  printf("8 %s\n",points[7].place );
//   // printf("7 %s\n",points[6].place );
//
//   //Begin at the bottom most point
//  //Keep joining points in anticlockwise/clockwise direction
// //until starting point
// //This loop runs n times
// //n = number of points user placed into it
//   //int p = l;
//   //int q;
//   count = 1;
//   if(n<3)
//   {
//     for(i=0;i<n-1;i++)
//     {
//       result[count] = points[i];
//     }
//     printf("n is %d , which is smaller than 3\n",n);
//     printf("Therefore , there will shape formed\n");
//
//   }
//   else
//   {
//     for(i = 1 ; i<n ; i++)
//     {
//       while(i<n-1 && (orientation(p0,points[i],points[i+1])==0))
//         i++;
//       result[count] = points[i];
//       count++;
//     }
//
//     LinkedList list;
//     Item *FirstItem = (Item *)malloc(sizeof(Item));
//     Item *SecondItem = (Item *)malloc(sizeof(Item));
//     Item *ThirdItem = (Item *)malloc(sizeof(Item));
//     createItem(FirstItem, (void*)&points[0],NULL);
//     createItem(SecondItem, (void*)&points[1],NULL);
//     createItem(ThirdItem, (void*)&points[2],NULL);
//     ListInit(&list);
//     listAdd(&list, FirstItem);
//     listAdd(&list, SecondItem);
//     listAdd(&list, ThirdItem);
//     Point a,b;
//     a = *((Point*)(list.head->next->data));
//     b = *((Point*)(list.tail->data));
//     printf("place 1 %s\n",((Point*)(list.head->data))->place);
//     printf("place 2 %s\n",((Point*)(list.head->next->data))->place);
//     printf("place 3 %s\n",((Point*)(list.head->next->next->data))->place);
//   if(choice == anticlockwise)
//   {
//    for(int i = 3;i<count ; i++)
//     {
//
//         if(orientation(a,b,points[i]) != 1)
//         ListRemove(&(list.tail));
//         *((Point*)(list.tail->data)) = points[i];
//     }
//   }
//   // else if(choice == clockwise)
//   // {
//   //   for(int i = 3 ; i<count ; i++)
//   //   {
//   //       if(orientation(a,b,points[i]) == 1)
//   //       ListRemove(&(list.tail));
//   //       printf("abc 1 %s\n",((Point*)(list.tail->data))->place);
//   //       *((Point*)(list.tail->data)) = points[i];
//   //       printf("z %s\n",points[i].place );
//   //   }
//   // }
//   //  if((Point*)(list.head->data) != NULL)
//   //  {
//   //    //int z = 0;
//   //    Point p = *((Point*)(list.tail->data));
//   //    printf("%s\n",p.place);
//   //    ListRemove(&(list.tail));
//   //
//   //    //z++;
//   //  }
//    //return (result);
//  }
//     // Search for a point q where a validation in function
//     //p = current point
//     //q = next targer point
//     // orientation(p, x, q) is done and to be make sure that
//     // it is counterclockwise for all points 'x'.
//     // The idea is to keep track of last visited outermost point
//     // during anticlockwise in q
//     // If any point 'i' is the outermost point,
//     // then update q.
//     /*q = (p+1)%n;
//     for(i = 0;i < n;i++)
//       {
//         if(choice == 1){
//           if(orientation(points[p],points[i],points[q])==1)
//           q = i;
//         }
//         else if(choice == 0){
//           if(orientation(points[p],points[i],points[q])==2)
//           q = i;
//         }
//       }
//       // After valiation of point q as the outermost point in anticlockwise
//       // Let p = q as for the next joining outermost point
//       p = q;
//   } while(p != l);
//   int z = &(result[0]);
//   return z;
// }*/
// //return result;
// }

/*
void convexHull(Point points[] , int n , int choice)
{
  double x , y;
  int i;
  int l = 0;
  //int result = 0;
  Point result[100];
  int j;
  //Making sure that there must be at least 3 points
  //if(n < 3)
  //return ;

  //Search for the leftmost point
  for(i = 1 ; i < n ; i++)
  {
    if(points[l].x>points[i].x)
      l=i;
    else if((points[l].x==points[i].x)&&(points[l].y>points[i].y))
    l =i;
  }
  //Begin at the leftmost point
 //Keep joining points in anticlockwise direction
//until starting point
//This loop runs n times
//n = number of points user placed into it
  int p = l;
  int q;
  int count =0;
  if(n<3)
  {
    for(i=0;i<n-1;i++)
    {
      //points[i]
    }
  }
  else
  {
  do {
    // Store current point to the result
    printf("result %d\n",p );
    printf("result[x] %d\n",points[p].x);
    printf("result[y] %d\n",points[p].y);


    // Search for a point q where a validation in function
    //p = current point
    //q = next targer point
    // orientation(p, x, q) is done and to be make sure that
    // it is counterclockwise for all points 'x'.
    // The idea is to keep track of last visited outermost point
    // during anticlockwise in q
    // If any point 'i' is the outermost point,
    // then update q.
    q = (p+1)%n;
    for(i = 0;i < n;i++)
      {
        if(choice == 1){
          if(orientation(points[p],points[i],points[q])==1)
          q = i;
        }
        else if(choice == 0){
          if(orientation(points[p],points[i],points[q])==2)
          q = i;
        }
      }
      // After valiation of point q as the outermost point in anticlockwise
      // Let p = q as for the next joining outermost point
      p = q;
      //printf("point[p] x %d\n",points[p].x);
      //printf("point[p] y %d\n",points[p].y);
  } while(p != l);
}
}*/
