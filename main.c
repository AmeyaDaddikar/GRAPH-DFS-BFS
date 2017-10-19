#include <stdio.h>
#include "header/queue.h"
#include "header/stack.h"
#include "header/list.h"

//COMPARE FUNCTIONS TO HANDLE void* data types
int compareInt(void*,void*);
int compareVertex(void*,void*);
int compareVertexInt(void*,void*);

//VERTEX STRUCTURE USING ADJACENCY LIST
typedef struct vertex{
	
	int val;
	LIST adj_list;
	
} VERTEX;

VERTEX* createVertex(VERTEX *vertex, int vertexVal)
{
	vertex->val = vertexVal;
	createList(&vertex->adj_list);
	return vertex;
}

void deleteVertex(VERTEX *vertex)
{
	deleteList(&vertex->adj_list);
}

void createGraph(VERTEX *startVertex)
{
	int value,tot_nodes,i;
	
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

int compareInt(void* val1,void* val2)
{
	int i1 = *(int*)val1;
	int i2 = *(int*)val2;
	
	if(i1 == i2)
		return 0;
	
	if(i1 < i2)
		return -1;
	
	return 1;
}

int compareVertex(void* val1,void* val2)
{
	VERTEX *vert1 = (VERTEX*)val1;
	VERTEX *vert2 = (VERTEX*)val2;
	
	return compareInt(&vert1->val,&vert2->val);
}

int compareVertexInt(void* val1,void* val2)
{
	int vertexValue = ((VERTEX*)val1)->val;
	
	return compareInt(&vertexValue,val2);
}