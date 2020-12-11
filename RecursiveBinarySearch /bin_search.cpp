#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define us unsigned short

using namespace std;

int bin_search(vector <int> &n,int l, int r, int e){

	int mid = l + (r-l)/2;
	if(l > r)
		return -1;

	else if(n[mid] == e)
		return mid;

	else{

		if(n[mid] > e)
			r = mid - 1;
		else
			l = mid + 1;
	}
	bin_search(n, l, r, e);
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);


	vector <int> n = {1,2,3,4,8,12,90,110,150};
	cout << bin_search(n, 0, n.size()-1, 150);

    return 0;
}











