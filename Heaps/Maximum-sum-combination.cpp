vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b)
{
	// code here
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	priority_queue<pair<int, pair<int, int>>> maxHeap;
	set<pair<int, int>> myset;

	maxHeap.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
	myset.insert({n - 1, n - 1});

	vector<int> ans;
	for (int cnt = 0; cnt < k; cnt++)
	{
		auto temp = maxHeap.top();
		ans.push_back(temp.first);
		maxHeap.pop();

		int i = temp.second.first;
		int j = temp.second.second;

		int sum1 = a[i - 1] + b[j];
		if (myset.find({i - 1, j}) == myset.end())
		{
			myset.insert({i - 1, j});
			maxHeap.push({sum1, {i - 1, j}});
		}

		int sum2 = a[i] + b[j - 1];
		if (myset.find({i, j - 1}) == myset.end())
		{
			myset.insert({i, j - 1});
			maxHeap.push({sum2, {i, j - 1}});
		}
	}

	return ans;
}