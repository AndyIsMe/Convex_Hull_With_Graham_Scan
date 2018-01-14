#include "orientation.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

Point p0;

int distp(Point p ,Point q)
{
  return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
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

int compare(const void *vp,const void *vp1)
{
  Point *p1 = (Point *)vp;
  Point *p2 = (Point *)vp1;
  printf("p1%s\n",p1->place );
  printf("p2%s\n",p2->place );
  int o = orientation(p0 , *p1 , *p2);
  if(o == 0)
  {
    if(distp(p0,*p2)<=distp(p0,*p1))
      return 1;
    else
      return -1;
  }
  if(o == 2)
    return -1;
  else
    return  1;
}

// Point nextToTop(LinkedList *list)
// {
//     Point p = *((Point *)(list->tail->data));
//     ListRemove(&(list->tail));
//     Point res = *((Point*)(list->head->next->data));
//     *((Point*)(list->tail->data)) = p;
//     return res;
// }

Point *convexHull(Point points[] , int n , int choice)
{
  int x , y;
  int i;
  int l = 0;
  Point *result = (Point*)malloc(sizeof(Point) * 1001);
  Point temp[100];
  //Search for the bottom most point
  for(i = 1 ; i < n ; i++)
  {
    if(points[l].y>points[i].y)
      l = i;
    else if((points[l].y==points[i].y)&&(points[l].x>points[i].x))
    l = i;
  }
  //Place the bottom most point to array 0
  //points[0] = points[l];
  // points[8].x = NULL;
  // points[8].y = NULL;
  // points[8].place = NULL;
  p0 = points[l];
  //l = 0;
  points[l].x = NULL;
  points[l].y = NULL;
  points[l].place = NULL;
  int j;
  int min;
  for(i = 1 ; i<n ; i++)
    {
      min = i;
    for (j = i+1; j < n-1; j++){
      if (PolarAngle(points[j],p0)<PolarAngle(points[min],p0))
        {
        //min = i+1;
        //printf("min %d\n",min );
        //int j = i+1;
        points[j-min] = points[j];
        points[j].x = NULL;
        points[j].y = NULL;
        points[j].place = NULL;
        temp[i+1] = points[min];
        points[i+1].x = NULL;
        points[i+1].y = NULL;
        points[i+1].place = NULL;
        printf("point %s\n",points[j-i].place);
        printf("point remaining %s\n",temp[i+1].place);
        printf("min %d\n",min );
        }
      }
        if(PolarAngle(points[i+1],p0)==PolarAngle(points[min],p0))
        {
          temp[i] = points[min];
          printf("remaining last %s\n",temp[i].place);
          printf("int %d\n",i );

        }
  }
  // for(i = 1 ; i<n ; i++)
  //   {
  // min = i;
  // // for (j = i+1; j < n-1; j++)
  //   if(PolarAngle(points[i+1],p0)==PolarAngle(points[min],p0))
  //   {
  //     if((points[i+1].x == p0.x)&&(points[i+1].y == p0.y)\
  //     ||(points[i].x==p0.x)&&(points[i].x==p0.x))
  //     {
  //       //skip cause comparing same coordinates
  //     }
  //     else{
  //       if(distp(p0,points[i+1])>distp(p0,points[min]))
  //       {
  //         printf("min %d\n",min);
  //         printf("i %d\n",i);
  //         //printf("%d\n",min);
  //         temp[i] = points[min];
  //         points[min].x = NULL;
  //         points[min].y = NULL;
  //         points[min].place = NULL;
  //         printf("result %s\n",temp[i].place);
  //       }
  //       else
  //       {
  //         temp[i] = points[min];
  //         printf("remaining %s\n",temp[i].place);
  //       }
  //         }
  //       }
  //     }
    // for(i=0 ; i<n ; i++)
    // {
    //   if((
    //   temp[i+10] = points[i];
    //   printf("temp %s\n",temp[i+10].place );
    // }
  //qsort(&points[1],n-1,sizeof(Point),compare);
  // printf("1 %s\n",points[0].place );
  // printf("2 %s\n",points[1].place );
  // printf("3 %s\n",points[2].place );
  // printf("4 %s\n",points[3].place );
  // printf("5 %s\n",points[4].place );
  //  printf("6 %s\n",points[5].place );
  //  printf("7 %s\n",points[6].place );
  //  printf("8 %s\n",points[7].place );
  // printf("7 %s\n",points[6].place );

  //Begin at the bottom most point
 //Keep joining points in anticlockwise/clockwise direction
//until starting point
//This loop runs n times
//n = number of points user placed into it
  //int p = l;
  //int q;
  int count = 1;
  if(n<3)
  {
    for(i=0;i<n-1;i++)
    {
      result[count] = points[i];
    }
    printf("n is %d , which is smaller than 3\n",n);
    printf("Therefore , there will shape formed\n");

  }
  else
  {
    for(i = 1 ; i<n ; i++)
    {
      while(i<n-1 && (orientation(p0,points[i],points[i+1])==0))
        i++;
      result[count] = points[i];
      count++;
    }

    LinkedList list;
    Item *FirstItem = (Item *)malloc(sizeof(Item));
    Item *SecondItem = (Item *)malloc(sizeof(Item));
    Item *ThirdItem = (Item *)malloc(sizeof(Item));
    createItem(FirstItem, (void*)&points[0],NULL);
    createItem(SecondItem, (void*)&points[1],NULL);
    createItem(ThirdItem, (void*)&points[2],NULL);
    ListInit(&list);
    listAdd(&list, FirstItem);
    listAdd(&list, SecondItem);
    listAdd(&list, ThirdItem);
    Point a,b;
    a = *((Point*)(list.head->next->data));
    b = *((Point*)(list.tail->data));
    printf("place 1 %s\n",((Point*)(list.head->data))->place);
    printf("place 2 %s\n",((Point*)(list.head->next->data))->place);
    printf("place 3 %s\n",((Point*)(list.head->next->next->data))->place);
  if(choice == anticlockwise)
  {
   for(int i = 3;i<count ; i++)
    {

        if(orientation(a,b,points[i]) != 1)
        ListRemove(&(list.tail));
        *((Point*)(list.tail->data)) = points[i];
    }
  }
  else if(choice == clockwise)
  {
    for(int i = 3 ; i<count ; i++)
    {
        if(orientation(a,b,points[i]) == 1)
        ListRemove(&(list.tail));
        printf("abc 1 %s\n",((Point*)(list.tail->data))->place);
        *((Point*)(list.tail->data)) = points[i];
        printf("z %s\n",points[i].place );
    }
  }
   if((Point*)(list.head->data) != NULL)
   {
     //int z = 0;
     Point p = *((Point*)(list.tail->data));
     printf("%s\n",p.place);
     ListRemove(&(list.tail));

     //z++;
   }
   //return (result);
 }
    // Search for a point q where a validation in function
    //p = current point
    //q = next targer point
    // orientation(p, x, q) is done and to be make sure that
    // it is counterclockwise for all points 'x'.
    // The idea is to keep track of last visited outermost point
    // during anticlockwise in q
    // If any point 'i' is the outermost point,
    // then update q.
    /*q = (p+1)%n;
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
  } while(p != l);
  int z = &(result[0]);
  return z;
}*/
return result;
}

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
