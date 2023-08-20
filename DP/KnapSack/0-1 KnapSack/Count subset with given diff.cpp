int countPartitions(int n, int d, vector<int> &nums)
{
	// Code here
	// s1 - s2 = d
	// s1 + s2 = sum
	// s1 = d + sum / 2
	int mod = 1e9 + 7;
	long sum = 0;
	for (auto n : nums)
	{
		sum += n;
	}

	if (abs(d) > sum || (d + sum) % 2 != 0)
	{
		return 0;
	}

	long k = (d + sum) / 2;

	vector<vector<long>> dp(n + 1, vector<long>(k + 1, 0));
	dp[0][0] = 1;

	for (long i = 1; i <= n; i++)
	{
		for (long j = 0; j <= k; j++)
		{
			if (nums[i - 1] <= j)
			{
				dp[i][j] = ((dp[i - 1][j] % mod) + (dp[i - 1][j - nums[i - 1]] % mod)) % mod;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j]) % mod;
			}
		}
	}

	return dp[n][k] % mod;
}