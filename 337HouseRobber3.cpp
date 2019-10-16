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
    
    void robUtil(TreeNode* root, int& excl, int& incl) {
        
        if(root == NULL){
            return;
        }
        
        int nodeLeftExcl = 0, nodeLeftIncl = 0, nodeRightIncl = 0, nodeRightExcl = 0;

        robUtil(root->left, nodeLeftExcl, nodeLeftIncl);
        robUtil(root->right, nodeRightExcl, nodeRightIncl);

        excl = max( nodeLeftIncl, nodeLeftExcl) + max(nodeRightIncl, nodeRightExcl);
        incl = nodeLeftExcl + nodeRightExcl + root->val;

        return;

    }
    
    int rob(TreeNode* root) {
        
        int excl = 0, incl = 0;
        
        robUtil(root, excl, incl);            
        return max(excl, incl);
    }
};