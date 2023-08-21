int cutRod(int price[], int n)
{
	vector<int> len;
	for (int i = 1; i <= n; i++)
	{
		len.push_back(i);
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (len[i - 1] <= j)
			{
				dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - len[i - 1]]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][n];
}