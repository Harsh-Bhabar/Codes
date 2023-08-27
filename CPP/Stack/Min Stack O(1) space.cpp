class MinStack
{
public:
	stack<long> st;
	long min = INT_MAX;

	MinStack()
	{
	}

	void push(int val)
	{
		if (st.empty())
		{
			st.push(val);
			min = val;
		}
		else
		{
			if (val >= min)
			{ // comapare with min
				st.push(val);
			}
			else
			{
				long temp = 1LL * 2 * val - min; // 2*val - min
				st.push(temp);
				min = val;
			}
		}
	}

	void pop()
	{
		if (st.empty())
		{
			return;
		}
		if (st.top() > min)
		{
			st.pop();
		}
		else
		{
			min = 1LL * 2 * min - st.top(); // 2*min - top
			st.pop();
		}
	}

	int top()
	{
		if (st.empty())
		{
			return -1;
		}
		else
		{
			if (st.top() < min)
			{ // modified values at top
				return min;
			}
			else
			{
				return st.top();
			}
		}
	}

	int getMin()
	{
		return min;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */