class MedianFinder
{
public:
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	MedianFinder()
	{
	}

	void addNum(int num)
	{
		if (maxHeap.size() == 0 or num <= maxHeap.top())
		{
			maxHeap.push(num);
		}
		else
		{
			minHeap.push(num);
		}
		balance();
	}

	void balance()
	{
		if (maxHeap.size() > 1 + minHeap.size())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if (minHeap.size() > 1 + maxHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian()
	{
		if (maxHeap.size() > minHeap.size())
		{
			return maxHeap.top();
		}
		else if (minHeap.size() > maxHeap.size())
		{
			return minHeap.top();
		}
		return (double)(maxHeap.top() + minHeap.top()) / 2;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */