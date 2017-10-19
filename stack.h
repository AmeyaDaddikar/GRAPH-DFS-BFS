#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "node.h"

typedef struct stack{
	NODE *top;
	
} STACK;

void createStack(STACK *stack)
{
	stack->top = NULL;
}

void deleteStack(STACK *stack)
{
	deleteAllNodes(stack->top);
}

int isStackEmpty(STACK *stack)
{
	if(stack->top == NULL)
		return 1;
	else
		return 0;
}

void push(STACK *stack, int val)
{
	stack->top = newNode(stack->top,val);
}

int pop(STACK *stack)
{
	if(isStackEmpty(stack))
		return -1;
	else
	{
		int top_val = stack->top->data;
		NODE *del_node = stack->top;
		
		stack->top = stack->top->next;
		
		free(del_node);
		
		return top_val;
	}
}

#endif