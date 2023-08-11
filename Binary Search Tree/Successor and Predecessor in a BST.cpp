class Solution
{
public:
	Node *pred = NULL;
	Node *succ = NULL;

	void successor(Node *root, int key)
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
			if (root->key <= key)
			{
				root = root->right;
			}
			else
			{
				succ = root;
				root = root->left;
			}
		}
	}

	void predecessor(Node *root, int key)
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
			if (root->key < key)
			{
				pred = root;
				root = root->right;
			}
			else
			{
				root = root->left;
			}
		}
	}

	void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
	{
		// Your code goes here
		successor(root, key);
		predecessor(root, key);

		pre = pred;
		suc = succ;
	}
};