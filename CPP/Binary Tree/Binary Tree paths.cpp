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
	vector<string> ansStr;

	void solve(TreeNode *root, string ans)
	{
		if (!root)
		{
			return;
		}
		ans += to_string(root->val);
		ans += "->";
		if (!root->left and !root->right)
		{
			ans.pop_back();
			ans.pop_back();
			ansStr.push_back(ans);
			return;
		}
		solve(root->left, ans);
		solve(root->right, ans);
	}

	vector<string> binaryTreePaths(TreeNode *root)
	{
		if (!root)
		{
			return ansStr;
		}
		string ans = "";
		solve(root, ans);
		return ansStr;
	}
};