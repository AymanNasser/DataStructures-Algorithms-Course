class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);  std::cout.tie(NULL);
        
    if(ransomNote.length() > magazine.length())
	return false;

	int freqm[26]={0};
	int freqr[26]={0};
	int var;
	for (var = 0; var < magazine.length(); ++var) {
		freqm[magazine[var]-97]++;
	}

	for (var = 0; var < ransomNote.length(); ++var) {
		freqr[ransomNote[var]-97]++;
	}

	for (var = 0; var < 26; ++var) {
		if(freqr[var] > freqm[var])
			return false;
	}

	return true;
        
    }
};
