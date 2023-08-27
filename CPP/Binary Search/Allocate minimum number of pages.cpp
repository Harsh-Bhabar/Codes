bool isValid(vector<int> &nums, int n, int k, int mid)
{
	int totalStudent = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += nums[i];
		if (sum > mid)
		{
			totalStudent++;
			sum = nums[i];
		}
		if (totalStudent > k)
		{
			return false;
		}
	}
	return true;
}

int findPages(vector<int> &nums, int n, int k)
{
	// Write your code here.
	if (n < k)
	{
		return -1; // less books more students, since each has to get one
	}

	int start = INT_MIN; // max from the array
	int end = 0;		 // total sum of array elements
	int ans = -1;

	for (auto num : nums)
	{
		if (num > start)
		{
			start = num;
		}
		end += num;
	}

	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (isValid(nums, n, k, mid) == true)
		{
			ans = mid;
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	return ans;
}