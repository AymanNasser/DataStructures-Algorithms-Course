class Solution {
public:
   int firstUniqChar(string s) {

	int freq[26]={0};

	for (int var = 0; var < s.length(); var++) {
		freq[s[var]-97]++;
	}


	for (int var = 0; var < s.length(); var++) {
		if( freq[s[var]-97] == 1 )
			return var;
	}

	return -1;

}
};
