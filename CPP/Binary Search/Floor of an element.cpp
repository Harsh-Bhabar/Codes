class Solution
{
public:
	int searchInsert(vector<int> &nums, int target)
	{
		int n = nums.size();
		if (nums[n - 1] < target)
		{
			return n;
		}
		if (nums[0] >= target)
		{
			return 0;
		}

		int l = 0;
		int r = n - 1;
		int ans = 0;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			if (nums[mid] > target)
			{
				r = mid - 1;
			}
			else
			{
				ans = mid;
				l = mid + 1;
			}
		}

		return ans + 1;
	}
};