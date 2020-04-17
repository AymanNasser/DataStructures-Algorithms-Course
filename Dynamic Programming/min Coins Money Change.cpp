#include <bits/stdc++.h>



#define ll long long int
#define ull unsigned long long int

using namespace std;

#define MAX 1000
#define NIL 1

/* Calculating minimum coins needed to change an amount of money using
 * DP tabulation approach ==> by saving to the table[i] the amount of coins
 * needed to change the amount (table[i]) for each specific coin by looping
 * on number of coins (denominations)
 * */

long minCoinsMoneyChange(long amount, long *coins, long coinsAmount){

	long table[amount + 1];

	/* Initializing the table with a big value to fit when comparing & also
	 * table[0] = 0 which means that 0 amount needs 0 coins for change
	 * */
	table[0] = 0;
	for (long var = 1; var <= amount; ++var) {

		table[var] = amount+1;
	}

	for (long ite = 1; ite <= amount; ++ite) {
		for (long itr = 0; itr < coinsAmount; ++itr) {
			if(ite >= coins[itr])
				table[ite] = min(table[ite - coins[itr]]+1, table[ite]);
		}
	}


	if(table[amount] == amount+1)
		return -1;
	else
		return table[amount];
}



int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	string temp;

	long coins[] = {2};

	cout << minCoinsMoneyChange(3,coins,1);



    return 0;
}















