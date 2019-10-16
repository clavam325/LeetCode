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
    unordered_map<TreeNode*, int> map;
    vector<int> ans;
    int find(TreeNode* root, TreeNode* target) {
        if(root == NULL)
            return -1;
        
        if(root == target){
            map[root] = 0;
            return 0;
        }
        
        int dl = find(root->left, target);
        if(dl >= 0) {
            map[root] = dl+1;
            return dl+1;
        }

        int dr = find(root->right, target);
        if(dr >= 0) {
            map[root] = dr+1;
            return dr+1;
        }

        return -1;
    }

    void dfs(TreeNode* root, TreeNode* target, int length, int K) {

        if(root == NULL)
            return;

        if(map.find(root) != map.end()) length = map[root];

        if(length == K) {
            ans.push_back(root->val);
        }

        dfs(root->left, target, length+1, K);
        dfs(root->right, target, length+1, K);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        find(root, target);
        dfs(root, target, map[root], K);
        return ans;
    }
};