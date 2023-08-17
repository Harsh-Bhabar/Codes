class Solution
{
public:
	vector<int> findAnagrams(string s, string p)
	{
		int psize = p.size();
		int ssize = s.size();
		vector<int> ans;

		if (psize > ssize)
		{
			return ans;
		}

		vector<int> freqS(26, 0);
		vector<int> freqP(26, 0);

		for (auto c : p)
		{
			freqP[c - 'a']++;
		}

		int i = 0;
		int j = 0;

		while (j < ssize)
		{
			freqS[s[j] - 'a']++;
			if (j - i + 1 == psize)
			{
				if (freqP == freqS)
				{
					ans.push_back(i);
				}
				freqS[s[i] - 'a']--;
				i++;
			}
			j++;
		}

		return ans;
	}
};