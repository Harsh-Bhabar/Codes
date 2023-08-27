class OurNode
{
public:
	int size;
	int maxNode;
	int minNode;
	OurNode(int size, int maxNode, int minNode)
	{
		this->size = size;
		this->maxNode = maxNode;
		this->minNode = minNode;
	}
};

class Solution
{
public:
	/*You are required to complete this method */
	// Return the size of the largest sub-tree which is also a BST

	OurNode solve(Node *root)
	{
		if (!root)
		{
			return OurNode(0, INT_MIN, INT_MAX); // passing opposite
		}

		OurNode left = solve(root->left);
		OurNode right = solve(root->right);

		// valid bst
		if (left.maxNode < root->data && root->data < right.minNode)
		{
			return OurNode(
				1 + left.size + right.size,
				max(root->data, right.maxNode),
				min(root->data, left.minNode));
		}

		else
		{
			return OurNode(max(left.size, right.size), INT_MAX, INT_MIN);
		}
	}

	int largestBst(Node *root)
	{
		// postorder
		if (!root)
		{
			return 0;
		}
		return solve(root).size;
	}
};