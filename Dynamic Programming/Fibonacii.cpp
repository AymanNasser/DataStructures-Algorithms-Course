#include <bits/stdc++.h>



#define ll long long int
#define ull unsigned long long int

using namespace std;

#define MAX 1000
#define NIL -1

// Solving fibonacci number using DP memoization approach
int savedAnswers[MAX]; // Will be initialized to NIL value (-1)
int fibonaci_Memoization(int n){

	if(n <= 1)
		return 1;

	if(savedAnswers[n] != -1)
		return savedAnswers[n];

	return savedAnswers[n] = fibonaci_Memoization(n-1) + fibonaci_Memoization(n-2);


}

// Solving fibonacci number using DP tabulation approach
int fibonaci_Dp(int n){

	int savedAnswers[MAX];
	savedAnswers[0] = savedAnswers[1] = 1;


	for (int var = 2; var <= n; ++var) {
		savedAnswers[var] = savedAnswers[var-1] + savedAnswers[var-2];
	}

	return savedAnswers[n];


}




int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	for (int var = 0; var < MAX; ++var) {
		savedAnswers[var] = -1;
	}


	cout << fibonaci_Memoization(11);
    return 0;
}















