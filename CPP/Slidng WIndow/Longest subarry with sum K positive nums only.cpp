#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k)
{
	int n = nums.size();
	if (n == 0)
	{
		return 0;
	}

	int j = 0;
	int i = 0;
	long long sum = 0;
	int ans = 0;

	while (j < n)
	{
		sum += nums[j];
		if (sum < k)
		{
			j++;
		}
		else if (sum == k)
		{
			ans = max(ans, j - i + 1);
			j++;
		}
		else if (sum > k)
		{
			while (sum > k)
			{
				sum -= nums[i];
				i++;
			}
			if (sum == k)
			{
				ans = max(ans, j - i + 1);
			}
			j++;
		}
	}

	return ans;
}