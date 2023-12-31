vector<int> firstNegative(vector<int> nums, int n, int k)
{
	vector<int> ans;
	if (n == 0)
	{
		return ans;
	}
	int i = 0;
	int j = 0;
	queue<int> q;

	while (j < n)
	{
		if (nums[j] < 0)
		{
			q.push(j);
		}
		if (j - i + 1 == k)
		{
			int temp = q.empty() ? 0 : nums[q.front()];
			ans.push_back(temp);
			if (!q.empty() & q.front() <= i)
			{
				q.pop();
			}
			i++;
		}
		j++;
	}

	return ans;
}