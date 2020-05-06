

int firstBadVersion(char *arr,int n) {

	int start = 1,end = n,mid;

	while (start < end)

        mid = start + (end-start)/2;

		if(isBadVersion(mid))
			end = mid;
		else
			start = mid+1;
	}

	return mid;
}

