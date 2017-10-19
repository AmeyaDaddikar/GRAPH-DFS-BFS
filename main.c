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
	int value,option=0;
	
	LIST vertexList;
	createList(&vertexList);
	
	do{
		printf("ENTER THE VALUE/NAME OF THE VERTEX\n");
		scanf("%d",&value);
		
		VERTEX *new_vertex = (VERTEX*) malloc(sizeof(VERTEX));
		_insert(&vertexList,createVertex(new_vertex,value));

		printf("ENTER ANOTHER VERTEX? input 0 for no\n");
		scanf("%d",&option);
		
	}while(option);
	
	ITERATOR *vertexListIterator = (ITERATOR*)(getIterator(&vertexList));
	ITERATOR *firstVertex = vertexListIterator;
	
	while(vertexListIterator !=  NULL)
	{
		option = 0;
		value  = 0;
		VERTEX* curr_vertex = (VERTEX*) (vertexListIterator->data);
		
		printf("CURRENT VERTEX = %d\n",curr_vertex->val);
		
		printf("INPUT THE ADJACENT VERTICES. press 0 if no more vertex in adjacecncy list\n");
		scanf("%d",&option);
		
		while(option != 0)
		{
			printf("INPUT THE NAME/VALUE OF THE ADJACENT VERTEX\n");
			scanf("%d",&value);
			
			VERTEX *neighbour = (VERTEX*)(getNode(&vertexList,&value,&compareVertexInt));
			_insert(&curr_vertex->adj_list,neighbour);
			
			printf("INPUT THE ADJACENT VERTICES. press 0 if no more vertex in adjacecncy list\n");
			scanf("%d",&option);			
		}
		
		vertexListIterator = vertexListIterator->next;
	}

	if(startVertex != NULL)
		*startVertex = *((VERTEX*)(firstVertex->data));
	else
		createVertex(startVertex,-1);
	
	deleteList(&vertexList);
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
	
	createGraph(&vertex);
	
	deleteList(&list);
	deleteQueue(&queue);
	deleteStack(&stack);
	//deleteVertex(&vertex);
	
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