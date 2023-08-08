class Solution
{
public:
	string reorganizeString(string str)
	{
		if (str.size() < 2)
		{
			return str;
		}

		unordered_map<char, int> mp;
		for (int i = 0; i < str.size(); i++)
		{
			mp[str[i]]++;
		}

		priority_queue<pair<int, char>> maxHeap;
		for (auto i : mp)
		{
			if (i.second > (str.size() + 1) / 2)
			{ // if any char occues more than half the size of str
				return "";
			}
			maxHeap.push({i.second, i.first});
		}

		string ans(str.size(), 'a');
		int i = 0;

		while (!maxHeap.empty())
		{
			auto top = maxHeap.top();
			while (top.first)
			{
				if (i >= str.size())
				{
					i = 1;
				}
				ans[i] = top.second;
				i += 2;
				top.first--;
			}

			maxHeap.pop();
		}

		return ans;
	}
};