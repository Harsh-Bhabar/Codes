class Solution
{
public:
	int kadanes(vector<int> &nums)
	{
		int curr = nums[0];
		int ans = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			curr = max(nums[i], curr + nums[i]);
			ans = max(ans, curr);
		}
		return ans;
	}

	int maxSubarraySumCircular(vector<int> &nums)
	{
		if (nums.size() == 1)
		{
			return nums[0];
		}

		// case 1 when max subarray lies on one side and no circluar
		int maSumSubarray = kadanes(nums);
		int total = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			total += nums[i];
			nums[i] = -1 * nums[i];
		}

		// case 2 when circular
		int negMaxSumSubarray = kadanes(nums);
		// from total subtract the maxSubarry of inverted array
		int neg = total - (-1 * negMaxSumSubarray);

		if (neg == 0)
		{ // to check for cases like [-1 -2 -3]
			return maSumSubarray;
		}
		return max(maSumSubarray, neg);
	}
};