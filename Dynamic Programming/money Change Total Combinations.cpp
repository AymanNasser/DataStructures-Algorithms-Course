#include <bits/stdc++.h>



#define ll long long int
#define ull unsigned long long int

using namespace std;

#define MAX 1000
#define NIL 1

/* Calc. total number of combinations given an int amount & array of coin denominations
 * if (amount >= coins[i]) ==> combinations[i] = combinations[i] + combinations[amount - coin[i]]
 * Problem is solved using DP tabulation approach
 * */
long moneyChangeTotalCombinations(long amount, long *coins, long coinsAmount){

	long combinations[amount + 1] = {1,0};

	for (long coinIndex = 0; coinIndex < coinsAmount; ++coinIndex) {

		for (long var = 1; var <= amount; ++var) {

			if(var >= coins[coinIndex])
				combinations[var] += combinations[var - coins[coinIndex]];
		}
	}

	return combinations[amount];
}




int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	string temp;

	long coins[] = {1,2,5};

	cout << moneyChangeTotalCombinations(12,coins, 3);



    return 0;
}















