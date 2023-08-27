#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k)
{
	int ans = 0;
	int sum = 0;
	unordered_map<int, int> mp; // sum , indexes

	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		if (sum == k)
		{
			ans = max(ans, i + 1);
		}

		int rem = sum - k; // means we've got this before as well
		if (mp.find(rem) != mp.end())
		{ // after that index to here
			ans = max(ans, i - mp[rem]);
		}

		if (mp.find(sum) == mp.end())
		{
			mp[sum] = i;
		}
	}

	return ans;
}