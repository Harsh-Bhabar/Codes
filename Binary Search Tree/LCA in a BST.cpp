/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
	// Let large = max(p.val, q.val), small = min(p.val, q.val).
	// We keep iterate root in our BST:
	// If root.val > large then both node p and q belong to the left subtree,
	// go to left by root = root.left.
	// If root.val < small then both node p and q belong to the right subtree,
	// go to right by root = root.right.
	// Now, small <= root.val <= large the current root is the LCA between q and p.

	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root)
		{
			return NULL;
		}

		int small = min(p->val, q->val);
		int large = max(p->val, q->val);

		while (root)
		{
			if (root->val > large)
			{
				root = root->left;
			}
			else if (root->val < small)
			{
				root = root->right;
			}
			else
			{
				return root;
			}
		}

		return NULL;
	}
};