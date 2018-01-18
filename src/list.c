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

Item *removeLast(LinkedList *list){
  if(list->head == NULL)
  {
    return NULL;
  }
  else
  {
    if(list->head->next != NULL)
    {
      list->head = list->head->next;
    }
    list->head->next = NULL;
  }
}

void ListRemove(LinkedList *list){
	Item *Initial = NULL;
	Item *Now = list->head;


   if(Now==NULL)
   {
	   //no data matched until last node
	   Now=NULL;
   }
   else
   {
	   if(Initial==NULL)
	   {
		   //the data is the head
		   removeLast(list);
	   }
	   else if(Now==list->tail)
	   {
		   //the item is tail
		   list->tail=Initial;
		   list->tail->next=NULL;
		   list->len--;
	   }

	   else
	   {
		   //the item is in between 2 node
		   Initial->next=Now->next;
		   list->len--;
	   }
   }
}
void ListRemoveEither1stOrLast(LinkedList *list,Item *item)
{
	Item *TempToPoint1 = NULL ;
	Item *TempToPoint2 = list->tail->data;

	if(list->head == NULL)
	return NULL;

	else
	{
    if(TempToPoint2 == item->data)
    {
      list->tail = TempToPoint1;
      list->len--;
    }

	}
}
