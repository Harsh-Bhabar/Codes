class Solution
{
public:
	int totalFruit(vector<int> &fruits)
	{
		// longest substr having K unique chars, k=2
		int j = 0;
		int i = 0;
		int n = fruits.size();

		if (n <= 2)
		{ // base case
			return n;
		}

		map<int, int> mp;
		int ans = 0;

		while (j < n)
		{
			mp[fruits[j]]++;
			if (mp.size() == 2)
			{
				ans = max(ans, j - i + 1);
			}
			else if (mp.size() > 2)
			{
				while (mp.size() > 2)
				{
					mp[fruits[i]]--;
					if (mp[fruits[i]] == 0)
					{
						mp.erase(fruits[i]);
					}
					i++;
				}
			}
			j++;
		}

		// edge case -> [1, 1,1 ,1 1, 1]
		if (mp.size() == 1)
		{
			if (mp[fruits[0]] == n)
			{
				return n;
			}
		}

		return ans;
	}
};