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

class OurNode
{
public:
	int sum;
	int size;
	int maxval;
	int minval;
	OurNode(int sum, int size, int maxval, int minval)
	{
		this->sum = sum;
		this->size = size;
		this->maxval = maxval;
		this->minval = minval;
	}
};

class Solution
{
public:
	int maxsum = 0;

	OurNode *solve(TreeNode *root)
	{
		if (!root)
		{
			return new OurNode(0, 0, INT_MIN, INT_MAX);
		}
		auto left = solve(root->left);
		auto right = solve(root->right);

		// for valid BST -> largest < root < smallest
		if (left->maxval < root->val && root->val < right->minval)
		{

			maxsum = max(maxsum, root->val + left->sum + right->sum);

			return new OurNode(
				root->val + left->sum + right->sum,
				1 + left->size + right->size,
				max(root->val, right->maxval),
				min(root->val, left->minval));
		}

		else
		{
			return new OurNode(0, max(left->size, right->size), INT_MAX, INT_MIN);
		}
	}

	int maxSumBST(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}
		OurNode *ans = solve(root);
		// cout<<ans->size; // this will give us the max size of BST
		return maxsum;
	}
};