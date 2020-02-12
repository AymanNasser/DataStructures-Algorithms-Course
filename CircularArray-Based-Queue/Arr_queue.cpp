/*
 * Arr_queue.cpp
 *
 *  Created on: Feb 12, 2020
 *      Author: an
 */
#include "Arr_queue.h"

// Initializing the queue
void createQueue(Queue * const pq){
	pq->Front = 0;
	pq->Rear = -1;
	pq->size = 0;
}

// Inserting a new element at the back of the queue
void append(QUEUE_ENTRY element,Queue * const pq){
	/* Checking if the rear is at the max of the queue array, and if
	 * the condition is true, make the inserting position at the queue[0]
	 * else ++Rear & insert
	 * */
	if(pq->Rear == MAX_QUEUE-1)
	{
		pq->Rear = 0;
		pq->Entry[pq->Rear] = element;
	}
	else
	{
		pq->Entry[++(pq->Rear)] = element;
	}

	pq->size++;
}
// Removing element from the front position
void serve(QUEUE_ENTRY * const pe, Queue * const pq){
	*pe = pq->Entry[pq->Front];
	/* Checking if the front is at the max of the queue array, and if
	 * the condition is true, make the removing position at the queue[0]
	 * else ++Front
	 * */
	if(pq->Front == MAX_QUEUE-1)
	{
		pq->Front = 0;
	}
	else
	{
		pq->Front++;
	}
	pq->size--;
}

bool queueEmpty(Queue * const pq){
	return !(pq->size) ;
}

bool queueFull(Queue * const pq){
	return (pq->size == MAX_QUEUE);
}

void traverseQueue(Queue * const pq, void(*pf)(QUEUE_ENTRY)){
	int pos,i;
	for(pos=pq->Front,i=0 ; i< pq->size ;i++)
	{
		(*pf)(pq->Entry[pos]);

		if(pq->Front == MAX_QUEUE-1)
			{
				pos = 0;
			}
			else
			{
				pos++;
			}
	}
}
void clearQueue(Queue * const pq){
	pq->Front = 0;
	pq->Rear = -1;
	pq->size = 0;
}

int queueSize(Queue * const pq){
	return pq->size ;
}

void copyQueue(Queue *const pFromQueue, Queue *const pIntoQueue){
	int fromPos = pFromQueue->Front;
	int intoPos = pIntoQueue->Rear;

	for (int var = 0; var < MAX_QUEUE; ++var) {
		pIntoQueue->Entry[intoPos] = pFromQueue->Entry[fromPos];
		/* Checking if either rear or front are at the max of the queue array, and if
		 * the condition is true, make the inserting/removing position at the queue[0]
		 * by modulus operation instead of if statements
		 * */
		fromPos= (fromPos+1) % MAX_QUEUE;
		intoPos= (intoPos+1) % MAX_QUEUE;
	}
}


