int findFloor(int nums[], int n, int x)
{
	if (nums[n - 1] < x)
	{
		return nums[n - 1];
	}
	if (nums[0] > x)
	{
		return -1;
	}
	int ans = -1;
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (nums[mid] == x)
		{
			return nums[mid];
		}
		if (nums[mid] > x)
		{
			r = mid - 1;
		}
		else
		{
			ans = nums[mid];
			l = mid + 1;
		}
	}
	return ans;
}

int findCeil(int nums[], int n, int x)
{
	if (nums[n - 1] < x)
	{
		return -1;
	}
	if (nums[0] > x)
	{
		return nums[0];
	}
	int ans = 0;
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (nums[mid] == x)
		{
			return nums[mid];
		}
		if (nums[mid] > x)
		{
			ans = nums[mid];
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
	// code here
	sort(arr, arr + n);
	int floor = findFloor(arr, n, x);
	int ceil = findCeil(arr, n, x);
	return {floor, ceil};
}