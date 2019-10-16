#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    dequeue<int> deq;
    vector<int> window;
    int maxVal = INT_MIN, count = 0;

    for(int i = 0 ; i < nums.size() ; i++) {

        if(deq.size() < k){
            deq.push_back(nums[i]);
            if(nums[i] > maxVal) {

            }
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
