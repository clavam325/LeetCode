class Solution {
    public int rob(int[] nums) {
        
        int inclLeft = 0, exclLeft = 0, inclRight = 0, exclRight = 0;

        for(int i = 0 ; i < nums.length ; i++ ) {
        	exclLeft += Math.max(inclLeft, exclLeft);
        	inclLeft += nums[i] + exclLeft;
        }

        for(int i = nums.length-1 ; i >= 0  ; i-- ) {
        	exclRight += Math.max(inclRight, exclRight);
        	inclRight += nums[i] + exclRight;
        }

        if(inclRight == inclLeft) {
        	return Math.max(exclRight, exclLeft);
        } else {
        	return Math.max( Math.max(inclLeft , inclRight) , Math.max(exclRight, exclLeft) );
        }
    }
}