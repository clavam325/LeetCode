/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	TreeNode* constructBst(std::vector<int>& preorder, int& index, int minm, int maxm) {

		if(index >= preorder.size()) 
			return NULL;

		TreeNode* root = NULL;
		if(preorder[index] < maxm && preorder[index] > minm) {

			root = new TreeNode(preorder[index]);
			index = index+1;

			root->left = constructBst(preorder, index, minm, root->val);
			root->right = constructBst(preorder, index, root->val, maxm);
		}

		return root;
	}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
    	if(preorder.size()  == 0)
    		return NULL;

    	int index = 0;
    	return constructBst(preorder, index, INT_MIN, INT_MAX);
        
    }
};