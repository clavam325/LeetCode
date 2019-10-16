//https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    
    void recur(vector<int>& nums, vector<int>& output, int pre_sum, int& post_sum, int index)
    {
        if(index == nums.size())
            return;
        
        recur(nums, output, pre_sum*nums[index], post_sum, index+1);
        output[index] = pre_sum*post_sum;
        post_sum = post_sum*nums[index];
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> output(nums.size(), 0 );
        int pre_sum = 1, post_sum = 1;
        int index = 0;
        
        recur(nums, output, pre_sum, post_sum, index);
        
        return output;
        
    }
};