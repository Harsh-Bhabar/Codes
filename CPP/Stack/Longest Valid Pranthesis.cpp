class Solution
{
public:
	int longestValidParentheses(string s)
	{
		if (s.size() <= 1)
		{
			return 0;
		}

		stack<int> st;
		st.push(-1);
		int mxlen = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				st.push(i);
			}
			else
			{
				st.pop();
				if (st.empty())
				{
					st.push(i);
				}
				else
				{
					mxlen = max(mxlen, i - st.top());
					// calculating the lenght from the prev invalid item
				}
			}
		}

		return mxlen;
	}
};