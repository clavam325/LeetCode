//https://leetcode.com/problems/valid-triangle-number/description/

class Solution {
public:

    bool isTriangle(int a, int b, int c)
    {
       if((a+b > c) && (a+c > b) && (b+c > a))
           return true;
        return false;
    }

    int binSearch(vector<int>& nums, int val1, int val2, int start, int end)
    {
        int ret = start-1;
        int mid;

        while(start <= end)
        {
            mid = (start+end)/2;

            if(isTriangle(val1, val2, nums[mid]))
            {
                start = mid+1;
                ret = mid;
            }
            else
            {
                end = mid-1;
            }
        }

        return ret;
    }

    int triangleNumber(vector<int>& nums) {

        int triangleCount = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i+1 ; j < nums.size() ; j++)
            {
                int k = binSearch(nums, nums[i], nums[j], j+1, nums.size()-1);

                triangleCount += (k-j > 0) ? (k-j) : 0;
            }
        }

        return triangleCount;

    }
};
