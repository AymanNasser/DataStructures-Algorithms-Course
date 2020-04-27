#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define us unsigned short

using namespace std;


long knapSack(long knapSackWeight,long noOfItems,vector<long> itemWeight,vector<long> itemValue){

	long table[noOfItems+1][knapSackWeight+1];

	for (long ite = 0; ite <= noOfItems; ++ite) {

		for (long itr = 0; itr <= knapSackWeight; ++itr) {

			if(ite == 0 || itr == 0)
				table[ite][itr] = 0;

			else if(itemWeight[ite-1] <= knapSackWeight)
				table[ite][itr] = max(itemValue[ite-1] + table[ite-1][itr-itemWeight[ite-1]],
						table[ite-1][itr]);
			else
				table[ite][itr] = table[ite-1][itr];

		}
	}

	return table[noOfItems][knapSackWeight];

}



int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	long w,n;
	cin >> w >> n;
	vector <long> itW(n), itV(n);
	for (int var = 0; var < n; ++var) {
		cin >> itW[var];
	}
	for (int var = 0; var < n; ++var) {
		cin >> itV[var];
	}

	cout << knapSack(w,n,itW,itV);

    return 0;
}











