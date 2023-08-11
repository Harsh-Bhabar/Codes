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
	TreeNode *insertInBST(TreeNode *head, int val)
	{
		if (!head)
		{
			return new TreeNode(val);
		}
		if (head->val < val)
		{
			head->right = insertInBST(head->right, val);
		}
		else
		{
			head->left = insertInBST(head->left, val);
		}
		return head;
	}

	TreeNode *bstFromPreorder(vector<int> &preorder)
	{
		if (preorder.size() == 0)
		{
			return NULL;
		}
		TreeNode *head = new TreeNode(preorder[0]);
		for (int i = 1; i < preorder.size(); i++)
		{
			insertInBST(head, preorder[i]);
		}
		return head;
	}
};