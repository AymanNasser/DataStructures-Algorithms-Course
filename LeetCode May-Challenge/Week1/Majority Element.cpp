#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define us unsigned short

using namespace std;

int majorityElement(vector<int>& nums) {

	map <int, int> cont;
	map<int, int>::iterator itr;
	int maxIndex,maxValue = 0;
    
    // Initializing map values to 0
	for(int i =0; i < nums.size(); i++){
		cont[nums[i]] = 0;
	}
    // Calc. frequency of each key
	for(int i =0; i < nums.size(); i++){
		cont[nums[i]]++;
	}
    // Retrieving max frequency
	for(itr =cont.begin(); itr != cont.end(); itr++){

		if(itr->second > maxValue)
		{
			maxIndex = itr->first;
			maxValue = itr->second;
		}
	}

	return maxIndex;
}


int main()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);  std::cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);



	int n ;
	std::cin >> n;
	std::vector<int> numbers(n);

	for(int i =0; i < n; i++){
		cin >> numbers[i];
	}
	cout << majorityElement(numbers);


    return 0;
}
















