/*
 * heapSort.cpp
 *
 *  Created on: Apr 29, 2020
 *      Author: an
 */

#include <algorithm>


void shiftDown(long *ptr,long size,long index){

	long maxIndex = index;
	long right = index*2 + 1; // right child at index = 2*index + 1
	long left = index*2 ; // left child at index = 2*index

	if(left <= size && ptr[left] > ptr[maxIndex])
		maxIndex = left;

	if(right <= size && ptr[right] > ptr[maxIndex])
		maxIndex = right;

	if(maxIndex != index)
	{
		std::swap(ptr[index], ptr[maxIndex]);
		shiftDown(ptr,size,maxIndex);
	}
	else{}

}


void buildMaxHeap(long *ptr, long size){

	for (long var = size / 2; var >= 1; --var) {

		shiftDown(ptr,size,var);
	}
}


void heapSort(long *ptr, long size){

	buildMaxHeap(ptr,size);

	for (long var = 0; var < size-1; ++var) {

		std::swap(ptr[1], ptr[size]);
		--size;
		shiftDown(ptr,size,1);
	}

}




