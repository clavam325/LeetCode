//https://leetcode.com/problems/shopping-offers/description/

int localCache = INT_MAX;

class Solution {
public:
    
    int priceNeeds( vector<int>& sp , vector<int>& ne)
    {
        int res = 0;
        for(int i = 0 ; i < sp.size() ; i++)
            res += sp[i] * ne[i];
        
        return res;
    }   
    
    bool sumVec( vector<int>& special, vector<int>& cur_vec, vector<int>& needs, bool plus)
    {
        for(int i = 0 ; i < cur_vec.size() ; i++)
        {
            if(plus)
                cur_vec[i] = needs[i] + special[i];
            else
                cur_vec[i] = needs[i] - special[i];
            
            if(cur_vec[i] > needs[i] || cur_vec[i] < 0)
                return false;
        }
        
        return true;
    }
    
    void showMeTheMoney( vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int index, int costTillNow )
    {
        if( index >= special.size() )
            return;
        
        for( int i = index ; i < special.size() ; i++ )
        {
            vector<int> temp(needs.size() , 0) ;
            
            if( !sumVec( special[i] , temp, needs, false) )
                continue;
            
            //Add cost for this Special Offer
            localCache = min( localCache, costTillNow + special[i][special[i].size()-1] + priceNeeds(price, temp) );
            
            //Added the Offer i in this run, Retain the index, add the cost, send the updated needs.
            showMeTheMoney( price, special, temp, index, costTillNow + special[i][special[i].size()-1] );
            
            //Didn't add Offer i, Needs remains same, CostTillNow is same.
            showMeTheMoney( price, special, needs, index + 1, costTillNow );
        }
    }
    
    int shoppingOffers( vector<int>& price, vector<vector<int>>& special, vector<int>& needs ) {
               
        localCache = 0;
        for(int i = 0 ; i < price.size() ; i++)
        {
            localCache += price[i] * needs[i];
        }
        
        int index = 0;
        int costTillNow = 0;
        
        showMeTheMoney( price, special, needs, index, costTillNow );
        
        return localCache;
        
    }
};