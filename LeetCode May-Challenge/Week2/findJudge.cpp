class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);  
        
    int noTrustsBody = -1;
    vector <int> arr(N+1,0);
    

	for (int var = 0; var < trust.size(); ++var) {

		arr[trust[var][0]]++;
	}

	for (int var = 1; var <= N; ++var) {

		if(arr[var] ==0)
			noTrustsBody = var;
		arr[var] = 0;
	}

	if(noTrustsBody == -1)
		return -1;

	for (int var = 0; var < trust.size(); ++var) {

		if(trust[var][1] == noTrustsBody)
			arr[trust[var][0]]++;
	}

	for (int var = 1; var <= N; ++var) {

		if(var == noTrustsBody)
			continue;
		else if(arr[var] ==0)
			return -1;
	}

return noTrustsBody;
    }
};
