/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//#define null -1

class Solution {
public:
        
    int getDepthParent(TreeNode *node,int nodeValue,int &parent,int level){

	if(node == NULL)
		return 0 ;
	else if(node->val == nodeValue)
		return level;
    
    parent = node->val;
        
	int a = getDepthParent(node->left, nodeValue,parent,level+1);
	// If the element is found in the left subtree so return level at which node present
	// which is level(a)
	if(a != 0)
		return a;
    
    // Else search for right subtree
    parent = node->val;    
    return getDepthParent(node->right, nodeValue,parent,level+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);  std::cout.tie(NULL);
        
    int x_parent, y_parent,x_depth,y_depth;

    x_depth = getDepthParent(root, x, x_parent,0);
    y_depth = getDepthParent(root, y, y_parent,0);
    
    
 

    if(x_depth == y_depth &&  x_parent != y_parent)
    	return true;
    else
    	return false;
        
        
        
        
    }
};
