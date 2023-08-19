class Solution
{
public: // O(n+m)
	vector<int> computeLPS(string s, int n)
	{
		vector<int> lps(n, 0);
		int prevLps = 0;
		int i = 1;

		while (i < n)
		{
			if (s[i] == s[prevLps])
			{
				lps[i] = prevLps + 1;
				prevLps += 1;
				i += 1;
			}
			else
			{
				if (prevLps == 0)
				{
					lps[i] = 0;
					i += 1;
				}
				else
				{
					prevLps = lps[prevLps - 1];
				}
			}
		}

		return lps;
	}

	int strStr(string haystack, string needle)
	{
		int n = haystack.size();
		int m = needle.size();

		vector<int> lps = computeLPS(needle, m);

		int i = 0;
		int j = 0;

		while (i < n)
		{
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				if (j == 0)
				{ // means no prefix-suffix match for this char at i of haystack
					i++;
				}
				else
				{
					j = lps[j - 1];
				}
			}
			if (j == m)
			{ // traversed all the elements of lps array
				return i - m;
			}
		}

		return -1;
	}
};