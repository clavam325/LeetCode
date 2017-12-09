//https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        if(nums.size() == 0)
            return 0;

        int ans = 0, sum = 0;
        map<int, int> maps;
        maps[0] = 1;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum += nums[i];

            if(maps.find(sum-k) != maps.end())
                ans += maps[sum-k];

            maps[sum]++;
        }

        return ans;
    }
};
