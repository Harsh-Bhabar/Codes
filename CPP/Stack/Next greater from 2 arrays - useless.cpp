class Solution
{
public:
	vector<int> nextGreaterToRight(vector<int> &nums, int n)
	{
		vector<int> ans(n);
		stack<int> st;

		for (int i = n - 1; i >= 0; i--)
		{
			int ele = nums[i];
			while (!st.empty() && st.top() <= ele)
			{
				st.pop();
			}
			ans[i] = !st.empty() ? st.top() : -1;
			st.push(ele);
		}

		return ans;
	}

	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		int n = nums2.size();
		vector<int> ngr = nextGreaterToRight(nums2, n);
		unordered_map<int, int> mp;
		vector<int> ans;

		for (int i = 0; i < ngr.size(); i++)
		{
			mp[nums2[i]] = ngr[i];
		}

		for (int i = 0; i < nums1.size(); i++)
		{
			ans.push_back(mp[nums1[i]]);
		}

		return ans;
	}
};