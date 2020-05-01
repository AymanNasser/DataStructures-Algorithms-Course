/*
 * DisjointSets.h
 *
 *  Created on: May 1, 2020
 *      Author: an
 */

#ifndef DISJOINTSETS_H_
#define DISJOINTSETS_H_

class DisjointSets {

private:
	long *parent;
	long *rank;
public:
	DisjointSets(long);
	long makeSet(long);
	long find(long);
	long Union(long,long);


};

#endif /* DISJOINTSETS_H_ */
