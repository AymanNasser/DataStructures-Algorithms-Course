/*
 * Arr_list.cpp
 *
 *  Created on: Feb 14, 2020
 *      Author: an
 */

#include "Arr_list.h"

void createList(List * const pl){
	pl->size = 0;
}

/* Inserting a new element at a specific index to the list following 3 steps
 * 1st==> shifting all elements above the specified index by 1 step upwards
 * 2nd==> inserting the new element at index[pos]
 * 3rd==> incrementing the size
 * */
void insertIntoList(int pos, LIST_ENTRY element,List * const pl){
	for (int var = (pl->size-1); var >= pos; --var) {
		pl->Entry[var + 1] = pl->Entry[var];
	}
	pl->Entry[pos] = element;
	pl->size++;
}
/* Deleting am existing element at a specific index from the list following 3 steps
 * 1st==> shifting all elements above the specified index by 1 step downwards
 * 2nd==> deleting the element at index[pos]
 * 3rd==> decrementing the size
 * */
void deleteFromList(int pos, LIST_ENTRY * const pe, List * const pl){
	*pe = pl->Entry[pos];
	for (int var = (pos + 1) ; var <=(pl->size-1); ++var) {
		pl->Entry[var - 1] = pl->Entry[var];
	}
	pl->size--;
}
/* Checking if the list is empty
 * if pl->size == 0 , therefore the list is empty and !(0) == 1 which indicates that the list
 * is empty
 * if pl->size != 0 , therefore the list isn't empty and !(size) == 0
 * */
bool listEmpty(List * const pl){
	return !(pl->size) ;
}
/* Checking if the list is full
 * if pl->size == MAX_LIST , therefore the list is full and the condition is true which
 * indicates that the list is full
 * if pl->size != MAX_LIST , therefore the list isn't empty and and condition is false returning 0
 * */
bool listFull(List * const pl){
	return (pl->size == MAX_LIST) ;
}
/* Passing list elements to a function using pointer to function (pf) as an argument */
void traverseList(List * const pl, void(*pf)(LIST_ENTRY)){
	for (int var = 0; var < MAX_LIST; ++var) {
		(*pf)(pl->Entry[var]);
	}
}

void clearList(List * const pl){
	pl->size =0;
}

int listSize(List * const pl){
	return pl->size ;
}
/* Copy List contents to another list */
void copyList(List *const pFromList, List *const pIntoList){
	for (int var = 0; var < MAX_LIST; ++var) {
		pIntoList->Entry[var]= pFromList->Entry[var];
	}
}
/* Retrieve an element from the list at index[pos] without deleting it */
void retrieveFromList(int pos, LIST_ENTRY * const pe, List * const pl){
	*pe = pl->Entry[pos];
}
/* Replacing an element from the list at index[pos] */
void replaceElementInList(int pos, LIST_ENTRY pe, List * const pl){
	pl->Entry[pos] = pe;
}



