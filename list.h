#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "node.h"

typedef struct list {
	NODE *head;
} LIST;

void createList(LIST *list)
{
	list->head = NULL;
}

void deleteList(LIST *list)
{
	deleteAllNodes(list->head);
}

int isListEmpty(LIST *list)
{
	if(list->head == NULL)
		return 1;
	else
		return 0;
}

NODE* getIterator(LIST *list)
{
	return list->head;
}

void _insert(LIST *list, void* val)
{
	NODE *new_node = newNode(NULL,val);
	
	if(list->head == NULL)
		list->head = new_node;
	else
	{
		NODE *curr = list->head;
		
		while(curr->next != NULL)
			curr = curr->next;
		
		curr->next = new_node;
	}
}

int _contains(LIST *list, void* key)
{
	NODE *curr = list->head;
	
	while(curr != NULL)
		if(curr->data == key)
			return 1;
		else
			curr = curr->next;
	
	return 0;
}
//THIS FUNCTION CAN POTEITIALLY MESS STUFF UP
//CREATE FUNCTION POINTER TO COMPARE TWO VOID* ARGUMENTS
void _delete(LIST *list, void* val, int (*comp)(void*,void*))
{
	NODE *del_node;
	
	if(list->head == NULL)
		return;
		
	if((*comp)(list->head->data,val)==0)
	{
		del_node   = list->head;
		list->head = list->head->next;
	}
}

#endif