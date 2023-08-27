class Solution
{
public:
	int findFirstOcc(vector<int> &nums, int l, int r, int target)
	{
		int ans = -1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				if (nums[mid] < target)
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
		}
		return ans;
	}
	int findLastOcc(vector<int> &nums, int l, int r, int target)
	{
		int ans = -1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				ans = mid;
				l = mid + 1;
			}
			else
			{
				if (nums[mid] < target)
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
		}
		return ans;
	}

	vector<int> searchRange(vector<int> &nums, int target)
	{
		int n = nums.size();
		if (n == 0)
		{
			return {-1, -1};
		}
		vector<int> ans;
		ans.push_back(findFirstOcc(nums, 0, n - 1, target));
		ans.push_back(findLastOcc(nums, 0, n - 1, target));
		return ans;
	}
};