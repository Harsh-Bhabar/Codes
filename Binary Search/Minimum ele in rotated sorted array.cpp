class Solution
{
public:
	int findMin(vector<int> &nums)
	{
		int n = nums.size();
		if (n == 1)
		{
			return nums[0];
		}

		int l = 0;
		int r = n - 1;

		if (nums[l] < nums[r])
		{
			return nums[l];
		}

		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			int prev = (mid - 1 + n) % n;
			int next = (mid + 1) % n;
			// min ele will always be smaller than its neightbor
			if (nums[prev] >= nums[mid] && nums[mid] <= nums[next])
			{
				return nums[mid];
			}
			// checking for sorted array, min will always be in unsorted
			if (nums[r] <= nums[mid])
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}

		return 0;
	}
};