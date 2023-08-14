class Solution
{
public:
	int trap(vector<int> &height)
	{
		int n = height.size();
		// find max from left for each element
		vector<int> maxleft(n);
		maxleft[0] = height[0];
		// find max from right for each element
		vector<int> maxright(n);
		maxright[n - 1] = height[n - 1];

		for (int i = 1; i < n; i++)
		{
			maxleft[i] = max(maxleft[i - 1], height[i]);
		}

		for (int i = n - 2; i >= 0; i--)
		{
			maxright[i] = max(maxright[i + 1], height[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			// total water at the top of each would be min(leftmax, rightmax)-num
			ans += min(maxleft[i], maxright[i]) - height[i];
		}

		return ans;
	}
};