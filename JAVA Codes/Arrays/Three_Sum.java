package Codes.Arrays;

public class Three_Sum {
	
}

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        if(n < 3){
            return ans;
        }
        
        Arrays.sort(nums);
        
        for(int k=0; k<n-2; k++){
            if(k > 0 && nums[k-1] == nums[k]){
                continue;
            }
            int l = k+1;
            int r = n-1;
            while(l < r){
                int sum = nums[k] + nums[l] + nums[r];
                if(sum == 0){
                    ans.add(Arrays.asList(nums[k], nums[l], nums[r]));
                    while(l < r && nums[l] == nums[l+1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }
                else if(sum > 0){
                    r--;
                }else{
                    l++;
                }
            }
        }

        return ans;
    }
}