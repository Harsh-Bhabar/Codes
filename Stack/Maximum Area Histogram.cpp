class Solution
{
public:
	vector<int> nextSmallestToLeft(vector<int> &nums, int n)
	{
		stack<int> st;			// storing indexes
		vector<int> ans(n, -1); // left most is "-1"
		for (int i = 0; i < n; i++)
		{
			int ele = nums[i];
			while (!st.empty() && nums[st.top()] >= ele)
			{
				st.pop();
			}
			if (!st.empty())
			{
				ans[i] = st.top();
			}
			st.push(i);
		}
		return ans;
	}

	vector<int> nextSmallestToRight(vector<int> &nums, int n)
	{
		stack<int> st;		   // storing indexes
		vector<int> ans(n, n); // right most is "n"
		for (int i = n - 1; i >= 0; i--)
		{
			int ele = nums[i];
			while (!st.empty() && nums[st.top()] >= ele)
			{
				st.pop();
			}
			if (!st.empty())
			{
				ans[i] = st.top();
			}
			st.push(i);
		}
		return ans;
	}

	int largestRectangleArea(vector<int> &heights)
	{
		int n = heights.size();
		if (n == 1)
		{
			return heights[0];
		}
		// getting indexes
		vector<int> nsl = nextSmallestToLeft(heights, n);
		vector<int> nsr = nextSmallestToRight(heights, n);

		int ans = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			// (indexOfRight - indexOfLeft - 1) * num
			ans = max(ans, (nsr[i] - nsl[i] - 1) * heights[i]);
		}
		return ans;
	}
};