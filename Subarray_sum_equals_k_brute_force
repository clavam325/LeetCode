//https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        if(nums.size() == 0)
            return 0;

        int ans = 0;

        vector<int> partial_sum(nums.size(), nums[0]);

        for(int i = 1 ; i < nums.size() ; i++)
            partial_sum[i] = partial_sum[i-1] + nums[i];


        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i ; j < nums.size() ; j++)
            {
                if( partial_sum[j] - partial_sum[i] + nums[i] == k)
                    ans++;
            }
        }


        return ans;

    }
};
