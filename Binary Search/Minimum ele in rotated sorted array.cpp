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

		while (l < r)
		{
			int mid = l + (r - l) / 2;
			// checking for sorted array, min will always be in unsorted
			if (nums[r] < nums[mid])
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}

		return nums[l];
	}
};