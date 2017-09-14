//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map <char, int> hash;

        int len = 0, max_len = 0;
        int prev_num = 0;

        for(int i = 0 ; i < s.length() ; i++)
        {
            if(hash.find(s[i]) == hash.end())
                len++;
            else
            {
                int num = hash[s[i]];
                for(int j = prev_num ; j <= num ; j++)
                    hash.erase(s[j]);

                len = len - (num - prev_num);
                prev_num = num+1;
            }

            hash[s[i]] = i;
            max_len = max(len , max_len);
        }

        return max_len;

    }
};
