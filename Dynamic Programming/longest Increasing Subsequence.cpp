#include <bits/stdc++.h>



#define ll long long int
#define ull unsigned long long int

using namespace std;

#define MAX 1000
#define NIL 1

// Solving longest Increasing Subsequence problem using DP tabulation approach

long findMaxSubsequence(long *nil, long size){

	long maxSubsequence = 1;

	for (long var = 0; var < size; ++var) {
		if(nil[var] > maxSubsequence)
			maxSubsequence = nil[var];
	}
	return maxSubsequence;
}

long longestIncreasingSubsequence(long *ptr, long size){

	long *nil = new long[size];

	// Initialization of nil array
	for (long var = 0; var < size; ++var) {
		nil[var] = NIL;
	}


	for (long ite = 1; ite < size; ++ite) {

		for (long itr = 0; itr < ite ; ++itr) {

			if(ptr[ite] > ptr[itr] && nil[itr]+1 > nil[ite])
				nil[ite]++;
		}
	}
	return findMaxSubsequence(nil,size);
}






int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	long n;
	cin >> n;

	long *arr = new long[n];

	for (long var = 0; var < n; ++var) {
		cin >> arr[var];
	}

	cout << longestIncreasingSubsequence(arr,n);

    return 0;
}















