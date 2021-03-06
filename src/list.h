#ifndef _LIST_H
#define _LIST_H
#include "Node.h"

typedef struct Item Item;
typedef struct LinkedList LinkedList;

struct Item {
  Item *next;
  Point *data;
};

struct LinkedList{
  Item *head;
  Item *tail;
  int len;
};

#define StackPush(list,p)  listAdd(list,p);
#define StackPop(list,item)      ListRemoveEither1stOrLast(list,item);
void ListInit(LinkedList *list);
void listAdd(LinkedList *list,Item *item);
void listInit1(LinkedList *list,Item *item);
void ListRemoveEither1stOrLast(LinkedList *list,Item *item);
void createItem(Item *item, void *data, Item *next);
#endif // _LIST_H
