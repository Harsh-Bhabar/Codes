bool isSubsetSum(vector<int>nums, int sum){
        int n = nums.size();
        if(sum == 0 and (n != 0 or n == 0)){
            return true;
        }
        if(n ==0 and sum != 0){
            return false;
        }
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    
        for(int i=0; i<=n; i++){
            dp[i][0] = true;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
        
    }