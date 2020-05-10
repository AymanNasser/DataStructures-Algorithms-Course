#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long int

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  ll key;
  ll left;
  ll right;

  Node() : key(0), left(-1), right(-1) {}
  Node(ll key_, ll left_, ll right_) : key(key_), left(left_), right(right_) {}
};

bool auxiSearchTree(const vector<Node>& tree, ll index, ll min, ll max){

	if(index == -1)
		return true;

	if(tree[index].key < min || tree[index].key >= max)
		return false;

	return auxiSearchTree(tree, tree[index].left, min, tree[index].key) &&
		   auxiSearchTree(tree, tree[index].right, tree[index].key, max);

}

bool IsBinarySearchTree(const vector<Node>& tree) {

	if(tree.size() <2)
		return true;

  return auxiSearchTree(tree, 0,  (-9223372036854775807 - 1),  9223372036854775807);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;

  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }


  if(IsBinarySearchTree(tree))
	  cout << "CORRECT" ;

  else
	  cout << "INCORRECT";


  return 0;
}
