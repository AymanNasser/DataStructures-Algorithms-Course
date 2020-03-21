/*
 * Lin_list.h
 *
 *  Created on: Feb 14, 2020
 *      Author: an
 */

#ifndef LIN_LIST_H_
#define LIN_LIST_H_

#include <stdio.h>

		/************ PreProcessors ***********/
#define LIST_ENTRY int

		/************ Structures ***********/
typedef struct ListNode{
	LIST_ENTRY Entry;
	ListNode *next;
};

typedef struct List{
	ListNode *head;
	ListNode *current;
	int currentPos;
	int size;
};
		/************ Function APIs ***********/

void createList(List * const);
bool insertIntoList(int, LIST_ENTRY,List * const);
void deleteFromList(int, LIST_ENTRY * const, List * const);
bool listEmpty(List * const);
bool listFull(List * const);
void traverseList(List * const, void(*pf)(LIST_ENTRY));
void clearList(List * const);
int listSize(List * const);
void retrieveFromList(int, LIST_ENTRY * const, List * const);
void replaceElementInList(int, LIST_ENTRY, List * const);



#endif /* LIN_LIST_H_ */
