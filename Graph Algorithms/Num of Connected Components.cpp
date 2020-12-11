#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define us unsigned short

using namespace std;



void dfs(int &nodePos, vector<bool> &isNodeVisited,  int &numConnectedComponents,
		vector<int> &nodeToComponent, map<int, vector<int>> &graphAdjacencyList)
{
	isNodeVisited[nodePos] = true;
	nodeToComponent[nodePos] = numConnectedComponents;

	for(int i : graphAdjacencyList[nodePos]){

		if(!isNodeVisited[i])
			dfs(i, isNodeVisited, numConnectedComponents, nodeToComponent, graphAdjacencyList);
	}

}

void findComponents(int &numNodesInGraph, int &numConnectedComponents, vector<bool> &isNodeVisited,
		vector<int> &nodeToComponent, map<int, vector<int>> &graphAdjacencyList)
{
	for (int var = 0; var < numNodesInGraph; ++var) {

		if(!isNodeVisited[var])
		{
			numConnectedComponents++;
			dfs(var, isNodeVisited, numConnectedComponents, nodeToComponent, graphAdjacencyList);
		}
	}
}

void setInputsTest(map<int, vector<int>> &graphAdjacencyList)
{
	vector<int> in_1{8};
	graphAdjacencyList[0] = in_1;

	vector<int> in_2{5};
	graphAdjacencyList[1] = in_2;

	vector<int> in_3{9};
	graphAdjacencyList[3] = in_3;

	vector<int> in_8{4,14};
	graphAdjacencyList[8] = in_8;

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);

	map<int, vector<int>> graphAdjacencyList;
	int numConnectedComponents = 0, numNodesInGraph = 16;
	vector<bool> isNodeVisited(numNodesInGraph,false);
	vector<int> nodeToComponent(numNodesInGraph);

	findComponents(numNodesInGraph, numConnectedComponents, isNodeVisited, nodeToComponent, graphAdjacencyList);

	for (int var = 0; var < numNodesInGraph; ++var) {
		cout << nodeToComponent[var] << '\n';
	}

    return 0;
}











