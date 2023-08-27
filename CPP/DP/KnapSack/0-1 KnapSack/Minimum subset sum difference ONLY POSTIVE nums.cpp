class Solution
{
public:
	int minimumDifference(vector<int> &nums)
	{

		int sum = 0;
		for (auto n : nums)
		{
			sum += n;
		}

		int n = nums.size();
		vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));

		for (int i = 0; i <= n; i++)
		{
			dp[i][0] = 1;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= sum / 2; j++)
			{
				if (nums[i - 1] <= j)
				{
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		int mx = -1;
		for (int j = sum / 2; j >= 0; j--)
		{
			if (dp[n][j] == 1)
			{
				mx = j;
				break;
			}
		}

		return sum - 2 * mx;
	}
};