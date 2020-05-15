class Solution {
public:
    string removeKdigits(string num, int k) {
        
        
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	if(k == num.length())
		return "0";

	int n = num.length();
	stack <char> stk;


	for (int var = 0; var < n; ++var) {

		while(!stk.empty() && k > 0 && stk.top() > num[var] )
		{
			stk.pop();
			k--;
		}
		if(!stk.empty()||num[var] != '0')
			stk.push(num[var]);
	}

	if(k != 0)
	{
		while(!stk.empty() && k>0)
		{
			stk.pop();
			k--;
		}
	}


	while(!stk.empty()){
		num[n-1] = stk.top();
		stk.pop();
		n--;
	}
	if(num.substr(n) == "")
		return "0";
	return num.substr(n);
    }
};
