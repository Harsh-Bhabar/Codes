import java.util.ArrayDeque;
import java.util.Queue;

class Solution
{
public
	int orangesRotting(int[][] grid)
	{
		int row = grid.length;
		int col = grid[0].length;
		int minutes = 0;

		int[][] dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		Queue<int[]> q = new ArrayDeque<>();

		int total = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] != 0)
				{
					total++;
				}
				if (grid[i][j] == 2)
				{
					q.offer(new int[]{i, j});
				}
			}
		}

		int cnt = 0;
		while (!q.isEmpty())
		{
			int n = q.size();
			cnt += n;
			while (n-- > 0)
			{
				int[] curr = q.poll();
				for (int[] dir : dirs)
				{
					int dx = dir[0] + curr[0];
					int dy = dir[1] + curr[1];

					if (dx < 0 || dy < 0 || dx >= row || dy >= col || grid[dx][dy] != 1)
						continue;

					grid[dx][dy] = 2;
					q.offer(new int[]{dx, dy});
				}
			}
			if (!q.isEmpty())
				minutes++;
		}

		return cnt == total ? minutes : -1;
	}
}
