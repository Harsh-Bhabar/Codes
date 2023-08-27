//USING TWO QUEUES
void QueueStack ::push(int x)
{
	// add X in q2
	// move all from q1 to q2
	// swap q1 and q2

	q2.push(x);
	while (!q1.empty())
	{
		q2.push(q1.front());
		q1.pop();
	}
	swap(q1, q2);
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
	// top elemenet of q1 would be the stacks top element
	if (q1.empty())
	{
		return -1;
	}
	int temp = q1.front();
	q1.pop();
	return temp;
}


// USING SINGLE QUEUE
class MyStack
{
public:
	queue<int> q;

	MyStack()
	{
	}

	void push(int x)
	{
		q.push(x);
		int n = q.size();
		for (int i = 0; i < n - 1; i++) // till size-1 push all elements back in the queue
		{
			q.push(q.front());
			q.pop();
		}
	}

	int pop()
	{
		int temp = q.front();
		q.pop();
		return temp;
	}

	int top()
	{
		return q.empty() ? -1 : q.front();
	}

	bool empty()
	{
		return q.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */