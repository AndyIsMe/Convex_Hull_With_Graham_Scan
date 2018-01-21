#include "Insert.h"
#include "stdio.h"
#include "stdlib.h"
#include "Rotate.h"
/*
int avl_Insert(Node **rootPtr, Node *nodeToAdd){
  int heightstatus;
    if(*rootPtr == NULL){
      *rootPtr = nodeToAdd;
      (*rootPtr)->left = NULL;
      (*rootPtr)->right = NULL;
      return heightstatus = 1;
                        }
    else{
      if((*rootPtr)->data > nodeToAdd->data){
        heightstatus = avl_Insert((&(*rootPtr)->left),nodeToAdd);
        if(heightstatus == 1){
        //(*rootPtr)->left = avl_Insert((&(*rootPtr)->left),nodeToAdd);
        (*rootPtr)->balanceFactor -= 1;
          if((*rootPtr)->balanceFactor == 0)
            heightstatus = 0;
        }
        else{
          (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
        }
                                            }
      else if((*rootPtr)->data < nodeToAdd->data){
        heightstatus = avl_Insert((&(*rootPtr)->right),nodeToAdd);
        if(heightstatus == 1){
        //(*rootPtr)->right = avl_Insert((&(*rootPtr)->right),nodeToAdd);
        (*rootPtr)->balanceFactor += 1;
          if((*rootPtr)->balanceFactor == 0)
            heightstatus = 0;
        }
        else
          (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
                                                  }
        }
      if((*rootPtr)->balanceFactor >= 2)
        avlBalanceRightTreeV1(&(*rootPtr));
      else if((*rootPtr)->balanceFactor <= -2)
        avlBalanceLeftTreeV1(&(*rootPtr));
      else{
        *rootPtr = *rootPtr;
      }
      return heightstatus;
}*/

int avl_Insert(Node **rootPtr, Node *nodeToAdd,Compare compareFunc){
  int heightstatus;
    if(*rootPtr == NULL){
      *rootPtr = nodeToAdd;
      (*rootPtr)->left = NULL;
      (*rootPtr)->right = NULL;
      return heightstatus = 1;
                        }
    else{
      int compareResult = compareFunc(nodeToAdd->data,*rootPtr);
      if(compareResult > 0){
        heightstatus = avl_Insert((&(*rootPtr)->left),nodeToAdd,(Compare)compareFunc);
        if(heightstatus == 1){
        //(*rootPtr)->left = avl_Insert((&(*rootPtr)->left),nodeToAdd);
        (*rootPtr)->balanceFactor -= 1;
          if((*rootPtr)->balanceFactor == 0)
            heightstatus = 0;
        }
        else
        {
          (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
        }
                                            }
      else if(compareResult < 0){
        heightstatus = avl_Insert((&(*rootPtr)->right),nodeToAdd,(Compare)compareFunc);
        if(heightstatus == 1){
        //(*rootPtr)->right = avl_Insert((&(*rootPtr)->right),nodeToAdd);
        (*rootPtr)->balanceFactor += 1;
          if((*rootPtr)->balanceFactor == 0)
            heightstatus = 0;
        }
        else
          (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
                                                  }
      else
      {
        Throw(createException("Found nodes with the same x coordinates\n\n",NODE_DUPLICATE_EXIST));
      }
        }
      if((*rootPtr)->balanceFactor >= 2)
        avlBalanceRightTreeV1(&(*rootPtr));
      else if((*rootPtr)->balanceFactor <= -2)
        avlBalanceLeftTreeV1(&(*rootPtr));
      else{
        *rootPtr = *rootPtr;
      }
      return heightstatus;
}

// int IntCompare(int data,Node *refNode)
// {
//   if(data < refNode->data)
//   {
//   return 1;
// }
//   else if(data > refNode->data)
//   {
//   return -1;
// }
//   else
//   return 0;
// }
