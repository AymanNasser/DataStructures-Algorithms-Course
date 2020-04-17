#include <bits/stdc++.h>



#define ll long long int
#define ull unsigned long long int

using namespace std;

#define MAX 1000
#define NIL 1

/* Given two strings str1 and str2 and below operations that can performed on str1.
 * Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
 * 1- Replace
 * 2- Insert
 * 3- Delete
 * All of the above operations are of equal cost.
 * */



long editDistance(string A, string B){

	long table[A.length()+1][B.length()+1];


	/* If characters of [row][column] of two strings are same, nothing
	 * much to do. get the diagonal number of operations.
	 * */
	for (long row = 0; row <= A.length(); ++row) {

		for (long column = 0; column <= B.length(); ++column) {

			/* Initializing table with minimum number of operations needed to
			 * perform on string A to approach B
			 * */

			if(row == 0)
				table[row][column] = column;

			else if(column == 0)
				table[row][column] = row;

			else if(A[row-1] == B[column-1])
				table[row][column] = table[row-1][column-1];

			else
			{	/* Insert ==> table[row][column-1]
				 * Remove ==> table[row-1][column]
				 * Replace ==> table[row-1][column-1]
			 	 */
				table[row][column] = 1 + min(table[row-1][column-1], min(table[row-1][column],table[row][column-1]));
			}
		}

	}


	return table[A.length()][B.length()];
}



int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cout << editDistance("cut","cat");

    return 0;
}















