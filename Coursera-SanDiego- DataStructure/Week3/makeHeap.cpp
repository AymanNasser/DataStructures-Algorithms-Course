#include <bits/stdc++.h>
//#include "priorityQueue.h"

#define ll long long int
#define ull unsigned long long int
#define us unsigned short

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

void shiftDown(long *ptr,long size,long index, long &, vector<pair <long,long> > &);
void buildMaxHeap(long *ptr, long size, long &,vector <pair <long,long>> &s);


int main()
{

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	long n,swaps=0,j;
	vector <pair <long,long>> s;
	cin >> n;

	long *arr = new long [n];

	for (int var = 0; var < n; ++var) {
		cin >> arr[var];
	}


	buildMaxHeap(arr,n,swaps,s);

	//cout << s.size() << '\n';
	cout << swaps << '\n';

	for(int i=0; i < s.size(); i++){
		cout << s[i].first << " " << s[i].second << '\n';
	}



    return 0;
}

// Min-heap 0-based indexing
void shiftDown(long *ptr,long size,long index, long &maxSwaps, vector<pair <long,long>> &swapa_j){

	long minIndex = index;
	long right = index*2 + 2; // right child at index = 2*index + 2
	long left = index*2 + 1; // left child at index = 2*index + 1

	if(left < size && ptr[left] < ptr[maxIndex])
		minIndex = left;

	if(right < size && ptr[right] < ptr[maxIndex])
		minIndex = right;

	if(minIndex != index)
	{
		std::swap(ptr[index], ptr[minIndex]);
		swapa_j.push_back(make_pair(index, minIndex));

		shiftDown(ptr,size, minIndex,maxSwaps,swapa_j);
		maxSwaps++;
	}
	else{}

}


void buildMaxHeap(long *ptr, long size,long &swaps,vector<pair <long,long>>& swapping){

	for (long var = size/2 -1 ; var >= 0; --var) {

		shiftDown(ptr,size,var,swaps,swapping);
	}
}















