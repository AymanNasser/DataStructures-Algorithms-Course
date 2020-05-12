#include <iostream>
#include <vector>
#include <string>
#include <list>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

struct Contact{
	string name;
	int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;

    const long long m = 10000000;
    long long preHash;
    vector<string> contacts(m);
    long long ite = 0;

    while(ite < queries.size()){

    	if(queries[ite].type == "add")
    	{
    		preHash = queries[ite].number;

    		contacts[preHash] = queries[ite].name;

    	}
    	else if(queries[ite].type == "del")
    	{
    		preHash = queries[ite].number;

    		contacts[preHash] = "";
    	}
    	else
    	{
    		preHash = queries[ite].number;
    		if(contacts[preHash] != "")
    			result.push_back(contacts[preHash]);
    		else
    			result.push_back("not found");
    	}

    	ite++;
    }

    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}

