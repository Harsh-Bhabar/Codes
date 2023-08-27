package Codes.Arrays;

public class Maximum_Subarray_sum {
	
}

class Solution {

    int Kadanes(int[] nums){
        int curr = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.length; i++){
            curr = Math.max(nums[i], curr+nums[i]);
            ans = Math.max(curr, ans);
        }

        return ans;
    }

    public int maxSubArray(int[] nums) {
        return Kadanes(nums);
    }
}