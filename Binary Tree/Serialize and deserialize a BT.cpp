/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root)
	{
		if (!root)
		{
			return "";
		}
		queue<TreeNode *> q;
		q.push(root);
		string bfs = "";

		while (!q.empty())
		{
			int n = q.size();
			while (n--)
			{
				TreeNode *curr = q.front();
				q.pop();
				if (!curr)
				{
					bfs += "N,";
				}
				else
				{
					bfs += to_string(curr->val);
					bfs += ",";
				}
				if (curr)
				{
					q.push(curr->left);
					q.push(curr->right);
				}
			}
		}
		// cout<<bfs<<endl;
		return bfs;
	}

	vector<string> stringToArray(string data)
	{
		stringstream ss(data);
		string s;
		vector<string> ans;
		while (getline(ss, s, ','))
		{
			ans.push_back(s);
		}
		return ans;
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data)
	{
		if (data == "")
		{
			return NULL;
		}

		vector<string> nums = stringToArray(data);
		int n = nums.size();
		queue<TreeNode *> q;

		TreeNode *root = new TreeNode(stoi(nums[0]));
		q.push(root);

		int ind = 0;
		while (ind < n)
		{
			TreeNode *curr = q.front();
			q.pop();

			ind++;
			if (ind < n and nums[ind] != "N")
			{
				curr->left = new TreeNode(stoi(nums[ind]));
				q.push(curr->left);
			}

			ind++;
			if (ind < n and nums[ind] != "N")
			{
				curr->right = new TreeNode(stoi(nums[ind]));
				q.push(curr->right);
			}
		}

		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));