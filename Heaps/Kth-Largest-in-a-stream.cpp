vector<int> kthLargest(int k, int arr[], int n)
{

	vector<int> v;
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < k - 1; i++)
	{
		v.push_back(-1);
	}

	for (int i = 0; i < k; i++)
	{
		q.push(arr[i]);
	}

	v.push_back(q.top());

	for (int i = k; i < n; i++)
	{
		if (arr[i] > q.top())
		{
			q.pop();
			q.push(arr[i]);
		}
		v.push_back(q.top());
	}

	return v;
}