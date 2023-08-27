class Solution
{
public:
	// Function to return a list of integers denoting the node
	// values of both the BST in a sorted order.
	stack<Node *> first;
	stack<Node *> second;

	void pushAllLeft(Node *root, stack<Node *> &st)
	{
		while (root)
		{
			st.push(root);
			root = root->left;
		}
	}

	int firstNext()
	{
		if (first.empty())
		{
			return -1;
		}
		Node *temp = first.top();
		first.pop();
		pushAllLeft(temp->right, first);
		return temp->data;
	}
	int secondNext()
	{
		if (second.empty())
		{
			return -1;
		}
		Node *temp = second.top();
		second.pop();
		pushAllLeft(temp->right, second);
		return temp->data;
	}

	vector<int> merge(Node *root1, Node *root2)
	{
		// Your code here
		pushAllLeft(root1, first);
		pushAllLeft(root2, second);
		int l = firstNext();
		int r = secondNext();
		vector<int> ans;

		while (l != -1 && r != -1)
		{
			if (l <= r)
			{
				ans.push_back(l);
				l = firstNext();
			}
			else
			{
				ans.push_back(r);
				r = secondNext();
			}
		}
		if (l != -1)
		{
			while (l != -1)
			{
				ans.push_back(l);
				l = firstNext();
			}
		}
		if (r != -1)
		{
			while (r != -1)
			{
				ans.push_back(r);
				r = secondNext();
			}
		}

		return ans;
	}
};