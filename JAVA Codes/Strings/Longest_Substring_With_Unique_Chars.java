package Codes.Strings;

public class Longest_Substring_With_Unique_Chars {
	
}

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0 ;
        int i = 0;
        int j = 0;
        int n = s.length();
        Map<Character, Integer> map = new HashMap<>();

        while(j < n){
            if(map.getOrDefault(s.charAt(j), 0) == 0){
                map.put(s.charAt(j), map.getOrDefault(s.charAt(j), 0)+1);
                ans = Math.max(ans, j-i+1);
                j++;
            }else{
                map.put(s.charAt(i), map.get(s.charAt(i))-1);
                i++;
            }
        }

        return ans;
    }
}