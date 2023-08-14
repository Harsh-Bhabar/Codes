vector<long long> nextLargerElement(vector<long long> nums, int n)
{
	// Your code here
	vector<long long> ans(n, -1);
	if (n <= 1)
	{
		return ans;
	}
	stack<long long> st;

	for (int i = n - 1; i >= 0; i--)
	{
		long long ele = nums[i];
		if (!st.empty())
		{
			if (st.top() > ele)
			{
				ans[i] = st.top();
			}
			else
			{
				while (!st.empty() && st.top() <= ele)
				{
					st.pop();
				}
				if (!st.empty())
				{
					ans[i] = st.top();
				}
			}
		}
		st.push(ele);
	}

	return ans;
}