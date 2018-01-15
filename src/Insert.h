#ifndef _INSERT_H
#define _INSERT_H
#include "Node.h"
#include "Rotate.h"

//Node createNode(int node);
typedef int(*Compare)(void *data,Node *refdata);

//#define avlAddInteger(rootPtr,nodeToAdd) avl_Insert(rootPtr,nodeToAdd , (Compare)IntCompare)
//#define avlAddString(rootPtr,nodeToAdd) avl_Insert(rootPtr,nodeToAdd , (Compare)compareString)
int avl_Insert(Node **rootPtr, Node *nodeToAdd,Compare IntCompare);
int IntCompare(int data,Node *refNode);
#endif // _INSERT_H
