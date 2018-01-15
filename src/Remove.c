#include "Remove.h"
#include "stdio.h"
#include "stdlib.h"

Node *getReplace(Node **rootPtr,int *heightstatus)
{
Node *temp;
Node *child = (*rootPtr)->left;
  if(child != NULL)
  {
    if(child->left != NULL)
      getReplace(&(*rootPtr)->left,heightstatus);
      else
      {
        if(child->right != NULL)
        {
          (*rootPtr)->left = child->right;
          (*rootPtr)->balanceFactor++;
          child->right = NULL;
          if((*rootPtr)->balanceFactor !=0)
          *heightstatus = 0;
          else
          *heightstatus = 1;
        }
        else
        {
          (*rootPtr)->left = NULL;
          (*rootPtr)->balanceFactor++;
          if((*rootPtr)->balanceFactor >= 2)
            avlBalanceRightTreeV1(&(*rootPtr));
          else if((*rootPtr)->balanceFactor <= -2)
            avlBalanceLeftTreeV1(&(*rootPtr));
          else{
            *rootPtr = *rootPtr;
          }
          if((*rootPtr)->balanceFactor !=0)
          *heightstatus = 0;
          else
          *heightstatus = 1;
        }
        return child;
      }
    }
  else
    {
      temp = *rootPtr;
      *heightstatus = 1;
      *rootPtr = NULL;
      return temp;
    }
}
/*
Node *RemoveN(Node **rootPtr, int nodeToRemove)
{
  int heightstatus;
  Node *RemoveN = avl_Remove(rootPtr,nodeToRemove, &heightstatus);
  return RemoveN;
}*/

Node *RemoveN(Node **rootPtr, int nodeToRemove,Compare compareFunc)
{
  int heightstatus;
  Node *RemoveN = avl_Remove(rootPtr,nodeToRemove, &heightstatus,(Compare)compareFunc);
  return RemoveN;
}

Node *avl_Remove(Node **rootPtr, int nodeToRemove, int *heightstatus,Compare compareFunc)
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
            //if((*rootPtr)->balanceFactor != 0)
            //*heightstatus = 0;
            //else
            //*heightstatus = 1;
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
            //if((*rootPtr)->balanceFactor != 0)
            //*heightstatus = 0;
            //else
            //*heightstatus = 1;
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
                else
                *heightstatus = 1;
              }
              else
              (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
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
      avlBalanceRightTreeV1(&(*rootPtr));
    else if((*rootPtr)->balanceFactor <= -2)
      avlBalanceLeftTreeV1(&(*rootPtr));
    else
    {
      *rootPtr = *rootPtr;
    }
    if((*rootPtr)->balanceFactor !=0)
    *heightstatus = 0;
    else
    *heightstatus = 1;
    return *rootPtr;
}
/*
Node *avl_Remove(Node **rootPtr, int nodeToRemove, int *heightstatus)
{
  if((*rootPtr) == NULL){
    return *rootPtr;
  }
      if(nodeToRemove < (*rootPtr)->data)
      {
        avl_Remove(&((*rootPtr)->left),nodeToRemove,heightstatus);
        if(*heightstatus == 1)
        {
          (*rootPtr)->balanceFactor++;
            //if((*rootPtr)->balanceFactor != 0)
            //*heightstatus = 0;
            //else
            //*heightstatus = 1;
        }
        else
        (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
      }
      else if(nodeToRemove > (*rootPtr)->data)
      {
        avl_Remove(&((*rootPtr)->right),nodeToRemove,heightstatus);
        if(*heightstatus == 1)
        {
          (*rootPtr)->balanceFactor--;
            //if((*rootPtr)->balanceFactor != 0)
            //*heightstatus = 0;
            //else
            //*heightstatus = 1;
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
                else
                *heightstatus = 1;
              }
              else
              (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;
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
      avlBalanceRightTreeV1(&(*rootPtr));
    else if((*rootPtr)->balanceFactor <= -2)
      avlBalanceLeftTreeV1(&(*rootPtr));
    else
    {
      *rootPtr = *rootPtr;
    }
    if((*rootPtr)->balanceFactor !=0)
    *heightstatus = 0;
    else
    *heightstatus = 1;
    return *rootPtr;
}*/
