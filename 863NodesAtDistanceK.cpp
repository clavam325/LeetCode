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
    vector <int> ans;
    
    void printNodesDistanceKDown(TreeNode* root, int K) {
        if(root == NULL)
            return;
        
        if(K == 0) {
            ans.push_back(root->val);
            return;
        }

        printNodesDistanceKDown(root->left, K-1);
        printNodesDistanceKDown(root->right, K-1);
    }

    int distanceUtil(TreeNode* root, TreeNode* target, int K) {
        if(root == NULL)
            return -1;

        if(root == target) {
            printNodesDistanceKDown(root, K);
            return 0;
        }

        int valLeft = distanceUtil(root->left, target, K);
        if(valLeft != -1) {
            //Value found in left subTree
            if(valLeft + 1 == K)
                ans.push_back(root->val);
            else
                printNodesDistanceKDown(root->right, K-valLeft-2);
            return valLeft+1;
        }

        int valRight = distanceUtil(root->right, target, K);
        if(valRight != -1) {
            //Value found in left subTree
            if(valRight + 1 == K)
                ans.push_back(root->val);
            else
                printNodesDistanceKDown(root->left, K-valRight-2);
            return valRight+1;
        }

        return -1;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

        distanceUtil(root, target, K);
        return ans;
        
    }
};