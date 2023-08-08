long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
{
	// Your code goes here
	priority_queue<int> maxHeap;

	for (long long i = 0; i < N; i++)
	{
		maxHeap.push(A[i]);
		if (maxHeap.size() > K2)
		{
			maxHeap.pop();
		}
	}

	maxHeap.pop();
	long long ans = 0;

	while (maxHeap.size() > K1)
	{
		ans += maxHeap.top();
		maxHeap.pop();
	}

	return ans;
}