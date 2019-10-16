class Solution {
    public boolean isMatch(String s, String p) {
        
        int slen = s.length();
        int plen = p.length();

        if(slen == 0)
        	return (plen == 0);

        boolean[][] lookup = new int[slen+1][plen+1];

        lookup[0][0] = true;

        for(int j = 1 ; j <= plen ; j++) {
        	if(p.charAt(j-1) == '*')
        		lookup[0][j] = lookup[0][j-1];
        }

        for(int i = 1 ; i <= slen ; i++) {
        	for(int j = 1 ; j <= plen ; j++) {

        		if(p.charAt(j-1) == '?' ||
        			p.charAt(j-1) == s.charAt(i-1))
        			lookup[i][j] = lookup[i-1][j-1];
        		else if(p.charAt(j-1) == '*') 
        			lookup[i][j] = lookup[i-1][j-1] || lookup[i-1][j] || lookup[i][j-1];
        		else
        			lookup[i][j] = false;

        	}
        }

        return lookup[slen][plen];
    }
}