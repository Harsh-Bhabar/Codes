class Solution
{
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		int i = 0;
		int j = n - 1;

		while (j >= 0 and i < m)
		{
			if (matrix[i][j] == target)
			{
				return true;
			}
			if (matrix[i][j] < target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}

		return false;
	}
};