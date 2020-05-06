/*
 * heapSort.cpp
 *
 *  Created on: Apr 29, 2020
 *      Author: an
 */

#include <algorithm>

// Building binary max-heap using 0-based index


void shiftDown(long *ptr,long size,long index){

	long maxIndex = index;
	long right = index*2 + 1; // right child at index = 2*index + 1
	long left = index*2 ; // left child at index = 2*index

	if(left < size && ptr[left] > ptr[maxIndex])
		maxIndex = left;

	if(right < size && ptr[right] > ptr[maxIndex])
		maxIndex = right;

	if(maxIndex != index)
	{
		std::swap(ptr[index], ptr[maxIndex]);
		shiftDown(ptr,size,maxIndex);
	}
	else{}

}


void buildMaxHeap(long *ptr, long size){
    
    /* Begining the heapify procedure from size = (size of tree / 2) because the heap property will not be violated 
     * for the nodes of of last edges but it may be violated for all upper nodes, repairing heap propery from bottom to top
    */
	for (long var = size / 2; var >= 0; --var) {

		shiftDown(ptr,size,var);
	}
}


void heapSort(long *ptr, long size){

	buildMaxHeap(ptr,size);

	for (long var = size - 1; var > 0; --var) {

		std::swap(ptr[0], ptr[var]);
		shiftDown(ptr,var,0);
	}

}






