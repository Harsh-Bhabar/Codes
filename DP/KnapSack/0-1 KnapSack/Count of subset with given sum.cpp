int mod = 1e9 + 7;
int perfectSum(int nums[], int n, int target)
{
	vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= target; j++)
		{ // starting from zero, since there can be ZERO in list
			if (nums[i - 1] <= j)
			{
				dp[i][j] = ((dp[i - 1][j] % mod) + (dp[i - 1][j - nums[i - 1]] % mod)) % mod;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] % mod;
			}
		}
	}

	return dp[n][target] % mod;
}