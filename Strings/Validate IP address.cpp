int isValid(string s)
{
	if (s.length() > 15 or s.length() < 7)
		return 0;

	int dot = 0, res;
	string str;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			if (str.length() > 1 and str[0] == '0')
				return 0;
			str.clear();
			dot++;
			if (dot > 3)
				return 0;
		}
		else if (s[i] >= 48 and s[i] <= 57)
		{
			str.push_back(s[i]);
			if (str.length() == 4)
				return 0;
			res = stoi(str);
			if (res > 255)
				return 0;
		}
		else
		{
			return 0;
		}
	}

	if (str.length() > 1 and str[0] == '0')
		return 0;

	return 1;
}