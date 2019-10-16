#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int index(vector<int> vec, int low, int high, int key) {

    while(high > low){
        int mid = low + (high-low)/2;

        if(vec[mid] >= key)
            high = mid;
        else
            low = mid+1;
    }
    return high;
}

int lengthOfLIS(vector<int>& nums) {

    if(nums.size() == 0)
        return -1;

    vector<int> lis(nums.size(), 0);
    lis[0] = nums[0];
    int length = 1;

    for(int i = 1; i < nums.size() ; i++) {

        //New smallest element
        if(nums[i] < lis[0]) {
            lis[0] = nums[i];
        }
        //Largest element adds to the largest list
        else if(nums[i] > lis[length-1]) {
            lis[length++] = nums[i];
        }
        else {
            lis[index(lis, 0, length-1, nums[i])] = nums[i];
        }
    }

    return length;
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
