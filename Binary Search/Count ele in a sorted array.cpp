class Solution
{
public:
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int findFirstOcc(int nums[], int l, int r, int x)
	{
		int ans = -1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] == x)
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				if (nums[mid] < x)
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

	int findLastOcc(int nums[], int l, int r, int x)
	{
		int ans = -1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] == x)
			{
				ans = mid;
				l = mid + 1;
			}
			else
			{
				if (nums[mid] < x)
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

	int count(int arr[], int n, int x)
	{
		// code here
		if (n == 0)
		{
			return 0;
		}
		int first = findFirstOcc(arr, 0, n - 1, x);
		int last = findLastOcc(arr, 0, n - 1, x);

		if (first == -1 && last == -1)
		{
			return 0;
		}
		if (first == -1 or last == -1)
		{
			return 1;
		}
		return 1 + last - first;
	}
};