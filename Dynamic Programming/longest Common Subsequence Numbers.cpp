#include <bits/stdc++.h>



#define ll long long int
#define ull unsigned long long int

using namespace std;

#define MAX 1000
#define NIL 1

vector <long long> retrieveSequence(vector <vector <long> > &ptr, vector <long long> &A,long x, long y){

	vector <long long> retrievedSequence;


	long n = x, m =y;

	while(ptr[n][m] != 0)
	{
		if((ptr[n][m] > ptr[n-1][m]) && (ptr[n][m] > ptr[n][m-1]))
		{
			retrievedSequence.push_back(A[n-1]);
			n--;
			m--;
		}

		else if((ptr[n][m] == ptr[n][m-1]))
			m--;

		else
			n--;

	}
    

}


long longestCommonSubsequenceCount(vector <long long> &A, vector <long long> &B,
		long n, long m){

	vector <vector <long> > lcs(n+1,vector<long>(m+1));

	vector <long long> thirdSequence;

	for (long rowSize = 0; rowSize <= n ; ++rowSize) {
		for (long columnSize = 0; columnSize <= m ; ++columnSize) {

			if(rowSize == 0 || columnSize == 0)
				lcs[rowSize][columnSize] = 0;
            // Diagonal value
			else if(A[rowSize-1] == B[columnSize-1])
				lcs[rowSize][columnSize] = lcs[rowSize-1][columnSize-1] + 1;
            // Max of top value & left value
			else
				lcs[rowSize][columnSize] = max(lcs[rowSize-1][columnSize],lcs[rowSize][columnSize-1]);
		}
	}

	thirdSequence = retrieveSequence(lcs,A,n,m);
	reverse(thirdSequence.begin(),thirdSequence.end());

	return lcs[n][m];
}





int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	long n,m,k;

	cin >> n;

	//long long *ptr = new long long[n];
	vector <long long> ptr(n);
	for (long var = 0; var < n; ++var) {
		cin >> ptr[var];
	}

	cin >> m;

	//long long *arr = new long long[m];
	vector <long long> arr(m);
	for (long var = 0; var < m; ++var) {
		cin >> arr[var];
	}


    return 0;
}














