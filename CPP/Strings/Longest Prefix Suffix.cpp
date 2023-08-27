int lps(string s)
{
	// Your code goes here
	int n = s.size();
	if (n == 0)
	{
		return 0;
	}
	vector<int> lps(n, 0);
	int i = 1;
	int prevLps = 0;

	while (i < n)
	{
		if (s[i] == s[prevLps])
		{
			lps[i] = prevLps + 1;
			i++;
			prevLps++;
		}
		else
		{
			if (prevLps == 0)
			{
				i++;
			}
			else
			{
				prevLps = lps[prevLps - 1];
			}
		}
	}

	return lps.back();