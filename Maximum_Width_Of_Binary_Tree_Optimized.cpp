//https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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

void fillVec(TreeNode *root, int index, int level, vector<vector<int> >& vec)
{
  if(root == NULL)
    return;

  if(vec[level][0] == -1)
  {
    vec[level][0] = index;
    vec[level][1] = index;
  }
  else
    vec[level][1] = index;

  fillVec(root->left , 2*index+1, level+1, vec);
  fillVec(root->right, 2*index+2, level+1, vec);
}

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        int height = getHeight(root);
        vector<vector<int> > vec(height, vector<int> (2,-1));

        fillVec(root, 0, 0, vec);

        int max_ans = 0, cur_ans;

        for(int i = 0 ; i < height ; i++)
        {
          cur_ans = vec[i][1] - vec[i][0] + 1;
          max_ans = max(cur_ans, max_ans);
        }

        return max_ans;
    }
};
