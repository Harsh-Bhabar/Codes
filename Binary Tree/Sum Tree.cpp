class Solution
{
public:
	bool ans = true;

	int solve(Node *root)
	{
		if (!root)
		{
			return 0;
		}
		if (!root->left && !root->right)
		{
			return root->data;
		}
		int left = solve(root->left);
		int right = solve(root->right);
		if (root->data != left + right)
		{
			ans = false;
		}
		return root->data + left + right;
	}

	bool isSumTree(Node *root)
	{
		// Your code here
		if (!root)
		{
			return ans;
		}
		solve(root);
		return ans;
	}
};