#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define us unsigned short

using namespace std;

int arrangeCoins(int n) {

	int i = 0;
	while(n > i)
	{
		i++;
		n -= i;
	}
	return i;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	cout << arrangeCoins(1);


    return 0;
}











