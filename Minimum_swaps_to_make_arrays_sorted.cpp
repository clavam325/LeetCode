//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        
        vector< vector<int>> vec(A.size(), vector<int>(2,0));
        
        vec[0][0] = 0;
        vec[0][1] = (A[0] == B[0]) ? 0 : 1;
        
        for(int i = 0 ; i < A.size()-1 ; i++)
        {
            if( (A[i+1] > A[i]) && (A[i+1] > B[i])
              && (B[i+1] > A[i]) && (B[i+1] > B[i]))
            {
                //Sequences are already sorted before or after any swapping. Find the min we can get at this point.
                vec[i+1][0] = min(vec[i][0], vec[i][1]);
                vec[i+1][1] = min(vec[i][0], vec[i][1]) + 1;
            }
            else if( (A[i+1] > B[i]) && (B[i+1] > A[i]))
            {
                //We need a swap to get the sorted Order.
                //If we don't swap at (i+1) , we should have at i.
                //If we swap at (i+1) , we shouldn't have at i.
                vec[i+1][0] = vec[i][1];
                vec[i+1][1] = vec[i][0] + 1;
            }
            else
            {
                // There are equal numbers somewhere.
                // If there are equal numbers in same sequence, swap is required.
                // If there are equal numbers in diff sequence, we can't swap.
                if(A[i+1] == A[i] || B[i+1] == B[i])
                {
                    vec[i+1][0] = vec[i][1];
                    vec[i+1][1] = vec[i][0] + 1;
                }
                else
                {
                   vec[i+1][0] = vec[i][0];
                   vec[i+1][1] = vec[i][1] + 1;
                }
            }
        }
        
        return min(vec[A.size()-1][0], vec[A.size()-1][1]);
        
    }
};