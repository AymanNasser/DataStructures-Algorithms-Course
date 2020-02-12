/*
 * Lin_stack.h
 *
 *  Created on: Feb 10, 2020
 *      Author: an
 */

#ifndef LINKED_BASED_STACK_LIN_STACK_H_
#define LINKED_BASED_STACK_LIN_STACK_H_

#include <stdio.h>
#include <stdlib.h>

		/************ PreProcessors ***********/
#define STACK_ENTRY int
#define MAX_ENTRY 10


		/************ Structures ***********/
typedef struct StackNode{
	STACK_ENTRY Entry;
	StackNode *next;
};
typedef struct Stack{
	StackNode *top;
	int size;
};


		/************ Function APIs ***********/
void createStack(Stack * const ps);
bool pushStack(STACK_ENTRY,Stack * const ps);
void popStack(STACK_ENTRY * const,Stack * const ps);
void clearStack(Stack * const ps);
bool stackFull(Stack * const ps);
bool stackEmpty(Stack * const ps);
void stackTop(STACK_ENTRY * const,Stack * const ps);
int stackSize(Stack * const ps);
void traverseStack(Stack * const ps,void(*pf)(STACK_ENTRY));




#endif /* LINKED_BASED_STACK_LIN_STACK_H_ */
