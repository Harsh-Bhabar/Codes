int firstIndex(int nums[], int n)
{
	// Your code goes here
	int l = 0;
	int r = n - 1;
	while (l <= r and r < n)
	{
		int mid = l + (r - l) / 2;
		if (nums[mid] == 1 && (mid == 0 || nums[mid - 1] == 0))
		{
			return mid;
		}
		if (nums[mid] == 1)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}