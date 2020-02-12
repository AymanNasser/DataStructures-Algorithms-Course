/*
 * Arr_stack.cpp
 *
 *  Created on: Feb 10, 2020
 *      Author: an
 */
#include "Arr_stack.h"


void createStack(Stack * const ps){
	ps->top = 0;
}

bool pushStack(STACK_ENTRY element,Stack * const ps){
	if(ps->top == MAX_ENTRY)
		return 0;
	else
	{
		ps->Entry[(ps->top)++] = element ;
		return 1;
	}
}

void popStack(STACK_ENTRY * const pe,Stack * const ps){
	*pe = ps->Entry[--(ps->top)];
}

void clearStack(Stack * const ps){
	ps->top = 0;
}

bool stackFull(Stack * const ps){
	return ps->top == MAX_ENTRY;
}

bool stackEmpty(Stack * const ps){
	return ps->top == 0;
}

void stackTop(STACK_ENTRY * const pe,Stack * const ps){
	*pe = ps->Entry[ps->top-1];
}

int stackSize(Stack * const ps){
	return ps->top;
}

void traverseStack(Stack * const ps,void(*pf)(STACK_ENTRY)){

	for(int i= ps->top; i>0; --i)
	{
		(*pf)(ps->Entry[i-1]);
	}
}

void stackBottom(STACK_ENTRY * const pe,Stack * const ps){
	*pe = ps->Entry[0];
}

bool copyStack(Stack * const pFromStack,Stack * const pIntoStack){

	for (int var = 0; var < MAX_ENTRY; ++var) {
		if(!(pFromStack->top == MAX_ENTRY) )
		pIntoStack->Entry[var] = pFromStack->Entry[var];
		else
		{
			return false;
		}
	}
	return true;
}




