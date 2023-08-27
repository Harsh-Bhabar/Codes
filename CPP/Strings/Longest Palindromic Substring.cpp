class Solution
{
public:
	string longestPalindrome(string s)
	{
		if (s.size() <= 1)
		{
			return s;
		}

		int cnt = 0;
		int len = 0;
		int palstart = 0;
		int n = s.size();

		for (int k = 0; k < n; k++)
		{
			// odd len
			cnt = 1;
			int tempstart = k;
			int l = k - 1;
			int r = k + 1;
			while (l >= 0 and r < n and s[l] == s[r])
			{
				cnt += 2;
				tempstart = l;
				l--;
				r++;
			}
			if (cnt > len)
			{
				len = cnt;
				palstart = tempstart;
			}

			// odd len
			if (k > 0 and s[k - 1] == s[k])
			{
				tempstart = k - 1;
				int l = k - 2;
				int r = k + 1;
				cnt = 2;
				while (l >= 0 and r < n and s[l] == s[r])
				{
					cnt += 2;
					tempstart = l;
					l--;
					r++;
				}
				if (cnt > len)
				{
					len = cnt;
					palstart = tempstart;
				}
			}
		}

		return s.substr(palstart, len);
	}
};