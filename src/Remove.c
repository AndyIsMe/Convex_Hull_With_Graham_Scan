#include "Remove.h"
#include "stdio.h"
#include "stdlib.h"

Node *getReplace(Node **rootPtr,int *heightstatus)
{
Node *child;
if(*rootPtr == NULL)
{
    *heightstatus = 1;
    return NULL;
}
  if((*rootPtr)->left != NULL)
  {
      child = getReplace(&(*rootPtr)->left,heightstatus);
        if(*heightstatus == 1)
            (*rootPtr)->balanceFactor++;
        else
            (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
          if((*rootPtr)->balanceFactor >= 2)
            avlBalanceRightTreeV1(&(*rootPtr));
          else if((*rootPtr)->balanceFactor <= -2)
            avlBalanceLeftTreeV1(&(*rootPtr));
          else
            {
            *rootPtr = *rootPtr;
            }
          if((*rootPtr)->balanceFactor !=0)
          *heightstatus = 0;

        if((child)->right != NULL)
        {
          (*rootPtr)->left = child->right;
          child->right = NULL;
        }
        return child;
      }

  else
    {
      child = *rootPtr;
      *heightstatus = 1;
      *rootPtr = NULL;
      return child;
    }
}

Node *RemoveN(Node **rootPtr, void *nodeToRemove,Compare compareFunc)
{
  int heightstatus;
  Node *RemoveN = avl_Remove(rootPtr,nodeToRemove, &heightstatus,(Compare)compareFunc);
  return RemoveN;
}

Node *avl_Remove(Node **rootPtr, void *nodeToRemove, int *heightstatus,Compare compareFunc)
{
  if((*rootPtr) == NULL){
    return *rootPtr;
  }
  int compareResult = compareFunc((void*)nodeToRemove,*rootPtr);
      if(compareResult > 0)
      {
        avl_Remove(&((*rootPtr)->left),nodeToRemove,heightstatus,(Compare)compareFunc);
        if(*heightstatus == 1)
        {
          (*rootPtr)->balanceFactor++;
            if((*rootPtr)->balanceFactor != 0)
            *heightstatus = 0;
        }
        else
        (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
      }
      else if(compareResult < 0)
      {
        avl_Remove(&((*rootPtr)->right),nodeToRemove,heightstatus,(Compare)compareFunc);
        if(*heightstatus == 1)
        {
          (*rootPtr)->balanceFactor--;
            if((*rootPtr)->balanceFactor != 0)
            *heightstatus = 0;
        }
        else
        (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
      }
      else
      {
            if(((*rootPtr)->left == NULL)||((*rootPtr)->right == NULL))
            {
              Node *Remove = (*rootPtr)->left ? (*rootPtr)->left :(*rootPtr)->right;
                if(Remove == NULL)
                {
                  Remove = *rootPtr;
                  *rootPtr = NULL;
                  *heightstatus = 1;
                }
                else
                {
                  *rootPtr =  Remove;
                  *heightstatus = 1;
                }
              }
            else
            {
              Node *Replacer = getReplace(&(*rootPtr)->right,heightstatus);
              if(*heightstatus == 1)
              {
                (*rootPtr)->balanceFactor--;
                if((*rootPtr)->balanceFactor !=0)
                *heightstatus = 0;
              }
              else
              {
                (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
                *heightstatus = 1;
              }
                if(Replacer->right != NULL)
                {
                    Replacer->left = (*rootPtr)->left;
                    Replacer->balanceFactor = (*rootPtr)->balanceFactor;
                    *rootPtr = Replacer;
                }
                else
                {
                  Replacer->right = (*rootPtr)->right;
                  Replacer->left = (*rootPtr)->left;
                  Replacer->balanceFactor = (*rootPtr)->balanceFactor;
                  *rootPtr = Replacer;
                }
            }
          }
    if((*rootPtr)==NULL)
    {
      return *rootPtr;
    }
    if((*rootPtr)->balanceFactor >= 2)
    {
      avlBalanceRightTreeV1(&(*rootPtr));
      if((*rootPtr)->balanceFactor !=0)
      *heightstatus = 0;
      else
      *heightstatus = 1;
    }
    else if((*rootPtr)->balanceFactor <= -2)
    {
      avlBalanceLeftTreeV1(&(*rootPtr));
      if((*rootPtr)->balanceFactor !=0)
      *heightstatus = 0;
      else
      *heightstatus = 1;
    }
    else
    {
      *rootPtr = *rootPtr;
    }
    return *rootPtr;
}
