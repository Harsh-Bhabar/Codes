vector<int> topView(Node *root)
{
	// Your code here
	vector<int> ans;
	if (!root)
	{
		return ans;
	}

	map<int, int> mp;
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

			if (mp.find(vLevel) == mp.end())
			{
				mp[vLevel] = curr->data;
			}
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
		ans.push_back(i.second);
	}

	return ans;
}