class Solution
{
public:
	bool find132pattern(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> mini(n, -1);

		mini[0] = nums[0];
		for (int i = 1; i < n; i++)
		{
			mini[i] = min(mini[i - 1], nums[i]);
		}

		stack<int> st;

		for (int j = n - 1; j >= 0; j--)
		{
			if (nums[j] > mini[j])
			{ // y > x
				while (!st.empty() and st.top() <= mini[j])
				{ // if z < x -> pop
					st.pop();
				}
				if (!st.empty() and st.top() < nums[j])
				{ // y > z
					return true;
				}
				st.push(nums[j]);
			}
		}

		return false;
	}
};