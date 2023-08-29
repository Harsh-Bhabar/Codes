package Codes.Strings;

public class Group_anagrams {
	
}


class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for(String s : strs){
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String sb = new String(chars);

            if(!map.containsKey(sb)){
                map.put(sb, new ArrayList<String>());
            }
            map.get(sb).add(s);
        }

        List<List<String>> ans = new ArrayList<>(map.values());

        return ans;

    }
}