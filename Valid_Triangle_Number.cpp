//https://leetcode.com/problems/valid-triangle-number/description/

class Solution {
public:

    bool isTriangle(int a, int b, int c)
    {
       if((a+b>c) && (a+c>b) && (b+c>a))
           return true;
        return false;
    }

    int triangleNumber(vector<int>& nums) {

        int triangleCount = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i+1 ; j < nums.size() ; j++)
            {
                for(int k = j+1 ; k < nums.size() ; k++)
                {
                    if(isTriangle(nums[i], nums[j],nums[k]))
                        triangleCount++;
                    else
                        break;
                }
            }
        }

        return triangleCount;

    }
};
