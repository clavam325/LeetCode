//https://leetcode.com/problems/maximum-swap/

class Solution {
public:
    int maximumSwap(int num) {
        
        vector<int> vec;
        int tempa = num;
        int temp;
        int ans = 0;
        
        while(num > 0)
        {
            temp = num%10;
            vec.push_back(temp);
            num /= 10;
        }
        
        reverse(vec.begin(), vec.end());
        vector<int> count(vec.size(), vec.size()-1);
        int max_num = vec.size()-1;
        bool swap = false;
        
        for(int i = vec.size()-2 ; i >= 0 ; i--)
        {
            if(vec[max_num] >= vec[i])
            {
                count[i] = max_num;
                swap = true;
            }
            else
            {
                max_num = i;
                count[i] = i;
            }
        }
        
        if(!swap)
            return tempa;
        
        for(int i = 0 ; i < count.size() ; i++)
        {
            if(count[i] != i && vec[i] != vec[count[i]])
            {
                int tmp = vec[i];
                vec[i] = vec[count[i]];
                vec[count[i]] = tmp;
                break;
            }
        }
        

        for(int i = vec.size()-1 ; i >= 0 ; i--)
            ans = ans + vec[i]*pow(10,vec.size()-1-i);
        
        return ans;
    }
};