class Solution
{
public:
	// next greater element logic only, but start the index at 2*n - 1 ans use i as i%N
	vector<int> nextGreaterElements(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> ans(n);
		stack<int> st;

		for (int i = 2 * n - 1; i >= 0; i--)
		{
			int ele = nums[i % n];
			// if small elem, then pop
			while (!st.empty() and st.top() <= ele)
			{
				st.pop();
			}
			ans[i % n] = st.empty() ? -1 : st.top();
			st.push(ele);
		}

		return ans;
	}
};