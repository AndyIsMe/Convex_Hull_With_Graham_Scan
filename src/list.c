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
		   removeFirst(list);
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
    /*
    if(Now==NULL){
      list=list;
    }
		if(Now==list->tail){			//If my 'Now' is equal to my last one
			list->tail = Initial;		//I'm able to proceed on deleting the last data
			Initial->next = NULL;
			list->len--;
		}
		else if(Now == list->head){
      if(list->head == list->tail)	//If my "Initial' is equal to NULL from the beginning
			ListInit(list);
    else{
        Now = Now->next;
				list->head = Now;
				list->len--;
    }
  }//It fulfills the criteria of the remove 1st data from the function above
      else
      {
        if(Now == NULL){
          Now = NULL;
        }
        else{
  		  Initial->next = Now->next;
  		  list->len--;
      }
  	   }							//Thus,I'm able to proceed on deleting the middle data
}
*/
