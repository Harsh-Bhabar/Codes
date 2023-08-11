class Solution
{
public:
	Node *succ = NULL;
	// returns the inorder successor of the Node x in BST (rooted at 'root')

	void solve(Node *root, int x)
	{
		if (!root)
		{
			return;
		}
		while (root)
		{
			if (!root)
			{
				return;
			}
			if (root->data <= x)
			{
				root = root->right;
			}
			else
			{
				succ = root;
				root = root->left;
			}
		}
		return;
	}

	Node *inOrderSuccessor(Node *root, Node *x)
	{
		// Your code here
		if (!root)
		{
			return NULL;
		}
		solve(root, x->data);
		return succ;
	}
};