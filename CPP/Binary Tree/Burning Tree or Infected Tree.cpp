class Solution
{
public:
	unordered_map<TreeNode *, TreeNode *> parentMap;
	unordered_map<TreeNode *, bool> burned;

	TreeNode *findTargetAndfillParentMap(TreeNode *root, int start)
	{
		queue<TreeNode *> q;
		q.push(root);

		TreeNode *target;

		while (!q.empty())
		{
			TreeNode *curr = q.front();
			q.pop();
			if (curr->val == start)
			{
				target = curr;
			}
			if (curr->left)
			{
				parentMap[curr->left] = curr;
				burned[curr->left] = false;
				q.push(curr->left);
			}
			if (curr->right)
			{
				parentMap[curr->right] = curr;
				burned[curr->right] = false;
				q.push(curr->right);
			}
		}

		return target;
	}

	int countTime(TreeNode *root)
	{
		int ans = 0;

		queue<TreeNode *> q;
		q.push(root);

		burned[root] = true;

		while (!q.empty())
		{
			int n = q.size();
			bool somethingBurned = false;
			while (n--)
			{
				TreeNode *curr = q.front();
				q.pop();

				if (curr->left && burned[curr->left] == false)
				{
					burned[curr->left] = true;
					somethingBurned = true;
					q.push(curr->left);
				}
				if (curr->right && burned[curr->right] == false)
				{
					burned[curr->right] = true;
					somethingBurned = true;
					q.push(curr->right);
				}

				if (parentMap[curr] && burned[parentMap[curr]] == false)
				{
					burned[parentMap[curr]] = true;
					somethingBurned = true;
					q.push(parentMap[curr]);
				}
			}
			if (somethingBurned)
			{
				ans++;
			}
		}

		return ans;
	}

	int amountOfTime(TreeNode *root, int start)
	{
		if (!root)
		{
			return 0;
		}
		TreeNode *burningNode = findTargetAndfillParentMap(root, start);
		return countTime(burningNode);
	}
};