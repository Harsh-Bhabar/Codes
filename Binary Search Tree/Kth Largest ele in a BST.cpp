class Solution
{
public:
	int kthLargest(Node *root, int k)
	{
		// Your code here
		if (!root)
		{
			return -1;
		}

		stack<Node *> st;
		while (root || !st.empty())
		{
			while (root)
			{
				st.push(root);
				root = root->right;
			}
			root = st.top();
			st.pop();
			if (k == 1)
			{
				return root->data;
			}
			root = root->left;
			k--;
		}

		return -1;
	}
};