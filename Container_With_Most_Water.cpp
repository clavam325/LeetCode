//https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {

        int max_num = 0;
        int leftIndex = 0, rightIndex = height.size()-1;

        while(leftIndex < rightIndex)
        {
            max_num = max(max_num , min(height[leftIndex], height[rightIndex]) * (rightIndex - leftIndex));

            if(height[leftIndex] < height[rightIndex])
                leftIndex++;
            else
                rightIndex--;
        }

        return max_num;
    }
};
