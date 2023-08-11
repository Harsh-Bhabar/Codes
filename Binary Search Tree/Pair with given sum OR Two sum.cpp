/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
	stack<TreeNode *> inorderNext;
	stack<TreeNode *> inorderLast;

	void pushAllLeft(TreeNode *root)
	{
		if (!root)
		{
			return;
		}
		while (root)
		{
			inorderNext.push(root);
			root = root->left;
		}
	}

	void pushAllRight(TreeNode *root)
	{
		if (!root)
		{
			return;
		}
		while (root)
		{
			inorderLast.push(root);
			root = root->right;
		}
	}

	int next()
	{
		TreeNode *temp = inorderNext.top();
		inorderNext.pop();
		pushAllLeft(temp->right);
		return temp->val;
	}

	int last()
	{
		TreeNode *temp = inorderLast.top();
		inorderLast.pop();
		pushAllRight(temp->left);
		return temp->val;
	}

	bool findTarget(TreeNode *root, int k)
	{
		if (!root)
		{
			return false;
		}

		pushAllLeft(root);
		pushAllRight(root);

		int nex = next();
		int las = last();

		while (nex != las)
		{
			int sum = nex + las;
			if (sum == k)
			{
				return true;
			}
			if (sum < k)
			{
				nex = next();
			}
			else
			{
				las = last();
			}
		}

		return false;
	}
};