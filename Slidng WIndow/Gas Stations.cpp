class Solution
{
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
	{
		int totalGas = 0;
		int totalCost = 0;

		for (int i = 0; i < gas.size(); i++)
		{
			totalGas += gas[i];
			totalCost += cost[i];
		}

		if (totalGas < totalCost)
		{
			return -1;
		}

		int remainingGas = 0;
		int start = 0;

		for (int i = 0; i < gas.size(); i++)
		{
			remainingGas += gas[i] - cost[i];
			if (remainingGas < 0)
			{
				start = i + 1;
				remainingGas = 0;
			}
		}

		return start;
	}
};