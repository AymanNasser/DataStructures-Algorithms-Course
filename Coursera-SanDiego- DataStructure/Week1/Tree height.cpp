#include <bits/stdc++.h>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif




#define ll long long int
#define ull unsigned long long int

using namespace std;

#define MAX 1000
#define NIL -1
class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int getRoot(vector<Node> &nodes){

	for (int var = 0; var < nodes.size(); ++var) {
		if(nodes[var].parent == NULL)
			return var;
	}

}


int getMaxHeight(Node rootIndex){

	int maxHeight = 0,temp;

	if(rootIndex.children.size() == 0)
		return 1;

	for (int var = 0; var < rootIndex.children.size(); ++var) {
		temp = getMaxHeight(*rootIndex.children[var]);
		maxHeight = max(maxHeight,temp);
	}
	maxHeight++;
	return maxHeight;
}


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }

  // Replace this code with a faster implementation
  int rootIndex = getRoot(nodes);
  int maxHeight = getMaxHeight(nodes[rootIndex]);


//  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
//    int height = 0;
//    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
//      height++;
//    maxHeight = std::max(maxHeight, height);
//  }

  std::cout << maxHeight << '\n';
  return 0;
}




int main (int argc, char **argv)
{

#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}













