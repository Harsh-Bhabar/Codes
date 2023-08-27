class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
		int zero = 0;
		int two = nums.size() - 1;
		int i = 0;
		while (i <= two)
		{
			if (nums[i] == 0)
			{
				swap(nums[zero], nums[i]);
				zero++;
				i++;
			}
			else if (nums[i] == 2)
			{
				swap(nums[two], nums[i]);
				two--;
			}
			else
			{
				i++;
			}
		}
	}
};