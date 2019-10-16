class Solution {
public:

	int search(std::vector<int>& nums, int lo, int hi, int target) {

		while(lo <= hi) {
			int mid = lo + (hi-lo)/2;

			if(nums[mid] == target)
				return mid;
			else if(nums[mid] > target)
				lo = mid-1;
			else
				hi = mid+1;
		}

		return -1;
	}

	int findPivot(std::vector<int>& nums) {

		int lo = 0, hi = nums.size()-1, mid;

		while(lo <= hi) {
			mid = lo + (hi-lo)/2;

			if(mid > 0 && nums[mid] < nums[mid-1])
				return mid;
			else if(nums[lo] > nums[mid])
				hi = mid-1;
			else
				lo = mid+1;
		}

		return 0;
	}

    int search(vector<int>& nums, int target) {
        
        int pivot = findPivot(nums);

        if(target >= nums[0]) {
        	return search(nums, 0, pivot-1, target);
        }
        return search(nums, pivot, nums.size()-1, target);
    }
};