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
class BSTIterator
{
public:
	stack<TreeNode *> inorderSt;

	BSTIterator(TreeNode *root)
	{
		pushAllLeft(root);
	}

	void pushAllLeft(TreeNode *root)
	{
		while (root)
		{
			inorderSt.push(root);
			root = root->left;
		}
	}

	int next()
	{
		TreeNode *temp = inorderSt.top();
		inorderSt.pop();
		pushAllLeft(temp->right);
		return temp->val;
	}

	bool hasNext()
	{
		return !inorderSt.empty();
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */