long maximumSumSubarray(int k, vector<int> &nums , int n){
        if(n == 0){
            return 0;
        }
        int i = 0;
        int j = 0;
        long sum = 0;
        long ans = 0;
        while(j < n){
            sum += nums[j];
            if(j-i+1 < k){ // when window size is smaller
                j++;
            }
            else if(j-i+1 == k){ // when window size is reached
                ans = max(ans, sum);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        
        return ans;
    }