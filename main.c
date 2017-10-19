#include <stdio.h>
#include "header/queue.h"
#include "header/stack.h"
#include "header/list.h"

typedef struct vertex{
	
	int val;
	LIST adj_list;
	
} VERTEX;

void createVertex(VERTEX *vertex, int vertexVal)
{
	vertex->val = vertexVal;
	createList(&vertex->adj_list);
}

void deleteVertex(VERTEX *vertex)
{
	deleteList(&vertex->adj_list);
}

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
	deleteVertex(&vertex);
	
	return 0;
}