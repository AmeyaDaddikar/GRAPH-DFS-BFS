#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include "list.h"



int main()
{
	LIST list;
	QUEUE queue;
	STACK stack;
	VERTEX vertex;
	
	createList(&list);
	createQueue(&queue);
	createStack(&stack);
	createVertex(&vertex,-1);
	
	deleteList(&list);
	deleteQueue(&queue);
	deleteStack(&stack);
	
	return 0;
}