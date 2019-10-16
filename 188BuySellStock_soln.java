class Solution {
    public int maxProfit(int k, int[] prices) {

    	if(prices.length == 0)
    		return 0;

    	int n = prices.length;
    	int[][] profit = new int[k+1][n];

    	for( int i = 0 ; i <= k ; i++ ) {

    		int prevDiff = Integer.MIN_VALUE;
    		for( int j = 0 ; j < n ; j++ ) {

    			if( i == 0 || j == 0 ) {
    				profit[i][j] = 0;
    			} else {
    				prevDiff = Math.max(prevDiff, profit[i-1][j-1] - prices[j-1]);
    				profit[i][j] = Math.max(profit[i][j-1], prices[j] + prevDiff);
    			}
    		}
    	}

    	return profit[k][n-1];
    }
}