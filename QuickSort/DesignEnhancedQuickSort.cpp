#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int


using namespace std;


	/* Designed enhanced QuickSort algorithm using random pivot element &
	 * 3-way partitioning
	 * */
void partition(long long  *ptr, long long  leftIndex, long long  rightIndex,
		 long long &m1, long long &m2){

	long long pivot = ptr[leftIndex];
	long long i,k;


	i = leftIndex + 1;
	m1 = leftIndex ;
	m2 = leftIndex ;

	while(i <= rightIndex) {

		if(ptr[i] < pivot)
		{
			m1++;
			swap(ptr[i],ptr[m1]);
		}
		else if(ptr[i] == pivot)
		{
			m2++;
			swap(ptr[i],ptr[m2]);
		}
		i++;
	}

	swap(ptr[leftIndex],ptr[m1]);

}



void quickSort(long long  *ptr, long long  leftIndex, long long  rightIndex){



	if(leftIndex < rightIndex)
	{

		/* Randomized selection of pivot element */
		long long k = leftIndex +  rand() % (rightIndex - leftIndex + 1) ;
		swap(ptr[k],ptr[leftIndex]);
		//cout << k << '\n';
		long long m1,m2;
		partition(ptr,leftIndex,rightIndex,m1,m2);

		quickSort(ptr,leftIndex,m1-1);
		quickSort(ptr,m2+1,rightIndex);
	}


}


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











