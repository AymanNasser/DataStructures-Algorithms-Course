
// Code fails at test case-8

#include <bits/stdc++.h>


#define ll long long int
#define ull unsigned long long int
#define us unsigned short

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct DisjointSetsElement {
	int size, parent, rank;

	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	int max_table_size;
	vector <DisjointSetsElement> sets;

	DisjointSets(int size): size(size), max_table_size(0), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}

	void updateTables(int dest, int source){
		sets[dest].size += sets[source].size;
		sets[source].size = 0;

		// Updating maxTableSize of our table
		if(this->max_table_size < sets[dest].size)
			this->max_table_size = sets[dest].size;
	}

	int getParent(int table) {

		if(table != sets[table].parent)
	    	sets[table].parent = getParent(sets[table].parent);
	   return sets[table].parent;
	}

	void Union(int destination, int source){

		if(sets[source].rank > sets[destination].rank)
		{
			// Parent is the source
			sets[destination].parent = sets[source].parent;
			std::swap(destination,source);

		}

		else
		{
			sets[source].parent = sets[destination].parent;

			if(sets[destination].rank == sets[source].rank)
				sets[sets[destination].parent].rank++;
		}

		updateTables(destination, source);
	}



	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);

		if (realDestination != realSource) {
			// merge two components
			// use union by rank heuristic
			Union(destination,source);
                        // update max_table_size
		}
	}


};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	DisjointSets tables(n);
	for (auto &table : tables.sets) {
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	for (int i = 0; i < m; i++) {
		int destination, source;
		cin >> destination >> source;
		// Decrementing the destination & source for 0-based indexing
                --destination;
                --source;

		tables.merge(destination, source);
	        cout << tables.max_table_size << '\n';
	}

	return 0;
}
