//https://leetcode.com/problems/maximum-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* ConstructTree(vector<int>& nums, int start, int end)
{
    if(start > end)
        return NULL;

    int max_num = INT_MIN, max_i = -1;
    for(int i = start ; i <= end ; i++)
    {
        if(nums[i] > max_num)
        {
            max_num = nums[i];
            max_i = i;
        }
    }

    TreeNode *root = new TreeNode(max_num);

    root->left = ConstructTree(nums, start, max_i-1);
    root->right = ConstructTree(nums, max_i+1, end);

    return root;
}

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        TreeNode *root = ConstructTree(nums, 0, nums.size()-1);
        return root;
    }
};
