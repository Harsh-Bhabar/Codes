class Solution
{
public:
	// Function to find if there is a celebrity in the party or not.
	int celebrity(vector<vector<int>> &M, int n)
	{
		// code here
		stack<int> st;
		for (int i = 0; i < n; i++)
		{
			st.push(i);
		}

		while (st.size() >= 2)
		{
			int i = st.top();
			st.pop();
			int j = st.top();
			st.pop();
			if (M[i][j] == 1)
			{
				// i knows j => i is not a celebrity
				st.push(j);
			}
			else
			{
				st.push(i);
			}
		}

		int tempCele = st.top();
		st.pop();
		bool isCelebrity = true;

		int i = tempCele;
		for (int j = 0; j < n; j++)
		{
			if (j != tempCele and (M[tempCele][j] == 1 or M[j][tempCele] == 0))
			{
				// tempCele should not know anybody
				// j should know i
				isCelebrity = false;
				break;
			}
		}

		return isCelebrity ? tempCele : -1;
	}
};