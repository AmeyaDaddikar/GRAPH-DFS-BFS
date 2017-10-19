#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "node.h"

typedef struct queue {
	NODE *front;
	NODE *rear;
	
} QUEUE;

void createQueue(QUEUE *queue)
{
	queue->front = NULL;
	queue->rear  = NULL;
}

void deleteQueue(QUEUE *queue)
{
	deleteAllNodes(queue->front);
}

int isQueueEmpty(QUEUE *queue,int (*comp)(void*,void*))
{
	if()
		return 1;
	else
		return 0;
}

void enqueue(QUEUE *queue, int val)
{
	NODE *new_node = newNode(NULL,val);

	if(isQueueEmpty(queue))
	{
		queue->front = new_node;
		queue->rear  = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear  =  queue->rear->next;
	}
}

int dequeue(QUEUE *queue)
{
	if(isQueueEmpty(queue))
		return -1;
	else
	{
		int top = queue->front->data;
		NODE *del_node = queue->front;
		queue->front = queue->front->next;
		
		if(queue->front == NULL)
			queue->rear = NULL;
		
		free(del_node);
		
		return top;
	}
}

#endif