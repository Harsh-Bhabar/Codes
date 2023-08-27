/************************************************************

	Following is the Binary Tree node structure:

	template <typename T>
	class TreeNode
	{
	public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this -> data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if(left)
				delete left;
			if(right)
				delete right;
		}
	};

************************************************************/

vector<int> ans;

bool isLeaf(TreeNode<int> *root)
{
	return !root->left && !root->right;
}

void leftBoundryExcludingLeafNode(TreeNode<int> *root)
{
	TreeNode<int> *curr = root->left;
	while (curr)
	{
		if (!isLeaf(curr))
		{
			ans.push_back(curr->data);
		}
		if (curr->left)
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}
	}
}

void allLeafNode(TreeNode<int> *root)
{
	if (isLeaf(root))
	{
		ans.push_back(root->data);
		return;
	}
	if (root->left)
	{
		allLeafNode(root->left);
	}
	if (root->right)
	{
		allLeafNode(root->right);
	}
}

vector<int> rightBoundryInReverseExcludingLeaf(TreeNode<int> *root)
{
	vector<int> temp;
	if (!root->right)
		return temp;

	TreeNode<int> *curr = root->right;
	while (curr)
	{
		if (!isLeaf(curr))
		{
			temp.push_back(curr->data);
		}
		if (curr->right)
			curr = curr->right;
		else
		{
			curr = curr->left;
		}
	}
	reverse(temp.begin(), temp.end());
	return temp;
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
	if (!root)
	{
		return ans;
	}
	if (!isLeaf(root))
	{
		ans.push_back(root->data);
	}
	leftBoundryExcludingLeafNode(root);
	allLeafNode(root);
	vector<int> temp = rightBoundryInReverseExcludingLeaf(root);
	ans.insert(ans.end(), temp.begin(), temp.end());
	return ans;
}
