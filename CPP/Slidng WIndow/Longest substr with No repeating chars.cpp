class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int j = 0;
		int i = 0;
		int n = s.size();
		int ans = 0;
		unordered_map<char, int> ump;

		while (j < n)
		{
			char curr = s[j];
			if (ump[curr] == 0)
			{
				ump[curr]++;
				ans = max(ans, j - i + 1);
				j++;
			}
			else
			{
				ump[s[i]]--;
				i++;
			}
		}

		return ans;
	}
};