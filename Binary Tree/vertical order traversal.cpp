vector<int> verticalOrder(Node *root)
{
	// Your code here
	vector<int> ans;
	if (!root)
	{
		return ans;
	}

	map<int, vector<int>> mp;

	queue<pair<Node *, int>> q;
	q.push({root, 0});

	while (!q.empty())
	{
		int n = q.size();
		while (n--)
		{
			Node *curr = q.front().first;
			int vLevel = q.front().second;
			q.pop();

			mp[vLevel].push_back(curr->data);

			if (curr->left)
			{
				q.push({curr->left, vLevel - 1});
			}
			if (curr->right)
			{
				q.push({curr->right, vLevel + 1});
			}
		}
	}

	for (auto i : mp)
	{
		for (auto j : i.second)
		{
			ans.push_back(j);
		}
	}

	return ans;
}