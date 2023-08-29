package Codes.Recursion;

public class Combination_Sum {
	
}

class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    void solve(int[] nums, int i, int target, List<Integer> temp){
        if(i == nums.length){
            if(target == 0){
                ans.add(new ArrayList<>(temp));
            }
            return;
        }
        if(nums[i] <= target){
            temp.add(nums[i]);
            solve(nums, i, target-nums[i], temp);
            temp.remove(temp.size() - 1);
        }
        solve(nums, i+1, target, temp);
    }

    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<Integer> temp = new ArrayList<>();
        solve(nums, 0, target, temp);
        return ans;    
    }
}

