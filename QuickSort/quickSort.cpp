#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int


using namespace std;

// Pivot element is the left most index in the container

long long partition(long long  *ptr, long long  leftIndex, long long  rightIndex){

	long long pivot = ptr[leftIndex];
	long long i,partitioningIndex,k;


	i = leftIndex + 1;
	partitioningIndex = leftIndex ;

	while(i <= rightIndex) {

		if(ptr[i] <= pivot)
		{
			partitioningIndex++;
			swap(ptr[i],ptr[partitioningIndex]);
		}

		i++;
	}
	swap(ptr[leftIndex],ptr[partitioningIndex]);

	return partitioningIndex;
}



void quickSort(long long  *ptr, long long  leftIndex, long long  rightIndex){



	if(leftIndex < rightIndex)
	{
		long long m = partition(ptr,leftIndex,rightIndex);
		quickSort(ptr,leftIndex,m-1);
		quickSort(ptr,m+1,rightIndex);
	}


}

// Driver code to test
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	long n;
	cin >> n;

	long long *arr = new long long[n];

	for (int var = 0; var < n; ++var) {
		cin >> arr[var];
	}

	quickSort(arr,0,n-1);

	for (int var = 0; var < n; ++var) {
		cout << arr[var] << " ";
	}


    return 0;
}











