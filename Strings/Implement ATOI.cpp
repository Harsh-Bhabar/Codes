class Solution
{
public:
	int myAtoi(string s)
	{
		int i = 0;
		int len = s.size();
		long num = 0;
		int neg = false;

		while (i < len and s[i] == ' ')
		{ // remove trailing white spaces
			i++;
		}
		if (s[i] == '-')
		{ // checck if negaive
			neg = true;
			i++;
		}
		else if (s[i] == '+')
		{ // check for positive
			i++;
		}

		while (s[i] >= '0' and s[i] <= '9')
		{ // only intake numbers
			num = num * 10 + s[i] - '0';
			i++;

			if (num > INT_MAX)
			{
				break;
			}
		}

		if (num > INT_MAX)
		{
			if (neg)
			{
				return INT_MIN;
			}
			else
			{
				return INT_MAX;
			}
		}

		if (neg)
		{
			return -1 * num;
		}
		else
		{
			return num;
		}
	}
};