class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    	std::vector<std::vector<int> > ans;
    	if(root == NULL)
    		return ans;

    	stack<TreeNode*> st1, st2;
    	st1.push(root);

    	while(!st1.empty() || !st2.empty()) {
    		vector<int> temp;

    		//St1 is L->R
    		while(!st1.empty()) {

    			TreeNode* node = st1.top();
    			st1.pop();
    			temp.push_back(node->val);

    			if(node->left != NULL)
    				st2.push(node->left);
    			if(node->right != NULL)
    				st2.push(node->right);
    		}

    		if(temp.size() > 0)
    			ans.push_back(temp);
    		temp.clear();

    		while(!st2.empty()) {

    			TreeNode* node = st2.top();
    			st2.pop();
    			temp.push_back(node->val);

    			if(node->right != NULL)
    				st1.push(node->right);
    			if(node->left != NULL)
    				st1.push(node->left);
    		}


    		if(temp.size() > 0)
    			ans.push_back(temp);
    		temp.clear();

    	}

    	return ans;
    }
};