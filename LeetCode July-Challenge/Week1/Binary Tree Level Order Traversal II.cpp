// Submission runtime = 4ms

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	vector<vector<int>> result;

	if(root == nullptr)
        return result;

	TreeNode* currentNode;
	queue<TreeNode*> que;
	que.push(root);

	while(!que.empty()){

        int rowSize = que.size();
        vector<int> valuesPerRowNodes;

        while(rowSize-- > 0){
			currentNode = que.front();
			que.pop();

			valuesPerRowNodes.push_back(currentNode->val);

			if(currentNode->left)
				que.push(currentNode->left);
			if(currentNode->right)
				que.push(currentNode->right);
		 }
		result.push_back(valuesPerRowNodes);
	 }

    reverse(result.begin(),result.end());
	return result;
}
