class Solution
{
public:
	int longestConsecutive(vector<int> &nums)
	{
		unordered_map<int, bool> mp;

		for (auto it : nums)
		{
			mp[it] = true;
		}

		for (auto it : nums)
		{
			if (mp.find(it - 1) != mp.end())
			{
				mp[it] = false;
			}
		}

		int cnt = 0;
		int ans = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (mp[nums[i]] == true)
			{
				cnt = 1;
				int j = 1;
				while (mp.find(nums[i] + j) != mp.end())
				{
					cnt++;
					j++;
				}
			}
			ans = max(ans, cnt);
		}

		return ans;
	}
};