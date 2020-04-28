/*
 * priorityQueue.cpp
 *
 *  Created on: Apr 28, 2020
 *      Author: an
 */

#include "priorityQueue.h"

#define INFINITY 1e6


priorityQueue::priorityQueue(long size){

	this->maxSize = size;
	this->pHeap = new long [size];
    this->size = 0;
}


long priorityQueue::parent(long index){return index/2;}
long priorityQueue::leftChild(long index){return index*2;}
long priorityQueue::rightChild(long index){return index*2 +1;}

void priorityQueue::shiftUp(long index){
    
    // Looping over the height till we approach a level where the parent priority is max of left & right childs
	while(index > 1 && this->pHeap[parent(index)] > this->pHeap[index] ){
		std::swap(this->pHeap[parent(index)], this->pHeap[index]);
		index = index / 2; // index = parent(index)
	}
}

void priorityQueue::shiftDown(long index){

	long maxIndex = index;
	long right = index*2 + 1; // right child at index = 2*index + 1
	long left = index*2 + 1; // left child at index = 2*index

	if(left <= this->size && this->pHeap[left] > this->pHeap[maxIndex])
		maxIndex = left;

	if(right <= this->size && this->pHeap[right] > this->pHeap[maxIndex])
		maxIndex = right;

	if(maxIndex != index)
		std::swap(this->pHeap[index], this->pHeap[maxIndex]);
	else{}

	shiftDown(maxIndex);
}


void priorityQueue::insert(long value){

	if(this->size != this->maxSize)
	{
		this->size++;
		this->pHeap[this->size] = value;
		shiftUp(this->size);
	}
	else{}
}


long priorityQueue::extractMax(){

	if(this->size != 0){

		long res = this->pHeap[1];
		this->pHeap[1] = this->pHeap[this->size];
		this->size--;

		shiftDown(1);
		return res;
	}

	else{}

	return -1;
}

void priorityQueue::remove(long index){

	long temp;
	this->pHeap[index] = INFINITY;
	shiftUp(index);
	temp = extractMax();
}


void priorityQueue::changeValue(long index ,long value){

	long oldValue = this->pHeap[index];
	this->pHeap[index] = value;

	if(value > oldValue)
		shiftUp(index);
	else
		shiftDown(index);
}
