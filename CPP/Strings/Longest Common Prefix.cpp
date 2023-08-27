class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs)
	{

		if (strs.size() == 0)
		{
			return "";
		}

		int minEleSize = INT_MAX;
		string ans = "";

		for (auto s : strs)
		{
			if (s.size() < minEleSize)
			{ // find minimum element size
				minEleSize = s.size();
			}
		}

		for (int i = 0; i < minEleSize; i++)
		{
			bool isSame = true;
			for (int j = 0; j < strs.size() - 1; j++)
			{ // check character by character for each word
				if (strs[j][i] != strs[j + 1][i])
				{
					isSame = false;
				}
			}
			if (isSame)
			{
				ans += strs[0][i];
			}
			else
			{
				return ans;
			}
		}

		return ans;
	}
};