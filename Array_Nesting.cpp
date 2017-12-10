//https://leetcode.com/problems/array-nesting/description/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        vector<int> listSize(nums.size() , -1);
        map<int,int> maps;
        int maxSize = INT_MIN;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(listSize[i] == -1)
            {
                //Fill the map
                int index = i;
                while(maps.find(index) == maps.end())
                {
                    maps[index] = nums[index];
                    index       = nums[index];
                }

                listSize[i] = maps.size();
                maxSize = max(maxSize, listSize[i]);

                //Clear the map
                map<int,int>:: iterator it;
                for(it = maps.begin() ; it != maps.end() ; it++)
                {
                    listSize[it->second] = listSize[i];
                }
                maps.clear();
            }
        }

        return maxSize;

    }
};
