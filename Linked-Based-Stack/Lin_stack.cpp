/*
 * Lin_stack.cpp
 *
 *  Created on: Feb 10, 2020
 *      Author: an
 */
#include "Lin_stack.h"

void createStack(Stack * const ps){
	ps->top = NULL;
	ps->size = 0;
}

bool pushStack(STACK_ENTRY element,Stack * const ps){
	StackNode *pn = new StackNode;
	if(pn)
	{
		pn->Entry = element;
		pn->next = ps->top;
		ps->top = pn;
		ps->size++;
		return true;
	}
	else
	{
		return false;
	}
}

void popStack(STACK_ENTRY * const pe,Stack * const ps){
	StackNode *pTemp = ps->top;
	*pe = ps->top->Entry ;
	ps->top = ps->top->next;
	free(pTemp);
	ps->size--;
}

void clearStack(Stack * const ps){
	StackNode *pn = ps->top;
	while(pn)
	{
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
}

bool stackFull(Stack * const ps){
	return 0;
}

bool stackEmpty(Stack * const ps){
	return (ps->size == 0) ;
}

void stackTop(STACK_ENTRY * const pe,Stack * const ps){
	*pe = ps->top->Entry;
}



int stackSize(Stack * const ps){
	return ps->size ;
}

void traverseStack(Stack * const ps,void(*pf)(STACK_ENTRY)){
	StackNode *pn = ps->top;
	for (int var = 0; var < ps->size; ++var) {
		(*pf)(pn->Entry);
		pn = pn->next ;
	}
}


