/*
 * stack.h
 *
 *  Created on: Feb 10, 2020
 *      Author: an
 */

#ifndef ARRAY_BASED_STACK_ARR_STACK_H_
#define ARRAY_BASED_STACK_ARR_STACK_H_

		/************ PreProcessors ***********/
#define STACK_ENTRY char
#define MAX_ENTRY 10


		/************ Structures ***********/
typedef struct Stack{
	int top;
	STACK_ENTRY Entry[MAX_ENTRY];
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



#endif /* ARRAY_BASED_STACK_ARR_STACK_H_ */
