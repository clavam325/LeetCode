class Solution {
    private HashMap<Character, Integer> map = new HashMap<>();
    private HashMap<Character, Integer> sourceMap = new HashMap<>();

    boolean suffices() {
        for (Map.Entry<Character, Integer> entry : map.entrySet())
        {
            if(!sourceMap.containsKey(entry.getKey()))
                return  false;

            if(sourceMap.get(entry.getKey()) < entry.getValue())
                return false;
        }; 

        return true;
    }
    public String minWindow(String s, String t) {
        
    	String ans = "";
        if(t.length() > s.length())
        	return "";

        

        for(int i = 0 ; i < t.length() ; i++) {
            Character c = t.charAt(i);
        	if(map.containsKey(c))
        		map.put(c, map.get(c)+1);
        	else
        		map.put(c,1);
        };

        int start = 0, end = 0;
        while(start <= end && end < s.length()) {

            String str = s.substring(start, end+1);
            //If current substring encapsulated the String t, increment start
            if( suffices()) {
                if(str.length() < ans.length() || ans == "")
                    ans = str;

                Character c = s.charAt(start);
                if(sourceMap.containsKey(c))
                    sourceMap.put(c, map.get(c)-1);
                start++;
                
            } else {
                //Else means we are missing something, need to increment
                Character c = s.charAt(end);
                if(sourceMap.containsKey(c))
                    sourceMap.put(c, sourceMap.get(c)+1);
                else
                    sourceMap.put(c, 1);

                end++;
            }
        }
        
        return ans;
    }
}