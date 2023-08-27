// USING TWO STACKS
class MyQueue
{
public:
	stack<int> st1;
	stack<int> st2;

	MyQueue()
	{
	}

	void push(int x)
	{
		// all st1 -> st2
		// x -> st1
		// all st2 -> st1

		while (!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
		st1.push(x);
		while (!st2.empty())
		{
			st1.push(st2.top());
			st2.pop();
		}
	}

	int pop()
	{
		int temp = st1.top();
		st1.pop();
		return temp;
	}

	int peek()
	{
		return st1.top();
	}

	bool empty()
	{
		return st1.empty();
	}
};

// USING TWO STACKs only but O(1) amotized time comp
class MyQueue
{
public:
	stack<int> input;
	stack<int> output;

	MyQueue()
	{
	}

	void push(int x)
	{
		input.push(x);
	}

	int pop()
	{
		if (output.empty())
		{
			while (!input.empty())
			{
				output.push(input.top());
				input.pop();
			}
			int temp = output.top();
			output.pop();
			return temp;
		}
		else
		{
			int temp = output.top();
			output.pop();
			return temp;
		}
	}

	int peek()
	{
		if (output.empty())
		{
			while (!input.empty())
			{
				output.push(input.top());
				input.pop();
			}
			int temp = output.top();
			return temp;
		}
		else
		{
			int temp = output.top();
			return temp;
		}
	}

	bool empty()
	{
		return input.empty() && output.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
