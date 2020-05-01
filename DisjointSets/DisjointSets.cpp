/*
 * DisjointSets.cpp
 *
 *  Created on: May 1, 2020
 *      Author: an
 */

#include "DisjointSets.h"

DisjointSets::DisjointSets(long size) {
	this->parent = new long [size];
	this->rank = new long[size];
}

long DisjointSets::makeSet(long index){

	this->parent[index] = index;
	this->rank[index] = 0;
}

long DisjointSets::find(long index){

	if(index != this->parent[index])
		this->parent[index] = find(this->parent[index]);
	return this->parent[index];
}

long DisjointSets::Union(long element1, long element2){

	long id_1, id_2;
	id_1 = find(element1);
	id_2 = find(element2);

	if(rank[id_1] > rank[id_2])
		parent[id_2] = id_1;
	else
		parent[id_1] = id_2;

	if(rank[id_1] == rank[id_2])
		rank[id_2] = rank[id_1] +1;
}
