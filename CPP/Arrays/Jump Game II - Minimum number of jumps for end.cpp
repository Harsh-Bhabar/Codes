class Solution
{
public:
	int jump(vector<int> &nums)
	{
		int n = nums.size();
		if (n == 1)
			return 0;

		int cnt = 1;
		int maxjump = nums[0];
		int curr = nums[0];

		for (int i = 1; i < n - 1; i++)
		{
			maxjump = max(maxjump, i + nums[i]);
			if (i == curr)
			{
				curr = maxjump;
				cnt++;
			}
		}

		return cnt;
	}
};