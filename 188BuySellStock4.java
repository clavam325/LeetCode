class Solution {
    public int maxProfit(int k, int[] prices) {
        
        if(prices.length == 0 || k == 0)
            return 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(k);
        int maxSum = 0, sumSoFar = 0;        
        int minVal = prices[0];
        
        for(int i = 1 ; i < prices.length ; i++) {
        	while(i < prices.length && prices[i] > prices[i-1]) {
        		i++;
        	}

        	int diff = prices[i-1] - minVal;
        	if(diff > 0) {
        		if(pq.size() >= k) {
        			pq.poll();
        		}
        		System.out.println("Adding " + diff);
        		pq.add(diff);
        	} 
        	
            if(i < prices.length)
        	    minVal = prices[i];
        }
            
        Iterator itr = pq.iterator();
        while(itr.hasNext()) {
            maxSum += pq.poll();
        }

        return maxSum;
    }
}