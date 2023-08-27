class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k)
	{
		deque<int> dq; // keep track of elements in decreasing order (indexes)
		vector<int> ans;

		for (int i = 0; i < nums.size(); i++)
		{
			if (!dq.empty() and dq.front() == i - k)
			{ // if front(max) is out of bound
				dq.pop_front();
			}

			while (!dq.empty() and nums[dq.back()] < nums[i])
			{ // remove all the samller from back
				dq.pop_back();
			}

			dq.push_back(i);

			if (i >= k - 1)
			{
				ans.push_back(nums[dq.front()]);
			}
		}

		return ans;
	}
};