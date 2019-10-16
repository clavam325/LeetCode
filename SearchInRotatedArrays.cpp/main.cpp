#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
	int search(std::vector<int>& nums, int lo, int hi, int target) {

		while(lo <= hi) {

			int mid = lo + (hi-lo)/2;
            //cout << "lo " << lo << " | hi" << hi << " | mid" << mid << endl;

			if(nums[mid] == target)
				return mid;
			else if(nums[mid] > target)
				hi = mid-1;
			else
				lo = mid+1;
		}

		return -1;
	}

	int findPivot(std::vector<int>& nums) {

		int lo = 0, hi = nums.size()-1, mid;

		while(lo < hi) {
 		    mid = (lo + hi)/2;

            if(nums[mid] > nums[hi])
                lo = mid+1;
            else
                hi = mid;
		}

		return lo;
	}

    int search(vector<int>& nums, int target) {

        int pivot = findPivot(nums);
        //cout << "Pivot is " << pivot << endl;

        if(target == nums[pivot])
            return pivot;

        if(nums[pivot] <= target && nums[nums.size()-1] >= target)
            return search(nums, pivot, nums.size()-1, target);
        else
            return search(nums, 0, pivot-1, target);
    }

  */



	int search(std::vector<int>& nums, int lo, int hi, int target) {

		while(lo <= hi) {

			int mid = lo + (hi-lo)/2;
            //cout << "lo " << lo << " | hi" << hi << " | mid" << mid << endl;

			if(nums[mid] == target)
				return mid;
			else if(nums[mid] > target)
				hi = mid-1;
			else
				lo = mid+1;
		}

		return -1;
	}

	int findPivot(vector<int>& nums) {
		int lo = 0, hi = nums.size()-1;

		while(lo < hi) {
			if(nums[lo] < nums[hi])
				return lo;

            int mid = (lo+hi)/2;

			if(nums[mid] >= nums[lo])
				lo = mid+1;
			else
				hi = mid;
		}

		return lo;
	}

	int search(vector<int>& nums, int target) {

        int pivot = findPivot(nums);

        cout << "Pivot is " << pivot << endl;

        if(target == nums[pivot])
            return pivot;

        if(nums[pivot] <= target && nums[nums.size()-1] >= target)
            return search(nums, pivot, nums.size()-1, target);
        else
            return search(nums, 0, pivot-1, target);
    }



int main()
{
    vector<int> vec;
    //vec.push_back(3);
    vec.push_back(4);
    cout << "Pivot sda " << endl;

    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    cout << search(vec, 0);


    return 0;
}
