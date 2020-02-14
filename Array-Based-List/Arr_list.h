/*
 * Arr_list.h
 *
 *  Created on: Feb 14, 2020
 *      Author: an
 */

#ifndef ARR_LIST_H_
#define ARR_LIST_H_


		/************ PreProcessors ***********/
#define LIST_ENTRY int
#define MAX_LIST 10

		/************ Structures ***********/
typedef struct List{
	LIST_ENTRY Entry[MAX_LIST];
	int size;
};
		/************ Function APIs ***********/
void createList(List * const);
void insertIntoList(int, LIST_ENTRY,List * const);
void deleteFromList(int, LIST_ENTRY * const, List * const);
bool ListEmpty(List * const);
bool ListFull(List * const);
void traverseList(List * const, void(*pf)(LIST_ENTRY));
void clearList(List * const);
int ListSize(List * const);
void copyList(List *const, List *const);
void retrieveFromList(int, LIST_ENTRY * const, List * const);
void replaceElementInList(int, LIST_ENTRY, List * const);


#endif /* ARR_LIST_H_ */
