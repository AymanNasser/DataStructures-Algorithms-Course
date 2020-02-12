/*
 * Arr_queue.h
 *
 *  Created on: Feb 12, 2020
 *      Author: an
 */

#ifndef ARR_QUEUE_H_
#define ARR_QUEUE_H_

		/************ PreProcessors ***********/
#define QUEUE_ENTRY int
#define MAX_QUEUE 10

		/************ Structures ***********/
typedef struct Queue{
	int Rear;
	int Front;
	int size;
	QUEUE_ENTRY Entry[MAX_QUEUE];
};
		/************ Function APIs ***********/
void createQueue(Queue * const);
void append(QUEUE_ENTRY,Queue * const);
void serve(QUEUE_ENTRY * const, Queue * const);
bool queueEmpty(Queue * const);
bool queueFull(Queue * const);
void traverseQueue(Queue * const, void(*pf)(QUEUE_ENTRY));
void clearQueue(Queue * const);
int queueSize(Queue * const);
void copyQueue(Queue *const, Queue *const);


#endif /* ARR_QUEUE_H_ */
