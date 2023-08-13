/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
	int findPeakIndex(int target, MountainArray nums)
	{
		int l = 0;
		int size = nums.length();
		int r = size - 1;

		while (l <= r)
		{
			int mid = l + (r - l) / 2;

			if (mid > 0 && mid < size - 1)
			{
				if (nums.get(mid) > nums.get(mid + 1) && nums.get(mid) > nums.get(mid - 1))
				{
					return mid;
				}
				else if (nums.get(mid) < nums.get(mid + 1))
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
			else if (mid == 0)
			{
				if (nums.get(0) > nums.get(1))
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			else if (mid == size - 1)
			{
				if (nums.get(size - 1) > nums.get(size - 2))
				{
					return size - 1;
				}
				else
				{
					return size - 2;
				}
			}
		}

		return -1;
	}

	int binarySearchOnIncreasingOrder(MountainArray nums, int l, int r, int target)
	{
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums.get(mid) == target)
			{
				return mid;
			}
			else
			{
				if (nums.get(mid) < target)
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
		}
		return -1;
	}

	int binarySearchOnDecreasingOrder(MountainArray nums, int l, int r, int target)
	{
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums.get(mid) == target)
			{
				return mid;
			}
			else
			{
				if (nums.get(mid) > target)
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
		}
		return -1;
	}

	int findInMountainArray(int target, MountainArray &mountainArr)
	{
		int size = mountainArr.length();
		int peak = findPeakIndex(target, mountainArr);
		int inc = binarySearchOnIncreasingOrder(mountainArr, 0, peak - 1, target);
		int dec = binarySearchOnDecreasingOrder(mountainArr, peak, size - 1, target);
		cout << inc << dec;
		if (inc == -1 && dec == -1)
			return -1;
		else if (inc == -1 && dec != -1)
		{
			return dec;
		}
		else if (dec == -1 && inc != -1)
		{
			return inc;
		}
		return min(inc, dec);
	}
};