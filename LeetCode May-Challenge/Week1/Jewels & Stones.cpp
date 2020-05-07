#include <bits/stdc++.h>
//#include "priorityQueue.h"

#define ll long long int
#define ull unsigned long long int
#define us unsigned short

using namespace std;

int majorityElement(vector<int>& nums) {

	sort(nums.begin(),nums.end());

	int prev,elementValue,maxValue,maxIndex;

	prev = nums[0];
	elementValue = 1;
	maxIndex = nums[0];
	maxValue = 0;

	for(int i = 1; i< nums.size(); i++){

		if(nums[i] == prev)
		{
			elementValue++;
			prev = nums[i];
		}

		if(elementValue > maxValue)
		{
			maxValue = elementValue;
			maxIndex = nums[i-1];

			prev = nums[i];
		}

		if(nums[i] != prev)
			elementValue = 1;



	}
	return maxIndex;

}


int numJewelsInStones(string J, string S) {

	char capLetters[26] = {0};
	char smallLetters[26] = {0};
	int maxValue = 0;

	for(int i=0; i < S.length(); i++){

		if(S[i] >= 97 && S[i] <= 122)
			smallLetters[S[i]-97]++;
		else
			capLetters[S[i]-65]++;
	}

	for(int i=0; i < J.length(); i++){

		if(J[i] >= 97 && J[i] <= 122)
			maxValue += smallLetters[J[i]-97];
		else
			maxValue += capLetters[J[i]-65];
	}
	return maxValue;
}


int main()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);  std::cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cout << numJewelsInStones("z","ZZ");


    return 0;
}
















