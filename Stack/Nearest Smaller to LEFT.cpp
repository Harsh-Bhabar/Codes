vector<int> leftSmaller(int n, int nums[])
{
	// code here
	vector<int> ans(n, -1);
	if (n == 1)
	{
		return ans;
	}
	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		int ele = nums[i];
		if (!st.empty())
		{
			if (st.top() < ele)
			{
				ans[i] = st.top();
			}
			else
			{
				while (!st.empty() && st.top() >= ele)
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