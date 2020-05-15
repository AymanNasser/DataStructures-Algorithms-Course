class Trie {

public
    
    Trie *children[26] ;
    bool endOfWord;
    /** Initialize your data structure here. */
    Trie() {
    	this->endOfWord = false;
    	for (int var = 0; var < 26; ++var) {
			children[var] = nullptr;
		}
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);  cout.tie(NULL);

    	Trie * currentNode = this;
    	for (int var = 0; var < word.length(); ++var) {

    		if(currentNode->children[word[var]-97] == nullptr)
    			currentNode->children[word[var]-97] = new Trie();

    		currentNode = currentNode->children[word[var]-97];
		}
    	currentNode->endOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);  cout.tie(NULL);
    	Trie * currentNode = this;
    	for (int var = 0; var < word.length(); ++var) {

    		if(currentNode->children[word[var]-97] == nullptr)
    			return false;

    		currentNode = currentNode->children[word[var]-97];
		}
    	if(currentNode->endOfWord)
    		return true;
    	else
    		return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);  cout.tie(NULL);
    	Trie * currentNode = this;
    	for (int var = 0; var < prefix.length(); ++var) {

    		if(currentNode->children[prefix[var]-97] == nullptr)
    			return false;

    		currentNode = currentNode->children[prefix[var]-97];
		}
    	return true;
    }
};

