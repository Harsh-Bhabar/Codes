class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k)
	{
		vector<int> ans;
		int n = nums.size();
		if (n == 0)
		{
			return ans;
		}
		deque<int> dq;

		int i = 0;
		int j = 0;

		while (j < n)
		{
			if (dq.empty())
			{
				dq.push_back(j);
			}
			else
			{
				// remove all smaller than nums[j] from its front
				while (!dq.empty() and nums[dq.back()] < nums[j])
				{
					dq.pop_back();
				}
				dq.push_back(j);
			}
			if (j - i + 1 == k)
			{
				ans.push_back(nums[dq.front()]);
				if (dq.front() == i)
				{
					dq.pop_front();
				}
				i++;
			}
			j++;
		}

		return ans;
	}
};