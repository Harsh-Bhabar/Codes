class Solution
{
public:
	int rob(vector<int> &nums)
	{
		int n = nums.size();
		if (n == 1)
			return nums[0];

		int ans = 0;
		int p1 = 0;
		int p2 = 0;

		for (int i = 0; i < n; i++)
		{
			int curr = max(nums[i] + p2, p1);
			ans = max(ans, curr);
			p2 = p1;
			p1 = curr;
		}

		return ans;
	}
};