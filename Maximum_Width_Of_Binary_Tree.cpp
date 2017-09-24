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

void fillVec(TreeNode *root, vector<int>& vec, int index)
{
  if(root == NULL)
    return;

  vec[index] = root->val;

  fillVec(root->left,  vec, 2*index + 1);
  fillVec(root->right, vec, 2*index + 2);
}

int calcMaxWidth(vector<int> vec, int height)
{
      int cur_width = INT_MIN, max_width = INT_MIN;
      int start = 0;
      for(int levels = 0 ; levels < height ; levels++)
      {
          int nel = pow(2, level);
          int fi = -1, li = -1;
          for(int i = start; i < start+nel ; i++)
          {
              if(vec[i] != INT_MIN && fi == -1)
                    fi = i;
              else if(vec[i] != INT_MIN)
                    li = i;
          }

          if(li != -1)
            cur_width = li - fi + 1;
          else if(fi != -1)
            cur_width = 1;

          max_width = max(cur_width, max_width);
          start = start + nel;
      }

      return max_width;
}

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        int height = getHeight(root);
        int nel = pow(2, height) - 1;
        vector<int> vec(nel, INT_MIN);
        int index = 0;

        fillVec(root, vec, index);

        return calcMaxWidth(vec, height);
    }
};
