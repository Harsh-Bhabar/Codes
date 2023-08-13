/************************************************************

	Use get function that returns the value at index i
	in the infinite sorted binary array.

	get(i)
	{

	}


************************************************************/

long long firstOne()
{
	// Write your code here.
	long long l = 0;
	long long r = 1;

	while (get(r) != 1)
	{
		l = r;
		r = r * 2;
	}

	long long ind = -1;

	while (l < r)
	{
		long long mid = l + (r - l) / 2;
		if (get(mid) == 1)
		{
			ind = mid;
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return ind;
}
