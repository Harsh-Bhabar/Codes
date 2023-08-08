class Solution
{
public:
	vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
	{

		if (k == 1 and points.size() == 1)
		{
			return points;
		}

		priority_queue<pair<double, int>> maxHeap;
		vector<vector<int>> ans;

		int ind = 0;
		for (auto it : points)
		{
			double dist = sqrt((pow(it[0], 2) + pow(it[1], 2)));
			maxHeap.push({dist, ind});
			if (maxHeap.size() > k)
			{
				maxHeap.pop();
			}
			ind++;
		}

		while (maxHeap.size())
		{
			int ind = maxHeap.top().second;
			ans.push_back(points[ind]);
			maxHeap.pop();
		}

		return ans;
	}
};