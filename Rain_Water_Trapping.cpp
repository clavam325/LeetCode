//https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        vector<int> left(N,0), right(N,0);

    for(int i = 1 ; i < N ; i++)
        left[i] = max(left[i-1], height[i-1]);

    for(int j = N-2 ; j >= 0 ; j--)
        right[j] = max(right[j+1], height[j+1]);

    int sum = 0;

    for(int i = 0 ; i < N ; i++)
    {
        int tsum = 0;
        tsum = (min(left[i],right[i]) - height[i]);

        if(tsum < 0)
            tsum = 0;

        sum += tsum;
    }

    return sum;

    }
};
