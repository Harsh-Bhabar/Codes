class Solution
{
public:
	int trap(vector<int> &nums)
	{
		int n = nums.size();
		int l = 0;
		int r = n - 1;
		int leftmax = 0;
		int rightmax = 0;
		int ans = 0;

		while (l < r)
		{
			if (nums[l] <= nums[r])
			{ // left side is small -> min(leftmax, rightmax)
				if (leftmax < nums[l])
				{
					leftmax = nums[l];
				}
				else
				{
					ans += (leftmax - nums[l]);
				}
				l++;
			}
			else
			{ // right is small, -> min(leftmax, rightmax)
				if (rightmax < nums[r])
				{
					rightmax = nums[r];
				}
				else
				{
					ans += (rightmax - nums[r]);
				}
				r--;
			}
		}

		return ans;
	}
};