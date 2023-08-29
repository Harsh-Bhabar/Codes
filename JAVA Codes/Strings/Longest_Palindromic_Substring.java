package Codes.Strings;

public class Longest_Palindromic_Substring {
	
}

class Solution {
    public String longestPalindrome(String s) {
        
        int startans = 0;
        int charcnt = 0;
        int n = s.length();

        for(int k=0; k<n; k++){
            // odd len pal
            int cnt = 1;
            int tempstart = k;        
            int i = k-1; 
            int j = k+1;
            while(i >= 0 && j < n && s.charAt(i) == s.charAt(j)){
                cnt += 2;
                tempstart = i;
                i--;
                j++;
            }
            if(cnt > charcnt){
                charcnt = cnt;
                startans = tempstart;
            }

            // even len pal
            if(k > 0 && k < n && s.charAt(k-1) == s.charAt(k)){
                cnt = 2;
                tempstart = k-1;        
                i = k-2; 
                j = k+1;
                while(i >= 0 && j < n && s.charAt(i) == s.charAt(j)){
                    cnt += 2;
                    tempstart = i;
                    i--;
                    j++;
                }
                if(cnt > charcnt){
                    charcnt = cnt;
                    startans = tempstart;
                }
            }
        }

        return s.substring(startans, startans+charcnt);

    }
}