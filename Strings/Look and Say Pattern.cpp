string lookandsay(int n)
{
	if (n == 1)
	{
		return "1";
	}
	if (n == 2)
	{
		return "11";
	}

	string s = "11";

	for (int i = 3; i <= n; i++)
	{
		string temp = "";
		s += "#"; // will help wiht out of bound
		int cnt = 1;

		for (int j = 1; j < s.size(); j++)
		{
			if (s[j] != s[j - 1])
			{ // count of a number
				temp = temp + to_string(cnt);
				temp += s[j - 1];
				cnt = 1;
			}
			else
			{ // count of same numbers
				cnt++;
			}
		}
		s = temp;
	}

	return s;
}