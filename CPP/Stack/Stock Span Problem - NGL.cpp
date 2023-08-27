class StockSpanner
{
public:
	stack<pair<int, int>> st; // stockPrice - cnt

	StockSpanner()
	{
	}

	int next(int price)
	{
		int cnt = 1;
		while (!st.empty() && st.top().first <= price)
		{
			cnt += st.top().second; // add the cnt of smaller elements
			st.pop();
		}
		st.push({price, cnt});
		return cnt;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */