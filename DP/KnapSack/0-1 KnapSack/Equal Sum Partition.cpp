class Solution
{
public:
	bool canPartition(vector<int> &nums)
	{
		int n = nums.size();
		if (n == 0)
		{
			return false;
		}

		long sum = 0;
		for (auto i : nums)
		{
			sum += i;
		}

		if (sum % 2 != 0)
		{
			return false;
		}
		int k = sum / 2;

		// subset sum problem

		vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));

		for (int i = 0; i <= n; i++)
		{
			dp[i][0] = true;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				if (nums[i - 1] <= j)
				{
					dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		return dp[n][k];
	}
};