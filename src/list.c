#include "list.h"
#include <stdio.h>

void ListInit(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void listInit1(LinkedList *list,Item *item){

    list->tail = item;
    list->head = item;
    list->len = 1;

    item->next = NULL;
}


void listAdd(LinkedList *list,Item *item){
    // Implement your code here...
    if (list->head == NULL)
    {
      list->head = item;
      list->tail = item;
    }
    else
    {
	  list->tail->next = item;
      list->tail = item;
    }
    list->len+=1;
    item->next = NULL;

}

void createItem(Item *item, void *data, Item *next){
  item->data = data;
  item->next = next;
}


Item *removeFirst(LinkedList *list){

	if(list->head == NULL){
		return NULL;
	}
	else {
		list->head = list->head->next;
		list->len--;
	}
}


void ListRemoveEither1stOrLast(LinkedList *list,Item *item)
{
	Item *TempToPoint1 = NULL ;
	Item *TempToPoint2 = list->head;

	if(list->head == NULL)
	return ;

  while(TempToPoint2 != NULL)
  {
    if(TempToPoint2->data == item->data)
    {
      list->tail = TempToPoint1;
      TempToPoint1->next = NULL;
      list->len--;
    }
    TempToPoint1 = TempToPoint2;
    TempToPoint2 = TempToPoint2->next;
  }

}
