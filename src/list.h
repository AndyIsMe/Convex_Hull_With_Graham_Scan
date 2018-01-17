#ifndef _LIST_H
#define _LIST_H

typedef struct Item Item;
typedef struct LinkedList LinkedList;

struct Item {
  Item *next;
  void *data;
};

struct LinkedList{
  Item *head;
  Item *tail;
  int len;
};

#define StackPush(list,p)  listAdd(list,p);
#define StackPop(list)      ListRemove(list);
void ListInit(LinkedList *list);
void listAdd(LinkedList *list,Item *item);
void listInit1(LinkedList *list,Item *item);
//Item *ListRemove(LinkedList *list,uint32_t key,Compare compareFunc);
void ListRemove(LinkedList *list);
//Data *ListSearch(LinkedList *list,uint32_t key, Compare compareFunc);
void createItem(Item *item, void *data, Item *next);
//void ListAddOrReplace(LinkedList *list, Item *item,uint32_t key,Compare compareFunc);
#endif // _LIST_H
