class Solution
{
public:
	int findTargetSumWays(vector<int> &nums, int target)
	{

		// s1 + s2 = S
		// s1 - s2 = K
		// s1 = S+K / 2

		int sum = 0;
		for (auto i : nums)
		{
			sum += i;
		}

		int k = (sum + target) / 2;
		if (abs(target) > sum || (sum + target) % 2 != 0)
		{
			return 0;
		}

		int n = nums.size();
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

		dp[0][0] = 1;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)
			{ // handles the 0 condition
				if (nums[i - 1] <= j)
				{
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
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