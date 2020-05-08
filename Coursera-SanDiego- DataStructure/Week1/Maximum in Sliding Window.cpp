#include <bits/stdc++.h>
//#include "priorityQueue.h"

#define ll long long int
#define ull unsigned long long int
#define us unsigned short

using namespace std;

void maximumSlidingWindow(int n, int m, vector<int> &sequence){

	deque<int> cont;

	for (int var = 0; var < sequence.size()+1; ++var) {
    
		if( var >= m)
		{
			cout << sequence[cont.front()] << " ";

			while(!cont.empty() && cont.front() <= var-m)
				cont.pop_front();
		}

		while(!cont.empty() && sequence[var] > sequence[cont.back()])
			cont.pop_back();

		cont.push_back(var);
	}

}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n,m;

	cin >> n;
	vector<int> sequence(n);


	for (int var = 0; var < n; ++var) {
		cin >> sequence[var];
	}

	cin >> m;

	maximumSlidingWindow(n,m,sequence);


	return 0;
}
