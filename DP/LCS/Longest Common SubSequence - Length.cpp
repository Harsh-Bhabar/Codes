class Solution
{
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		int m = text1.size();
		int n = text2.size();

		if (m == 0 or n == 0)
		{
			return 0;
		}

		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (text1[i - 1] == text2[j - 1])
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		return dp[m][n];
	}
};