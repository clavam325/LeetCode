class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int l1 = nums1.size();
        int l2 = nums2.size();

        int start = 0, end = l1;

        while( start <= end ) {

        	int partitionX = (start + end)/2;
        	int partitionY = (l1 + l2 + 1)/2 - partitionX;

        	int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
        	int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];

        	int minRightX = (partitionX == l1) ? INT_MAX : nums1[partitionX];
        	int minRightY = (partitionY == l2) ? INT_MAX : nums2[partitionY];

        	if(maxLeftX <= minRightY && maxLeftY <= minRightX) {

        		if((l1 +l2) %2 == 0) {
        			return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
        		} else
        		return max(maxLeftX, maxLeftY);

        	}
        	else if( maxLeftX > minRightY) {
        		end = partitionX - 1;
        	}
        	else
        		start = partitionX + 1;


        }

        return -1;
        
    }
};