package Codes.Arrays;

public class Containter_with_most_water {
	
}

class Solution {
    public int maxArea(int[] height) {
        int l = 0 ;
        int r = height.length - 1;
        int ans = 0 ;
        while(l < r){
            if(height[l] <= height[r]){
                ans = Math.max(ans, height[l] * (r-l));
                l++; 
            }else{
                ans = Math.max(ans, height[r] * (r-l));
                r--;
            }
        }
        return ans;
    }
}