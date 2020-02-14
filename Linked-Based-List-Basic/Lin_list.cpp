/*
 * Lin_list.cpp
 *
 *  Created on: Feb 14, 2020
 *      Author: an
 */
#include "Lin_list.h"

void createList(List * const pl){
	pl->head = NULL;
	pl->size = 0;
}

bool insertIntoList(int pos, LIST_ENTRY element,List * const pl){
	ListNode *temp;
	ListNode *pNewNode;
	int var;
	if( (pNewNode = new ListNode) )
	{
		pNewNode->Entry = element;

		if(pos == 0)
		{
			pNewNode->next = pl->head;
			pl->head = pNewNode;
		}
		else
		{
			for (temp = pl->head , var = 0; var < pos - 1; ++var)
			{
				temp = temp->next;
			}
			pNewNode->next = temp->next;
			temp->next = pNewNode;
		}
		pl->size++;
		return true;
	}
	else
	{
		return false;
	}



}

void deleteFromList(int pos, LIST_ENTRY * const pe, List * const pl){
	ListNode *temp, *inc;
	int var;
	if(pos==0)
	{
		*pe = pl->head->Entry;
		temp = pl->head->next;
		delete(pl->head);
		pl->head = temp;
	}
	else
	{
		for (var = 0, inc = pl->head ; var < pos - 1; ++var) {
			inc = inc->next;
		}
		*pe = inc->next->Entry;
		temp = inc->next->next;
		delete (inc->next);
		inc->next = temp;
	}
	pl->size--;
}

bool listEmpty(List * const pl){
	return !(pl->head);
}
bool listFull(List * const){
	return 0;
}
void traverseList(List * const pl, void(*pf)(LIST_ENTRY)){
	ListNode * temp;
	for (temp = pl->head; temp != NULL ; temp= temp->next)
	{
		(*pf)(temp->Entry);
	}
}

void clearList(List * const pl){
	ListNode * temp;
	while(pl->head)
	{
		temp = pl->head->next;
		delete(pl->head);
		pl->head = temp;
	}
}

int listSize(List * const pl){
	return pl->size;
}
void retrieveFromList(int pos, LIST_ENTRY * const pe, List * const pl){
	int var = 0;
	ListNode *temp = pl->head;
	while(var < pos)
	{
		var++;
		temp = temp->next;
	}
	*pe = temp->Entry;
}

void replaceElementInList(int pos, LIST_ENTRY element, List * const pl){
	int var = 0;
	ListNode *temp = pl->head;
	while(var < pos)
	{
		var++;
		temp = temp->next;
	}
	temp->Entry = element;
}



