class Solution
{
public:
	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
	{
		vector<vector<int>> ans;

		if (intervals.size() == 0)
		{
			return {newInterval};
		}

		int i = 0;
		int n = intervals.size();
		while (i < n and intervals[i][1] < newInterval[0])
		{
			ans.push_back(intervals[i++]);
		}

		int low = newInterval[0];
		int high = newInterval[1];
		while (i < n and intervals[i][0] <= newInterval[1])
		{
			low = min(low, intervals[i][0]);
			high = max(high, intervals[i][1]);
			i++;
		}
		ans.push_back({low, high});

		while (i < n)
		{
			ans.push_back(intervals[i++]);
		}

		return ans;
	}
};