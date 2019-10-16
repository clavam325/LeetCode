#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        vector<int> lis(nums.size(), 1);
        int maxVal = 1;

        for(int i = 1 ; i < nums.size() ; i++) {
            for(int j = i-1 ; j >= 0 ; j--) {

                if(nums[j] < nums[i]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                    maxVal = max(maxVal, lis[i]);
                }
            }
        }

        return maxVal;
    }

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(10);
    vec.push_back(5);
    vec.push_back(6);
    cout << lengthOfLIS(vec);
    return 0;
}
