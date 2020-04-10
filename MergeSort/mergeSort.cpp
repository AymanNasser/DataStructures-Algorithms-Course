#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int


using namespace std;

void merge(long long  *ptr, long long  leftIndex, long long  mid, long long  rightIndex){

	const long long sizeOfArray1 = mid - leftIndex + 1;
	const long long sizeOfArray2 = rightIndex - mid;

	/* Creating temporary arrays */
	long long L[sizeOfArray1], R[sizeOfArray2];

	/* Initializing the 2 sub-arrays*/
	for (long long var = 0; var < sizeOfArray1; ++var) {
		L[var] = ptr[leftIndex + var];
	}
	for (long long var = 0; var < sizeOfArray2; ++var) {
		R[var] = ptr[mid + 1 + var];
	}


	long long i=0,j=0,k=leftIndex;

    while (i < sizeOfArray1 && j < sizeOfArray2)
    {
        if (L[i] <= R[j])
        {
            ptr[k] = L[i];
            i++;
        }
        else
        {
            ptr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < sizeOfArray1)
    {
        ptr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < sizeOfArray2)
    {
        ptr[k] = R[j];
        j++;
        k++;
    }

}


void mergeSort(long long  *ptr, long long  leftIndex, long long  rightIndex){

	/* Checking recursion reached splitting array to only 2 elements or not */
	if (leftIndex < rightIndex){

		long long  mid = leftIndex + (rightIndex-leftIndex) / 2;

		mergeSort(ptr,leftIndex, mid);

		mergeSort(ptr,mid+1,rightIndex);

		merge(ptr,leftIndex,mid,rightIndex);
	}


}

// Driver to test
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll n;
	cin >> n;

	ll *arr = new ll[n];

	for (int var = 0; var < n; ++var) {
		cin >> arr[var];
	}

	mergeSort(arr,0,n-1);

	for (int var = 0; var < n; ++var) {
		cout << arr[var] << " ";
	}


    return 0;
}











