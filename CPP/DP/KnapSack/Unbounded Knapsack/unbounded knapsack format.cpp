int knapSack(int N, int W, int val[], int wt[])
{
	// code here
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (wt[i - 1] <= j)
			{
				// max( not taking , can take the same again )
				dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[N][W];
}