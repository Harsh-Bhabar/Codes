class Solution
{
public:
	vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
	{
		int m = image.size();
		int n = image[0].size();

		vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

		queue<pair<int, int>> pq;
		pq.push({sr, sc});

		int oriColor = image[sr][sc];

		if (oriColor == newColor)
		{
			return image;
		}

		image[sr][sc] = newColor;

		while (!pq.empty())
		{
			int r = pq.front().first;
			int c = pq.front().second;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int dr = r + dirs[i][0];
				int dc = c + dirs[i][1];

				if (dr >= 0 and dc >= 0 and dr < m and dc < n and image[dr][dc] == oriColor)
				{
					image[dr][dc] = newColor;
					pq.push({dr, dc});
				}
			}
		}

		return image;
	}
};