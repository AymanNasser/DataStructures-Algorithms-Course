/*
 * priorityQueue.h
 *
 *  Created on: Apr 28, 2020
 *      Author: an
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <algorithm>

/* Implementation of a priority queue using heaps on complete binary tree to benefit from O(log(n)) height  
*/

class priorityQueue {

private:
	long size;
	long maxSize;
	long*pHeap;

private:
	void shiftUp(long);
	void shiftDown(long);

public:
	priorityQueue(long);
	long parent(long);
	long leftChild(long);
	long rightChild(long);

	void insert(long);
	long extractMax();
	void remove(long);
	void changeValue(long,long);
};

#endif /* PRIORITYQUEUE_H_ */
