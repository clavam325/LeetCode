https://leetcode.com/problems/maximum-width-of-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int getHeight(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int lht = getHeight(root->left);
    int rht = getHeight(root->right);

    return (max(lht, rht) + 1);
}


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        int height = getHeight(root);

        int nel = pow(2, height) - 1;

        vector<int> vec(nel, INT_MIN);

    }
};
