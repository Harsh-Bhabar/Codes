class Solution
{
public:
	vector<int> nearestSmallestToRight(vector<int> &nums, int n)
	{
		stack<int> st;
		vector<int> ans(n, n);

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

	vector<int> nearestSmallestToLeft(vector<int> &nums, int n)
	{
		stack<int> st;
		vector<int> ans(n, -1);

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

	int maxAreaHistogram(vector<int> &nums, int n)
	{
		int ans = INT_MIN;
		vector<int> nsr = nearestSmallestToRight(nums, n);
		vector<int> nsl = nearestSmallestToLeft(nums, n);

		for (int i = 0; i < n; i++)
		{
			ans = max(ans, (nsr[i] - nsl[i] - 1) * nums[i]);
		}
		return ans;
	}

	int maximalRectangle(vector<vector<char>> &matrix)
	{
		int ans = INT_MIN;
		int m = matrix.size();
		int n = matrix[0].size();

		vector<int> prev(n, 0);

		for (int i = 0; i < m; i++)
		{
			vector<int> temp(n, 0); // make each row a histogram question 
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
				{
					temp[j] = prev[j] + 1;
				}
			}
			ans = max(ans, maxAreaHistogram(temp, n));
			prev = temp;
		}

		return ans;
	}
};