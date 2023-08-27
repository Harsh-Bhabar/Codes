class Solution
{
public:
	bool wordBreak(string s, vector<string> &wordDict)
	{
		int sz = s.size();
		vector<bool> dp(sz + 1, 0);
		dp[0] = true;

		for (int i = 0; i <= sz; i++)
		{
			if (dp[i] == true)
			{
				for (auto str : wordDict)
				{
					int len = str.size();
					if (s.substr(i, len) == str)
					{
						dp[i + len] = true;
					}
				}
			}
		}

		return dp[sz];
	}
};