class Solution
{
public:
	int romanToInt(string s)
	{
		unordered_map<char, int> mp;
		mp['I'] = 1;
		mp['V'] = 5;
		mp['X'] = 10;
		mp['L'] = 50;
		mp['C'] = 100;
		mp['D'] = 500;
		mp['M'] = 1000;

		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int firstVal = mp[s[i]];
			if (i + 1 < s.size())
			{
				int secondVal = mp[s[i + 1]];
				if (firstVal < secondVal)
				{ // for cases like IV
					ans += secondVal - firstVal;
					i++;
				}
				else
				{
					ans += firstVal;
				}
			}
			else
			{
				ans += firstVal;
			}
		}

		return ans;
	}
};