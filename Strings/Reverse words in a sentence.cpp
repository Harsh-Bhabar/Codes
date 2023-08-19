class Solution
{
public:
	string reverseWords(string s)
	{
		int i = 0;
		int j = s.size() - 1;

		while (s[i] == ' ')
		{
			i++;
		}
		while (s[j] == ' ')
		{
			j--;
		}

		string ans = "";
		string temp = "";

		while (i <= j)
		{
			if (s[i] != ' ')
			{
				temp += s[i];
			}
			else
			{
				if (temp != "")
				{
					ans = temp + " " + ans;
					temp = "";
				}
			}
			i++;
		}

		ans = temp + " " + ans;					 // last word
		ans.erase(ans.begin() + ans.size() - 1); // removes the last space

		return ans;
	}
};